/**
 * @file Apresentacao.hpp
 * @brief Controladoras de apresentação (interface com o usuário)
 * 
 * @details Este arquivo contém as classes responsáveis por interagir
 *          com o usuário via console (cin/cout), validar entradas de
 *          forma simples e chamar os serviços apropriados.
 * 
 * @author Seu Nome
 * @date 2024
 */

#ifndef APRESENTACAO_HPP_INCLUDED
#define APRESENTACAO_HPP_INCLUDED

#include "Interfaces.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>

using namespace std;

// ============================================
// PROTÓTIPOS DAS FUNÇÕES AUXILIARES
// ============================================

void limparBuffer();
void pausar();
bool validarFormatoCodigo(const string& codigo);

// ============================================
// CONTROLADORA PARA PESSOA
// ============================================

/**
 * @brief Controladora de apresentação para entidade Pessoa.
 */
class ControladoraPessoa {
private:
    IServicoPessoa* servico;

    string lerEmail();
    string lerNome();
    string lerSenha();
    string lerPapel();

public:
    ControladoraPessoa(IServicoPessoa* s);

    void executarMenu();
    void criarPessoaFlow();
    void consultarPessoaFlow();
    void atualizarPessoaFlow();
    void excluirPessoaFlow();
};

// ============================================
// CONTROLADORA PARA PROJETO
// ============================================

/**
 * @brief Controladora de apresentação para entidade Projeto.
 */
class ControladoraProjeto {
private:
    IServicoProjeto* servico;

    string lerCodigo(const string& mensagem);
    string lerNome();
    string lerData(const string& mensagem);
    string lerEmail();

public:
    ControladoraProjeto(IServicoProjeto* s);

    void executarMenu();
    void criarProjetoFlow();
    void listarProjetosFlow();
    void consultarProjetoFlow();
    void atualizarProjetoFlow();
    void excluirProjetoFlow();
};

// ============================================
// CONTROLADORA PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Controladora de apresentação para entidade PlanoSprint.
 */
class ControladoraPlanoSprint {
private:
    IServicoPlanoSprint* servico;

    bool validarFormatoCodigo(const string& codigo);
    bool validarFormatoData(const string& data);
    string lerCodigo(const string& mensagem);
    string lerData(const string& mensagem);
    int lerCapacidade();
    int lerEstimativa();

public:
    ControladoraPlanoSprint(IServicoPlanoSprint* s);

    void executarMenu();
    void criarPlanoSprintFlow();
    void listarPlanosFlow();
    void consultarPlanoFlow();
    void atualizarCapacidadeFlow();
    void excluirPlanoFlow();
    void associarHistoriaFlow();
    void desassociarHistoriaFlow();
    void listarHistoriasFlow();
};

// ============================================
// CONTROLADORA PARA HISTÓRIA DE USUÁRIO
// ============================================

/**
 * @brief Controladora de apresentação para entidade HistoriaUsuario.
 */
class ControladoraHistoriaUsuario {
private:
    IServicoHistoriaUsuario* servico;

    string lerCodigo(const string& mensagem);
    string lerNome();
    string lerDescricao();
    string lerPrioridade();
    string lerEstado();
    int lerEstimativa();
    string lerCodigoPessoa();

public:
    ControladoraHistoriaUsuario(IServicoHistoriaUsuario* s);

    void executarMenu();
    void criarHistoriaFlow();
    void listarHistoriasFlow();
    void consultarHistoriaFlow();
    void alterarEstadoFlow();
    void atualizarHistoriaFlow();
    void excluirHistoriaFlow();
    void atribuirResponsavelFlow();
    void removerResponsavelFlow();
    void listarPorProjetoFlow();
};

// ============================================
// MENU PRINCIPAL
// ============================================

/**
 * @brief Menu principal do sistema.
 */
class MenuPrincipal {
private:
    ControladoraPessoa ctrlPessoa;
    ControladoraProjeto ctrlProjeto;
    ControladoraPlanoSprint ctrlPlanoSprint;
    ControladoraHistoriaUsuario ctrlHistoria;

public:
    MenuPrincipal(IServicoPessoa* sp,
                  IServicoProjeto* spr,
                  IServicoPlanoSprint* splan,
                  IServicoHistoriaUsuario* shist);

    void executar();
};

#endif // APRESENTACAO_HPP_INCLUDED