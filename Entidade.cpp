#include "Entidade.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;


void Projeto::setCodigo(const Codigo& codigoNovo){
    codigo = codigoNovo;
}
void Projeto::setNome(const Nome& nomeNovo){
    nome = nomeNovo;
}
void Projeto::setDataInicio(const Data& dataInicio){
    data_inicio = dataInicio;
}
void Projeto::setDataTermino(const Data& dataTermino){
    data_termino = dataTermino;
}
// ------------------IMPLEMENTAÇÕES: PESSOA ----------------------------------

Pessoa::Pessoa(const Email& emailNovo,
               const Nome& nomeNovo,
               const Senha& senhaNova,
               const Papel& papelNovo)
    : email(emailNovo),
      nome(nomeNovo),
      senha(senhaNova),
      papel(papelNovo)
{
}

void Pessoa::setEmail(const Email& emailNovo){
    email = emailNovo;
}

void Pessoa::setNome(const Nome& nomeNovo){
    nome = nomeNovo;
}

void Pessoa::setSenha(const Senha& senhaNova){
    senha = senhaNova;
}

void Pessoa::setPapel(const Papel& papelNovo){
    papel = papelNovo;
}


// ------------------IMPLEMENTAÇÕES: PLANOS DE SPRINT ----------------------------------





// Construtor
PlanoSprint::PlanoSprint(const string& codigoStr, int capacidadeInt,
                         const string& dataInicioStr, const string& dataTerminoStr,
                         const string& codigoProjetoStr) {
    // Inicializa a soma das estimativas com ZERO
    // Quando o sprint é criado, ainda não tem nenhuma história associada
    somaEstimativas = 0;
    
    // Valida e atribui cada domínio
    // Se qualquer um lançar exceção, o objeto NÃO é criado
    setCodigo(codigoStr);
    setCapacidade(capacidadeInt);
    setDataInicio(dataInicioStr);
    setDataTermino(dataTerminoStr);
    setCodigoProjeto(codigoProjetoStr);
}

// Getters - retornam os valores como string
string PlanoSprint::getCodigo() const {
    return codigo.getValor();
}

int PlanoSprint::getCapacidade() const {
    return capacidade.getTempo();
}

string PlanoSprint::getDataInicio() const {
    return dataInicio.getValor();
}

string PlanoSprint::getDataTermino() const {
    return dataTermino.getValor();
}

string PlanoSprint::getCodigoProjeto() const {
    return codigoProjeto.getValor();
}

const vector<string>& PlanoSprint::getHistoriasAssociadas() const {
    // Retorna referência constante para evitar cópia e prevenir modificação direta
    return historiasAssociadas;
}

int PlanoSprint::getSomaEstimativas() const {
    return somaEstimativas;
}

// Setters
void PlanoSprint::setCodigo(const string& novoCodigo) {
    codigo.setValor(novoCodigo);
}

void PlanoSprint::setCapacidade(int novaCapacidade) {
    // Usa um objeto temporário para validar o valor
    Tempo temp;
    temp.setTempo(novaCapacidade);  // Pode lançar exceção
    
    // REGRA DE NEGÓCIO: A nova capacidade não pode ser menor que a soma das estimativas
    // Porque as histórias já associadas não caberiam mais no sprint
    if (somaEstimativas > novaCapacidade) {
        throw runtime_error("Nova capacidade (" + to_string(novaCapacidade) + 
                           ") menor que soma das estimativas atuais (" + 
                           to_string(somaEstimativas) + ")");
    }
    
    capacidade = temp;
}

void PlanoSprint::setDataInicio(const string& novaData) {
    dataInicio.setValor(novaData);
}

void PlanoSprint::setDataTermino(const string& novaData) {
    dataTermino.setValor(novaData);
}

void PlanoSprint::setCodigoProjeto(const string& novoCodigo) {
    codigoProjeto.setValor(novoCodigo);
}

