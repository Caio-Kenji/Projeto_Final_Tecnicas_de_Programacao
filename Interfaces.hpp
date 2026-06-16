/**
 * @file Interfaces.hpp
 * @brief Interfaces (classes abstratas) para a camada de serviço
 * 
 * @details Este arquivo contém todas as interfaces que definem os contratos
 *          entre a camada de apresentação e a camada de serviço. Cada interface
 *          corresponde a uma entidade do sistema.
 * 
 * @author Seu Nome
 * @date 2024
 */

#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;






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






#endif // INTERFACES_HPP_INCLUDED