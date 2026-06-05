#include "Prioridade.h"
#include <string>

bool Prioridade::validar(string prioridade){


    if (prioridade == "ALTA" || prioridade == "MÉDIA" ||  prioridade == "MEDIA" || prioridade == "BAIXA"){
        return true;
    }
    else {
        return false;
    }
}

void Prioridade::set(string prioridade){
    if(validar(prioridade)){
        this->prioridade = prioridade;
    }
    else {
        cout << "Pralavra Inválida";
    }
}
