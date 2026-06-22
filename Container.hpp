#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

// incluir cabeçalhos do projeto se faltarem
#include "Dominio.hpp"
#include "Entidade.hpp"

#include <map>

// ----------------------------------------------------------------------

class ContainerPessoa{
private:
    map<string, Pessoa> containerPes;
    static ContainerPessoa *instancia;
    ContainerPessoa(){};
public:
    static ContainerPessoa* getInstancia();
    bool criar(Pessoa);
    bool excluir(Email);
    bool ler(Pessoa*);
    bool atualizar(Pessoa);
};

// ----------------------------------------------------------------------

class ContainerProjeto{
private:
    map<string, Projeto> containerPro;
    static ContainerProjeto *instancia;
    ContainerProjeto(){};
public:
    static ContainerProjeto* getInstancia();
    bool criar(Projeto);
    bool excluir(Codigo);
    bool ler(Projeto*);
    bool atualizar(Projeto);
};

// ----------------------------------------------------------------------

class ContainerPlanoSprint{
private:
    map<string, PlanoSprint> containerPS;
    static ContainerPlanoSprint *instancia;
    ContainerPlanoSprint(){};
public:
    static ContainerPlanoSprint* getInstancia();
    bool criar(PlanoSprint);
    bool excluir(Codigo);
    bool ler(PlanoSprint*);
    bool atualizar(PlanoSprint);

    // Métodos ADICIONAIS que o serviço precisa
    bool existe(const string& codigo) const;
    vector<PlanoSprint> listarTodas() const;
    PlanoSprint* buscar(const string& codigo);
    const PlanoSprint* buscar(const string& codigo) const;



};

// ----------------------------------------------------------------------

class ContainerHistoriaUsuario{
private:
    map<string, HistoriaUsuario> containerHU;
    static ContainerHistoriaUsuario *instancia;
    ContainerHistoriaUsuario(){};
public:
    static ContainerHistoriaUsuario* getInstancia();
    bool criar(HistoriaUsuario);
    bool excluir(Codigo);
    bool ler(HistoriaUsuario*);
    bool atualizar(HistoriaUsuario);
};


#endif // CONTAINER_HPP_INCLUDED