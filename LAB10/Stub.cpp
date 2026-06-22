#include "Stub.hpp"

    const static string StubISAutenticacao::TRIGGER_FALHA;
    const static string StubISAutenticacao::TRIGGER_ERRO_SISTEMA;

    bool StubSAutenticacao::autenticar(const Email& email, const Senha& senha){

        cout << endl << "StubSAutenticacao::autenticar" << endl ;
        cout << "Email = " << email.get() << endl ;
        cout << "Senha = " << senha.getSenha() << endl ;

        switch(matricula.getValor()){
            case TRIGGER_FALHA:
                return false;
            case TRIGGER_ERRO_SISTEMA:
                throw runtime_error("Erro de sistema");
        }
        return true;
    }
