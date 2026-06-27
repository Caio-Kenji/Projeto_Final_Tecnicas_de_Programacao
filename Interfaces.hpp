/**
 * @file Interfaces.hpp
 * @brief Interfaces (classes abstratas) para a camada de serviço
 *
 * @details Este arquivo contém todas as interfaces que definem os contratos
 *          entre a camada de apresentação e a camada de serviço. Cada interface
 *          corresponde a uma entidade do sistema.
 *
 */

#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include "Dominio.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;


class Email;
class Senha;
class Codigo;
class Projeto;






// ============================================
// INTERFACE AUTENTICAÇÃO
// ============================================

class IAAutenticacao{
public:
    virtual bool autenticar(Email*) = 0;
    virtual ~IAAutenticacao(){};
};

class ISAutenticacao{
public:
    virtual bool autenticar(const Email&, const Senha&) = 0;
    virtual ~ISAutenticacao(){};
};













// ============================================
// INTERFACE PARA PESSOA 
// ============================================




/**
 * @brief Interface para serviços da entidade Pessoa.
 *
 * @details Define as operações de criação, leitura, atualização e exclusão
 *          de pessoas cadastradas no sistema.
 */
class IServicoPessoa {
public:
    virtual ~IServicoPessoa() {}

    /**
     * @brief Cria uma nova pessoa.
     * @param email Email da pessoa.
     * @param nome Nome da pessoa.
     * @param senha Senha da pessoa.
     * @param papel Papel da pessoa no projeto.
     */
    virtual void criarPessoa(const string& email,
                             const string& nome,
                             const string& senha,
                             const string& papel) = 0;

    /**
     * @brief Consulta uma pessoa pelo email.
     * @param email Email da pessoa.
     */
    virtual void consultarPessoa(const string& email) = 0;

    /**
     * @brief Atualiza os dados de uma pessoa.
     * @param email Email da pessoa.
     * @param nome Novo nome.
     * @param senha Nova senha.
     * @param papel Novo papel.
     */
    virtual void atualizarPessoa(const string& email,
                                 const string& nome,
                                 const string& senha,
                                 const string& papel) = 0;

    /**
     * @brief Exclui uma pessoa pelo email.
     * @param email Email da pessoa.
     */
    virtual void excluirPessoa(const string& email) = 0;
};



















// ============================================
// INTERFACE PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Interface para serviços da entidade PlanoSprint
 * 
 * @details Define todas as operações que podem ser realizadas sobre
 *          planos de sprint, incluindo associação de histórias.
 */
class IServicoPlanoSprint {
public:
    virtual void listarPlanosPorProjeto(const string& codigoProjeto) = 0;

    virtual ~IServicoPlanoSprint() {}

    /**
     * @brief Cria um novo plano de sprint
     * @param codigo Identificador único (2 letras + 3 dígitos)
     * @param capacidade Capacidade em dias (1-365)
     * @param dataInicio Data de início (DD/MM/AAAA)
     * @param dataTermino Data de término (DD/MM/AAAA)
     * @param codigoProjeto Código do projeto associado
     */
    virtual void criarPlanoSprint(const std::string& codigo,
                                  int capacidade,
                                  const std::string& dataInicio,
                                  const std::string& dataTermino,
                                  const std::string& codigoProjeto) = 0;

    /**
     * @brief Lista todos os planos de sprint
     */
    virtual void listarPlanosSprint() = 0;

    /**
     * @brief Consulta um plano de sprint específico
     * @param codigo Código do sprint
     */
    virtual void consultarPlanoSprint(const std::string& codigo) = 0;

    /**
     * @brief Atualiza a capacidade de um sprint
     * @param codigo Código do sprint
     * @param novaCapacidade Nova capacidade em dias
     */
    virtual void atualizarCapacidade(const std::string& codigo,
                                     int novaCapacidade) = 0;

    /**
     * @brief Exclui um plano de sprint
     * @param codigo Código do sprint
     */
    virtual void excluirPlanoSprint(const std::string& codigo) = 0;

    /**
     * @brief Associa uma história de usuário a um sprint
     * @param codigoSprint Código do sprint
     * @param codigoHistoria Código da história
     * @param estimativa Estimativa em dias
     */
    virtual void associarHistoria(const std::string& codigoSprint,
                                  const std::string& codigoHistoria,
                                  int estimativa) = 0;

    /**
     * @brief Remove associação de uma história
     * @param codigoSprint Código do sprint
     * @param codigoHistoria Código da história
     * @param estimativa Estimativa da história
     */
    virtual void desassociarHistoria(const std::string& codigoSprint,
                                     const std::string& codigoHistoria,
                                     int estimativa) = 0;

    /**
     * @brief Lista histórias associadas a um sprint
     * @param codigoSprint Código do sprint
     */
    virtual void listarHistoriasDoSprint(const std::string& codigoSprint) = 0;
};







