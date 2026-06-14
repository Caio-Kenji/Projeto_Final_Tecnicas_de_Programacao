/**
 * @file Containers.cpp
 * @brief Implementação dos métodos dos containers
 * 
 * @author Seu Nome
 * @date 2024
 */

#include "Containers.hpp"
#include <stdexcept>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
using namespace std;





// ============================================
// IMPLEMENTAÇÃO: CONTAINER PLANO SPRINT
// ============================================

void ContainerPlanoSprint::adicionar(const PlanoSprint& sprint) {
    if (existe(sprint.getCodigo())) {
        throw runtime_error("Erro: Plano de sprint com codigo '" + sprint.getCodigo() + "' ja existe");
    }
    planos.push_back(sprint);
}

void ContainerPlanoSprint::remover(const string& codigo) {
    for (auto it = planos.begin(); it != planos.end(); ++it) {
        if (it->getCodigo() == codigo) {
            planos.erase(it);
            return;
        }
    }
    throw runtime_error("Erro: Plano de sprint com codigo '" + codigo + "' nao encontrado");
}

PlanoSprint* ContainerPlanoSprint::buscar(const string& codigo) {
    for (auto& sprint : planos) {
        if (sprint.getCodigo() == codigo) {
            return &sprint;
        }
    }
    return nullptr;
}

const PlanoSprint* ContainerPlanoSprint::buscar(const string& codigo) const {
    for (const auto& sprint : planos) {
        if (sprint.getCodigo() == codigo) {
            return &sprint;
        }
    }
    return nullptr;
}

vector<PlanoSprint> ContainerPlanoSprint::listarTodas() const {
    return planos;
}

bool ContainerPlanoSprint::existe(const string& codigo) const {
    return buscar(codigo) != nullptr;
}

int ContainerPlanoSprint::tamanho() const {
    return planos.size();
}