#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED

#include "Stub.hpp"

class CntrIAAutenticacao:public IAAutenticacao {
private:
ISAutenticacao *cntrSAutenticacao; // Referência para servidor.
public:
bool autenticar(Email*);
void setCntrSAutenticacao(ISAutenticacao*);
};
void inline CntrIAAutenticacao::setCntrSAutenticacao(ISAutenticacao *cntrSAutenticacao){
this->cntrSAutenticacao = cntrSAutenticacao;
}

#endif // CONTROLADORA_HPP_INCLUDED
