/**
 * @file Servico.cpp
 * @brief Implementação dos métodos dos serviços
 * 
 * @author Seu Nome
 * @date 2024
 */

#include "Servico.hpp"
#include "Entidade.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;

// ============================================
// SERVIÇO: PESSOA
// ============================================

void ServicoPessoa::criarPessoa(const string& email,
                                const string& nome,
                                const string& senha,
                                const string& papel) {
    Email emailObj(email);

    Nome nomeObj;
    nomeObj.setNome(nome);

    Senha senhaObj;
    senhaObj.setSenha(senha);

    Papel papelObj(papel);

    Pessoa pessoa(emailObj, nomeObj, senhaObj, papelObj);

    if (!container.criar(pessoa)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' ja existe");
    }

    cout << "Pessoa criada com sucesso!" << endl;
}

void ServicoPessoa::consultarPessoa(const string& email) {
    Email emailObj(email);

    Nome nomeTemp;
    nomeTemp.setNome("Temp");

    Senha senhaTemp;
    senhaTemp.setSenha("a1B2c3");

    Papel papelTemp("DESENVOLVEDOR");

    Pessoa pessoa(emailObj, nomeTemp, senhaTemp, papelTemp);

    if (!container.ler(&pessoa)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' nao encontrada");
    }

    cout << "\n=== DADOS DA PESSOA ===" << endl;
    cout << "Email: " << pessoa.getEmail().get() << endl;
    cout << "Nome: " << pessoa.getNome().getNome() << endl;
    cout << "Senha: " << pessoa.getSenha().getSenha() << endl;
    cout << "Papel: " << pessoa.getPapel().getValor() << endl;
}

void ServicoPessoa::atualizarPessoa(const string& email,
                                    const string& nome,
                                    const string& senha,
                                    const string& papel) {
    Email emailObj(email);

    Nome nomeObj;
    nomeObj.setNome(nome);

    Senha senhaObj;
    senhaObj.setSenha(senha);

    Papel papelObj(papel);

    Pessoa pessoa(emailObj, nomeObj, senhaObj, papelObj);

    if (!container.atualizar(pessoa)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' nao encontrada");
    }

    cout << "Pessoa atualizada com sucesso!" << endl;
}

void ServicoPessoa::excluirPessoa(const string& email) {
    Email emailObj(email);

    if (!container.excluir(emailObj)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' nao encontrada");
    }

    cout << "Pessoa excluida com sucesso!" << endl;
}

// ============================================
// SERVIÇO: PLANO SPRINT (COMPLETO)
// ============================================

ServicoPlanoSprint::ServicoPlanoSprint(ContainerProjeto* contProjeto, 
                                       ContainerHistoriaUsuario* contHistoria)
    : containerProjeto(contProjeto), containerHistoria(contHistoria) {
    if (containerProjeto == nullptr || containerHistoria == nullptr) {
        throw invalid_argument("Containers de dependencia nao podem ser nulos");
    }
}

void ServicoPlanoSprint::criarPlanoSprint(const string& codigo,
                                           int capacidade,
                                           const string& dataInicio,
                                           const string& dataTermino,
                                           const string& codigoProjeto) {
    // 1. Verifica se o código do sprint já existe
    if (container.existe(codigo)) {
        throw runtime_error("Erro: Sprint com codigo '" + codigo + "' ja existe");
    }
    
    // 2. Verifica se o projeto associado existe
    if (!containerProjeto->existe(codigoProjeto)) {
        throw runtime_error("Erro: Projeto com codigo '" + codigoProjeto + "' nao encontrado");
    }
    
    // 3. Cria o objeto PlanoSprint (o construtor valida todos os domínios)
    PlanoSprint novoSprint(codigo, capacidade, dataInicio, dataTermino, codigoProjeto);
    
    // 4. Armazena no container usando o método criar()
    if (!container.criar(novoSprint)) {
        throw runtime_error("Erro: Falha ao criar plano de sprint");
    }
    
    cout << "✓ Plano de sprint criado com sucesso!" << endl;
    cout << "  Codigo: " << codigo << endl;
    cout << "  Capacidade: " << capacidade << " dias" << endl;
    cout << "  Periodo: " << dataInicio << " a " << dataTermino << endl;
}

void ServicoPlanoSprint::listarPlanosSprint() {
    vector<PlanoSprint> lista = container.listarTodas();
    
    if (lista.empty()) {
        cout << "Nenhum plano de sprint cadastrado." << endl;
        return;
    }
    
    cout << "\n=== PLANOS DE SPRINT ===" << endl;
    cout << left;
    cout << setw(10) << "Codigo"
         << setw(12) << "Capacidade"
         << setw(12) << "Data Inicio"
         << setw(12) << "Data Termino"
         << setw(10) << "Projeto"
         << setw(10) << "Historias" << endl;
    cout << string(66, '-') << endl;
    
    for (const auto& s : lista) {
        cout << setw(10) << s.getCodigo()
             << setw(12) << (to_string(s.getCapacidade()) + " dias")
             << setw(12) << s.getDataInicio()
             << setw(12) << s.getDataTermino()
             << setw(10) << s.getCodigoProjeto()
             << setw(10) << s.getHistoriasAssociadas().size() << endl;
    }
}

