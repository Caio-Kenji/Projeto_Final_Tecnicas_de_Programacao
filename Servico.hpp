/**
 * @file Servico.hpp
 * @brief Implementação concreta dos serviços (lógica de negócio)
 *
 * @details Este arquivo contém as classes que implementam as interfaces
 *          definidas em Interfaces.hpp. Cada classe contém a lógica de
 *          negócio e utiliza os containers para armazenamento.
 *
 */

#ifndef SERVICO_HPP_INCLUDED
#define SERVICO_HPP_INCLUDED

#include "Interfaces.hpp"
#include "Container.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;

// ============================================
// SERVIÇO PARA PESSOA
// ============================================

/**
 * @brief Implementação concreta do serviço de Pessoa.
 *
 * @details Implementa IServicoPessoa e utiliza ContainerPessoa
 *          para armazenar pessoas em memória e aplicar as regras
 *          de negócio relacionadas ao gerenciamento de usuários.
 */
class ServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa* container;  // Ponteiro para Singleton

public:
    /**
     * @brief Inicializa o serviço de pessoas.
     */
    ServicoPessoa();

    /**
     * @brief Cria uma nova pessoa.
     *
     * @param email Email da pessoa.
     * @param nome Nome da pessoa.
     * @param senha Senha da pessoa.
     * @param papel Papel da pessoa no sistema.
     */
    void criarPessoa(const string& email,
                     const string& nome,
                     const string& senha,
                     const string& papel) override;

    /**
     * @brief Consulta uma pessoa pelo email.
     *
     * @param email Email da pessoa.
     */
    void consultarPessoa(const string& email) override;

    /**
     * @brief Atualiza os dados de uma pessoa.
     *
     * @param email Email da pessoa.
     * @param nome Novo nome da pessoa.
     * @param senha Nova senha da pessoa.
     * @param papel Novo papel da pessoa.
     */
    void atualizarPessoa(const string& email,
                         const string& nome,
                         const string& senha,
                         const string& papel) override;

    /**
     * @brief Exclui uma pessoa.
     *
     * @param email Email da pessoa.
     */
    void excluirPessoa(const string& email) override;
};






// ============================================
// SERVIÇO PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Implementação concreta do serviço de PlanoSprint.
 *
 * @details Implementa IServicoPlanoSprint e contém as regras de negócio
 *          relacionadas aos planos de sprint, incluindo validação de
 *          capacidade, associação e desassociação de histórias e
 *          verificação da existência de projetos e histórias.
 */
class ServicoPlanoSprint : public IServicoPlanoSprint {
private:
    ContainerPlanoSprint* container;              // Ponteiro para Singleton
    ContainerProjeto* containerProjeto;           // Ponteiro para Singleton
    ContainerHistoriaUsuario* containerHistoria;  // Ponteiro para Singleton

public:
    /**
     * @brief Constrói o serviço de planos de sprint.
     *
     * @details Obtém as instâncias Singleton dos contêineres utilizados
     *          pelo serviço.
     */
    ServicoPlanoSprint();

    /**
     * @brief Cria um novo plano de sprint.
     *
     * @param codigo Código do plano de sprint.
     * @param capacidade Capacidade do sprint em dias.
     * @param dataInicio Data de início do sprint.
     * @param dataTermino Data de término do sprint.
     * @param codigoProjeto Código do projeto ao qual o sprint pertence.
     */
    void criarPlanoSprint(const std::string& codigo,
                          int capacidade,
                          const std::string& dataInicio,
                          const std::string& dataTermino,
                          const std::string& codigoProjeto) override;

    /**
     * @brief Lista todos os planos de sprint cadastrados.
     */
    void listarPlanosSprint() override;

    /**
     * @brief Consulta um plano de sprint pelo código.
     *
     * @param codigo Código do plano de sprint.
     */
    void consultarPlanoSprint(const std::string& codigo) override;

