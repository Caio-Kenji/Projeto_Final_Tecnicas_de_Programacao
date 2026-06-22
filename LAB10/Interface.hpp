#ifndef INTERFACE_HPP_INCLUDED
#define INTERFACE_HPP_INCLUDED

#include "Dominio.hpp
using namespace std;
//camada de apresentação
class IAAutenticacao{
    public:
        virtual bool autenticar(Email*) = 0;
        virtual ~IAAutenticacao(){};
};

//camada de serviços
class ISAutenticacao{
    public:
        virtual bool autenticar(const Email&, const Senha&) = 0;
        virtual ~ISAutenticacao(){};
};

#endif // INTERFACE_HPP_INCLUDED
