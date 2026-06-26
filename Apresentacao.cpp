/**
 * @file Apresentacao.cpp
 * @brief Implementação das controladoras de apresentação
 * 
 * @details Este arquivo contém a implementação de todos os métodos
 *          das classes responsáveis pela interface com o usuário.
 * 
 * @author Seu Nome
 * @date 2024
 */

#include "Apresentacao.hpp"

#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;



// ============================================
// UTILITÁRIOS AUXILIARES
// ============================================

/**
 * @brief Limpa o buffer de entrada do teclado
 */
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Pausa a execução até o usuário pressionar Enter
 */
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get();
}


/**
 * @brief Valida o formato de um código (2 letras + 3 dígitos)
 * @param codigo String a ser validada
 * @return true se o formato for válido
 */
bool validarFormatoCodigo(const string& codigo) {
    if (codigo.length() != 5) return false;
    if (!isupper(codigo[0]) || !isupper(codigo[1])) return false;
    if (!isdigit(codigo[2]) || !isdigit(codigo[3]) || !isdigit(codigo[4])) return false;
    return true;
}

/**
 * @brief Valida o formato de uma data (DD/MM/AAAA)
 * @param data String a ser validada
 * @return true se o formato for válido
 */
bool validarFormatoData(const string& data) {
    if (data.length() != 10) return false;
    if (data[2] != '/' || data[5] != '/') return false;
    return true;
}














// ============================================
// IMPLEMENTAÇÃO: CONTROLADORA PLANO SPRINT
// ============================================

ControladoraPlanoSprint::ControladoraPlanoSprint(IServicoPlanoSprint* s) : servico(s) {
    if (servico == nullptr) {
        throw invalid_argument("Servico de plano sprint nao pode ser nulo");
    }
}

bool ControladoraPlanoSprint::validarFormatoCodigo(const string& codigo) {
    if (codigo.length() != 5) return false;
    if (!isupper(codigo[0]) || !isupper(codigo[1])) return false;
    if (!isdigit(codigo[2]) || !isdigit(codigo[3]) || !isdigit(codigo[4])) return false;
    return true;
}

bool ControladoraPlanoSprint::validarFormatoData(const string& data) {
    if (data.length() != 10) return false;
    if (data[2] != '/' || data[5] != '/') return false;
    return true;
}

string ControladoraPlanoSprint::lerCodigo(const string& mensagem) {
    string codigo;
    do {
        cout << mensagem;
        getline(cin, codigo);
        
        if (!validarFormatoCodigo(codigo)) {
            cout << "Codigo invalido! Deve ter 2 letras maiusculas + 3 digitos (ex: AB123)" << endl;
        } else {
            break;
        }
    } while (true);
    return codigo;
}

string ControladoraPlanoSprint::lerData(const string& mensagem) {
    string data;
    do {
        cout << mensagem << " (DD/MM/AAAA): ";
        getline(cin, data);
        
        if (!validarFormatoData(data)) {
            cout << "Formato invalido! Use DD/MM/AAAA" << endl;
        } else {
            break;
        }
    } while (true);
    return data;
}

int ControladoraPlanoSprint::lerCapacidade() {
    int cap;
    string entrada;
    do {
        cout << "Capacidade (1 a 365 dias): ";
        getline(cin, entrada);
        
        try {
            cap = stoi(entrada);
            if (cap >= 1 && cap <= 365) {
                break;
            }
            cout << "Capacidade deve estar entre 1 e 365!" << endl;
        } catch (...) {
            cout << "Digite um numero valido!" << endl;
        }
    } while (true);
    return cap;
}

int ControladoraPlanoSprint::lerEstimativa() {
    int est;
    string entrada;
    do {
        cout << "Estimativa da historia (1 a 365 dias): ";
        getline(cin, entrada);
        
        try {
            est = stoi(entrada);
            if (est >= 1 && est <= 365) {
                break;
            }
            cout << "Estimativa deve estar entre 1 e 365!" << endl;
        } catch (...) {
            cout << "Digite um numero valido!" << endl;
        }
    } while (true);
    return est;
}

