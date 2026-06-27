/**
 * @file Sessao.hpp
 * @brief Armazena as informações da sessão do usuário autenticado.
 *
 * @details Esta classe contém apenas atributos estáticos que representam
 *          o estado da sessão atual do sistema, permitindo identificar
 *          o usuário autenticado, seu papel e controlar o logout.
 */

#ifndef SESSAO_HPP_INCLUDED
#define SESSAO_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @brief Classe responsável por armazenar os dados da sessão atual.
 *
 * @details Como todos os atributos são estáticos, não é necessário criar
 *          instâncias desta classe. Ela funciona como um armazenamento
 *          global das informações do usuário autenticado durante a execução
 *          do sistema.
 */
class Sessao {
public:

    /**
     * @brief Email do usuário atualmente autenticado.
     */
    static string emailLogado;

    /**
     * @brief Papel do usuário atualmente autenticado.
     *
     * @details Pode assumir os valores:
     * - DESENVOLVEDOR
     * - MESTRE SCRUM
     * - PROPRIETARIO DE PRODUTO
     */
    static string papelLogado;

    /**
     * @brief Indica se foi solicitado o encerramento da sessão.
     *
     * @details Quando verdadeiro, o sistema retorna para a tela de login.
     */
    static bool logout;
};

#endif // SESSAO_HPP_INCLUDED