/**
 * @file Containers.hpp
 * @brief Containers para armazenamento em memória das entidades
 * 
 * @details Este arquivo contém todas as classes container responsáveis
 *          por armazenar e gerenciar coleções de objetos (Pessoa, Projeto,
 *          PlanoSprint, HistoriaUsuario).
 * 
 * @author Seu Nome
 * @date 2024
 */

#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "Entidade.hpp"  // Inclui as definições das entidades
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;



// ============================================
// CONTAINER PARA PLANO DE SPRINT
// ============================================

/**
 * @brief Container para armazenar e gerenciar planos de sprint
 */
class ContainerPlanoSprint {
private:
    std::vector<PlanoSprint> planos;

public:
    void adicionar(const PlanoSprint& sprint);
    void remover(const std::string& codigo);
    PlanoSprint* buscar(const std::string& codigo);
    const PlanoSprint* buscar(const std::string& codigo) const;
    std::vector<PlanoSprint> listarTodas() const;
    bool existe(const std::string& codigo) const;
    int tamanho() const;
};














#endif // CONTAINERS_HPP_INCLUDED