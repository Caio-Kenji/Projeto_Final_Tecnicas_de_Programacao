#ifndef STUB_HPP_INCLUDED
#define STUB_HPP_INCLUDED

#include "Interface.hpp"
using namespace std;

class StubSAutenticacao:public ISAutenticacao{
    private:
        const static string TRIGGER_FALHA = "123456";
        const static string TRIGGER_ERRO_SISTEMA = "abcdef";
    public:
        bool autenticar(const Email&, const Senha&);
};

#endif // STUB_HPP_INCLUDED
