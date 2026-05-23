#include "testes.hpp"
#include"dominios.hpp"
//-----------------------------TUCodigo-----------------------------------
void TUCodigo::setUp(){
codigo = new Codigo();
estado = SUCESSO;
}

void TUCodigo::tearDown(){
delete codigo;
}

void TUCodigo::testarCenarioValorValido(){
try{
codigo->setValor(VALOR_VALIDO);
if (codigo->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUCodigo::testarCenarioValorInvalido(){
try{
codigo->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (codigo->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUCodigo::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}
//-----------------------------TUData-----------------------------------
void TUData::setUp(){
data = new Data();
estado = SUCESSO;
}

void TUData::tearDown(){
delete data;
}

void TUData::testarCenarioValorValido(){
try{
data->setValor(VALOR_VALIDO);
if (data->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUData::testarCenarioValorInvalido(){
try{
data->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (data->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUData::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}

//-----------------------------TUEstado-----------------------------------
void TUEstado::setUp(){
estadoDominio = new Estado();
estado = SUCESSO;
}

void TUEstado::tearDown(){
delete estadoDominio;
}

void TUEstado::testarCenarioValorValido(){
try{
estadoDominio->setValor(VALOR_VALIDO);
if (estadoDominio->getValor() != VALOR_VALIDO)
estado = FALHA;
}
catch(invalid_argument &excecao){
estado = FALHA;
}
}

void TUEstado::testarCenarioValorInvalido(){
try{
estadoDominio->setValor(VALOR_INVALIDO);
estado = FALHA;
}
catch(invalid_argument &excecao){
if (estadoDominio->getValor() == VALOR_INVALIDO)
estado = FALHA;
}
}

int TUEstado::run(){
setUp();
testarCenarioValorValido();
testarCenarioValorInvalido();
tearDown();
return estado;
}
