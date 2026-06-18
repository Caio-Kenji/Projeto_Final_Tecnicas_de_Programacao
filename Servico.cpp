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
// SERVIÇO: PLANO SPRINT
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
    if (container.existe(codigo)) {
        throw runtime_error("Erro: Sprint com codigo '" + codigo + "' ja existe");
    }
    
    if (!containerProjeto->existe(codigoProjeto)) {
        throw runtime_error("Erro: Projeto com codigo '" + codigoProjeto + "' nao encontrado");
    }
    
    PlanoSprint novoSprint(codigo, capacidade, dataInicio, dataTermino, codigoProjeto);
    container.adicionar(novoSprint);
    
    cout << "✓ Plano de sprint criado com sucesso!" << endl;
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
         << setw(10) << "Capacidade"
         << setw(12) << "Data Inicio"
         << setw(12) << "Data Termino"
         << setw(10) << "Projeto"
         << setw(10) << "Historias" << endl;
    cout << string(64, '-') << endl;
    
    for (const auto& s : lista) {
        cout << setw(10) << s.getCodigo()
             << setw(10) << (to_string(s.getCapacidade()) + "d")
             << setw(12) << s.getDataInicio()
             << setw(12) << s.getDataTermino()
             << setw(10) << s.getCodigoProjeto()
             << setw(10) << s.getHistoriasAssociadas().size() << endl;
    }
}

void ServicoPlanoSprint::consultarPlanoSprint(const string& codigo) {
    const PlanoSprint* s = container.buscar(codigo);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint nao encontrado");
    }
    
    cout << "\n=== DETALHES DO SPRINT ===" << endl;
    cout << "Codigo: " << s->getCodigo() << endl;
    cout << "Capacidade: " << s->getCapacidade() << " dias" << endl;
    cout << "Periodo: " << s->getDataInicio() << " a " << s->getDataTermino() << endl;
    cout << "Projeto: " << s->getCodigoProjeto() << endl;
    cout << "Soma estimativas: " << s->getSomaEstimativas() << " dias" << endl;
    cout << "Historias associadas: " << s->getHistoriasAssociadas().size() << endl;
}

void ServicoPlanoSprint::atualizarCapacidade(const string& codigo, 
                                              int novaCapacidade) {
    PlanoSprint* s = container.buscar(codigo);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint nao encontrado");
    }
    
    s->setCapacidade(novaCapacidade);
    cout << "✓ Capacidade atualizada para " << novaCapacidade << " dias" << endl;
}

void ServicoPlanoSprint::excluirPlanoSprint(const string& codigo) {
    container.remover(codigo);
    cout << "✓ Plano de sprint removido com sucesso" << endl;
}

void ServicoPlanoSprint::associarHistoria(const string& codigoSprint,
                                           const string& codigoHistoria,
                                           int estimativa) {
    PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Sprint nao encontrado");
    }
    
    if (!containerHistoria->existe(codigoHistoria)) {
        throw runtime_error("Erro: Historia nao encontrada");
    }
    
    s->associarHistoria(codigoHistoria, estimativa);
    
    cout << "✓ Historia associada ao sprint!" << endl;
    cout << "  Soma atual: " << s->getSomaEstimativas() 
         << " / " << s->getCapacidade() << " dias" << endl;
}

void ServicoPlanoSprint::desassociarHistoria(const string& codigoSprint,
                                              const string& codigoHistoria,
                                              int estimativa) {
    PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Sprint nao encontrado");
    }
    
    if (!s->desassociarHistoria(codigoHistoria, estimativa)) {
        throw runtime_error("Erro: Historia nao esta associada a este sprint");
    }
    
    cout << "✓ Historia removida do sprint" << endl;
}

void ServicoPlanoSprint::listarHistoriasDoSprint(const string& codigoSprint) {
    const PlanoSprint* s = container.buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Sprint nao encontrado");
    }
    
    const vector<string>& historias = s->getHistoriasAssociadas();
    
    if (historias.empty()) {
        cout << "Nenhuma historia associada a este sprint" << endl;
        return;
    }
    
    cout << "\n=== HISTORIAS DO SPRINT " << codigoSprint << " ===" << endl;
    for (const auto& h : historias) {
        cout << "  - " << h << endl;
    }
    cout << "Total de historias: " << historias.size() << endl;
}
