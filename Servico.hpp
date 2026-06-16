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
#include "Containers.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;





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
    ContainerPlanoSprint container;
    ContainerProjeto* containerProjeto;           // Dependência injetada
    ContainerHistoriaUsuario* containerHistoria;  // Dependência injetada

public:
    /**
     * @brief Construtor com injeção de dependências
     * @param contProjeto Ponteiro para container de projetos
     * @param contHistoria Ponteiro para container de histórias
     */
    ServicoPlanoSprint(ContainerProjeto* contProjeto, 
                       ContainerHistoriaUsuario* contHistoria);

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








#endif //SERVICO_HPP_INCLUDED