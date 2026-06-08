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