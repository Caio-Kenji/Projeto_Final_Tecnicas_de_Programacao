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
// SERVIÇO: PESSOA (CORRIGIDO - VERSÃO SINGLETON)
// ============================================

ServicoPessoa::ServicoPessoa() {
    container = ContainerPessoa::getInstancia();
    if (container == nullptr) {
        throw runtime_error("Erro: Falha ao obter instancia do container de pessoa");
    }
}

void ServicoPessoa::criarPessoa(const string& email,
                                const string& nome,
                                const string& senha,
                                const string& papel) {
    // 1. Valida os domínios
    Email emailObj(email);
    Nome nomeObj;
    nomeObj.setNome(nome);
    Senha senhaObj;
    senhaObj.setSenha(senha);
    Papel papelObj(papel);

    // 2. Cria a pessoa
    Pessoa pessoa(emailObj, nomeObj, senhaObj, papelObj);

    // 3. Armazena no container (usando ->)
    if (!container->criar(pessoa)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' ja existe");
    }

    cout << "✓ Pessoa criada com sucesso!" << endl;
    cout << "  Email: " << email << endl;
    cout << "  Nome: " << nome << endl;
    cout << "  Papel: " << papel << endl;
}

void ServicoPessoa::consultarPessoa(const string& email) {
    // Cria uma pessoa temporária para buscar
    Email emailObj(email);
    Nome nomeTemp;
    nomeTemp.setNome("Temp");
    Senha senhaTemp;
    senhaTemp.setSenha("a1B2c3");
    Papel papelTemp("DESENVOLVEDOR");

    Pessoa pessoa(emailObj, nomeTemp, senhaTemp, papelTemp);

    if (!container->ler(&pessoa)) {
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

    if (!container->atualizar(pessoa)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' nao encontrada");
    }

    cout << "✓ Pessoa '" << email << "' atualizada com sucesso!" << endl;
}

void ServicoPessoa::excluirPessoa(const string& email) {
    Email emailObj(email);

    if (!container->excluir(emailObj)) {
        throw runtime_error("Erro: Pessoa com email '" + email + "' nao encontrada");
    }

    cout << "✓ Pessoa '" << email << "' excluida com sucesso!" << endl;
}



















// ============================================
// SERVIÇO: PLANO SPRINT (CORRIGIDO)
// ============================================

/**
 * @brief Construtor do serviço de plano de sprint.
 * @details Obtém as instâncias Singleton dos containers necessários.
 */
ServicoPlanoSprint::ServicoPlanoSprint() {
    container = ContainerPlanoSprint::getInstancia();
    containerProjeto = ContainerProjeto::getInstancia();
    containerHistoria = ContainerHistoriaUsuario::getInstancia();

    if (container == nullptr || containerProjeto == nullptr || containerHistoria == nullptr) {
        throw runtime_error("Erro: Falha ao obter instancias dos containers");
    }
}

void ServicoPlanoSprint::criarPlanoSprint(const string& codigo,
                                          int capacidade,
                                          const string& dataInicio,
                                          const string& dataTermino,
                                          const string& codigoProjeto) {
    // 1. Verifica se o código do sprint já existe
    if (container->existe(codigo)) {
        throw runtime_error("Erro: Sprint com codigo '" + codigo + "' ja existe");
    }

    // 2. Verifica se o projeto associado existe
    if (!containerProjeto->existe(codigoProjeto)) {
        throw runtime_error("Erro: Projeto com codigo '" + codigoProjeto + "' nao encontrado");
    }

    // 3. Cria o objeto PlanoSprint (o construtor valida todos os domínios)
    PlanoSprint novoSprint(codigo, capacidade, dataInicio, dataTermino, codigoProjeto);

    // 4. Armazena no container usando o método criar()
    if (!container->criar(novoSprint)) {
        throw runtime_error("Erro: Falha ao criar plano de sprint");
    }

    cout << "✓ Plano de sprint criado com sucesso!" << endl;
    cout << "  Codigo: " << codigo << endl;
    cout << "  Capacidade: " << capacidade << " dias" << endl;
    cout << "  Periodo: " << dataInicio << " a " << dataTermino << endl;
}

void ServicoPlanoSprint::listarPlanosSprint() {
    vector<PlanoSprint> lista = container->listarTodas();

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
    const PlanoSprint* s = container->buscar(codigo);
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
    PlanoSprint* s = container->buscar(codigo);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigo + "' nao encontrado");
    }

    s->setCapacidade(novaCapacidade);

    if (!container->atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar capacidade");
    }

    cout << "✓ Capacidade do sprint '" << codigo
         << "' atualizada para " << novaCapacidade << " dias" << endl;
}

