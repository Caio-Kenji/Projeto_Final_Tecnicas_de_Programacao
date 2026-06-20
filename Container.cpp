#include "Container.hpp"

#include "Container.hpp"

// MÉTODOS CONTEINER_PESSOA---------------------------------------------------------------
bool ContainerPessoa::criar(Pessoa pessoa){
    return containerPes.insert(make_pair(pessoa.getEmail().get(), pessoa)).second;
}

bool ContainerPessoa::excluir(Email email){
    map<string, Pessoa>::iterator it = containerPes.find(email.get());

    if(it != containerPes.end()){
        containerPes.erase(it);
        return true;
    }

    return false;
}

bool ContainerPessoa::ler(Pessoa* pessoa){
    map<string, Pessoa>::iterator it = containerPes.find(pessoa->getEmail().get());

    if(it != containerPes.end()){
        *pessoa = it->second;
        return true;
    }

    return false;
}

bool ContainerPessoa::atualizar(Pessoa pessoa){
    map<string, Pessoa>::iterator it = containerPes.find(pessoa.getEmail().get());

    if(it != containerPes.end()){
        it->second = pessoa;
        return true;
    }

    return false;
}

// MÉTODOS CONTEINER_PROJETO---------------------------------------------------------------

bool ContainerProjeto::criar(Projeto projeto){
    return containerPro.insert(make_pair(projeto.getCodigo().getValor(), projeto)).second;
}

bool ContainerProjeto::excluir(Codigo codigo){
    map<string, Projeto>::iterator it = containerPro.find(codigo.getValor());
    if(it != containerPro.end()){
            containerPro.erase(it);
        return true;
    }
    return false;
}

bool ContainerProjeto::ler(Projeto* projeto){
    map<string, Projeto>::iterator it = containerPro.find(projeto->getCodigo().getValor());
    if(it != containerPro.end()){
        *projeto = it->second;
        return true;
    }
    return false;
}

bool ContainerProjeto::atualizar(Projeto projeto){
    map<string, Projeto>::iterator it = containerPro.find(projeto.getCodigo().getValor());
    if(it != containerPro.end()){
        it->second = projeto;
        return true;
    }
    return false;
}

// MÉTODOS CONTEINER_PLANO_SPRINT---------------------------------------------------------------

bool ContainerPlanoSprint::criar(PlanoSprint plano_sprint){
    return containerPS.insert(make_pair(plano_sprint.getCodigo().getValor(), plano_sprint)).second;
}

bool ContainerPlanoSprint::excluir(Codigo codigo){
    map<string, PlanoSprint>::iterator it = containerPS.find(codigo.getValor());
    if(it != containerPS.end()){
            containerPS.erase(it);
        return true;
    }
    return false;
}

bool ContainerPlanoSprint::ler(PlanoSprint* plano_sprint){
    map<string, PlanoSprint>::iterator it = containerPS.find(plano_sprint->getCodigo().getValor());
    if(it != containerPS.end()){
        *plano_sprint = it->second;
        return true;
    }
    return false;
}

bool ContainerPlanoSprint::atualizar(PlanoSprint plano_sprint){
    map<string, PlanoSprint>::iterator it = containerPS.find(plano_sprint.getCodigo().getValor());
    if(it != containerPS.end()){
        it->second = plano_sprint;
        return true;
    }
    return false;
}

// ============================================
// MÉTODOS ADICIONAIS: CONTAINER PLANO SPRINT
// ============================================

bool ContainerPlanoSprint::existe(const string& codigo) const {
    return containerPS.find(codigo) != containerPS.end();
}

vector<PlanoSprint> ContainerPlanoSprint::listarTodas() const {
    vector<PlanoSprint> lista;
    for (const auto& par : containerPS) {
        lista.push_back(par.second);
    }
    return lista;
}

PlanoSprint* ContainerPlanoSprint::buscar(const string& codigo) {
    map<string, PlanoSprint>::iterator it = containerPS.find(codigo);
    if (it != containerPS.end()) {
        return &(it->second);
    }
    return nullptr;
}

const PlanoSprint* ContainerPlanoSprint::buscar(const string& codigo) const {
    map<string, PlanoSprint>::const_iterator it = containerPS.find(codigo);
    if (it != containerPS.end()) {
        return &(it->second);
    }
    return nullptr;
}





// MÉTODOS CONTEINER_HISTORIA_USUARIO---------------------------------------------------------------

bool ContainerHistoriaUsuario::criar(HistoriaUsuario historia_usuario){
    return containerHU.insert(make_pair(historia_usuario.getCodigo().getValor(), historia_usuario)).second;
}

bool ContainerHistoriaUsuario::excluir(Codigo codigo){
    map<string, HistoriaUsuario>::iterator it = containerHU.find(codigo.getValor());
    if(it != containerHU.end()){
            containerHU.erase(it);
        return true;
    }
    return false;
}

bool ContainerHistoriaUsuario::ler(HistoriaUsuario* historia_usuario){
    map<string, HistoriaUsuario>::iterator it = containerHU.find(historia_usuario->getCodigo().getValor());
    if(it != containerHU.end()){
        *historia_usuario = it->second;
        return true;
    }
    return false;
}

bool ContainerHistoriaUsuario::atualizar(HistoriaUsuario historia_usuario){
    map<string, HistoriaUsuario>::iterator it = containerHU.find(historia_usuario.getCodigo().getValor());
    if(it != containerHU.end()){
        it->second = historia_usuario;
        return true;
    }
    return false;
}