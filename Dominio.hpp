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
    string valor;  // onde o email válido será armazenado
    
    // Métodos privados (auxiliares, só usados dentro da classe)
    void validar(const string& email) const;
    void validarParteLocal(const string& local) const;
    void validarDominio(const string& dominio) const;
    
public:
    // Construtor: cria um objeto Email já validado
    Email(const string& email);
    
    // Método set: modifica o email (com validação)
    void setValor(const string& email);
    
    // Método get: retorna o email (apenas leitura)
    string getValor() const;
};













#endif // DOMINIO_HPP_INCLUDED