void ServicoPlanoSprint::excluirPlanoSprint(const string& codigo) {
    Codigo codigoObj(codigo);

    if (!container->excluir(codigoObj)) {
        throw runtime_error("Erro: Plano de sprint '" + codigo + "' nao encontrado");
    }

    cout << "✓ Plano de sprint '" << codigo << "' removido com sucesso" << endl;
}

void ServicoPlanoSprint::associarHistoria(const string& codigoSprint,
                                          const string& codigoHistoria,
                                          int estimativa) {
    PlanoSprint* s = container->buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigoSprint + "' nao encontrado");
    }

    if (!containerHistoria->existe(codigoHistoria)) {
        throw runtime_error("Erro: Historia de usuario '" + codigoHistoria + "' nao encontrada");
    }

    const HistoriaUsuario* h = containerHistoria->buscar(codigoHistoria);
    if (h != nullptr && !h->isAFazer()) {
        throw runtime_error("Erro: Historia '" + codigoHistoria +
                           "' nao pode ser associada a um sprint (estado: " +
                           h->getEstadoStr() + ")");
    }

    if (h != nullptr && h->estaAssociadaASprint()) {
        throw runtime_error("Erro: Historia '" + codigoHistoria +
                           "' ja esta associada ao sprint '" +
                           h->getCodigoPlanoSprint().getValor() + "'");
    }

    s->associarHistoria(codigoHistoria, estimativa);

    if (!container->atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar sprint");
    }

    if (h != nullptr) {
        HistoriaUsuario* hMod = containerHistoria->buscar(codigoHistoria);
        if (hMod != nullptr) {
            Codigo codigoSprintObj(codigoSprint);
            hMod->setCodigoPlanoSprint(codigoSprintObj);
            containerHistoria->atualizar(*hMod);
        }
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
    PlanoSprint* s = container->buscar(codigoSprint);
    if (s == nullptr) {
        throw runtime_error("Erro: Plano de sprint '" + codigoSprint + "' nao encontrado");
    }

    HistoriaUsuario* h = containerHistoria->buscar(codigoHistoria);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigoHistoria + "' nao encontrada");
    }

    if (h->getCodigoPlanoSprint().getValor() != codigoSprint) {
        throw runtime_error("Erro: Historia '" + codigoHistoria +
                           "' nao esta associada ao sprint '" + codigoSprint + "'");
    }

    if (!s->desassociarHistoria(codigoHistoria, estimativa)) {
        throw runtime_error("Erro: Falha ao remover historia do sprint");
    }

    if (!container->atualizar(*s)) {
        throw runtime_error("Erro: Falha ao atualizar sprint");
    }

    h->setCodigoPlanoSprint(Codigo());
    if (!containerHistoria->atualizar(*h)) {
        throw runtime_error("Erro: Falha ao atualizar historia");
    }

    cout << "✓ Historia '" << codigoHistoria
         << "' removida do sprint '" << codigoSprint << "'" << endl;
}

void ServicoPlanoSprint::listarHistoriasDoSprint(const string& codigoSprint) {
    const PlanoSprint* s = container->buscar(codigoSprint);
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
         << setw(12) << "Estimativa"
         << setw(15) << "Nome"
         << setw(12) << "Estado" << endl;
    cout << string(51, '-') << endl;

    for (const auto& codHist : historias) {
        const HistoriaUsuario* h = containerHistoria->buscar(codHist);
        if (h != nullptr) {
            cout << setw(12) << codHist
                 << setw(12) << (to_string(h->getEstimativa().getTempo()) + " dias")
                 << setw(15) << h->getNome().getNome()
                 << setw(12) << h->getEstadoStr() << endl;
        } else {
            cout << setw(12) << codHist
                 << setw(12) << "N/A"
                 << setw(15) << "(removida)"
                 << setw(12) << "-" << endl;
        }
    }

    cout << "\nSoma total das estimativas: " << s->getSomaEstimativas()
         << " / " << s->getCapacidade() << " dias" << endl;
}











