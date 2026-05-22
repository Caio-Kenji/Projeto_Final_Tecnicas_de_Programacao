#ifndef SENHA_HPP
#define SENHA_HPP

#include <string>
using namespace std;

/**
 * @brief Classe que representa uma senha válida.
 *
 * A senha deve possuir exatamente 6 caracteres,
 * contendo apenas letras e dígitos. 
 * Letra não pode ser seguida por letra e dígito não
 * pode ser seguido por dígito. Deve existir ao menos
 * uma letra minúscula, uma maiúscula e um dígito.
 */

 class Senha {
    private:
     /**
     * Armazena a senha.
     */
        string senha;
     /**
     * Verifica se o formato do senha é válido ou não.
     * @throw invalid_argument caso o formato seja inválido.
     * @param senha senha a ser validado
     */
        void validar(string senha);
    public:
     /**
     * Define a senha.
     * @param senha senha a ser guardada.
     */
        void setSenha(string senha);
     /**
     * Retorna a senha.
     */
        string getSenha();
     
 };

#endif