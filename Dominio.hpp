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













#endif // DOMINIO_HPP_INCLUDED