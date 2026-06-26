#ifndef SESSAO_HPP_INCLUDED
#define SESSAO_HPP_INCLUDED

#include <string>

using namespace std;

class Sessao {
public:
    static string emailLogado;
    static string papelLogado;
    static bool logout;
};

#endif