// Associa uma história ao sprint
void PlanoSprint::associarHistoria(const string& codigoHistoria, int estimativa) {
    // 1. Verifica se a história já está associada (evita duplicidade)
    if (temHistoria(codigoHistoria)) {
        throw runtime_error("Historia '" + codigoHistoria + 
                           "' ja esta associada a este sprint");
    }
    
    // 2. Valida a estimativa usando o domínio Tempo
    Tempo temp;
    temp.setTempo(estimativa);  // Pode lançar exceção se estimativa inválida
    
    // 3. Verifica a regra de capacidade: soma das estimativas ≤ capacidade
    if (somaEstimativas + estimativa > capacidade.getTempo()) {
        throw runtime_error("Capacidade do sprint excedida. "
                           "Soma atual: " + to_string(somaEstimativas) + 
                           ", Nova historia: " + to_string(estimativa) +
                           ", Capacidade: " + to_string(capacidade.getTempo()));
    }
    
    // 4. Adiciona a história e sua estimativa
    historiasAssociadas.push_back(codigoHistoria);
    estimativas.push_back(estimativa);
    
    // 5. Atualiza a soma total
    somaEstimativas += estimativa;
}

// Remove a associação de uma história
bool PlanoSprint::desassociarHistoria(const string& codigoHistoria, int estimativa) {
    // Percorre o vetor em busca da história
    for (size_t i = 0; i < historiasAssociadas.size(); i++) {
        if (historiasAssociadas[i] == codigoHistoria) {
            // Verifica se a estimativa fornecida corresponde à armazenada
            if (estimativas[i] != estimativa) {
                throw runtime_error("Estimativa fornecida (" + to_string(estimativa) + 
                                   ") nao corresponde a armazenada (" + 
                                   to_string(estimativas[i]) + ")");
            }
            
            // Remove do vetor de códigos
            historiasAssociadas.erase(historiasAssociadas.begin() + i);
            
            // Remove do vetor de estimativas (mesma posição)
            estimativas.erase(estimativas.begin() + i);
            
            // Atualiza a soma total
            somaEstimativas -= estimativa;
            
            return true;  // Removido com sucesso
        }
    }
    
    return false;  // História não encontrada
}

// Verifica se uma história está associada
bool PlanoSprint::temHistoria(const string& codigoHistoria) const {
    for (const string& historia : historiasAssociadas) {
        if (historia == codigoHistoria) {
            return true;
        }
    }
    return false;
}

// Recalcula a soma das estimativas percorrendo o vetor
int PlanoSprint::calcularSomaEstimativas() const {
    int soma = 0;
    for (int val : estimativas) {
        soma += val;
    }
    return soma;
}



// ----------------IMPLEMENTAÇÕES: PESSOA ----------------------------------------------


// ============================================
// IMPLEMENTAÇÃO: PESSOA
// ============================================

/**
 * @brief Construtor da classe Pessoa.
 * @details Inicializa todos os atributos com os objetos de domínio fornecidos.
 *          Os domínios já foram validados antes da criação da Pessoa.
 * 
 * @param emailNovo Objeto Email válido
 * @param nomeNovo Objeto Nome válido
 * @param senhaNova Objeto Senha válido
 * @param papelNovo Objeto Papel válido
 */
Pessoa::Pessoa(const Email& emailNovo,
               const Nome& nomeNovo,
               const Senha& senhaNova,
               const Papel& papelNovo)
    : email(emailNovo),
      nome(nomeNovo),
      senha(senhaNova),
      papel(papelNovo)
{
    // Todos os atributos são inicializados na lista de inicialização
    // Nenhuma validação adicional é necessária, pois os domínios já validaram
}

/**
 * @brief Define o email da pessoa.
 * @param emailNovo Objeto Email válido.
 * @post O atributo email é atualizado.
 */
void Pessoa::setEmail(const Email& emailNovo) {
    email = emailNovo;
}

/**
 * @brief Define o nome da pessoa.
 * @param nomeNovo Objeto Nome válido.
 * @post O atributo nome é atualizado.
 */
void Pessoa::setNome(const Nome& nomeNovo) {
    nome = nomeNovo;
}

/**
 * @brief Define a senha da pessoa.
 * @param senhaNova Objeto Senha válido.
 * @post O atributo senha é atualizado.
 */
void Pessoa::setSenha(const Senha& senhaNova) {
    senha = senhaNova;
}

/**
 * @brief Define o papel da pessoa.
 * @param papelNovo Objeto Papel válido.
 * @post O atributo papel é atualizado.
 */
void Pessoa::setPapel(const Papel& papelNovo) {
    papel = papelNovo;
}



