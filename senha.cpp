#include "senha.hpp"

#include <stdexcept>
#include <cctype>

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
