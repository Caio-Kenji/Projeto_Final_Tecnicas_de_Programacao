#ifndef CONTROLADORA_HPP_INCLUDED
#define CONTROLADORA_HPP_INCLUDED

#include "Interfaces.hpp"
#include "Dominio.hpp"
#include "Entidade.hpp"


#define CLR_SCR system("cls");

//-----------------------------------------------------------------------------------//
//CONTROLADORAS DA CAMADA DE APRESENTAÇÃO
//-----------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------------
// Classe controladora de apresentação controle.

class CntrApresentacaoServicos{
    private:
        Email email;
        IAAutenticacao *cntrIAAutenticacao;
        IAPessoa *cntrIAPessoa;
        IAProjeto *cntrIAProjeto;
        IAPlanoSprint *cntrIAPlanoSprint;

    public:
        void executar();
        void setCntrIAAutenticacao(IAAutenticacao*);
        void setCntrIAPessoa(IAPessoa*);
        void setCntrIAProjeto(IAProjeto*);
        void setCntrIAPlanoSprint(IAPlanoSprint*);
};

inline void CntrApresentacaoServicos::setCntrIAAutenticacao(IAAutenticacao *cntr){
        cntrIAAutenticacao = cntr;
}

inline void CntrApresentacaoServicos::setCntrIAPessoa(IAPessoa *cntr){
        cntrIAPessoa = cntr;
}

inline void CntrApresentacaoServicos::setCntrIAProjeto(IAProjeto *cntr){
        cntrIAProjeto = cntr;
}

inline void CntrApresentacaoServicos::setCntrIAPlanoSprint(IAPlanoSprint *cntr){
        cntrIAPlanoSprint = cntr;
}


//--------------------------------------------------------------------------------
// Classe controladora de apresentação e autenticação.


class CntrIAAutenticacao:public IAAutenticacao {
private:
    ISAutenticacao *cntrSAutenticacao;
public:
    bool autenticar(Email*);
    void setCntrSAutenticacao(ISAutenticacao*);
};

void inline CntrIAAutenticacao::setCntrSAutenticacao(ISAutenticacao *cntrSAutenticacao){
    this->cntrSAutenticacao = cntrSAutenticacao;
}


//--------------------------------------------------------------------------------
// Classe controladora de apresentação de pessoa


class CntrIAPessoa : public IAPessoa {
private:
    ISPessoa *cntrSPessoa;
public:
    void criar();
    void executar(const Email&);
    void setCntrSPessoa(ISPessoa*);
};

//--------------------------------------------------------------------------------
// Classe controladora de apresentação de projeto


class CntrIAProjeto : public IAProjeto {
private:
    ISProjeto *cntrSProjeto;
public:
    void executar(const Email&);
    void setCntrSProjeto(ISProjeto*);
};


//--------------------------------------------------------------------------------
// Classe controladora de apresentação de plano de sprint



class CntrIAPlanoSprint : public IAPlanoSprint {
private:
    ISPlanoSprint *cntrSPlanoSprint;
public:
    void executar(const Email&);
    void setCntrSPlanoSprint(ISPlanoSprint*);
};

//-----------------------------------------------------------------------------------//
//CONTROLADORAS DA CAMADA DE SERVIÇOS
//-----------------------------------------------------------------------------------//



//--------------------------------------------------------------------------------
// Classe controladora de apresentação e autenticação.


class CntrSAutenticacao : public ISAutenticacao {
public:
    bool autenticar(const Email&, const Senha&);
};


//--------------------------------------------------------------------------------
// Classe controladora de apresentação de pessoa


class CntrServicoPessoa : public ISPessoa {
public:
    void criarPessoa(const string& email,
                     const string& nome,
                     const string& senha,
                     const string& papel);

    void consultarPessoa(const string& email);

    void atualizarPessoa(const string& email,
                         const string& nome,
                         const string& senha,
                         const string& papel);

    void excluirPessoa(const string& email);
};

//--------------------------------------------------------------------------------
// Classe controladora de apresentação de projeto


class CntrSProjeto : public ISProjeto {
public:
    bool criar(Projeto);
    bool ler(Projeto);
    bool atualizar(Projeto);
    bool excluir(Codigo);
};


//--------------------------------------------------------------------------------
// Classe controladora de apresentação de plano de sprint



class CntrSPlanoSprint : public ISPlanoSprint {
public:
    void criarPlanoSprint(const std::string& codigo,
                          int capacidade,
                          const std::string& dataInicio,
                          const std::string& dataTermino,
                          const std::string& codigoProjeto);

    void listarPlanosSprint();

    void consultarPlanoSprint(const std::string& codigo);

    void atualizarCapacidade(const std::string& codigo,
                             int novaCapacidade);

    void excluirPlanoSprint(const std::string& codigo);

    void associarHistoria(const std::string& codigoSprint,
                          const std::string& codigoHistoria,
                          int estimativa);

    void desassociarHistoria(const std::string& codigoSprint,
                             const std::string& codigoHistoria,
                             int estimativa);

    void listarHistoriasDoSprint(const std::string& codigoSprint);
};

#endif // CONTROLADORA_HPP_INCLUDED
