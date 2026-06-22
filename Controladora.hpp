#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED

#include "Interfaces.hpp"
#include "Dominio.hpp"

class CntrIAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao *cntrSAutenticacao;
public:
    bool autenticar(Email*);
    void setCntrSAutenticacao(ISAutenticacao*);
};

void inline CntrIAAutenticacao::setCntrSAutenticacao(ISAutenticacao *cntrSAutenticacao){
    this->cntrSAutenticacao = cntrSAutenticacao;
}

#endif // CONTROLADORA_HPP_INCLUDED
