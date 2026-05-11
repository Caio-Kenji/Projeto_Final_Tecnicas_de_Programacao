// Este é o arquivo Dominio.cpp

#include "Dominio.hpp"
#include <string>
#include <iostream>
using namespace std;


// Implementação do método privado validar
void Papel::validar(const string& papel) {
    if (papel != "DESENVOLVEDOR" && 
        papel != "MESTRE SCRUM" && 
        papel != "PROPRIETARIO DE PRODUTO") {
        
        // Lança exceção com mensagem descritiva
        throw invalid_argument("Papel invalido. Opcoes validas: " 
                                "DESENVOLVEDOR, MESTRE SCRUM, "
                                "PROPRIETARIO DE PRODUTO");
    }
}

// Construtor
Papel::Papel(const string& papel) {
    validar(papel);  // Se lançar exceção, objeto NÃO é criado
    valor = papel;   // Só chega aqui se válido
}

// Método set
void Papel::setValor(const string& papel) {
    validar(papel);  // Se lançar exceção, valor antigo é preservado
    valor = papel;   // Só chega aqui se válido
}

// Método get
string Papel::getValor() const {
    return valor;
}













