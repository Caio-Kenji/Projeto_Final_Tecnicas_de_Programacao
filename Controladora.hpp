/**
 * @file Controladoras.hpp
 * @brief Controladoras da camada de apresentação
 * 
 * @details Este arquivo contém todas as classes controladoras responsáveis
 *          pela interface com o usuário, seguindo o padrão MVC.
 *          Cada controladora gerencia uma entidade do sistema.
 * 
 * @author Seu Nome
 * @date 2024
 */

#ifndef CONTROLADORAS_HPP_INCLUDED
#define CONTROLADORAS_HPP_INCLUDED

#include "Interfaces.hpp"
#include "Dominio.hpp"
#include "Entidade.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// ============================================
// UTILITÁRIOS AUXILIARES
// ============================================

/**
 * @brief Limpa o buffer de entrada do teclado
 */
void limparBuffer();

/**
 * @brief Pausa a execução até o usuário pressionar Enter
 */
void pausar();

/**
 * @brief Valida o formato de um código (2 letras + 3 dígitos)
 * @param codigo String a ser validada
 * @return true se o formato for válido
 */
bool validarFormatoCodigo(const string& codigo);

/**
 * @brief Valida o formato de uma data (DD/MM/AAAA)
 * @param data String a ser validada
 * @return true se o formato for válido
 */
bool validarFormatoData(const string& data);

/**
 * @brief Lê uma string do teclado com validação de não vazio
 * @param mensagem Mensagem a ser exibida
 * @return string lida
 */
string lerStringNaoVazia(const string& mensagem);

/**
 * @brief Lê um inteiro do teclado com validação de intervalo
 * @param mensagem Mensagem a ser exibida
 * @param min Valor mínimo
 * @param max Valor máximo
 * @return int lido
 */
int lerInteiro(const string& mensagem, int min, int max);

// ============================================
// CONTROLADORA DE AUTENTICAÇÃO
// ============================================

/**
 * @brief Controladora de apresentação para autenticação
 * 
 * @details Responsável por autenticar usuários no sistema.
 *          Gerencia o login e a sessão do usuário.
 */
class ControladoraAutenticacao {
private:
    IServicoPessoa* servicoPessoa;
    Email* emailUsuario;

public:
    /**
     * @brief Construtor da controladora de autenticação
     * @param servico Ponteiro para o serviço de pessoa
     */
    ControladoraAutenticacao(IServicoPessoa* servico);

    /**
     * @brief Executa o fluxo de autenticação
     * @return true se o usuário foi autenticado com sucesso
     */
    bool executar();

    /**
     * @brief Retorna o email do usuário autenticado
     * @return Email* Ponteiro para o email do usuário
     */
    Email* getEmailUsuario() const;

private:
    /**
     * @brief Tenta autenticar o usuário com email e senha
     * @param email Email informado
     * @param senha Senha informada
     * @return true se a autenticação for bem-sucedida
     */
    bool autenticar(const string& email, const string& senha);
};

// ============================================
// CONTROLADORA DE PESSOA
// ============================================

/**
 * @brief Controladora de apresentação para entidade Pessoa
 * 
 * @details Gerencia as operações de CRUD para pessoas,
 *          incluindo criação, consulta, atualização e exclusão.
 */
class ControladoraPessoa {
private:
    IServicoPessoa* servico;

    /**
     * @brief Lê um email do teclado com validação básica
     * @return string Email lido
     */
    string lerEmail();

    /**
     * @brief Lê um nome do teclado com validação
     * @return string Nome lido
     */
    string lerNome();

    /**
     * @brief Lê uma senha do teclado com validação
     * @return string Senha lida
     */
    string lerSenha();

    /**
     * @brief Lê um papel do teclado com validação
     * @return string Papel lido
     */
    string lerPapel();

public:
    /**
     * @brief Construtor da controladora de pessoa
     * @param s Ponteiro para o serviço de pessoa
     */
    ControladoraPessoa(IServicoPessoa* s);