    /**
     * @brief Atualiza a capacidade de um plano de sprint.
     *
     * @param codigo Código do plano de sprint.
     * @param novaCapacidade Nova capacidade do sprint.
     */
    void atualizarCapacidade(const std::string& codigo,
                             int novaCapacidade) override;

    /**
     * @brief Exclui um plano de sprint.
     *
     * @param codigo Código do plano de sprint.
     */
    void excluirPlanoSprint(const std::string& codigo) override;

    /**
     * @brief Associa uma história de usuário a um plano de sprint.
     *
     * @param codigoSprint Código do plano de sprint.
     * @param codigoHistoria Código da história de usuário.
     * @param estimativa Estimativa da história em dias.
     */
    void associarHistoria(const std::string& codigoSprint,
                          const std::string& codigoHistoria,
                          int estimativa) override;

    /**
     * @brief Remove uma história de usuário de um plano de sprint.
     *
     * @param codigoSprint Código do plano de sprint.
     * @param codigoHistoria Código da história de usuário.
     * @param estimativa Estimativa da história em dias.
     */
    void desassociarHistoria(const std::string& codigoSprint,
                             const std::string& codigoHistoria,
                             int estimativa) override;

    /**
     * @brief Lista as histórias associadas a um plano de sprint.
     *
     * @param codigoSprint Código do plano de sprint.
     */
    void listarHistoriasDoSprint(const std::string& codigoSprint) override;

    /**
     * @brief Lista os planos de sprint associados a um projeto.
     *
     * @param codigoProjeto Código do projeto.
     */
    void listarPlanosPorProjeto(const string& codigoProjeto) override;
};







// ============================================
// SERVIÇO PARA PROJETO
// ============================================

/**
 * @brief Implementação concreta do serviço de Projeto.
 *
 * @details Implementa IServicoProjeto e utiliza ContainerProjeto
 *          para armazenar projetos em memória e realizar as
 *          validações das regras de negócio relacionadas aos projetos.
 */
class ServicoProjeto : public IServicoProjeto {
private:
    ContainerProjeto* container;  // Usa ponteiro para Singleton

public:
    /**
     * @brief Inicializa o serviço de projetos.
     */
    ServicoProjeto();

    /**
     * @brief Cria um novo projeto.
     *
     * @param codigo Código do projeto.
     * @param nome Nome do projeto.
     * @param dataInicio Data de início do projeto.
     * @param dataTermino Data de término do projeto.
     * @param emailScrumMaster Email do Scrum Master responsável.
     */
    void criarProjeto(const std::string& codigo,
                      const std::string& nome,
                      const std::string& dataInicio,
                      const std::string& dataTermino,
                      const std::string& emailScrumMaster) override;

    /**
     * @brief Lista todos os projetos cadastrados.
     */
    void listarProjetos() override;

    /**
     * @brief Consulta um projeto pelo código.
     *
     * @param codigo Código do projeto.
     */
    void consultarProjeto(const std::string& codigo) override;

    /**
     * @brief Atualiza o nome de um projeto.
     *
     * @param codigo Código do projeto.
     * @param novoNome Novo nome do projeto.
     */
    void atualizarProjeto(const std::string& codigo,
                          const std::string& novoNome) override;

    /**
     * @brief Exclui um projeto.
     *
     * @param codigo Código do projeto.
     */
    void excluirProjeto(const std::string& codigo) override;

    /**
     * @brief Lista os projetos associados a uma pessoa.
     *
     * @param emailPessoa Email da pessoa.
     */
    void listarProjetosPorPessoa(const string& emailPessoa) override;
};





// ============================================
// SERVIÇO PARA HISTÓRIA DE USUÁRIO
// ============================================

/**
 * @brief Implementação concreta do serviço de HistoriaUsuario.
 *
 * @details Implementa IServicoHistoriaUsuario e utiliza ContainerHistoriaUsuario,
 *          ContainerProjeto e ContainerPessoa para armazenar histórias em memória
 *          e validar associações com projetos e pessoas.
 */
