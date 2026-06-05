#include "Texto.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

/**
 * @brief Implementação do método setValor para a classe Texto.
 * Realiza a validação conforme as regras do trabalho.
 */
void Texto::setValor(std::string v) {
    // 1. Validação de tamanho
    if (v.length() > 40 || v.empty()) {
        throw std::invalid_argument("Texto invalido: tamanho incorreto.");
    }

    // 2. Validação de caracteres e sequência
    // Regra: não pode começar ou terminar com vírgula, ponto ou espaço
    if (v[0] == ',' || v[0] == '.' || v[0] == ' ' ||
        v.back() == ',' || v.back() == '.' || v.back() == ' ') {
        throw std::invalid_argument("Texto invalido: inicio ou fim invalido.");
    }

    for (size_t i = 0; i < v.length(); ++i) {
        char c = v[i];

        // Verifica se é letra, dígito, vírgula, ponto ou espaço
        if (!(isalnum(c) || c == ',' || c == '.' || c == ' ')) {
            throw std::invalid_argument("Texto invalido: caractere nao permitido.");
        }

        // Regras de sequência: não pode ponto/vírgula seguidos
        if (c == ',' || c == '.') {
            if (i + 1 < v.length() && (v[i + 1] == ',' || v[i + 1] == '.')) {
                throw std::invalid_argument("Texto invalido: pontuacao seguida.");
            }
        }

        // Regra de espaço: deve ser seguido por letra ou dígito
        if (c == ' ') {
            if (i + 1 < v.length() && !(isalnum(v[i + 1]))) {
                throw std::invalid_argument("Texto invalido: espaco seguido de caracter invalido.");
            }
        }
    }

    // Se passou por tudo, o valor é aceito
    this->valor = v;
}

std::string Texto::getValor() const {
    return valor;
}
