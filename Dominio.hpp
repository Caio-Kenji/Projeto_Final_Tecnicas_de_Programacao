// Este é o arquivo Dominio.hpp

#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>
#include<cctype>
#include<stdexcept>

using namespace std;

/**
 * @brief Classe base abstrata para todos os domínios do sistema.
 *
 * @details Esta classe fornece a estrutura fundamental para qualquer domínio,
 *          garantindo que todo valor atribuído seja validado antes do armazenamento.
 *          O método setValor() lança exceção se o formato for inválido.
 *
 * @invariant O atributo 'valor' sempre armazena uma string válida para o domínio.
 *
 * @see Codigo, Data, Estado
 */
class Dominio{
protected:
    string valor; ///< Valor armazenado do domínio

     /**
     * @brief Método virtual puro para validação do valor.
     * @param valor String a ser validada.
     * @throw invalid_argument Se o valor não atender ao formato do domínio.
     */
    virtual void validar(string)=0;
public:
     /**
     * @brief Define um novo valor para o domínio.
     * @param valor Valor a ser atribuído.
     * @throw invalid_argument Repassa exceção do método validar().
     *
     * @post O atributo 'valor' é atualizado apenas se a validação for bem-sucedida.
     */
    void setValor(string);

     /**
     * @brief Retorna o valor atual armazenado.
     * @return string Cópia do valor interno.
     * @note Este método não modifica o objeto (const).
     * @see setValor()
     */
    string getValor() const;
};

/**
 * @brief Domínio para identificadores alfanuméricos com formato fixo de 5 caracteres.
 *
 * @details Armazena e valida strings que seguem a seguinte estrutura:
 *          - Posição 1 e 2: duas letras maiúsculas (A a Z)
 *          - Posição 3, 4 e 5: três dígitos numéricos (0 a 9)
 *
 * @note Este formato é comumente utilizado para identificação de tarefas,
 *       projetos ou itens no sistema.
 *
 * @exceptions
 * @throw invalid_argument "Codigo invalido." se:
 *         - A string não tiver exatamente 5 caracteres
 *         - O 1º ou 2º caractere não for letra maiúscula
 *         - O 3º, 4º ou 5º caractere não for dígito
 */
class Codigo:public Dominio{
private:

     /**
     * @brief Valida o formato do código conforme especificação.
     * @param valor String de 5 caracteres.
     * @throw invalid_argument "Codigo invalido." para qualquer violação.
     */
    void validar(string);
};

/**
 * @brief Domínio para representar um ponto específico no calendário gregoriano.
 *
 * @details Armazena e valida strings que seguem a estrutura "DD/MM/AAAA", onde:
 *          - DD: número de dois dígitos entre 01 e 31 (dia do mês)
 *          - MM: número de dois dígitos entre 01 e 12 (mês do ano)
 *          - AAAA: número de quatro dígitos entre 2000 e 2999 (ano)
 *
 * @note A combinação dia-mês-ano deve corresponder a uma data real existente,
 *       considerando a quantidade de dias de cada mês e anos bissextos.
 *
 * @details Validação especial para anos bissextos:
 *          - Ano bissexto: divisível por 4, exceto se divisível por 100
 *            (a menos que também seja divisível por 400)
 *          - Fevereiro pode ter 29 dias apenas em anos bissextos
 *
 * @exceptions
 * @throw invalid_argument "Data invalida." se:
 *         - Formato não for DD/MM/AAAA (10 caracteres)
 *         - Dia for 00 ou maior que o máximo do mês
 *         - Mês for 00 ou maior que 12
 *         - Ano for menor que 2000 ou maior que 2999
 *         - 29/02 em ano não bissexto
 *
 * @see Dominio
 */

class Data:public Dominio{
private:

     /**
     * @brief Valida se a string representa uma data real.
     * @param valor String no formato "DD/MM/AAAA".
     * @throw invalid_argument "Data invalida." para qualquer violação.
     */
    void validar(string);
};

/**
 * @brief Representa em qual etapa do fluxo de trabalho uma tarefa se encontra.
 *
 * @details
 * - "A FAZER" : Tarefa aguardando na fila, nenhum trabalho realizado
 * - "FAZENDO" : Tarefa sendo executada neste momento, trabalho em andamento
 * - "FEITO" : Tarefa completa, trabalho finalizado
 *
 * @exceptions
 * @throw invalid_argument "Estado invalido." se o valor não for exatamente
 *         um dos três strings definidos (case-sensitive).
 *
 * @note A transição entre estados segue a ordem natural:
 *       A FAZER → FAZENDO → FEITO (não é possível retroceder ou pular fases)
 */
class Estado:public Dominio{
private:

     /**
     * @brief Valida se o valor está entre os estados permitidos.
     * @param valor String a ser validada.
     * @throw invalid_argument "Estado invalido." se não for um dos três estados.
     */
    void validar(string);
};

class Papel {
private:
    string valor;  // atributo privado (nome sugestivo: "valor")

    // Método privado de validação (opcional, mas organiza o código)
    void validar(const string& papel);

public:
    // Construtor (já valida na criação)
    Papel(const string& papel);

    // Método set (lança exceção se inválido)
    void setValor(const string& papel);

    // Método get (retorna o valor)
    string getValor() const;
};


class Email {
private:
    std::string valor;

    // Método privado de validação (só a classe usa)
    void validar(const std::string& email) const;

public:
    // Construtor
    Email(const std::string& novoValor);

    // Métodos set e get
    void set(const std::string& novoValor);
    std::string get() const;
};

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


#endif // DOMINIO_HPP_INCLUDED
