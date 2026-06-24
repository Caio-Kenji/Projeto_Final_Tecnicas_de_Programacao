#include "Container.hpp"

ContainerPessoa* ContainerPessoa::instancia = nullptr;
ContainerProjeto* ContainerProjeto::instancia = nullptr;
ContainerPlanoSprint* ContainerPlanoSprint::instancia = nullptr;
ContainerHistoriaUsuario* ContainerHistoriaUsuario::instancia = nullptr;

// MÉTODOS CONTEINER_PESSOA---------------------------------------------------------------

ContainerPessoa* ContainerPessoa::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerPessoa();
    return instancia;
}

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

ContainerProjeto* ContainerProjeto::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerProjeto();
    return instancia;
}

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

// ============================================
// MÉTODOS ADICIONAIS: CONTAINER PROJETO
// ============================================

bool ContainerProjeto::existe(const string& codigo) const {
    return containerPro.find(codigo) != containerPro.end();
}

vector<Projeto> ContainerProjeto::listarTodas() const {
    vector<Projeto> lista;
    for (const auto& par : containerPro) {
        lista.push_back(par.second);
    }
    return lista;
}

Projeto* ContainerProjeto::buscar(const string& codigo) {
    map<string, Projeto>::iterator it = containerPro.find(codigo);
    if (it != containerPro.end()) {
        return &(it->second);
    }
    return nullptr;
}

const Projeto* ContainerProjeto::buscar(const string& codigo) const {
    map<string, Projeto>::const_iterator it = containerPro.find(codigo);
    if (it != containerPro.end()) {
        return &(it->second);
    }
    return nullptr;
}













// MÉTODOS CONTEINER_PLANO_SPRINT---------------------------------------------------------------

ContainerPlanoSprint* ContainerPlanoSprint::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerPlanoSprint();
    return instancia;
}

bool ContainerPlanoSprint::criar(PlanoSprint plano_sprint){
    return containerPS.insert(make_pair(plano_sprint.getCodigo(), plano_sprint)).second;
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
    map<string, PlanoSprint>::iterator it = containerPS.find(plano_sprint->getCodigo());
    if(it != containerPS.end()){
        *plano_sprint = it->second;
        return true;
    }
    return false;
}

bool ContainerPlanoSprint::atualizar(PlanoSprint plano_sprint){
    map<string, PlanoSprint>::iterator it = containerPS.find(plano_sprint.getCodigo());
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

ContainerHistoriaUsuario* ContainerHistoriaUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerHistoriaUsuario();
    return instancia;
}

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


// ============================================
// MÉTODOS ADICIONAIS: CONTAINER HISTORIA USUARIO
// ============================================

bool ContainerHistoriaUsuario::existe(const string& codigo) const {
    return containerHU.find(codigo) != containerHU.end();
}

vector<HistoriaUsuario> ContainerHistoriaUsuario::listarTodas() const {
    vector<HistoriaUsuario> lista;
    for (const auto& par : containerHU) {
        lista.push_back(par.second);
    }
    return lista;
}

HistoriaUsuario* ContainerHistoriaUsuario::buscar(const string& codigo) {
    map<string, HistoriaUsuario>::iterator it = containerHU.find(codigo);
    if (it != containerHU.end()) {
        return &(it->second);
    }
    return nullptr;
}

const HistoriaUsuario* ContainerHistoriaUsuario::buscar(const string& codigo) const {
    map<string, HistoriaUsuario>::const_iterator it = containerHU.find(codigo);
    if (it != containerHU.end()) {
        return &(it->second);
    }
    return nullptr;
}

vector<HistoriaUsuario> ContainerHistoriaUsuario::listarPorProjeto(const string& codigoProjeto) const {
    vector<HistoriaUsuario> resultado;
    for (const auto& par : containerHU) {
        if (par.second.getCodigoProjeto().getValor() == codigoProjeto) {
            resultado.push_back(par.second);
        }
    }
    return resultado;
}