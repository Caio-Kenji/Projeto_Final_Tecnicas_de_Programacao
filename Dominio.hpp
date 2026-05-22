// Este é o arquivo Dominio.hpp

#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>
using namespace std;


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