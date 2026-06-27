/**
 * @file Apresentacao.hpp
 * @brief Controladoras de apresentação (interface com o usuário)
 * 
 * @details Este arquivo contém as classes responsáveis por interagir
 *          com o usuário via console (cin/cout), validar entradas de
 *          forma simples e chamar os serviços apropriados.
 * 
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
/**
 * @brief Limpa a tela do console.
 */
void limparTela();

/**
 * @brief Limpa o buffer de entrada padrão.
 */
void limparBuffer();

/**
 * @brief Pausa a execução até o usuário pressionar Enter.
 */
void pausar();

/**
 * @brief Valida se uma string segue o formato de código do sistema.
 * @param codigo Código a ser validado.
 * @return true se o código for válido; false caso contrário.
 */
bool validarFormatoCodigo(const string& codigo);

// ============================================
// CONTROLADORA PARA PESSOA
// ============================================

/**
 * @brief Controladora de apresentação para entidade Pessoa.
 *
 * @details Responsável por exibir o menu de pessoas, ler dados digitados
 *          pelo usuário e acionar os serviços de criação, consulta,
 *          atualização e exclusão de pessoas.
 */
class ControladoraPessoa {
private:
    IServicoPessoa* servico;

    string lerEmail();
    string lerNome();
    string lerSenha();
    string lerPapel();

public:
    /**
     * @brief Inicializa a controladora com o serviço de pessoa.
     * @param s Ponteiro para a interface de serviço de pessoa.
     */
    ControladoraPessoa(IServicoPessoa* s);


    /**
     * @brief Exibe e executa o menu de gerenciamento de pessoas.
     */
    void executarMenu();


    /**
     * @brief Fluxo de criação de pessoa.
     */
    void criarPessoaFlow();

    /**
     * @brief Fluxo de consulta de pessoa.
     */
    void consultarPessoaFlow();

    /**
     * @brief Fluxo de atualização de pessoa.
     */
    void atualizarPessoaFlow();

    /**
     * @brief Fluxo de exclusão de pessoa.
     */
    void excluirPessoaFlow();
};

// ============================================
// CONTROLADORA PARA PROJETO
// ============================================
/**
 * @brief Controladora de apresentação para entidade Projeto.
 *
 * @details Responsável por exibir o menu de gerenciamento de projetos,
 *          ler os dados informados pelo usuário e solicitar ao serviço
 *          correspondente as operações sobre projetos.
 */
class ControladoraProjeto {
private:
    IServicoProjeto* servico;

    string lerCodigo(const string& mensagem);
    string lerNome();
    string lerData(const string& mensagem);
    string lerEmail();

public:
    /**
     * @brief Inicializa a controladora com o serviço de projeto.
     * @param s Ponteiro para o serviço de projeto.
     */
    ControladoraProjeto(IServicoProjeto* s);

    /**
     * @brief Exibe e executa o menu de gerenciamento de projetos.
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de projeto.
     */
    void criarProjetoFlow();

    /**
     * @brief Lista todos os projetos cadastrados.
     */
    void listarProjetosFlow();

    /**
     * @brief Consulta um projeto pelo código.
     */
    void consultarProjetoFlow();

    /**
     * @brief Fluxo de atualização de um projeto.
     */
    void atualizarProjetoFlow();

    /**
     * @brief Fluxo de exclusão de um projeto.
     */
    void excluirProjetoFlow();

    /**
     * @brief Lista os projetos associados a uma pessoa.
     */
    void listarProjetosPorPessoaFlow();
};