// ============================================
// SERVIÇO: HISTORIA USUARIO
// ============================================

ServicoHistoriaUsuario::ServicoHistoriaUsuario() {
    container = ContainerHistoriaUsuario::getInstancia();
    containerProjeto = ContainerProjeto::getInstancia();
}

void ServicoHistoriaUsuario::criarHistoria(const string& codigo,
                                           const string& nome,
                                           const string& descricao,
                                           const string& prioridade,
                                           const string& codigoProjeto,
                                           int estimativa) {
    // 1. Verifica se o código já existe
    if (container->existe(codigo)) {
        throw runtime_error("Erro: Historia com codigo '" + codigo + "' ja existe");
    }

    // 2. Verifica se o projeto existe
    if (!containerProjeto->existe(codigoProjeto)) {
        throw runtime_error("Erro: Projeto '" + codigoProjeto + "' nao encontrado");
    }

    // 3. Valida os domínios
    Codigo c(codigo);
    Nome n;
    n.setNome(nome);
    Texto t;
    t.setValor(descricao);
    Prioridade p(prioridade);
    Estado e("A FAZER");  // Estado inicial
    Codigo cp(codigoProjeto);
    Tempo tm;
    tm.setTempo(estimativa);

    // 4. Cria a história (sem responsável e sem sprint)
    HistoriaUsuario historia(c, n, t, p, e, cp, tm);

    // 5. Armazena
    if (!container->criar(historia)) {
        throw runtime_error("Erro: Falha ao criar historia");
    }

    cout << "✓ Historia criada com sucesso!" << endl;
    cout << "  Codigo: " << codigo << endl;
    cout << "  Nome: " << nome << endl;
    cout << "  Estado: A FAZER" << endl;
}

void ServicoHistoriaUsuario::listarHistorias() {
    vector<HistoriaUsuario> lista = container->listarTodas();

    if (lista.empty()) {
        cout << "Nenhuma historia cadastrada." << endl;
        return;
    }

    cout << "\n=== HISTORIAS CADASTRADAS ===" << endl;
    cout << left << setw(10) << "Codigo"
         << setw(15) << "Nome"
         << setw(12) << "Prioridade"
         << setw(12) << "Estado"
         << setw(10) << "Projeto"
         << setw(10) << "Estimativa" << endl;
    cout << string(69, '-') << endl;

    for (const auto& h : lista) {
        cout << setw(10) << h.getCodigo().getValor()
             << setw(15) << h.getNome().getNome()
             << setw(12) << h.getPrioridade().getValor()
             << setw(12) << h.getEstadoStr()
             << setw(10) << h.getCodigoProjeto().getValor()
             << setw(10) << h.getEstimativa().getTempo() << endl;
    }
}

void ServicoHistoriaUsuario::consultarHistoria(const string& codigo) {
    const HistoriaUsuario* h = container->buscar(codigo);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigo + "' nao encontrada");
    }

    cout << "\n=== DADOS DA HISTORIA ===" << endl;
    cout << "Codigo: " << h->getCodigo().getValor() << endl;
    cout << "Nome: " << h->getNome().getNome() << endl;
    cout << "Descricao: " << h->getDescricao().getValor() << endl;
    cout << "Prioridade: " << h->getPrioridade().getValor() << endl;
    cout << "Estado: " << h->getEstadoStr() << endl;
    cout << "Projeto: " << h->getCodigoProjeto().getValor() << endl;
    cout << "Estimativa: " << h->getEstimativa().getTempo() << " dias" << endl;

    string responsavel = h->getCodigoPessoa().getValor();
    cout << "Responsavel: " << (responsavel.empty() ? "Nenhum" : responsavel) << endl;

    string sprint = h->getCodigoPlanoSprint().getValor();
    cout << "Sprint: " << (sprint.empty() ? "Nao associado" : sprint) << endl;
}

