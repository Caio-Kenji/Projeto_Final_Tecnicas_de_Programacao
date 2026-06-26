/**
 * @file Servico.hpp
 * @brief Implementação concreta dos serviços (lógica de negócio)
 *
 * @details Este arquivo contém as classes que implementam as interfaces
 *          definidas em Interfaces.hpp. Cada classe contém a lógica de
 *          negócio e utiliza os containers para armazenamento.
 *
 * @author Seu Nome
 * @date 2024
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
// SERVIÇO PARA PESSOA (CORRIGIDO - VERSÃO SINGLETON)
// ============================================

/**
 * @brief Implementação concreta do serviço de Pessoa.
 *
 * @details Implementa IServicoPessoa e utiliza ContainerPessoa (Singleton)
 *          para armazenar pessoas em memória.
 */
class ServicoPessoa : public IServicoPessoa {
private:
    ContainerPessoa* container;  // ← MUDOU para ponteiro

public:
    ServicoPessoa();  // ← Construtor adicionado

    void criarPessoa(const string& email,
                     const string& nome,
                     const string& senha,
                     const string& papel) override;

    void consultarPessoa(const string& email) override;

    void atualizarPessoa(const string& email,
                         const string& nome,
                         const string& senha,
                         const string& papel) override;

    void excluirPessoa(const string& email) override;
};









// ============================================
// SERVIÇO PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Implementação concreta do serviço de PlanoSprint
 *
 * @details Implementa IServicoPlanoSprint e contém as regras de negócio
 *          específicas de sprints, como validação de capacidade e
 *          associação de histórias.
 */
class ServicoPlanoSprint : public IServicoPlanoSprint {
private:
    ContainerPlanoSprint* container;              // Ponteiro para Singleton
    ContainerProjeto* containerProjeto;           // Ponteiro para Singleton
    ContainerHistoriaUsuario* containerHistoria;  // Ponteiro para Singleton

public:
    void listarPlanosPorProjeto(const string& codigoProjeto) override;
    /**
     * @brief Construtor do serviço de plano de sprint.
     * @details Obtém as instâncias Singleton dos containers.
     */
    ServicoPlanoSprint();

    void criarPlanoSprint(const std::string& codigo,
                          int capacidade,
                          const std::string& dataInicio,
                          const std::string& dataTermino,
                          const std::string& codigoProjeto) override;

    void listarPlanosSprint() override;
    void consultarPlanoSprint(const std::string& codigo) override;
    void atualizarCapacidade(const std::string& codigo,
                             int novaCapacidade) override;
    void excluirPlanoSprint(const std::string& codigo) override;
    void associarHistoria(const std::string& codigoSprint,
                          const std::string& codigoHistoria,
                          int estimativa) override;
    void desassociarHistoria(const std::string& codigoSprint,
                             const std::string& codigoHistoria,
                             int estimativa) override;
    void listarHistoriasDoSprint(const std::string& codigoSprint) override;
};











// ============================================
// SERVIÇO PARA PROJETO
// ============================================

/**
 * @brief Implementação concreta do serviço de Projeto.
 *
 * @details Implementa IServicoProjeto e utiliza ContainerProjeto
 *          para armazenar projetos em memória.
 */
class ServicoProjeto : public IServicoProjeto {
private:
    ContainerProjeto* container;  // Usa ponteiro para Singleton

public:
    void listarProjetosPorPessoa(const string& emailPessoa) override;
    ServicoProjeto();

    void criarProjeto(const std::string& codigo,
                      const std::string& nome,
                      const std::string& dataInicio,
                      const std::string& dataTermino,
                      const std::string& emailScrumMaster) override;

    void listarProjetos() override;
    void consultarProjeto(const std::string& codigo) override;
    void atualizarProjeto(const std::string& codigo,
                          const std::string& novoNome) override;
    void excluirProjeto(const std::string& codigo) override;
};












// ============================================
// SERVIÇO PARA HISTÓRIA DE USUÁRIO
// ============================================

/**
 * @brief Implementação concreta do serviço de HistoriaUsuario.
 *
 * @details Implementa IServicoHistoriaUsuario e utiliza ContainerHistoriaUsuario
 *          para armazenar histórias em memória.
 */
class ServicoHistoriaUsuario : public IServicoHistoriaUsuario {
private:
    ContainerHistoriaUsuario* container;  // Usa ponteiro para Singleton
    ContainerProjeto* containerProjeto;   // Para validar projeto

public:
    void listarHistoriasPorPessoa(const string& codigoPessoa) override;
    ServicoHistoriaUsuario();

    void criarHistoria(const std::string& codigo,
                       const std::string& nome,
                       const std::string& descricao,
                       const std::string& prioridade,
                       const std::string& codigoProjeto,
                       int estimativa) override;

    void listarHistorias() override;
    void consultarHistoria(const std::string& codigo) override;
    void alterarEstado(const std::string& codigo,
                       const std::string& novoEstado) override;
    void atualizarHistoria(const std::string& codigo,
                           const std::string& nome,
                           const std::string& descricao,
                           const std::string& prioridade,
                           int estimativa) override;
    void excluirHistoria(const std::string& codigo) override;
    void atribuirResponsavel(const std::string& codigoHistoria,
                             const std::string& codigoPessoa) override;
    void removerResponsavel(const std::string& codigoHistoria) override;
    void listarHistoriasPorProjeto(const std::string& codigoProjeto) override;
};

class ServicoAutenticacao {
private:
    ContainerPessoa* containerPessoa;

public:
    ServicoAutenticacao();

    bool autenticar(const string& email, const string& senha, Pessoa* pessoaLogada);
};





#endif //SERVICO_HPP_INCLUDED
