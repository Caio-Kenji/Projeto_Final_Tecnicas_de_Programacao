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
// CONTROLADORA PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Controladora de apresentação para entidade PlanoSprint
 */
class ControladoraPlanoSprint {
private:
    IServicoPlanoSprint* servico;

    bool validarFormatoCodigo(const std::string& codigo);
    bool validarFormatoData(const std::string& data);
    std::string lerCodigo(const std::string& mensagem);
    std::string lerData(const std::string& mensagem);
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




#endif // APRESENTACAO_HPP_INCLUDED