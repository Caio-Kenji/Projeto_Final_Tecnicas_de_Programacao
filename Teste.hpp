#ifndef TESTES_HPP_INCLUDED
#define TESTES_HPP_INCLUDED

#include<stdexcept>
#include"dominios.hpp"

using namespace std;

class TUCodigo: public Codigo {
private:
inline const static string VALOR_VALIDO = "AS007";
inline const static string VALOR_INVALIDO = "a0s071";
Codigo *codigo;
int estado;
void setUp();
void tearDown();
void testarCenarioValorValido();
void testarCenarioValorInvalido();
public:
const static int SUCESSO = 0;
const static int FALHA = -1;
int run();
};

class TUData: public Data {
private:
inline const static string VALOR_VALIDO = "25/01/2006";
inline const static string VALOR_INVALIDO = "29/02/2026";
Data *data;
int estado;
void setUp();
void tearDown();
void testarCenarioValorValido();
void testarCenarioValorInvalido();
public:
const static int SUCESSO = 0;
const static int FALHA = -1;
int run();
};

class TUEstado: public Estado {
private:
inline const static string VALOR_VALIDO = "A FAZER";
inline const static string VALOR_INVALIDO = "EM ANÁLISE";
Estado *estadoDominio;
int estado;
void setUp();
void tearDown();
void testarCenarioValorValido();
void testarCenarioValorInvalido();
public:
const static int SUCESSO = 0;
const static int FALHA = -1;
int run();
};

#endif // TESTES_HPP_INCLUDED