void ServicoHistoriaUsuario::alterarEstado(const string& codigo,
                                           const string& novoEstado) {
    HistoriaUsuario* h = container->buscar(codigo);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigo + "' nao encontrada");
    }

    // Valida o novo estado
    Estado e(novoEstado);  // Pode lançar exceção

    // Verifica se é uma transição válida (apenas avanço)
    string estadoAtual = h->getEstadoStr();
    if (estadoAtual == "FEITO") {
        throw runtime_error("Erro: Historia ja esta em FEITO");
    }
    if (estadoAtual == "FAZENDO" && novoEstado != "FEITO") {
        throw runtime_error("Erro: De FAZENDO so pode ir para FEITO");
    }
    if (estadoAtual == "A FAZER" && novoEstado != "FAZENDO" && novoEstado != "FEITO") {
        throw runtime_error("Erro: De A FAZER so pode ir para FAZENDO ou FEITO");
    }

    h->setEstado(e);

    if (!container->atualizar(*h)) {
        throw runtime_error("Erro: Falha ao atualizar estado");
    }

    cout << "✓ Estado da historia '" << codigo
         << "' alterado para: " << novoEstado << endl;
}

void ServicoHistoriaUsuario::atualizarHistoria(const string& codigo,
                                               const string& nome,
                                               const string& descricao,
                                               const string& prioridade,
                                               int estimativa) {
    HistoriaUsuario* h = container->buscar(codigo);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigo + "' nao encontrada");
    }

    // Valida os novos valores
    Nome n;
    n.setNome(nome);
    Texto t;
    t.setValor(descricao);
    Prioridade p(prioridade);
    Tempo tm;
    tm.setTempo(estimativa);

    h->setNome(n);
    h->setDescricao(t);
    h->setPrioridade(p);
    h->setEstimativa(tm);

    if (!container->atualizar(*h)) {
        throw runtime_error("Erro: Falha ao atualizar historia");
    }

    cout << "✓ Historia '" << codigo << "' atualizada com sucesso!" << endl;
}

void ServicoHistoriaUsuario::excluirHistoria(const string& codigo) {
    Codigo c(codigo);
    if (!container->excluir(c)) {
        throw runtime_error("Erro: Historia '" + codigo + "' nao encontrada");
    }
    cout << "✓ Historia '" << codigo << "' removida com sucesso" << endl;
}

void ServicoHistoriaUsuario::atribuirResponsavel(const string& codigoHistoria,
                                                  const string& codigoPessoa) {
    HistoriaUsuario* h = container->buscar(codigoHistoria);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigoHistoria + "' nao encontrada");
    }

    // Verifica se a história pode ser atribuída
    if (!h->podeSerAtribuida()) {
        throw runtime_error("Erro: Historia em estado '" + h->getEstadoStr() +
                           "' nao pode ser atribuida");
    }

    Codigo pessoa(codigoPessoa);  // Valida o código
    h->setCodigoPessoa(pessoa);

    if (!container->atualizar(*h)) {
        throw runtime_error("Erro: Falha ao atribuir responsavel");
    }

    cout << "✓ Responsavel '" << codigoPessoa
         << "' atribuido a historia '" << codigoHistoria << "'" << endl;
}

void ServicoHistoriaUsuario::removerResponsavel(const string& codigoHistoria) {
    HistoriaUsuario* h = container->buscar(codigoHistoria);
    if (h == nullptr) {
        throw runtime_error("Erro: Historia '" + codigoHistoria + "' nao encontrada");
    }

    h->setCodigoPessoa(Codigo());  // Código vazio

    if (!container->atualizar(*h)) {
        throw runtime_error("Erro: Falha ao remover responsavel");
    }

    cout << "✓ Responsavel removido da historia '" << codigoHistoria << "'" << endl;
}

void ServicoHistoriaUsuario::listarHistoriasPorProjeto(const string& codigoProjeto) {
    vector<HistoriaUsuario> lista = container->listarPorProjeto(codigoProjeto);

    if (lista.empty()) {
        cout << "Nenhuma historia associada ao projeto '" << codigoProjeto << "'" << endl;
        return;
    }

    cout << "\n=== HISTORIAS DO PROJETO " << codigoProjeto << " ===" << endl;
    cout << left << setw(10) << "Codigo"
         << setw(15) << "Nome"
         << setw(12) << "Prioridade"
         << setw(12) << "Estado"
         << setw(10) << "Estimativa" << endl;
    cout << string(59, '-') << endl;

    for (const auto& h : lista) {
        cout << setw(10) << h.getCodigo().getValor()
             << setw(15) << h.getNome().getNome()
             << setw(12) << h.getPrioridade().getValor()
             << setw(12) << h.getEstadoStr()
             << setw(10) << h.getEstimativa().getTempo() << endl;
    }
}