//---------------------IMPLEMENTAÇÕES: HISTÓRIA DE USUÁRIO ---------------------------------------------------------------------

// ============================================
// IMPLEMENTAÇÃO: HISTORIA USUARIO
// ============================================

/**
 * @brief Construtor da classe HistoriaUsuario.
 * @details Inicializa todos os atributos com os objetos de domínio fornecidos.
 *          Os domínios já foram validados antes da criação da HistoriaUsuario.
 *
 * @param codigoObj Código da história
 * @param nomeObj Nome da história
 * @param descricaoObj Descrição da história
 * @param prioridadeObj Prioridade da história
 * @param estadoObj Estado inicial da história
 * @param codigoProjetoObj Código do projeto associado
 * @param estimativaObj Estimativa da história
 * @param codigoPessoaObj Código da pessoa responsável
 * @param codigoPlanoSprintObj Código do sprint associado
 */
HistoriaUsuario::HistoriaUsuario(const Codigo& codigoObj,
                                 const Nome& nomeObj,
                                 const Texto& descricaoObj,
                                 const Prioridade& prioridadeObj,
                                 const Estado& estadoObj,
                                 const Codigo& codigoProjetoObj,
                                 const Tempo& estimativaObj,
                                 const Codigo& codigoPessoaObj,
                                 const Codigo& codigoPlanoSprintObj)
    : codigo(codigoObj),
      nome(nomeObj),
      descricao(descricaoObj),
      prioridade(prioridadeObj),
      estado(estadoObj),
      codigoProjeto(codigoProjetoObj),
      estimativa(estimativaObj),
      codigoPessoa(codigoPessoaObj),
      codigoPlanoSprint(codigoPlanoSprintObj) {
    // Todos os atributos são inicializados na lista de inicialização
    // Nenhuma validação adicional é necessária, pois os domínios já validaram
}

// ========== SETTERS ==========

void HistoriaUsuario::setCodigo(const Codigo& novoCodigo) {
    codigo = novoCodigo;
}

void HistoriaUsuario::setNome(const Nome& novoNome) {
    nome = novoNome;
}

void HistoriaUsuario::setDescricao(const Texto& novaDescricao) {
    descricao = novaDescricao;
}

void HistoriaUsuario::setPrioridade(const Prioridade& novaPrioridade) {
    prioridade = novaPrioridade;
}

void HistoriaUsuario::setEstado(const Estado& novoEstado) {
    estado = novoEstado;
}

void HistoriaUsuario::setCodigoProjeto(const Codigo& novoCodigoProjeto) {
    codigoProjeto = novoCodigoProjeto;
}

void HistoriaUsuario::setEstimativa(const Tempo& novaEstimativa) {
    estimativa = novaEstimativa;
}

/**
 * @brief Define a pessoa (desenvolvedor) responsável pela história.
 * @param novoCodigoPessoa Objeto Codigo válido.
 * @post O atributo codigoPessoa é atualizado.
 * @note Pode ser usado um código vazio ("") para remover a associação.
 */
void HistoriaUsuario::setCodigoPessoa(const Codigo& novoCodigoPessoa) {
    codigoPessoa = novoCodigoPessoa;
}

/**
 * @brief Define o plano de sprint associado à história.
 * @param novoCodigoPlanoSprint Objeto Codigo válido.
 * @post O atributo codigoPlanoSprint é atualizado.
 * @note Pode ser usado um código vazio ("") para remover a associação.
 */
void HistoriaUsuario::setCodigoPlanoSprint(const Codigo& novoCodigoPlanoSprint) {
    codigoPlanoSprint = novoCodigoPlanoSprint;
}

// ========== MÉTODOS DE VALIDAÇÃO ==========

/**
 * @brief Avança o estado da história para o próximo estágio.
 * @details A FAZER → FAZENDO → FEITO
 * @return true se o estado foi alterado, false se já está em FEITO.
 */
bool HistoriaUsuario::avancarEstado() {
    string estadoAtual = estado.getValor();

    if (estadoAtual == "A FAZER") {
        Estado novoEstado;
        novoEstado.setValor("FAZENDO");
        estado = novoEstado;
        return true;
    } else if (estadoAtual == "FAZENDO") {
        Estado novoEstado;
        novoEstado.setValor("FEITO");
        estado = novoEstado;
        return true;
    } else {
        return false;
    }
}