    /**
     * @brief Executa o menu principal de pessoa
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de pessoa
     */
    void criarPessoaFlow();

    /**
     * @brief Fluxo de consulta de pessoa
     */
    void consultarPessoaFlow();

    /**
     * @brief Fluxo de atualização de pessoa
     */
    void atualizarPessoaFlow();

    /**
     * @brief Fluxo de exclusão de pessoa
     */
    void excluirPessoaFlow();
};

// ============================================
// CONTROLADORA DE PROJETO
// ============================================

/**
 * @brief Controladora de apresentação para entidade Projeto
 * 
 * @details Gerencia as operações de CRUD para projetos.
 */
class ControladoraProjeto {
private:
    IServicoProjeto* servico;

    /**
     * @brief Lê um código do teclado com validação de formato
     * @param mensagem Mensagem a ser exibida
     * @return string Código lido
     */
    string lerCodigo(const string& mensagem);

    /**
     * @brief Lê um nome do teclado com validação
     * @return string Nome lido
     */
    string lerNome();

    /**
     * @brief Lê uma data do teclado com validação de formato
     * @param mensagem Mensagem a ser exibida
     * @return string Data lida
     */
    string lerData(const string& mensagem);

public:
    /**
     * @brief Construtor da controladora de projeto
     * @param s Ponteiro para o serviço de projeto
     */
    ControladoraProjeto(IServicoProjeto* s);

    /**
     * @brief Executa o menu principal de projeto
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de projeto
     */
    void criarProjetoFlow();

    /**
     * @brief Fluxo de listagem de projetos
     */
    void listarProjetosFlow();

    /**
     * @brief Fluxo de consulta de projeto
     */
    void consultarProjetoFlow();

    /**
     * @brief Fluxo de atualização de projeto
     */
    void atualizarProjetoFlow();

    /**
     * @brief Fluxo de exclusão de projeto
     */
    void excluirProjetoFlow();
};

// ============================================
// CONTROLADORA DE PLANO DE SPRINT
// ============================================

/**
 * @brief Controladora de apresentação para entidade PlanoSprint
 * 
 * @details Gerencia as operações de CRUD para planos de sprint,
 *          incluindo associação e desassociação de histórias.
 */
class ControladoraPlanoSprint {
private:
    IServicoPlanoSprint* servico;

    /**
     * @brief Lê um código do teclado com validação de formato
     * @param mensagem Mensagem a ser exibida
     * @return string Código lido
     */
    string lerCodigo(const string& mensagem);

    /**
     * @brief Lê uma data do teclado com validação de formato
     * @param mensagem Mensagem a ser exibida
     * @return string Data lida
     */
    string lerData(const string& mensagem);

    /**
     * @brief Lê uma capacidade do teclado com validação
     * @return int Capacidade lida
     */
    int lerCapacidade();

    /**
     * @brief Lê uma estimativa do teclado com validação
     * @return int Estimativa lida
     */
    int lerEstimativa();

public:
    /**
     * @brief Construtor da controladora de plano de sprint
     * @param s Ponteiro para o serviço de plano de sprint
     */
    ControladoraPlanoSprint(IServicoPlanoSprint* s);

    /**
     * @brief Executa o menu principal de plano de sprint
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de plano de sprint
     */
    void criarPlanoSprintFlow();

    /**
     * @brief Fluxo de listagem de planos de sprint
     */
    void listarPlanosFlow();

    /**
     * @brief Fluxo de consulta de plano de sprint
     */
    void consultarPlanoFlow();

    /**
     * @brief Fluxo de atualização de capacidade
     */
    void atualizarCapacidadeFlow();

    /**
     * @brief Fluxo de exclusão de plano de sprint
     */
    void excluirPlanoFlow();

    /**
     * @brief Fluxo de associação de história a sprint
     */
    void associarHistoriaFlow();

    /**
     * @brief Fluxo de desassociação de história do sprint
     */
    void desassociarHistoriaFlow();

