#ifndef NOME_HPP
#define NOME_HPP

#include <string>
using namespace std;

/**
 * @brief Classe que representa um nome válido.
 *
 * O nome deve possuir no máximo 10 caracteres,
 * contendo apenas letras e espaços.
 */

 class Nome {
    private:
     /**
     * Armazena o nome.
     */
        string nome;
     /**
     * Verifica se o formato do nome é válido ou não.
     * @throw invalid_argument caso o formato seja inválido.
     * @param nome Nome a ser validado
     */
        void validar(string nome);
    public:
     /**
     * Define o nome.
     * @param nome Nome a ser guardado.
     */
        void setNome(string nome);
     /**
     * Retorna o nome.
     */
        string getNome();
     
 };

#endif