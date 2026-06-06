#ifndef ENTIDADE_HPP_INCLUDED
#define ENTIDADE_HPP_INCLUDED

#include "Dominio.hpp"

/**
 * @brief Classe que representa uma atividade identificada por um nome e um código, além de um início e fim.
 *
 * @details A classe Projeto é uma entidade que agrupa informações relacionadas
 *          a um projeto:
 *          - Código: identificador único do projeto (formato: 2 letras + 3 números)
 *          - Nome: designação textual do projeto (máximo 10 caracteres)
 *          - Data de início: quando o projeto começa (formato: DD/MM/AAAA)
 *          - Data de término: quando o projeto termina (formato: DD/MM/AAAA)
 *
 * @invariant Todos os atributos (codigo, nome, data_inicio, data_termino)
 *            sempre armazenam valores válidos, pois são instâncias de classes
 *            de domínio que validam seus valores internamente.
 *
 * @note Esta classe segue o princípio de encapsulamento, fornecendo métodos
 *       públicos de acesso (getters/setters) para cada atributo.
 * @note Esta classe não valida relacionamentos entre atributos (ex: se a data
 *       de término é posterior à data de início). Essa responsabilidade pertence
 *       à camada de controle/serviço.
 *
 * @see Codigo, Nome, Data
 */
class Projeto{
private:
    Codigo codigo;
    Nome nome;
    Data data_inicio, data_termino;

public:

     /**
     * @brief Define o código identificador do projeto.
     * @param codigo Objeto Codigo válido a ser atribuído.
     * @post O atributo codigo é atualizado com o valor informado.
     * @see Codigo::validar()
     */
    void setCodigo(const Codigo&);

     /**
     * @brief Define o nome do projeto.
     * @param nome Objeto Nome válido a ser atribuído.
     * @post O atributo nome é atualizado com o valor informado.
     * @see Nome::setNome()
     */
    void setNome(const Nome&);

     /**
     * @brief Define a data de início do projeto.
     * @param data_inicio Objeto Data válido a ser atribuído.
     * @post O atributo data_inicio é atualizado com o valor informado.
     * @see Data::validar()
     */
    void setDataInicio(const Data&);

     /**
     * @brief Define a data de término do projeto.
     * @param data_termino Objeto Data válido a ser atribuído.
     * @post O atributo data_termino é atualizado com o valor informado.
     * @see Data::validar()
     */
    void setDataTermino(const Data&);

    /**
     * @brief Retorna o código do projeto.
     * @return Codigo Objeto Codigo contendo o código do projeto.
     * @see setCodigo()
     */
    Codigo getCodigo() const;

    /**
     * @brief Retorna o nome do projeto.
     * @return Nome Objeto Nome contendo o nome do projeto.
     * @see setNome()
     */
    Nome getNome() const;

     /**
     * @brief Retorna a data de início do projeto.
     * @return Data Objeto Data contendo a data de início.
     * @see setDataInicio()
     */
    Data getDataInicio() const;

     /**
     * @brief Retorna a data de término do projeto.
     * @return Data Objeto Data contendo a data de término.
     * @see setDataTermino()
     */
    Data getDataTermino() const;
};

/**
 * @brief Retorna o código do projeto.
 * @details Implementação inline que retorna uma cópia do atributo codigo.
 * @return Codigo Cópia do código armazenado.
 */
inline Codigo Projeto::getCodigo() const{
    return codigo;
}

/**
 * @brief Retorna o nome do projeto.
 * @details Implementação inline que retorna uma cópia do atributo nome.
 * @return Nome Cópia do nome armazenado.
 */
inline Nome Projeto::getNome() const{
    return nome;
}

/**
 * @brief Retorna a data de início do projeto.
 * @details Implementação inline que retorna uma cópia do atributo data_inicio.
 * @return Data Cópia da data de início armazenada.
 */
inline Data Projeto::getDataInicio() const{
    return data_inicio;
}

/**
 * @brief Retorna a data de término do projeto.
 * @details Implementação inline que retorna uma cópia do atributo data_termino.
 * @return Data Cópia da data de término armazenada.
 */
inline Data Projeto::getDataTermino() const{
    return data_termino;
}

#endif // ENTIDADE_HPP_INCLUDED