    /**
     * @brief Fluxo de listagem de histórias do sprint
     */
    void listarHistoriasFlow();
};

// ============================================
// CONTROLADORA DE HISTÓRIA DE USUÁRIO
// ============================================

/**
 * @brief Controladora de apresentação para entidade HistoriaUsuario
 * 
 * @details Gerencia as operações de CRUD para histórias de usuário,
 *          incluindo alteração de estado e atribuição de responsável.
 */
class ControladoraHistoriaUsuario {
private:
    IServicoHistoriaUsuario* servico;

    /**
     * @brief Lê um código do teclado com validação de formato
     * @param mensagem Mensagem a ser exibida
     * @return string Código lido
     */
    string lerCodigo(const string& mensagem);

    /**
     * @brief Lê um nome do teclado com validação
     * @return string Nome lido
     */
    string lerNome();

    /**
     * @brief Lê uma descrição do teclado com validação
     * @return string Descrição lida
     */
    string lerDescricao();

    /**
     * @brief Lê uma prioridade do teclado com validação
     * @return string Prioridade lida
     */
    string lerPrioridade();

    /**
     * @brief Lê um estado do teclado com validação
     * @return string Estado lido
     */
    string lerEstado();

    /**
     * @brief Lê uma estimativa do teclado com validação
     * @return int Estimativa lida
     */
    int lerEstimativa();

public:
    /**
     * @brief Construtor da controladora de história de usuário
     * @param s Ponteiro para o serviço de história de usuário
     */
    ControladoraHistoriaUsuario(IServicoHistoriaUsuario* s);

    /**
     * @brief Executa o menu principal de história de usuário
     */
    void executarMenu();

    /**
     * @brief Fluxo de criação de história
     */
    void criarHistoriaFlow();

    /**
     * @brief Fluxo de listagem de histórias
     */
    void listarHistoriasFlow();

    /**
     * @brief Fluxo de consulta de história
     */
    void consultarHistoriaFlow();

    /**
     * @brief Fluxo de alteração de estado
     */
    void alterarEstadoFlow();

    /**
     * @brief Fluxo de atualização de história
     */
    void atualizarHistoriaFlow();

    /**
     * @brief Fluxo de exclusão de história
     */
    void excluirHistoriaFlow();

    /**
     * @brief Fluxo de atribuição de responsável
     */
    void atribuirResponsavelFlow();

    /**
     * @brief Fluxo de remoção de responsável
     */
    void removerResponsavelFlow();

    /**
     * @brief Fluxo de listagem de histórias por projeto
     */
    void listarPorProjetoFlow();
};

// ============================================
// CONTROLADORA PRINCIPAL (MENU)
// ============================================

/**
 * @brief Controladora principal do sistema
 * 
 * @details Coordena todas as controladoras e exibe o menu principal.
 *          Responsável por autenticar o usuário e direcionar para os
 *          módulos apropriados.
 */
class ControladoraPrincipal {
private:
    ControladoraAutenticacao ctrlAutenticacao;
    ControladoraPessoa ctrlPessoa;
    ControladoraProjeto ctrlProjeto;
    ControladoraPlanoSprint ctrlPlanoSprint;
    ControladoraHistoriaUsuario ctrlHistoria;

    /**
     * @brief Exibe o menu principal e gerencia as opções
     */
    void executarMenuPrincipal();

    /**
     * @brief Exibe o cabeçalho do sistema
     */
    void exibirCabecalho();

public:
    /**
     * @brief Construtor da controladora principal
     * @param sp Serviço de pessoa
     * @param spr Serviço de projeto
     * @param splan Serviço de plano de sprint
     * @param shist Serviço de história de usuário
     */
    ControladoraPrincipal(IServicoPessoa* sp,
                          IServicoProjeto* spr,
                          IServicoPlanoSprint* splan,
                          IServicoHistoriaUsuario* shist);

    /**
     * @brief Inicia a execução do sistema
     */
    void executar();
};

#endif // CONTROLADORAS_HPP_INCLUDED