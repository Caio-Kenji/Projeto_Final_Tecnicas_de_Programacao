#include "tempo.hpp"

#include <stdexcept>

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