/*

// ============================================
// INTERFACE PROJETO
// ============================================

class IAProjeto {
public:
    virtual void executar(const Email&) = 0;
    virtual ~IAProjeto() {}
};

class ISProjeto{
public:
    virtual bool criar(Projeto) = 0;
    virtual bool ler(Projeto) = 0;
    virtual bool atualizar(Projeto) = 0;
    virtual bool excluir(Codigo) = 0;
    virtual ~ISProjeto(){};
};

*/


// ============================================
// INTERFACE PARA PROJETO
// ============================================

/**
 * @brief Interface para serviços da entidade Projeto.
 *
 * @details Define as operações de criação, leitura, atualização e exclusão
 *          de projetos no sistema.
 */
class IServicoProjeto {
public:
    virtual void listarProjetosPorPessoa(const string& emailPessoa) = 0;

    virtual ~IServicoProjeto() {}

    /**
     * @brief Cria um novo projeto.
     * @param codigo Código do projeto (2 letras + 3 dígitos)
     * @param nome Nome do projeto (max 10 caracteres)
     * @param dataInicio Data de início (DD/MM/AAAA)
     * @param dataTermino Data de término (DD/MM/AAAA)
     * @param emailScrumMaster Email do Scrum Master responsável
     */
    virtual void criarProjeto(const std::string& codigo,
                              const std::string& nome,
                              const std::string& dataInicio,
                              const std::string& dataTermino,
                              const std::string& emailScrumMaster) = 0;

    /**
     * @brief Lista todos os projetos cadastrados.
     */
    virtual void listarProjetos() = 0;

    /**
     * @brief Consulta um projeto específico.
     * @param codigo Código do projeto.
     */
    virtual void consultarProjeto(const std::string& codigo) = 0;

    /**
     * @brief Atualiza o nome de um projeto.
     * @param codigo Código do projeto.
     * @param novoNome Novo nome do projeto.
     */
    virtual void atualizarProjeto(const std::string& codigo,
                                  const std::string& novoNome) = 0;

    /**
     * @brief Exclui um projeto.
     * @param codigo Código do projeto.
     */
    virtual void excluirProjeto(const std::string& codigo) = 0;
};























// ============================================
// INTERFACE PARA HISTÓRIA DE USUÁRIO
// ============================================

/**
 * @brief Interface para serviços da entidade HistoriaUsuario.
 *
 * @details Define as operações de criação, leitura, atualização, exclusão
 *          e alteração de estado de histórias de usuário.
 */
class IServicoHistoriaUsuario {
public:
    virtual void listarHistoriasPorPessoa(const string& emailPessoa) = 0;
    virtual ~IServicoHistoriaUsuario() {}

    /**
     * @brief Cria uma nova história de usuário.
     * @param codigo Código da história (2 letras + 3 dígitos)
     * @param nome Nome da história (max 10 caracteres)
     * @param descricao Descrição da história (max 40 caracteres)
     * @param prioridade Prioridade (ALTA, MEDIA, BAIXA)
     * @param codigoProjeto Código do projeto associado
     * @param estimativa Estimativa em dias (1-365)
     */
    virtual void criarHistoria(const std::string& codigo,
                               const std::string& nome,
                               const std::string& descricao,
                               const std::string& prioridade,
                               const std::string& codigoProjeto,
                               int estimativa) = 0;

    /**
     * @brief Lista todas as histórias cadastradas.
     */
    virtual void listarHistorias() = 0;

    /**
     * @brief Consulta uma história específica.
     * @param codigo Código da história.
     */
    virtual void consultarHistoria(const std::string& codigo) = 0;

    /**
     * @brief Altera o estado de uma história.
     * @param codigo Código da história.
     * @param novoEstado Novo estado (A FAZER, FAZENDO, FEITO)
     */
    virtual void alterarEstado(const std::string& codigo,
                               const std::string& novoEstado) = 0;

    /**
     * @brief Atualiza os dados de uma história.
     * @param codigo Código da história.
     * @param nome Novo nome.
     * @param descricao Nova descrição.
     * @param prioridade Nova prioridade.
     * @param estimativa Nova estimativa.
     */
    virtual void atualizarHistoria(const std::string& codigo,
                                   const std::string& nome,
                                   const std::string& descricao,
                                   const std::string& prioridade,
                                   int estimativa) = 0;

    /**
     * @brief Exclui uma história.
     * @param codigo Código da história.
     */
    virtual void excluirHistoria(const std::string& codigo) = 0;

    /**
     * @brief Atribui uma pessoa como responsável pela história.
     * @param codigoHistoria Código da história.
     * @param emailPessoa Email da pessoa responsável.
     */
    virtual void atribuirResponsavel(const std::string& codigoHistoria,
                                     const std::string& emailPessoa) = 0;

    /**
     * @brief Remove o responsável de uma história.
     * @param codigoHistoria Código da história.
     */
    virtual void removerResponsavel(const std::string& codigoHistoria) = 0;

    /**
     * @brief Lista histórias por projeto.
     * @param codigoProjeto Código do projeto.
     */
    virtual void listarHistoriasPorProjeto(const std::string& codigoProjeto) = 0;
};





#endif // INTERFACES_HPP_INCLUDE
