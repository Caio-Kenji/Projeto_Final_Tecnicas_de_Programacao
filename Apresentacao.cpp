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
            cout << "✗ Codigo invalido! Deve ter 2 letras maiusculas + 3 digitos (ex: AB123)" << endl;
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
            cout << "✗ Formato invalido! Use DD/MM/AAAA" << endl;
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
            cout << "✗ Capacidade deve estar entre 1 e 365!" << endl;
        } catch (...) {
            cout << "✗ Digite um numero valido!" << endl;
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
            cout << "✗ Estimativa deve estar entre 1 e 365!" << endl;
        } catch (...) {
            cout << "✗ Digite um numero valido!" << endl;
        }
    } while (true);
    return est;
}

void ControladoraPlanoSprint::executarMenu() {
    int opcao;
    do {
        cout << "\n╔════════════════════════════════════╗" << endl;
        cout << "║       MENU PLANO DE SPRINT         ║" << endl;
        cout << "╠════════════════════════════════════╣" << endl;
        cout << "║ 1 - Criar Sprint                   ║" << endl;
        cout << "║ 2 - Listar Sprints                 ║" << endl;
        cout << "║ 3 - Consultar Sprint               ║" << endl;
        cout << "║ 4 - Atualizar Capacidade           ║" << endl;
        cout << "║ 5 - Excluir Sprint                 ║" << endl;
        cout << "║ 6 - Associar Historia ao Sprint    ║" << endl;
        cout << "║ 7 - Remover Historia do Sprint     ║" << endl;
        cout << "║ 8 - Listar Historias do Sprint     ║" << endl;
        cout << "║ 0 - Voltar                         ║" << endl;
        cout << "╚════════════════════════════════════╝" << endl;
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
            default: cout << "✗ Opcao invalida!" << endl;
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
        cout << "✗ Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::listarPlanosFlow() {
    cout << "\n=== LISTAR PLANOS DE SPRINT ===" << endl;
    try {
        servico->listarPlanosSprint();
    } catch (const exception& e) {
        cout << "✗ Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::consultarPlanoFlow() {
    cout << "\n=== CONSULTAR PLANO DE SPRINT ===" << endl;
    string codigo = lerCodigo("Codigo do sprint: ");
    
    try {
        servico->consultarPlanoSprint(codigo);
    } catch (const exception& e) {
        cout << "✗ Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::atualizarCapacidadeFlow() {
    cout << "\n=== ATUALIZAR CAPACIDADE DO SPRINT ===" << endl;
    string codigo = lerCodigo("Codigo do sprint: ");
    int novaCapacidade = lerCapacidade();
    
    try {
        servico->atualizarCapacidade(codigo, novaCapacidade);
    } catch (const exception& e) {
        cout << "✗ Erro: " << e.what() << endl;
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
            cout << "✗ Erro: " << e.what() << endl;
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
        cout << "✗ Erro: " << e.what() << endl;
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
        cout << "✗ Erro: " << e.what() << endl;
    }
}

void ControladoraPlanoSprint::listarHistoriasFlow() {
    cout << "\n=== LISTAR HISTORIAS DO SPRINT ===" << endl;
    string codigoSprint = lerCodigo("Codigo do sprint: ");
    
    try {
        servico->listarHistoriasDoSprint(codigoSprint);
    } catch (const exception& e) {
        cout << "✗ Erro: " << e.what() << endl;
    }
}



