#include "Entidade.hpp"
using namespace std;

void Projeto::setCodigo(const Codigo& codigoNovo){
    codigo = codigoNovo;
}
void Projeto::setNome(const Nome& nomeNovo){
    nome = nomeNovo;
}
void Projeto::setDataInicio(const Data& dataInicio){
    data_inicio = dataInicio;
}
void Projeto::setDataTermino(const Data& dataTermino){
    data_termino = dataTermino;
}

