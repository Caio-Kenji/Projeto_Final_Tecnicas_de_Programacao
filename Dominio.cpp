// Este é o arquivo Dominio.cpp

#include "Dominio.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
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

/**
 * @brief Realiza a validação do nome.
 *
 * @param nome nome que será validado.
 *
 * @throw invalid_argument caso o nome seja inválido.
 */

 void Nome::validar(string nome) {
    if (nome.length() > 10 || nome.length() == 0)
        throw invalid_argument("Nome invalido");

    if (nome[0] == ' ' || nome.back() == ' ')
        throw invalid_argument("Nome invalido");
    
    char ant = 'z';

    for (char c : nome) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' '))
          throw invalid_argument("Nome invalido");
        if (ant == ' ' && c == ' ')
          throw invalid_argument("Nome invalido");
        ant = c;
    }
  }

 /**
 * @brief Armazena o nome.
 *
 * @param nome nome que será armazenado.
 */

  void Nome::setNome(string nome) {
    validar(nome);
    this-> nome = nome;
 } 

 /**
 * @brief Retorna o nome armazenado.
 *
 * @return String nome.
 */
string Nome::getNome(){
    return nome;
}

/**
 * @brief Realiza a validação da senha.
 *
 * @param senha senha que será validada.
 *
 * @throw invalid_argument caso a senha seja inválida.
 */

 void Senha::validar(string senha) {
    if (senha.length() != 6)
        throw invalid_argument("Senha invalida");
    
    char ant = ' ';
    int maiu = 0, min = 0, num = 0;

    for (char c : senha) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
          throw invalid_argument("Senha invalida");
        if ((c >= 'a' && c <= 'z')) {
            min++;
            if ((ant >= 'a' && ant <= 'z') || (ant >= 'A' && ant <= 'Z'))
              throw invalid_argument("Senha invalida");
        }
        if ((c >= 'A' && c <= 'Z')) {
            maiu++;
            if ((ant >= 'a' && ant <= 'z') || (ant >= 'A' && ant <= 'Z'))
              throw invalid_argument("Senha invalida");
        }
        if ((c >= '0' && c <= '9')) {
            num++;
            if ((ant >= '0' && ant <= '9'))
              throw invalid_argument("Senha invalida");
        }
        ant = c;
    }
    if (num == 0 || maiu == 0 || min == 0)
        throw invalid_argument("Senha invalida");
  }

 /**
 * @brief Armazena a senha.
 *
 * @param senha senha que será armazenada.
 */

  void Senha::setSenha(string senha) {
    validar(senha);
    this-> senha = senha;
 } 

 /**
 * @brief Retorna a senha armazenada.
 *
 * @return String senha.
 */
string Senha::getSenha(){
    return senha;
}

/**
 * @brief Realiza a validação do tempo inserido.
 *
 * @param tempo número que será validado.
 *
 * @throw invalid_argument caso o número seja inválido.
 */

 void Tempo::validar(int tempo) {
    if (tempo > 365 || tempo <= 0)
        throw invalid_argument("tempo invalido");
  }

 /**
 * @brief Armazena o tempo.
 *
 * @param tempo número que será armazenado.
 */

  void Tempo::setTempo(int tempo) {
    validar(tempo);
    this-> tempo = tempo;
 } 

 /**
 * @brief Retorna o tempo armazenado.
 *
 * @return Int tempo.
 */
int Tempo::getTempo(){
    return tempo;
}


