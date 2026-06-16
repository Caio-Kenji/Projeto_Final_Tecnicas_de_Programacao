#ifndef ENTIDADE_HPP_INCLUDED
#define ENTIDADE_HPP_INCLUDED

#include "Dominio.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;


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





// ----------------DEFINIÇÕES: PLANOS DE SPRINT---------------------------------------------------------------------





/**
 * @brief Representa um plano de sprint dentro de um projeto.
 * 
 * @details Um sprint é um período de tempo fixo onde um conjunto de histórias
 *          de usuário é executado. Esta classe gerencia:
 *          - Identificação única do sprint (código)
 *          - Capacidade em dias (1-365)
 *          - Período de execução (data início e fim)
 *          - Relação com o projeto pai
 *          - Associação com histórias de usuário
 * 
 * @invariant O código do plano de sprint é único no sistema.
 * @invariant A capacidade deve estar entre 1 e 365 dias.
 * @invariant A data de início deve ser anterior à data de término.
 * @invariant A soma das estimativas das histórias ≤ capacidade.
 * 
 * @note As regras de negócio sobre capacidade vs estimativas são
 *       verificadas nos métodos associarHistoria() e desassociarHistoria().
 * 
 * @see Codigo, Tempo, Data, HistoriaUsuario
 */
class PlanoSprint {
private:
    Codigo codigo;              ///< Identificador único do plano de sprint
    Tempo capacidade;           ///< Capacidade do sprint em dias (1-365)
    Data dataInicio;            ///< Data de início do sprint (formato DD/MM/AAAA)
    Data dataTermino;           ///< Data de término do sprint (formato DD/MM/AAAA)
    Codigo codigoProjeto;       ///< Código do projeto a que pertence
    
    /**
     * @brief Lista de códigos das histórias de usuário associadas.
     * @details Vetor que armazena os códigos das histórias alocadas para este sprint.
     *          Mantido em paralelo com o vetor 'estimativas'.
     */
    vector<string> historiasAssociadas;
    
    /**
     * @brief Lista de estimativas das histórias associadas.
     * @details Vetor paralelo a 'historiasAssociadas' onde cada posição
     *          armazena a estimativa (em dias) da história correspondente.
     */
    vector<int> estimativas;
    
    /**
     * @brief Soma total das estimativas das histórias associadas.
     * @details Mantido atualizado para validação rápida (O(1) em vez de O(n)).
     *          Quando uma história é associada, somaEstimativas += estimativa.
     *          Quando removida, somaEstimativas -= estimativa.
     */
    int somaEstimativas;

public:
    /**
     * @brief Construtor da classe PlanoSprint.
     * @param codigoStr Código do plano de sprint (2 letras + 3 dígitos).
     * @param capacidadeInt Capacidade em dias (1-365).
     * @param dataInicioStr Data de início do sprint (DD/MM/AAAA).
     * @param dataTerminoStr Data de término do sprint (DD/MM/AAAA).
     * @param codigoProjetoStr Código do projeto associado (2 letras + 3 dígitos).
     * @throw invalid_argument Se algum domínio for inválido (repassado pelos domínios).
     * 
     * @post Um objeto PlanoSprint válido é criado com somaEstimativas = 0.
     */
    PlanoSprint(const string& codigoStr, int capacidadeInt,
                const string& dataInicioStr, const string& dataTerminoStr,
                const string& codigoProjetoStr);
    
    // ========== GETTERS ==========
    
    /**
     * @brief Retorna o código do plano de sprint.
     * @return string Código no formato "XX999".
     */
    string getCodigo() const;
    
    /**
     * @brief Retorna a capacidade do sprint em dias.
     * @return int Valor entre 1 e 365.
     */
    int getCapacidade() const;
    
    /**
     * @brief Retorna a data de início do sprint.
     * @return string Data no formato "DD/MM/AAAA".
     */
    string getDataInicio() const;
    
    /**
     * @brief Retorna a data de término do sprint.
     * @return string Data no formato "DD/MM/AAAA".
     */
    string getDataTermino() const;
    
