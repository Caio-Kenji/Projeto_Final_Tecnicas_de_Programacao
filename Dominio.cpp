// Este é o arquivo Dominio.cpp

#include "Dominio.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
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




// Construtor
Email::Email(const std::string& novoValor) {
    set(novoValor);  // reutiliza o set
}

// Método set
void Email::set(const std::string& novoValor) {
    validar(novoValor);  // valida primeiro
    valor = novoValor;   // só atribui se válido
}

// Método get
std::string Email::get() const {
    return valor;
}

void Email::validar(const string& email) const {
    // 1. Encontrar a posição do @
    size_t arrobaPos = email.find('@');
    
    // 2. Verificar se existe @
    if (arrobaPos == std::string::npos) {
        throw invalid_argument("Email deve conter o caractere @");
    }
    
    // 3. Verificar se @ não está no início
    if (arrobaPos == 0) {
        throw invalid_argument("Email nao pode comecar com @");
    }
    
    // 4. Verificar se @ não está no fim
    if (arrobaPos == email.length() - 1) {
        throw invalid_argument("Email nao pode terminar com @");
    }
    
    // 5. Verificar se não existe outro @
    size_t segundaArroba = email.find('@', arrobaPos + 1);
    if (segundaArroba != std::string::npos) {
        throw invalid_argument("Email nao pode ter mais de um @");
    }

    string local = email.substr(0, arrobaPos);
    string dominio = email.substr(arrobaPos + 1);
    
    // 7. Verificar tamanhos
    if (local.length() > 64) {
        throw invalid_argument("Parte local do email excede 64 caracteres");
    }
    if (dominio.length() > 255) {
        throw invalid_argument("Dominio do email excede 255 caracteres");
    }
    if (local.empty() || dominio.empty()) {
        throw invalid_argument("Parte local ou dominio vazios");
    }

    for (size_t i = 0; i < local.length(); i++) {
        char c = local[i];
        
        // Se é letra ou dígito -> OK, continua
        if (isalnum(c)) {
            continue;
        }
        
        // Se é ponto ou hífen -> regras especiais
        if (c == '.' || c == '-') {
            // Não pode ser primeiro caractere
            if (i == 0) {
                throw std::invalid_argument("Parte local nao pode comecar com . ou -");
            }
            // Não pode ser último caractere
            if (i == local.length() - 1) {
                throw invalid_argument("Parte local nao pode terminar com . ou -");
            }
            // Próximo caractere deve ser letra ou dígito
            if (!isalnum(local[i + 1])) {
                throw invalid_argument("Apos . ou - deve vir letra ou digito");
            }
            continue;
        }
        
        // Qualquer outro caractere é inválido
        throw invalid_argument("Caractere invalido na parte local");
    }

    // 9. Validar domínio (quebrar por pontos)
    stringstream ss(dominio);
    string parte;
    
    while (getline(ss, parte, '.')) {
        // Parte não pode ser vazia (domínio com ponto consecutivo)
        if (parte.empty()) {
            throw invalid_argument("Dominio com ponto consecutivo");
        }
        
        // Primeiro caractere da parte não pode ser hífen
        if (parte.front() == '-') {
            throw invalid_argument("Parte do dominio nao pode comecar com -");
        }
        
        // Último caractere da parte não pode ser hífen
        if (parte.back() == '-') {
            throw invalid_argument("Parte do dominio nao pode terminar com -");
        }
        
        // Validar cada caractere da parte
        for (char c : parte) {
            if (!std::isalnum(c) && c != '-') {
                throw invalid_argument("Caractere invalido na parte do dominio");
            }
        }
    }
    
}  // fim do método validar