// ============================================
// CONTROLADORA PARA PLANO DE SPRINT
// ============================================
/**
 * @brief Controladora de apresentação para entidade PlanoSprint.
 *
 * @details Responsável por exibir o menu de gerenciamento de planos de
 *          sprint, ler os dados informados pelo usuário e solicitar ao
 *          serviço correspondente as operações sobre planos de sprint.
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
    /**
     * @brief Inicializa a controladora com o serviço de plano de sprint.
     * @param s Ponteiro para o serviço de plano de sprint.
     */
    ControladoraPlanoSprint(IServicoPlanoSprint* s);

    /**
     * @brief Exibe e executa o menu de gerenciamento de planos de sprint.
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de um plano de sprint.
     */
    void criarPlanoSprintFlow();

    /**
     * @brief Lista todos os planos de sprint cadastrados.
     */
    void listarPlanosFlow();

    /**
     * @brief Consulta um plano de sprint pelo código.
     */
    void consultarPlanoFlow();

    /**
     * @brief Fluxo de atualização da capacidade de um plano de sprint.
     */
    void atualizarCapacidadeFlow();

    /**
     * @brief Fluxo de exclusão de um plano de sprint.
     */
    void excluirPlanoFlow();

    /**
     * @brief Associa uma história de usuário a um plano de sprint.
     */
    void associarHistoriaFlow();

    /**
     * @brief Remove uma história de usuário de um plano de sprint.
     */
    void desassociarHistoriaFlow();

    /**
     * @brief Lista as histórias associadas a um plano de sprint.
     */
    void listarHistoriasFlow();

    /**
     * @brief Lista os planos de sprint associados a um projeto.
     */
    void listarPlanosPorProjetoFlow();
};

// ============================================
// CONTROLADORA PARA HISTÓRIA DE USUÁRIO
// ============================================
/**
 * @brief Controladora de apresentação para entidade HistoriaUsuario.
 *
 * @details Responsável por exibir o menu de gerenciamento de histórias de
 *          usuário, ler os dados informados pelo usuário e solicitar ao
 *          serviço correspondente as operações sobre histórias de usuário.
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
    string lerEmailPessoa();

public:
    /**
     * @brief Inicializa a controladora com o serviço de história de usuário.
     * @param s Ponteiro para o serviço de história de usuário.
     */
    ControladoraHistoriaUsuario(IServicoHistoriaUsuario* s);

    /**
     * @brief Exibe e executa o menu de gerenciamento de histórias de usuário.
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de uma história de usuário.
     */
    void criarHistoriaFlow();

    /**
     * @brief Lista todas as histórias de usuário cadastradas.
     */
    void listarHistoriasFlow();

    /**
     * @brief Consulta uma história de usuário pelo código.
     */
    void consultarHistoriaFlow();

    /**
     * @brief Fluxo de alteração do estado de uma história de usuário.
     */
    void alterarEstadoFlow();

    /**
     * @brief Fluxo de atualização dos dados de uma história de usuário.
     */
    void atualizarHistoriaFlow();

    /**
     * @brief Fluxo de exclusão de uma história de usuário.
     */
    void excluirHistoriaFlow();

    /**
     * @brief Atribui um responsável a uma história de usuário.
     */
    void atribuirResponsavelFlow();

    /**
     * @brief Remove o responsável de uma história de usuário.
     */
    void removerResponsavelFlow();

    /**
     * @brief Lista as histórias de usuário pertencentes a um projeto.
     */
    void listarPorProjetoFlow();

    /**
     * @brief Lista as histórias de usuário atribuídas a uma pessoa.
     */
    void listarPorPessoaFlow();
};

// ============================================
// MENU PRINCIPAL
// ============================================

/**
 * @brief Menu principal do sistema.
 *
 * @details Responsável por apresentar o menu principal após a autenticação
 *          do usuário e direcionar a navegação para as controladoras de
 *          Pessoa, Projeto, Plano de Sprint e História de Usuário.
 */
class MenuPrincipal {
private:
    ControladoraPessoa ctrlPessoa;
    ControladoraProjeto ctrlProjeto;
    ControladoraPlanoSprint ctrlPlanoSprint;
    ControladoraHistoriaUsuario ctrlHistoria;

public:
    /**
     * @brief Inicializa o menu principal com os serviços do sistema.
     *
     * @param sp Ponteiro para o serviço de Pessoa.
     * @param spr Ponteiro para o serviço de Projeto.
     * @param splan Ponteiro para o serviço de Plano de Sprint.
     * @param shist Ponteiro para o serviço de História de Usuário.
     */
    MenuPrincipal(IServicoPessoa* sp,
                  IServicoProjeto* spr,
                  IServicoPlanoSprint* splan,
                  IServicoHistoriaUsuario* shist);

    /**
     * @brief Exibe e executa o menu principal do sistema.
     *
     * @details Permite ao usuário autenticado acessar os menus de
     *          gerenciamento das entidades disponíveis, respeitando
     *          as permissões associadas ao seu papel.
     */
    void executar();
};

#endif // APRESENTACAO_HPP_INCLUDED