    /**
     * @brief Retorna o código do projeto associado.
     * @return string Código do projeto no formato "XX999".
     */
    string getCodigoProjeto() const;
    
    /**
     * @brief Retorna a lista de códigos das histórias associadas.
     * @return const vector<string>& Referência constante para o vetor interno.
     * @note Retorna referência const para evitar cópias e impedir modificações diretas.
     */
    const vector<string>& getHistoriasAssociadas() const;
    
    /**
     * @brief Retorna a soma atual das estimativas das histórias associadas.
     * @return int Soma das estimativas em dias.
     */
    int getSomaEstimativas() const;
    
    // ========== SETTERS ==========
    
    /**
     * @brief Define um novo código para o plano de sprint.
     * @param novoCodigo Novo código no formato "XX999".
     * @throw invalid_argument Se o código for inválido.
     * @post O atributo codigo é atualizado apenas se a validação for bem-sucedida.
     */
    void setCodigo(const string& novoCodigo);
    
    /**
     * @brief Define uma nova capacidade para o sprint.
     * @param novaCapacidade Novo valor entre 1 e 365.
     * @throw invalid_argument Se a capacidade for inválida.
     * @throw runtime_error Se a nova capacidade for menor que a soma das estimativas.
     * @post A capacidade é atualizada apenas se for ≥ somaEstimativas.
     */
    void setCapacidade(int novaCapacidade);
    
    /**
     * @brief Define uma nova data de início para o sprint.
     * @param novaData Data no formato "DD/MM/AAAA".
     * @throw invalid_argument Se a data for inválida.
     */
    void setDataInicio(const string& novaData);
    
    /**
     * @brief Define uma nova data de término para o sprint.
     * @param novaData Data no formato "DD/MM/AAAA".
     * @throw invalid_argument Se a data for inválida.
     */
    void setDataTermino(const string& novaData);
    
    /**
     * @brief Define um novo projeto associado ao sprint.
     * @param novoCodigo Código do projeto no formato "XX999".
     * @throw invalid_argument Se o código for inválido.
     */
    void setCodigoProjeto(const string& novoCodigo);
    
    // ========== GERENCIAMENTO DE HISTÓRIAS ==========
    
    /**
     * @brief Associa uma história de usuário a este plano de sprint.
     * @param codigoHistoria Código da história a ser associada (formato "XX999").
     * @param estimativa Estimativa de esforço da história em dias (1-365).
     * @throw invalid_argument Se o código da história ou estimativa forem inválidos.
     * @throw runtime_error Se a história já estiver associada.
     * @throw runtime_error Se a capacidade do sprint for excedida.
     * @post A história é adicionada ao vetor e a somaEstimativas é atualizada.
     * 
     * @note Esta é uma operação O(1) (apenas push_back no vetor).
     */
    void associarHistoria(const string& codigoHistoria, int estimativa);
    
    /**
     * @brief Remove a associação de uma história com este plano de sprint.
     * @param codigoHistoria Código da história a ser removida.
     * @param estimativa Estimativa da história (para verificação de consistência).
     * @return true se a história foi encontrada e removida, false caso contrário.
     * @throw runtime_error Se a estimativa fornecida não corresponder à armazenada.
     * @post Se encontrada, a história é removida e a somaEstimativas é atualizada.
     * 
     * @note A complexidade é O(n) onde n é o número de histórias associadas.
     */
    bool desassociarHistoria(const string& codigoHistoria, int estimativa);
    
    /**
     * @brief Verifica se uma história está associada a este sprint.
     * @param codigoHistoria Código da história a verificar.
     * @return true se a história está associada, false caso contrário.
     * @note Complexidade O(n) onde n é o número de histórias associadas.
     */
    bool temHistoria(const string& codigoHistoria) const;
    
    /**
     * @brief Calcula a soma total das estimativas percorrendo o vetor.
     * @return int Soma das estimativas (pode ser usada para testes).
     * @note Este método recalcula do zero, diferentemente de getSomaEstimativas()
     *       que retorna o valor mantido internamente.
     */
    int calcularSomaEstimativas() const;
};
































#endif // ENTIDADE_HPP_INCLUDED