void ServicoPlanoSprint::consultarPlanoSprint(const string& codigo) {
    const PlanoSprint* s = container.buscar(codigo);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigo + "' nao encontrado");
    }
    
    cout << "\n=== DETALHES DO PLANO DE SPRINT ===" << endl;
    cout << "Codigo: " << s->getCodigo() << endl;
    cout << "Capacidade: " << s->getCapacidade() << " dias" << endl;
    cout << "Data de inicio: " << s->getDataInicio() << endl;
    cout << "Data de termino: " << s->getDataTermino() << endl;
    cout << "Projeto associado: " << s->getCodigoProjeto() << endl;
    cout << "Soma das estimativas: " << s->getSomaEstimativas() << " dias" << endl;
    cout << "Historias associadas: " << s->getHistoriasAssociadas().size() << endl;
}

void ServicoPlanoSprint::atualizarCapacidade(const string& codigo, 
                                              int novaCapacidade) {
    PlanoSprint* s = container.buscar(codigo);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigo + "' nao encontrado");
    }
    
    // O método setCapacidade() do PlanoSprint já valida:
    // - Se a capacidade está entre 1 e 365
    // - Se a nova capacidade não é menor que a soma das estimativas atuais
    s->setCapacidade(novaCapacidade);
    
    // Atualiza no container
    if (!container.atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar capacidade");
    }
    
    cout << "✓ Capacidade do sprint '" << codigo 
         << "' atualizada para " << novaCapacidade << " dias" << endl;
}

void ServicoPlanoSprint::excluirPlanoSprint(const string& codigo) {
    // O container usa Codigo como parâmetro para excluir
    Codigo codigoObj(codigo);
    
    if (!container.excluir(codigoObj)) {
        throw runtime_error("Erro: Plano de sprint '" + codigo + "' nao encontrado");
    }
    
    cout << "✓ Plano de sprint '" << codigo << "' removido com sucesso" << endl;
}

void ServicoPlanoSprint::associarHistoria(const string& codigoSprint,
                                           const string& codigoHistoria,
                                           int estimativa) {
    // 1. Verifica se o sprint existe
    PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigoSprint + "' nao encontrado");
    }
    
    // 2. Verifica se a história existe
    if (!containerHistoria->existe(codigoHistoria)) {
        throw runtime_error("Erro: Historia de usuario '" + codigoHistoria + "' nao encontrada");
    }
    
    // 3. Delegar a associação para o próprio PlanoSprint
    // O método associarHistoria() do PlanoSprint valida:
    // - Se a história já está associada
    // - Se a estimativa é válida
    // - Se a capacidade não será excedida
    s->associarHistoria(codigoHistoria, estimativa);
    
    // 4. Atualiza no container
    if (!container.atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar sprint");
    }
    
    cout << "✓ Historia '" << codigoHistoria 
         << "' associada ao sprint '" << codigoSprint << "'" << endl;
    cout << "  Estimativa: " << estimativa << " dias" << endl;
    cout << "  Soma atual: " << s->getSomaEstimativas() 
         << " / " << s->getCapacidade() << " dias" << endl;
}

void ServicoPlanoSprint::desassociarHistoria(const string& codigoSprint,
                                              const string& codigoHistoria,
                                              int estimativa) {
    PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigoSprint + "' nao encontrado");
    }
    
    // O método desassociarHistoria() retorna false se a história não existir
    if (!s->desassociarHistoria(codigoHistoria, estimativa)) {
        throw runtime_error("Erro: Historia '" + codigoHistoria + 
                           "' nao esta associada ao sprint '" + codigoSprint + "'");
    }
    
    // Atualiza no container
    if (!container.atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar sprint");
    }
    
    cout << "✓ Historia '" << codigoHistoria 
         << "' removida do sprint '" << codigoSprint << "'" << endl;
}

void ServicoPlanoSprint::listarHistoriasDoSprint(const string& codigoSprint) {
    const PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigoSprint + "' nao encontrado");
    }
    
    const vector<string>& historias = s->getHistoriasAssociadas();
    
    if (historias.empty()) {
        cout << "Nenhuma historia associada ao sprint '" << codigoSprint << "'" << endl;
        return;
    }
    
    cout << "\n=== HISTORIAS ASSOCIADAS AO SPRINT " << codigoSprint << " ===" << endl;
    cout << left;
    cout << setw(12) << "Codigo"
         << setw(12) << "Estimativa" << endl;
    cout << string(24, '-') << endl;
    
    // Mostra as histórias associadas
    for (const auto& hist : historias) {
        cout << setw(12) << hist << endl;
    }
    
    cout << "\nSoma total das estimativas: " << s->getSomaEstimativas()
         << " / " << s->getCapacidade() << " dias" << endl;
}