class ServicoHistoriaUsuario : public IServicoHistoriaUsuario {
private:
    ContainerHistoriaUsuario* container;
    ContainerProjeto* containerProjeto;
    ContainerPessoa* containerPessoa;

public:
    /**
     * @brief Inicializa o serviço de histórias de usuário.
     */
    ServicoHistoriaUsuario();

    /**
     * @brief Cria uma nova história de usuário.
     * @param codigo Código da história.
     * @param nome Nome da história.
     * @param descricao Descrição da história.
     * @param prioridade Prioridade da história.
     * @param codigoProjeto Código do projeto associado.
     * @param estimativa Estimativa da história em dias.
     */
    void criarHistoria(const std::string& codigo,
                       const std::string& nome,
                       const std::string& descricao,
                       const std::string& prioridade,
                       const std::string& codigoProjeto,
                       int estimativa) override;

    /**
     * @brief Lista todas as histórias de usuário cadastradas.
     */
    void listarHistorias() override;

    /**
     * @brief Consulta uma história de usuário pelo código.
     * @param codigo Código da história.
     */
    void consultarHistoria(const std::string& codigo) override;

    /**
     * @brief Altera o estado de uma história de usuário.
     * @param codigo Código da história.
     * @param novoEstado Novo estado da história.
     */
    void alterarEstado(const std::string& codigo,
                       const std::string& novoEstado) override;

    /**
     * @brief Atualiza os dados de uma história de usuário.
     * @param codigo Código da história.
     * @param nome Novo nome da história.
     * @param descricao Nova descrição da história.
     * @param prioridade Nova prioridade da história.
     * @param estimativa Nova estimativa em dias.
     */
    void atualizarHistoria(const std::string& codigo,
                           const std::string& nome,
                           const std::string& descricao,
                           const std::string& prioridade,
                           int estimativa) override;

    /**
     * @brief Exclui uma história de usuário.
     * @param codigo Código da história.
     */
    void excluirHistoria(const std::string& codigo) override;

    /**
     * @brief Atribui uma pessoa responsável a uma história de usuário.
     * @param codigoHistoria Código da história.
     * @param emailPessoa Email da pessoa responsável.
     */
    void atribuirResponsavel(const std::string& codigoHistoria,
                             const std::string& emailPessoa) override;

    /**
     * @brief Remove o responsável de uma história de usuário.
     * @param codigoHistoria Código da história.
     */
    void removerResponsavel(const std::string& codigoHistoria) override;

    /**
     * @brief Lista histórias de usuário associadas a um projeto.
     * @param codigoProjeto Código do projeto.
     */
    void listarHistoriasPorProjeto(const std::string& codigoProjeto) override;

    /**
     * @brief Lista histórias de usuário associadas a uma pessoa.
     * @param emailPessoa Email da pessoa.
     */
    void listarHistoriasPorPessoa(const std::string& emailPessoa) override;
};

/**
 * @brief Serviço responsável pela autenticação de usuários.
 *
 * @details Utiliza ContainerPessoa para verificar se as credenciais
 *          informadas correspondem a uma pessoa cadastrada no sistema.
 */
class ServicoAutenticacao {
private:
    ContainerPessoa* containerPessoa;

public:
    /**
     * @brief Inicializa o serviço de autenticação.
     */
    ServicoAutenticacao();

    /**
     * @brief Autentica um usuário a partir de email e senha.
     *
     * @param email Email informado pelo usuário.
     * @param senha Senha informada pelo usuário.
     * @param pessoaLogada Ponteiro usado para retornar os dados da pessoa autenticada.
     * @return true se as credenciais forem válidas; false caso contrário.
     */
    bool autenticar(const string& email, const string& senha, Pessoa* pessoaLogada);
};





#endif //SERVICO_HPP_INCLUDED