void ControladoraPlanoSprint::executarMenu() {
    int opcao;
    do {
    cout << "\n========================================" << endl;
    cout << "        SISTEMA SCRUM - MENU PRINCIPAL  " << endl;
    cout << "========================================" << endl;
    cout << "1 - Gerenciar Pessoas" << endl;
    cout << "2 - Gerenciar Projetos" << endl;
    cout << "3 - Gerenciar Planos de Sprint" << endl;
    cout << "4 - Gerenciar Historias de Usuario" << endl;
    cout << "0 - Sair" << endl;
    cout << "========================================" << endl;
    cout << "Opcao: ";
        
        cin >> opcao;
        limparBuffer();
        
        switch (opcao) {
            case 1: criarPlanoSprintFlow(); break;
            case 2: listarPlanosFlow(); break;
            case 3: consultarPlanoFlow(); break;
            case 4: atualizarCapacidadeFlow(); break;
            case 5: excluirPlanoFlow(); break;
            case 6: associarHistoriaFlow(); break;
            case 7: desassociarHistoriaFlow(); break;
            case 8: listarHistoriasFlow(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida!" << endl;
        }
        
        if (opcao != 0) pausar();
    } while (opcao != 0);
}

void ControladoraPlanoSprint::criarPlanoSprintFlow() {
    cout << "\n=== CRIAR PLANO DE SPRINT ===" << endl;
    
    string codigo = lerCodigo("Codigo do sprint: ");
    int capacidade = lerCapacidade();
    string dataInicio = lerData("Data de inicio");
    string dataTermino = lerData("Data de termino");
    string codigoProjeto = lerCodigo("Codigo do projeto associado: ");
    
    try {
        servico->criarPlanoSprint(codigo, capacidade, dataInicio, dataTermino, codigoProjeto);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::listarPlanosFlow() {
    cout << "\n=== LISTAR PLANOS DE SPRINT ===" << endl;
    try {
        servico->listarPlanosSprint();
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::consultarPlanoFlow() {
    cout << "\n=== CONSULTAR PLANO DE SPRINT ===" << endl;
    string codigo = lerCodigo("Codigo do sprint: ");
    
    try {
        servico->consultarPlanoSprint(codigo);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::atualizarCapacidadeFlow() {
    cout << "\n=== ATUALIZAR CAPACIDADE DO SPRINT ===" << endl;
    string codigo = lerCodigo("Codigo do sprint: ");
    int novaCapacidade = lerCapacidade();
    
    try {
        servico->atualizarCapacidade(codigo, novaCapacidade);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::excluirPlanoFlow() {
    cout << "\n=== EXCLUIR PLANO DE SPRINT ===" << endl;
    string codigo = lerCodigo("Codigo do sprint: ");
    
    char confirm;
    cout << "Tem certeza? (S/N): ";
    cin >> confirm;
    limparBuffer();
    
    if (toupper(confirm) == 'S') {
        try {
            servico->excluirPlanoSprint(codigo);
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
        }
    } else {
        cout << "Operacao cancelada." << endl;
    }
}

void ControladoraPlanoSprint::associarHistoriaFlow() {
    cout << "\n=== ASSOCIAR HISTORIA AO SPRINT ===" << endl;
    string codigoSprint = lerCodigo("Codigo do sprint: ");
    string codigoHistoria = lerCodigo("Codigo da historia: ");
    int estimativa = lerEstimativa();
    
    try {
        servico->associarHistoria(codigoSprint, codigoHistoria, estimativa);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::desassociarHistoriaFlow() {
    cout << "\n=== REMOVER HISTORIA DO SPRINT ===" << endl;
    string codigoSprint = lerCodigo("Codigo do sprint: ");
    string codigoHistoria = lerCodigo("Codigo da historia: ");
    int estimativa = lerEstimativa();
    
    try {
        servico->desassociarHistoria(codigoSprint, codigoHistoria, estimativa);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::listarHistoriasFlow() {
    cout << "\n=== LISTAR HISTORIAS DO SPRINT ===" << endl;
    string codigoSprint = lerCodigo("Codigo do sprint: ");
    
    try {
        servico->listarHistoriasDoSprint(codigoSprint);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}
















// ============================================
// IMPLEMENTAÇÃO: CONTROLADORA PESSOA
// ============================================

ControladoraPessoa::ControladoraPessoa(IServicoPessoa* s) : servico(s) {
    if (servico == nullptr) {
        throw invalid_argument("Servico de pessoa nao pode ser nulo");
    }
}

string ControladoraPessoa::lerEmail() {
    string email;
    do {
        cout << "Email: ";
        getline(cin, email);
        if (email.find('@') == string::npos) {
            cout << "Email deve conter '@'" << endl;
        } else {
            break;
        }
    } while (true);
    return email;
}

string ControladoraPessoa::lerNome() {
    string nome;
    do {
        cout << "Nome (max 10 caracteres): ";
        getline(cin, nome);
        if (nome.empty() || nome.length() > 10) {
            cout << "Nome deve ter entre 1 e 10 caracteres!" << endl;
        } else if (nome[0] == ' ' || nome.back() == ' ') {
            cout << "Nome nao pode comecar ou terminar com espaco!" << endl;
        } else {
            bool valido = true;
            for (char c : nome) {
                if (!isalpha(c) && c != ' ') {
                    valido = false;
                    break;
                }
            }
            if (!valido) {
                cout << "Nome deve conter apenas letras e espacos!" << endl;
            } else {
                break;
            }
        }
    } while (true);
    return nome;
}

string ControladoraPessoa::lerSenha() {
    string senha;
    do {
        cout << "Senha (6 caracteres): ";
        getline(cin, senha);
        if (senha.length() != 6) {
            cout << "Senha deve ter exatamente 6 caracteres!" << endl;
        } else {
            break;
        }
    } while (true);
    return senha;
}

string ControladoraPessoa::lerPapel() {
    string papel;
    do {
        cout << "Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO): ";
        getline(cin, papel);
        if (papel == "DESENVOLVEDOR" || papel == "MESTRE SCRUM" || papel == "PROPRIETARIO DE PRODUTO") {
            break;
        }
        cout << "Papel invalido!" << endl;
    } while (true);
    return papel;
}

void ControladoraPessoa::executarMenu() {
    int opcao;
    do {
    cout << "\n==================================" << endl;
    cout << "          MENU PESSOA" << endl;
    cout << "==================================" << endl;
    cout << "1 - Criar Pessoa" << endl;
    cout << "2 - Consultar Pessoa" << endl;
    cout << "3 - Atualizar Pessoa" << endl;
    cout << "4 - Excluir Pessoa" << endl;
    cout << "0 - Voltar" << endl;
    cout << "==================================" << endl;
    cout << "Opcao: ";

        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: criarPessoaFlow(); break;
            case 2: consultarPessoaFlow(); break;
            case 3: atualizarPessoaFlow(); break;
            case 4: excluirPessoaFlow(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida!" << endl;
        }

        if (opcao != 0) pausar();
    } while (opcao != 0);
}

void ControladoraPessoa::criarPessoaFlow() {
    cout << "\n=== CRIAR PESSOA ===" << endl;
    string email = lerEmail();
    string nome = lerNome();
    string senha = lerSenha();
    string papel = lerPapel();

    try {
        servico->criarPessoa(email, nome, senha, papel);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPessoa::consultarPessoaFlow() {
    cout << "\n=== CONSULTAR PESSOA ===" << endl;
    string email = lerEmail();

    try {
        servico->consultarPessoa(email);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPessoa::atualizarPessoaFlow() {
    cout << "\n=== ATUALIZAR PESSOA ===" << endl;
    string email = lerEmail();
    string nome = lerNome();
    string senha = lerSenha();
    string papel = lerPapel();

    try {
        servico->atualizarPessoa(email, nome, senha, papel);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraPessoa::excluirPessoaFlow() {
    cout << "\n=== EXCLUIR PESSOA ===" << endl;
    string email = lerEmail();

    char confirm;
    cout << "Tem certeza? (S/N): ";
    cin >> confirm;
    limparBuffer();

    if (toupper(confirm) == 'S') {
        try {
            servico->excluirPessoa(email);
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
        }
    } else {
        cout << "Operacao cancelada." << endl;
    }
}

















// ============================================
// IMPLEMENTAÇÃO: CONTROLADORA PROJETO
// ============================================

ControladoraProjeto::ControladoraProjeto(IServicoProjeto* s) : servico(s) {
    if (servico == nullptr) {
        throw invalid_argument("Servico de projeto nao pode ser nulo");
    }
}



/**
 * @brief Lê um email do teclado com validação básica
 * @return string Email lido
 */
string ControladoraProjeto::lerEmail() {
    string email;
    do {
        cout << "Email do Scrum Master: ";
        getline(cin, email);
        
        if (email.find('@') == string::npos) {
            cout << "Email deve conter '@'" << endl;
        } else if (email.find('@') == 0 || email.find('@') == email.length() - 1) {
            cout << "'@' nao pode estar no inicio ou fim" << endl;
        } else if (email.find(' ') != string::npos) {
            cout << "Email nao pode conter espacos!" << endl;
        } else {
            break;
        }
    } while (true);
    return email;
}



string ControladoraProjeto::lerCodigo(const string& mensagem) {
    string codigo;
    do {
        cout << mensagem;
        getline(cin, codigo);
        if (!validarFormatoCodigo(codigo)) {
            cout << "Codigo invalido! Deve ter 2 letras maiusculas + 3 digitos (ex: AB123)" << endl;
        } else {
            break;
        }
    } while (true);
    return codigo;
}

string ControladoraProjeto::lerNome() {
    string nome;
    do {
        cout << "Nome (max 10 caracteres): ";
        getline(cin, nome);
        if (nome.empty() || nome.length() > 10) {
            cout << "Nome deve ter entre 1 e 10 caracteres!" << endl;
        } else if (nome[0] == ' ' || nome.back() == ' ') {
            cout << "Nome nao pode comecar ou terminar com espaco!" << endl;
        } else {
            bool valido = true;
            for (char c : nome) {
                if (!isalnum(c) && c != ' ') {
                    valido = false;
                    break;
                }
            }
            if (!valido) {
                cout << "Nome deve conter apenas letras, digitos e espacos!" << endl;
            } else {
                break;
            }
        }
    } while (true);
    return nome;
}

string ControladoraProjeto::lerData(const string& mensagem) {
    string data;
    do {
        cout << mensagem << " (DD/MM/AAAA): ";
        getline(cin, data);
        if (data.length() != 10 || data[2] != '/' || data[5] != '/') {
            cout << "Formato invalido! Use DD/MM/AAAA" << endl;
        } else {
            break;
        }
    } while (true);
    return data;
}

void ControladoraProjeto::executarMenu() {
    int opcao;
    do {
        cout << "\n==================================" << endl;
    cout << "         MENU PROJETO" << endl;
    cout << "==================================" << endl;
    cout << "1 - Criar Projeto" << endl;
    cout << "2 - Listar Projetos" << endl;
    cout << "3 - Consultar Projeto" << endl;
    cout << "4 - Atualizar Projeto" << endl;
    cout << "5 - Excluir Projeto" << endl;
    cout << "0 - Voltar" << endl;
    cout << "==================================" << endl;
    cout << "Opcao: ";

        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: criarProjetoFlow(); break;
            case 2: listarProjetosFlow(); break;
            case 3: consultarProjetoFlow(); break;
            case 4: atualizarProjetoFlow(); break;
            case 5: excluirProjetoFlow(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida!" << endl;
        }

        if (opcao != 0) pausar();
    } while (opcao != 0);
}

void ControladoraProjeto::criarProjetoFlow() {
    cout << "\n=== CRIAR PROJETO ===" << endl;
    string codigo = lerCodigo("Codigo do projeto: ");
    string nome = lerNome();
    string dataInicio = lerData("Data de inicio");
    string dataTermino = lerData("Data de termino");
    string emailScrumMaster = lerEmail();

    try {
        servico->criarProjeto(codigo, nome, dataInicio, dataTermino, emailScrumMaster);
    } catch (const exception& e) {
         cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraProjeto::listarProjetosFlow() {
    cout << "\n=== LISTAR PROJETOS ===" << endl;
    try {
        servico->listarProjetos();
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraProjeto::consultarProjetoFlow() {
    cout << "\n=== CONSULTAR PROJETO ===" << endl;
    string codigo = lerCodigo("Codigo do projeto: ");

    try {
        servico->consultarProjeto(codigo);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraProjeto::atualizarProjetoFlow() {
    cout << "\n=== ATUALIZAR PROJETO ===" << endl;
    string codigo = lerCodigo("Codigo do projeto: ");
    string novoNome = lerNome();

    try {
        servico->atualizarProjeto(codigo, novoNome);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraProjeto::excluirProjetoFlow() {
    cout << "\n=== EXCLUIR PROJETO ===" << endl;
    string codigo = lerCodigo("Codigo do projeto: ");

    char confirm;
    cout << "Tem certeza? (S/N): ";
    cin >> confirm;
    limparBuffer();

    if (toupper(confirm) == 'S') {
        try {
            servico->excluirProjeto(codigo);
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
        }
    } else {
        cout << "Operacao cancelada." << endl;
    }
}



















// ============================================
// IMPLEMENTAÇÃO: CONTROLADORA HISTORIA USUARIO
// ============================================

ControladoraHistoriaUsuario::ControladoraHistoriaUsuario(IServicoHistoriaUsuario* s) : servico(s) {
    if (servico == nullptr) {
        throw invalid_argument("Servico de historia nao pode ser nulo");
    }
}

string ControladoraHistoriaUsuario::lerCodigo(const string& mensagem) {
    string codigo;
    do {
        cout << mensagem;
        getline(cin, codigo);
        if (!validarFormatoCodigo(codigo)) {
            cout << "Codigo invalido! Deve ter 2 letras maiusculas + 3 digitos (ex: AB123)" << endl;
        } else {
            break;
        }
    } while (true);
    return codigo;
}

string ControladoraHistoriaUsuario::lerNome() {
    string nome;
    do {
        cout << "Nome (max 10 caracteres): ";
        getline(cin, nome);
        if (nome.empty() || nome.length() > 10) {
            cout << "Nome deve ter entre 1 e 10 caracteres!" << endl;
        } else if (nome[0] == ' ' || nome.back() == ' ') {
            cout << "Nome nao pode comecar ou terminar com espaco!" << endl;
        } else {
            bool valido = true;
            char ant = ' ';
            for (char c : nome) {
                if (!isalnum(c) && c != ' ') {
                    valido = false;
                    break;
                }
                if (ant == ' ' && c == ' ') {
                    valido = false;
                    break;
                }
                ant = c;
            }
            if (!valido) {
                cout << "Nome invalido! Use apenas letras, digitos e espacos (sem espacos duplos)" << endl;
            } else {
                break;
            }
        }
    } while (true);
    return nome;
}

string ControladoraHistoriaUsuario::lerDescricao() {
    string descricao;
    do {
        cout << "Descricao (max 40 caracteres): ";
        getline(cin, descricao);
        if (descricao.empty() || descricao.length() > 40) {
            cout << "Descricao deve ter entre 1 e 40 caracteres!" << endl;
        } else if (descricao[0] == ',' || descricao[0] == '.' || descricao[0] == ' ') {
            cout << "Descricao nao pode comecar com virgula, ponto ou espaco!" << endl;
        } else if (descricao.back() == ',' || descricao.back() == '.' || descricao.back() == ' ') {
            cout << "Descricao nao pode terminar com virgula, ponto ou espaco!" << endl;
        } else {
            break;
        }
    } while (true);
    return descricao;
}

string ControladoraHistoriaUsuario::lerPrioridade() {
    string prioridade;
    do {
        cout << "Prioridade (ALTA, MEDIA, BAIXA): ";
        getline(cin, prioridade);
        if (prioridade == "ALTA" || prioridade == "MEDIA" || prioridade == "BAIXA") {
            break;
        }
        cout << "Prioridade invalida! Opcoes: ALTA, MEDIA, BAIXA" << endl;
    } while (true);
    return prioridade;
}

string ControladoraHistoriaUsuario::lerEstado() {
    string estado;
    do {
        cout << "Novo estado (A FAZER, FAZENDO, FEITO): ";
        getline(cin, estado);
        if (estado == "A FAZER" || estado == "FAZENDO" || estado == "FEITO") {
            break;
        }
        cout << "Estado invalido! Opcoes: A FAZER, FAZENDO, FEITO" << endl;
    } while (true);
    return estado;
}

int ControladoraHistoriaUsuario::lerEstimativa() {
    int est;
    string entrada;
    do {
        cout << "Estimativa (1 a 365 dias): ";
        getline(cin, entrada);
        try {
            est = stoi(entrada);
            if (est >= 1 && est <= 365) {
                break;
            }
            cout << "Estimativa deve estar entre 1 e 365!" << endl;
        } catch (...) {
            cout << "Digite um numero valido!" << endl;
        }
    } while (true);
    return est;
}

string ControladoraHistoriaUsuario::lerCodigoPessoa() {
    return lerCodigo("Codigo do responsavel: ");
}

void ControladoraHistoriaUsuario::executarMenu() {
    int opcao;
    do {
    cout << "\n=========================================" << endl;
    cout << "      MENU HISTORIA DE USUARIO" << endl;
    cout << "=========================================" << endl;
    cout << "1 - Criar Historia" << endl;
    cout << "2 - Listar Historias" << endl;
    cout << "3 - Consultar Historia" << endl;
    cout << "4 - Alterar Estado" << endl;
    cout << "5 - Atualizar Historia" << endl;
    cout << "6 - Excluir Historia" << endl;
    cout << "7 - Atribuir Responsavel" << endl;
    cout << "8 - Remover Responsavel" << endl;
    cout << "9 - Listar por Projeto" << endl;
    cout << "0 - Voltar" << endl;
    cout << "=========================================" << endl;
    cout << "Opcao: ";

        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: criarHistoriaFlow(); break;
            case 2: listarHistoriasFlow(); break;
            case 3: consultarHistoriaFlow(); break;
            case 4: alterarEstadoFlow(); break;
            case 5: atualizarHistoriaFlow(); break;
            case 6: excluirHistoriaFlow(); break;
            case 7: atribuirResponsavelFlow(); break;
            case 8: removerResponsavelFlow(); break;
            case 9: listarPorProjetoFlow(); break;
            case 0: cout << "Voltando..." << endl; break;
            default: cout << "Opcao invalida!" << endl;
        }

        if (opcao != 0) pausar();
    } while (opcao != 0);
}

void ControladoraHistoriaUsuario::criarHistoriaFlow() {
    cout << "\n=== CRIAR HISTORIA USUARIO ===" << endl;
    string codigo = lerCodigo("Codigo da historia: ");
    string nome = lerNome();
    string descricao = lerDescricao();
    string prioridade = lerPrioridade();
    string codigoProjeto = lerCodigo("Codigo do projeto: ");
    int estimativa = lerEstimativa();

    try {
        servico->criarHistoria(codigo, nome, descricao, prioridade, codigoProjeto, estimativa);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::listarHistoriasFlow() {
    cout << "\n=== LISTAR HISTORIAS ===" << endl;
    try {
        servico->listarHistorias();
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::consultarHistoriaFlow() {
    cout << "\n=== CONSULTAR HISTORIA ===" << endl;
    string codigo = lerCodigo("Codigo da historia: ");

    try {
        servico->consultarHistoria(codigo);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::alterarEstadoFlow() {
    cout << "\n=== ALTERAR ESTADO ===" << endl;
    string codigo = lerCodigo("Codigo da historia: ");
    string novoEstado = lerEstado();

    try {
        servico->alterarEstado(codigo, novoEstado);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::atualizarHistoriaFlow() {
    cout << "\n=== ATUALIZAR HISTORIA ===" << endl;
    string codigo = lerCodigo("Codigo da historia: ");
    string nome = lerNome();
    string descricao = lerDescricao();
    string prioridade = lerPrioridade();
    int estimativa = lerEstimativa();

    try {
        servico->atualizarHistoria(codigo, nome, descricao, prioridade, estimativa);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::excluirHistoriaFlow() {
    cout << "\n=== EXCLUIR HISTORIA ===" << endl;
    string codigo = lerCodigo("Codigo da historia: ");

    char confirm;
    cout << "Tem certeza? (S/N): ";
    cin >> confirm;
    limparBuffer();

    if (toupper(confirm) == 'S') {
        try {
            servico->excluirHistoria(codigo);
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
        }
    } else {
        cout << "Operacao cancelada." << endl;
    }
}

void ControladoraHistoriaUsuario::atribuirResponsavelFlow() {
    cout << "\n=== ATRIBUIR RESPONSAVEL ===" << endl;
    string codigoHistoria = lerCodigo("Codigo da historia: ");
    string codigoPessoa = lerCodigoPessoa();

    try {
        servico->atribuirResponsavel(codigoHistoria, codigoPessoa);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::removerResponsavelFlow() {
    cout << "\n=== REMOVER RESPONSAVEL ===" << endl;
    string codigoHistoria = lerCodigo("Codigo da historia: ");

    try {
        servico->removerResponsavel(codigoHistoria);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ControladoraHistoriaUsuario::listarPorProjetoFlow() {
    cout << "\n=== LISTAR HISTORIAS POR PROJETO ===" << endl;
    string codigoProjeto = lerCodigo("Codigo do projeto: ");

    try {
        servico->listarHistoriasPorProjeto(codigoProjeto);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}









// ============================================
// IMPLEMENTAÇÃO: MENU PRINCIPAL
// ============================================

MenuPrincipal::MenuPrincipal(IServicoPessoa* sp,
                             IServicoProjeto* spr,
                             IServicoPlanoSprint* splan,
                             IServicoHistoriaUsuario* shist)
    : ctrlPessoa(sp), ctrlProjeto(spr),
      ctrlPlanoSprint(splan), ctrlHistoria(shist) {}

void MenuPrincipal::executar() {
    int opcao;
    do {
    cout << "\n========================================" << endl;
    cout << "        SISTEMA SCRUM - MENU PRINCIPAL  " << endl;
    cout << "========================================" << endl;
    cout << "1 - Gerenciar Pessoas" << endl;
    cout << "2 - Gerenciar Projetos" << endl;
    cout << "3 - Gerenciar Planos de Sprint" << endl;
    cout << "4 - Gerenciar Historias de Usuario" << endl;
    cout << "0 - Sair" << endl;
    cout << "========================================" << endl;
    cout << "Opcao: ";

        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: ctrlPessoa.executarMenu(); break;
            case 2: ctrlProjeto.executarMenu(); break;
            case 3: ctrlPlanoSprint.executarMenu(); break;
            case 4: ctrlHistoria.executarMenu(); break;
            case 0: cout << "Saindo..." << endl; break;
            default: cout << "Opcao invalida!" << endl;
        }

        if (opcao != 0) pausar();
    } while (opcao != 0);
}