#ifndef TEMPO_HPP
#define TEMPO_HPP

using namespace std;

/**
 * @brief Classe que representa o tempo.
 *
 * Deve ser um inteiro entre
 * 1 e 365.
 */

 class Tempo {
    private:
     /**
     * Armazena o tempo.
     */
        int tempo;
     /**
     * Verifica se o número é válido ou não.
     * @throw invalid_argument caso o número seja inválido.
     * @param tempo número a ser validado.
     */
        void validar(int tempo);
    public:
     /**
     * Define o tempo.
     * @param tempo tempo a ser guardado.
     */
        void setTempo(int tempo);
     /**
     * Retorna o tempo.
     */
        int getTempo();
     
 };

#endif