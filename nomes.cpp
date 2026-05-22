#include "nomes.hpp"

#include <stdexcept>
#include <cctype>

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