// ============================================
// SERVIÇO: PROJETO (ADICIONAR)
// ============================================

ServicoProjeto::ServicoProjeto() {
    container = ContainerProjeto::getInstancia();
    if (container == nullptr) {
        throw runtime_error("Erro: Falha ao obter instancia do container de projeto");
    }
}

void ServicoProjeto::criarProjeto(const string& codigo,
                                  const string& nome,
                                  const string& dataInicio,
                                  const string& dataTermino,
                                  const string& emailScrumMaster) {
    
   
    // 1. Verifica se o código já existe
    if (container->existe(codigo)) {
        throw runtime_error("Erro: Projeto com codigo '" + codigo + "' ja existe");
    }

    // 2. Valida os domínios
    Codigo c(codigo);
    Nome n;
    n.setNome(nome);
    Data di;
    di.setValor(dataInicio);
    Data dt;
    dt.setValor(dataTermino);
    Email scrummaster(emailScrumMaster);

    // 3. Cria o projeto
    Projeto projeto;
    projeto.setCodigo(c);
    projeto.setNome(n);
    projeto.setDataInicio(di);
    projeto.setDataTermino(dt);
    projeto.setMestre(scrummaster);

    // 4. Armazena
    if (!container->criar(projeto)) {
        throw runtime_error("Erro: Falha ao criar projeto");
    }

    cout << "✓ Projeto criado com sucesso!" << endl;
    cout << "  Codigo: " << codigo << endl;
    cout << "  Nome: " << nome << endl;
    cout << "  Periodo: " << dataInicio << " a " << dataTermino << endl;
    cout << "  Scrum Master: " << emailScrumMaster << endl;
}

void ServicoProjeto::listarProjetos() {
    vector<Projeto> lista = container->listarTodas();

    if (lista.empty()) {
        cout << "Nenhum projeto cadastrado." << endl;
        return;
    }

    cout << "\n=== PROJETOS CADASTRADOS ===" << endl;
    cout << left << setw(10) << "Codigo"
         << setw(20) << "Nome"
         << setw(12) << "Inicio"
         << setw(12) << "Termino"
         << setw(10) << "Scrum Master" << endl;
    cout << string(64, '-') << endl;

    for (const auto& p : lista) {
        cout << setw(10) << p.getCodigo().getValor()
             << setw(20) << p.getNome().getNome()
             << setw(12) << p.getDataInicio().getValor()
             << setw(12) << p.getDataTermino().getValor()
             << setw(10) << p.getMestre().get() << endl;
    }
}

void ServicoProjeto::consultarProjeto(const string& codigo) {
    const Projeto* p = container->buscar(codigo);
    if (p == nullptr) {
        throw runtime_error("Erro: Projeto '" + codigo + "' nao encontrado");
    }

    cout << "\n=== DADOS DO PROJETO ===" << endl;
    cout << "Codigo: " << p->getCodigo().getValor() << endl;
    cout << "Nome: " << p->getNome().getNome() << endl;
    cout << "Data Inicio: " << p->getDataInicio().getValor() << endl;
    cout << "Data Termino: " << p->getDataTermino().getValor() << endl;
    cout << "Scrum Master: " << p->getMestre().get() << endl;
}

void ServicoProjeto::atualizarProjeto(const string& codigo,
                                      const string& novoNome) {
    Projeto* p = container->buscar(codigo);
    if (p == nullptr) {
        throw runtime_error("Erro: Projeto '" + codigo + "' nao encontrado");
    }

    Nome nome;
    nome.setNome(novoNome);
    p->setNome(nome);

    if (!container->atualizar(*p)) {
        throw runtime_error("Erro: Falha ao atualizar projeto");
    }

    cout << "✓ Projeto '" << codigo << "' atualizado para: " << novoNome << endl;
}

void ServicoProjeto::excluirProjeto(const string& codigo) {
    Codigo c(codigo);
    if (!container->excluir(c)) {
        throw runtime_error("Erro: Projeto '" + codigo + "' nao encontrado");
    }
    cout << "✓ Projeto '" << codigo << "' removido com sucesso" << endl;
}