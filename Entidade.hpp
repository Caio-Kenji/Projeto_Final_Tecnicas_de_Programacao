#ifndef ENTIDADE_HPP_INCLUDED
#define ENTIDADE_HPP_INCLUDED

#include "Dominio.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>
#include <stdexcept>
using namespace std;

// ----------------DEFINIÇÕES: PROJETO ------------------------------------------


/**
 * @brief Classe que representa uma atividade identificada por um nome e um código, além de um início e fim.
 *
 * @details A classe Projeto é uma entidade que agrupa informações relacionadas
 *          a um projeto:
 *          - Código: identificador único do projeto (formato: 2 letras + 3 números)
 *          - Nome: designação textual do projeto (máximo 10 caracteres)
 *          - Data de início: quando o projeto começa (formato: DD/MM/AAAA)
 *          - Data de término: quando o projeto termina (formato: DD/MM/AAAA)
 *
 * @invariant Todos os atributos (codigo, nome, data_inicio, data_termino)
 *            sempre armazenam valores válidos, pois são instâncias de classes
 *            de domínio que validam seus valores internamente.
 *
 * @note Esta classe segue o princípio de encapsulamento, fornecendo métodos
 *       públicos de acesso (getters/setters) para cada atributo.
 *
 * @see Codigo, Nome, Data
 */
class Projeto{
private:
    Codigo codigo;
    Nome nome;
    Data data_inicio, data_termino;
    Email email_proprietario, email_mestre;

public:

     /**
     * @brief Define o código identificador do projeto.
     * @param codigo Objeto Codigo válido a ser atribuído.
     * @post O atributo codigo é atualizado com o valor informado.
     * @see Codigo::validar()
     */
    void setCodigo(const Codigo&);

     /**
     * @brief Define o nome do projeto.
     * @param nome Objeto Nome válido a ser atribuído.
     * @post O atributo nome é atualizado com o valor informado.
     * @see Nome::setNome()
     */
    void setNome(const Nome&);

     /**
     * @brief Define a data de início do projeto.
     * @param data_inicio Objeto Data válido a ser atribuído.
     * @post O atributo data_inicio é atualizado com o valor informado.
     * @see Data::validar()
     */
    void setDataInicio(const Data&);

     /**
     * @brief Define a data de término do projeto.
     * @param data_termino Objeto Data válido a ser atribuído.
     * @post O atributo data_termino é atualizado com o valor informado.
     * @see Data::validar()
     */
    void setDataTermino(const Data&);

     /**
     * @brief Define o email do proprietário do projeto.
     * @param email_proprietario Objeto Email válido a ser atribuído.
     * @post O atributo email_proprietario é atualizado com o valor informado.
     * @see Email::validar()
     */
    void setProprietario(const Email&);

     /**
     * @brief Define o email do mestre scrum do projeto.
     * @param email_mestre Objeto Email válido a ser atribuído.
     * @post O atributo email_mestre é atualizado com o valor informado.
     * @see Email::validar()
     */
    void setMestre(const Email&);// documentar

    /**
     * @brief Retorna o código do projeto.
     * @return Codigo Objeto Codigo contendo o código do projeto.
     * @see setCodigo()
     */
    Codigo getCodigo() const;

    /**
     * @brief Retorna o nome do projeto.
     * @return Nome Objeto Nome contendo o nome do projeto.
     * @see setNome()
     */
    Nome getNome() const;

     /**
     * @brief Retorna a data de início do projeto.
     * @return Data Objeto Data contendo a data de início.
     * @see setDataInicio()
     */
    Data getDataInicio() const;

     /**
     * @brief Retorna a data de término do projeto.
     * @return Data Objeto Data contendo a data de término.
     * @see setDataTermino()
     */
    Data getDataTermino() const;


     /**
     * @brief Retorna o email do proprietário do projeto.
     * @return Email Objeto Email contendo o email do proprietário.
     * @see setProprietario()
     */
    Email getProprietario() const;

     /**
     * @brief Retorna o email do mestre do projeto.
     * @return Email Objeto Email contendo o email do mestre.
     * @see setMestre()
     */
    Email getMestre() const;//documentar

};

/**
 * @brief Retorna o código do projeto.
 * @details Implementação inline que retorna uma cópia do atributo codigo.
 * @return Codigo Cópia do código armazenado.
 */
inline Codigo Projeto::getCodigo() const{
    return codigo;
}

/**
 * @brief Retorna o nome do projeto.
 * @details Implementação inline que retorna uma cópia do atributo nome.
 * @return Nome Cópia do nome armazenado.
 */
inline Nome Projeto::getNome() const{
    return nome;
}

/**
 * @brief Retorna a data de início do projeto.
 * @details Implementação inline que retorna uma cópia do atributo data_inicio.
 * @return Data Cópia da data de início armazenada.
 */
inline Data Projeto::getDataInicio() const{
    return data_inicio;
}

/**
 * @brief Retorna a data de término do projeto.
 * @details Implementação inline que retorna uma cópia do atributo data_termino.
 * @return Data Cópia da data de término armazenada.
 */
inline Data Projeto::getDataTermino() const{
    return data_termino;
}

/**
 * @brief Retorna o email do proprietário do projeto.
 * @details Implementação inline que retorna uma cópia do atributo email_proprietario.
 * @return Email Cópia do email do proprietário armazenado.
 * @see setProprietario()
 */
inline Email Projeto::getProprietario() const{
    return email_proprietario;
}

/**
 * @brief Retorna o email do mestre do projeto.
 * @details Implementação inline que retorna uma cópia do atributo email_mestre.
 * @return Email Cópia do email do mestre armazenado.
 * @see setMestre()
 */
inline Email Projeto::getMestre() const{
    return email_mestre;
}


// ----------------DEFINIÇÕES: PESSOA ------------------------------------------


/**
 * @brief Classe que representa uma pessoa cadastrada no sistema.
 *
 * @details A classe Pessoa é uma entidade que agrupa informações
 *          relacionadas a um usuário do sistema:
 *          - Email: identificador único da pessoa.
 *          - Nome: nome da pessoa.
 *          - Senha: credencial utilizada para autenticação.
 *          - Papel: função desempenhada no projeto
 *            (Desenvolvedor, Mestre Scrum ou Proprietário de Produto).
 *
 * @invariant Todos os atributos (email, nome, senha e papel)
 *            sempre armazenam valores válidos, pois são instâncias
 *            de classes de domínio que validam seus valores
 *            internamente.
 *
 * @note Esta classe segue o princípio de encapsulamento,
 *       fornecendo métodos públicos de acesso (getters e setters)
 *       para cada atributo.
 *
 * @see Email, Nome, Senha, Papel
 */
class Pessoa {
private:

    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

public:

    /**
     * @brief Constrói uma pessoa com os dados informados.
     *
     * @param email Email válido da pessoa.
     * @param nome Nome válido da pessoa.
     * @param senha Senha válida da pessoa.
     * @param papel Papel válido da pessoa.
     *
     * @post Uma instância de Pessoa é criada com os atributos
     *       inicializados pelos valores fornecidos.
     */
    Pessoa(const Email&,
           const Nome&,
           const Senha&,
           const Papel&);

    /**
     * @brief Define o email da pessoa.
     *
     * @param email Objeto Email válido a ser atribuído.
     *
     * @post O atributo email é atualizado com o valor informado.
     *
     * @see Email
     */
    void setEmail(const Email&);

    /**
     * @brief Define o nome da pessoa.
     *
     * @param nome Objeto Nome válido a ser atribuído.
     *
     * @post O atributo nome é atualizado com o valor informado.
     *
     * @see Nome
     */
    void setNome(const Nome&);

    /**
     * @brief Define a senha da pessoa.
     *
     * @param senha Objeto Senha válido a ser atribuído.
     *
     * @post O atributo senha é atualizado com o valor informado.
     *
     * @see Senha
     */
    void setSenha(const Senha&);

    /**
     * @brief Define o papel da pessoa.
     *
     * @param papel Objeto Papel válido a ser atribuído.
     *
     * @post O atributo papel é atualizado com o valor informado.
     *
     * @see Papel
     */
    void setPapel(const Papel&);

    /**
     * @brief Retorna o email da pessoa.
     *
     * @return Email Objeto Email contendo o email da pessoa.
     *
     * @see setEmail()
     */
    Email getEmail() const;

    /**
     * @brief Retorna o nome da pessoa.
     *
     * @return Nome Objeto Nome contendo o nome da pessoa.
     *
     * @see setNome()
     */
    Nome getNome() const;

    /**
     * @brief Retorna a senha da pessoa.
     *
     * @return Senha Objeto Senha contendo a senha da pessoa.
     *
     * @see setSenha()
     */
    Senha getSenha() const;

    /**
     * @brief Retorna o papel da pessoa.
     *
     * @return Papel Objeto Papel contendo o papel da pessoa.
     *
     * @see setPapel()
     */
    Papel getPapel() const;
};


/**
 * @brief Retorna o email da pessoa.
 *
 * @details Implementação inline que retorna uma cópia
 *          do atributo email.
 *
 * @return Email Cópia do email armazenado.
 */
inline Email Pessoa::getEmail() const{
    return email;
}

/**
 * @brief Retorna o nome da pessoa.
 *
 * @details Implementação inline que retorna uma cópia
 *          do atributo nome.
 *
 * @return Nome Cópia do nome armazenado.
 */
inline Nome Pessoa::getNome() const{
    return nome;
}

/**
 * @brief Retorna a senha da pessoa.
 *
 * @details Implementação inline que retorna uma cópia
 *          do atributo senha.
 *
 * @return Senha Cópia da senha armazenada.
 */
inline Senha Pessoa::getSenha() const{
    return senha;
}

/**
 * @brief Retorna o papel da pessoa.
 *
 * @details Implementação inline que retorna uma cópia
 *          do atributo papel.
 *
 * @return Papel Cópia do papel armazenado.
 */
inline Papel Pessoa::getPapel() const{
    return papel;
}








// ----------------DEFINIÇÕES: PLANOS DE SPRINT---------------------------------------------------------------------





/**
 * @brief Representa um plano de sprint dentro de um projeto.
 * 
 * @details Um sprint é um período de tempo fixo onde um conjunto de histórias
 *          de usuário é executado. Esta classe gerencia:
 *          - Identificação única do sprint (código)
 *          - Capacidade em dias (1-365)
 *          - Período de execução (data início e fim)
 *          - Relação com o projeto pai
 *          - Associação com histórias de usuário
 * 
 * @invariant O código do plano de sprint é único no sistema.
 * @invariant A capacidade deve estar entre 1 e 365 dias.
 * @invariant A data de início deve ser anterior à data de término.
 * @invariant A soma das estimativas das histórias ≤ capacidade.
 * 
 * @note As regras de negócio sobre capacidade vs estimativas são
 *       verificadas nos métodos associarHistoria() e desassociarHistoria().
 * 
 * @see Codigo, Tempo, Data, HistoriaUsuario
 */
class PlanoSprint {
private:
    Codigo codigo;              ///< Identificador único do plano de sprint
    Tempo capacidade;           ///< Capacidade do sprint em dias (1-365)
    Data dataInicio;            ///< Data de início do sprint (formato DD/MM/AAAA)
    Data dataTermino;           ///< Data de término do sprint (formato DD/MM/AAAA)
    Codigo codigoProjeto;       ///< Código do projeto a que pertence
    
    /**
     * @brief Lista de códigos das histórias de usuário associadas.
     * @details Vetor que armazena os códigos das histórias alocadas para este sprint.
     *          Mantido em paralelo com o vetor 'estimativas'.
     */
    vector<string> historiasAssociadas;
    
    /**
     * @brief Lista de estimativas das histórias associadas.
     * @details Vetor paralelo a 'historiasAssociadas' onde cada posição
     *          armazena a estimativa (em dias) da história correspondente.
     */
    vector<int> estimativas;
    
    /**
     * @brief Soma total das estimativas das histórias associadas.
     * @details Mantido atualizado para validação rápida (O(1) em vez de O(n)).
     *          Quando uma história é associada, somaEstimativas += estimativa.
     *          Quando removida, somaEstimativas -= estimativa.
     */
    int somaEstimativas;

public:
    /**
     * @brief Construtor da classe PlanoSprint.
     * @param codigoStr Código do plano de sprint (2 letras + 3 dígitos).
     * @param capacidadeInt Capacidade em dias (1-365).
     * @param dataInicioStr Data de início do sprint (DD/MM/AAAA).
     * @param dataTerminoStr Data de término do sprint (DD/MM/AAAA).
     * @param codigoProjetoStr Código do projeto associado (2 letras + 3 dígitos).
     * @throw invalid_argument Se algum domínio for inválido (repassado pelos domínios).
     * 
     * @post Um objeto PlanoSprint válido é criado com somaEstimativas = 0.
     */
    PlanoSprint(const string& codigoStr, int capacidadeInt,
                const string& dataInicioStr, const string& dataTerminoStr,
                const string& codigoProjetoStr);
    
    // ========== GETTERS ==========
    
    /**
     * @brief Retorna o código do plano de sprint.
     * @return string Código no formato "XX999".
     */
    string getCodigo() const;
    
    /**
     * @brief Retorna a capacidade do sprint em dias.
     * @return int Valor entre 1 e 365.
     */
    int getCapacidade() const;
    
    /**
     * @brief Retorna a data de início do sprint.
     * @return string Data no formato "DD/MM/AAAA".
     */
    string getDataInicio() const;
    
    /**
     * @brief Retorna a data de término do sprint.
     * @return string Data no formato "DD/MM/AAAA".
     */
    string getDataTermino() const;
    
    /**
     * @brief Retorna o código do projeto associado.
     * @return string Código do projeto no formato "XX999".
     */
    string getCodigoProjeto() const;
    
    /**
     * @brief Retorna a lista de códigos das histórias associadas.
     * @return const vector<string>& Referência constante para o vetor interno.
     * @note Retorna referência const para evitar cópias e impedir modificações diretas.
     */
    const vector<string>& getHistoriasAssociadas() const;
    
    /**
     * @brief Retorna a soma atual das estimativas das histórias associadas.
     * @return int Soma das estimativas em dias.
     */
    int getSomaEstimativas() const;
    
    // ========== SETTERS ==========
    
    /**
     * @brief Define um novo código para o plano de sprint.
     * @param novoCodigo Novo código no formato "XX999".
     * @throw invalid_argument Se o código for inválido.
     * @post O atributo codigo é atualizado apenas se a validação for bem-sucedida.
     */
    void setCodigo(const string& novoCodigo);
    
    /**
     * @brief Define uma nova capacidade para o sprint.
     * @param novaCapacidade Novo valor entre 1 e 365.
     * @throw invalid_argument Se a capacidade for inválida.
     * @throw runtime_error Se a nova capacidade for menor que a soma das estimativas.
     * @post A capacidade é atualizada apenas se for ≥ somaEstimativas.
     */
    void setCapacidade(int novaCapacidade);
    
    /**
     * @brief Define uma nova data de início para o sprint.
     * @param novaData Data no formato "DD/MM/AAAA".
     * @throw invalid_argument Se a data for inválida.
     */
    void setDataInicio(const string& novaData);
    
    /**
     * @brief Define uma nova data de término para o sprint.
     * @param novaData Data no formato "DD/MM/AAAA".
     * @throw invalid_argument Se a data for inválida.
     */
    void setDataTermino(const string& novaData);
    
    /**
     * @brief Define um novo projeto associado ao sprint.
     * @param novoCodigo Código do projeto no formato "XX999".
     * @throw invalid_argument Se o código for inválido.
     */
    void setCodigoProjeto(const string& novoCodigo);
    
    // ========== GERENCIAMENTO DE HISTÓRIAS ==========
    
    /**
     * @brief Associa uma história de usuário a este plano de sprint.
     * @param codigoHistoria Código da história a ser associada (formato "XX999").
     * @param estimativa Estimativa de esforço da história em dias (1-365).
     * @throw invalid_argument Se o código da história ou estimativa forem inválidos.
     * @throw runtime_error Se a história já estiver associada.
     * @throw runtime_error Se a capacidade do sprint for excedida.
     * @post A história é adicionada ao vetor e a somaEstimativas é atualizada.
     * 
     * @note Esta é uma operação O(1) (apenas push_back no vetor).
     */
    void associarHistoria(const string& codigoHistoria, int estimativa);
    
    /**
     * @brief Remove a associação de uma história com este plano de sprint.
     * @param codigoHistoria Código da história a ser removida.
     * @param estimativa Estimativa da história (para verificação de consistência).
     * @return true se a história foi encontrada e removida, false caso contrário.
     * @throw runtime_error Se a estimativa fornecida não corresponder à armazenada.
     * @post Se encontrada, a história é removida e a somaEstimativas é atualizada.
     * 
     * @note A complexidade é O(n) onde n é o número de histórias associadas.
     */
    bool desassociarHistoria(const string& codigoHistoria, int estimativa);
    
    /**
     * @brief Verifica se uma história está associada a este sprint.
     * @param codigoHistoria Código da história a verificar.
     * @return true se a história está associada, false caso contrário.
     * @note Complexidade O(n) onde n é o número de histórias associadas.
     */
    bool temHistoria(const string& codigoHistoria) const;
    
    /**
     * @brief Calcula a soma total das estimativas percorrendo o vetor.
     * @return int Soma das estimativas (pode ser usada para testes).
     * @note Este método recalcula do zero, diferentemente de getSomaEstimativas()
     *       que retorna o valor mantido internamente.
     */
    int calcularSomaEstimativas() const;
};


<<<<<<< HEAD
#endif // ENTIDADE_HPP_INCLUDED
=======


// -------------------DEFINIÇÕES: PESSOA -------------------------------------------------------------------------------




// ============================================
// CLASSE PESSOA (COMPLETA E DOCUMENTADA)
// ============================================

/**
 * @brief Classe que representa uma pessoa (usuário) cadastrada no sistema.
 *
 * @details A classe Pessoa é uma entidade que agrupa informações
 *          relacionadas a um usuário do sistema Scrum:
 *          - **Email**: identificador único da pessoa (domínio Email)
 *          - **Nome**: nome completo da pessoa (domínio Nome)
 *          - **Senha**: credencial para autenticação (domínio Senha)
 *          - **Papel**: função no projeto (domínio Papel)
 *
 * @invariant Todos os atributos (email, nome, senha e papel)
 *            sempre armazenam valores válidos, pois são instâncias
 *            de classes de domínio que validam seus valores internamente.
 *
 * @invariant O email é único no sistema (verificado na camada de serviço).
 *
 * @note Esta classe segue o princípio de encapsulamento,
 *       fornecendo métodos públicos de acesso (getters e setters)
 *       para cada atributo.
 *
 * @see Email, Nome, Senha, Papel
 * @see ServicoPessoa
 *
 * @example
 * @code
 * try {
 *     Email email("ana@empresa.com");
 *     Nome nome;
 *     nome.setNome("Ana Silva");
 *     Senha senha;
 *     senha.setSenha("a1B2c3");
 *     Papel papel("DESENVOLVEDOR");
 *     
 *     Pessoa pessoa(email, nome, senha, papel);
 *     cout << "Pessoa criada: " << pessoa.getNome().getNome() << endl;
 * } catch (const invalid_argument& e) {
 *     cout << "Erro: " << e.what() << endl;
 * }
 * @endcode
 */
class Pessoa {
private:
    /** @brief Email da pessoa (identificador único) */
    Email email;
    
    /** @brief Nome da pessoa */
    Nome nome;
    
    /** @brief Senha da pessoa (para autenticação) */
    Senha senha;
    
    /** @brief Papel da pessoa no projeto Scrum */
    Papel papel;

public:
    // ========== CONSTRUTORES ==========

    /**
     * @brief Constrói uma pessoa com os dados informados.
     *
     * @param emailNovo Objeto Email válido da pessoa.
     * @param nomeNovo Objeto Nome válido da pessoa.
     * @param senhaNova Objeto Senha válida da pessoa.
     * @param papelNovo Objeto Papel válido da pessoa.
     *
     * @post Uma instância de Pessoa é criada com os atributos
     *       inicializados pelos valores fornecidos.
     *
     * @note Os objetos de domínio já foram validados antes de serem passados.
     *
     * @see Email, Nome, Senha, Papel
     */
    Pessoa(const Email& emailNovo,
           const Nome& nomeNovo,
           const Senha& senhaNova,
           const Papel& papelNovo);

    // ========== SETTERS ==========

    /**
     * @brief Define o email da pessoa.
     *
     * @param emailNovo Objeto Email válido a ser atribuído.
     *
     * @post O atributo email é atualizado com o valor informado.
     *
     * @see Email
     */
    void setEmail(const Email& emailNovo);

    /**
     * @brief Define o nome da pessoa.
     *
     * @param nomeNovo Objeto Nome válido a ser atribuído.
     *
     * @post O atributo nome é atualizado com o valor informado.
     *
     * @see Nome
     */
    void setNome(const Nome& nomeNovo);

    /**
     * @brief Define a senha da pessoa.
     *
     * @param senhaNova Objeto Senha válido a ser atribuído.
     *
     * @post O atributo senha é atualizado com o valor informado.
     *
     * @see Senha
     */
    void setSenha(const Senha& senhaNova);

    /**
     * @brief Define o papel da pessoa.
     *
     * @param papelNovo Objeto Papel válido a ser atribuído.
     *
     * @post O atributo papel é atualizado com o valor informado.
     *
     * @see Papel
     */
    void setPapel(const Papel& papelNovo);

    // ========== GETTERS ==========

    /**
     * @brief Retorna o email da pessoa.
     *
     * @return Email Objeto Email contendo o email da pessoa.
     *
     * @note Método constante (não modifica o objeto).
     *
     * @see setEmail()
     */
    Email getEmail() const;

    /**
     * @brief Retorna o nome da pessoa.
     *
     * @return Nome Objeto Nome contendo o nome da pessoa.
     *
     * @note Método constante (não modifica o objeto).
     *
     * @see setNome()
     */
    Nome getNome() const;

    /**
     * @brief Retorna a senha da pessoa.
     *
     * @return Senha Objeto Senha contendo a senha da pessoa.
     *
     * @note Método constante (não modifica o objeto).
     *
     * @see setSenha()
     */
    Senha getSenha() const;

    /**
     * @brief Retorna o papel da pessoa.
     *
     * @return Papel Objeto Papel contendo o papel da pessoa.
     *
     * @note Método constante (não modifica o objeto).
     *
     * @see setPapel()
     */
    Papel getPapel() const;
};

// ============================================
// MÉTODOS INLINE: PESSOA
// ============================================

/**
 * @brief Retorna o email da pessoa.
 * @details Implementação inline que retorna uma cópia do atributo email.
 * @return Email Cópia do email armazenado.
 */
inline Email Pessoa::getEmail() const {
    return email;
}

/**
 * @brief Retorna o nome da pessoa.
 * @details Implementação inline que retorna uma cópia do atributo nome.
 * @return Nome Cópia do nome armazenado.
 */
inline Nome Pessoa::getNome() const {
    return nome;
}

/**
 * @brief Retorna a senha da pessoa.
 * @details Implementação inline que retorna uma cópia do atributo senha.
 * @return Senha Cópia da senha armazenada.
 */
inline Senha Pessoa::getSenha() const {
    return senha;
}

/**
 * @brief Retorna o papel da pessoa.
 * @details Implementação inline que retorna uma cópia do atributo papel.
 * @return Papel Cópia do papel armazenado.
 */
inline Papel Pessoa::getPapel() const {
    return papel;
}








// --------------DEFINIÇÕES: HISTÓRIA DE USUÁRIO --------------------------------------------------------------------------









// ============================================
// CLASSE HISTORIA USUARIO (ATUALIZADA)
// ============================================

/**
 * @brief Classe que representa uma história de usuário (User Story) no sistema.
 *
 * @details A classe HistoriaUsuario é uma entidade que descreve uma funcionalidade
 *          sob a perspectiva do usuário, seguindo o formato:
 *          **"Como [papel], eu quero [ação] para [valor]"**
 *
 *          Cada história pertence a um projeto e pode ser:
 *          - Associada a um plano de sprint (quando em execução)
 *          - Atribuída a uma pessoa (desenvolvedor responsável)
 *
 *          Seu estado evolui ao longo do desenvolvimento: A FAZER → FAZENDO → FEITO.
 *
 * @invariant Todos os atributos armazenam valores válidos, pois são instâncias
 *            de classes de domínio que validam seus valores internamente.
 * @invariant O código da história é único no sistema.
 * @invariant O código do projeto associado deve existir no sistema.
 * @invariant O estado inicial de uma história é sempre "A FAZER".
 *
 * @note As regras de negócio sobre capacidade vs estimativas são
 *       verificadas na camada de serviço (ServicoPlanoSprint).
 *
 * @see Codigo, Nome, Texto, Prioridade, Estado, Tempo
 * @see ServicoHistoriaUsuario
 * @see PlanoSprint
 * @see Pessoa
 *
 * @example
 * @code
 * try {
 *     Codigo codigo("US001");
 *     Nome nome;
 *     nome.setNome("Login");
 *     Texto descricao;
 *     descricao.setValor("Como usuario, eu quero fazer login para acessar o sistema");
 *     Prioridade prioridade("ALTA");
 *     Estado estado("A FAZER");
 *     Codigo codigoProjeto("PR001");
 *     Tempo estimativa;
 *     estimativa.setTempo(5);
 *     Codigo codigoPessoa("AD001");
 *     Codigo codigoSprint("SP001");
 *
 *     HistoriaUsuario historia(codigo, nome, descricao, prioridade,
 *                              estado, codigoProjeto, estimativa,
 *                              codigoPessoa, codigoSprint);
 *     cout << "Historia criada: " << historia.getNome().getNome() << endl;
 * } catch (const invalid_argument& e) {
 *     cout << "Erro: " << e.what() << endl;
 * }
 * @endcode
 */
class HistoriaUsuario {
private:
    /** @brief Código identificador único da história (formato: 2 letras + 3 dígitos) */
    Codigo codigo;

    /** @brief Nome/título resumido da história (máximo 10 caracteres) */
    Nome nome;

    /** @brief Descrição completa no formato "Como [papel], eu quero [ação] para [valor]" */
    Texto descricao;

    /** @brief Prioridade da história (ALTA, MEDIA, BAIXA) */
    Prioridade prioridade;

    /** @brief Estado atual da história (A FAZER, FAZENDO, FEITO) */
    Estado estado;

    /** @brief Código do projeto a que pertence (relacionamento com Projeto) */
    Codigo codigoProjeto;

    /** @brief Estimativa de esforço em dias (1-365) */
    Tempo estimativa;

    /** @brief Código da pessoa (desenvolvedor) responsável pela história */
    Codigo codigoPessoa;

    /** @brief Código do plano de sprint ao qual a história está associada */
    Codigo codigoPlanoSprint;

public:
    // ========== CONSTRUTOR ==========

    /**
     * @brief Construtor da classe HistoriaUsuario.
     *
     * @param codigoObj Código da história (2 letras + 3 dígitos).
     * @param nomeObj Nome/título da história (até 10 caracteres).
     * @param descricaoObj Descrição completa da história (até 40 caracteres).
     * @param prioridadeObj Prioridade (ALTA, MEDIA, BAIXA).
     * @param estadoObj Estado inicial (deve ser "A FAZER").
     * @param codigoProjetoObj Código do projeto associado.
     * @param estimativaObj Estimativa em dias (1-365).
     * @param codigoPessoaObj Código da pessoa responsável (opcional - pode ser vazio).
     * @param codigoPlanoSprintObj Código do sprint associado (opcional - pode ser vazio).
     *
     * @throw invalid_argument Se algum domínio for inválido (repassado pelos domínios).
     *
     * @post Um objeto HistoriaUsuario válido é criado com todos os atributos
     *       validados pelos respectivos domínios.
     *
     * @note O estado inicial deve ser "A FAZER". Alterações de estado
     *       devem ser feitas através do método setEstado().
     * @note Os códigos de pessoa e sprint podem ser vazios ("") inicialmente.
     */
    HistoriaUsuario(const Codigo& codigoObj,
                    const Nome& nomeObj,
                    const Texto& descricaoObj,
                    const Prioridade& prioridadeObj,
                    const Estado& estadoObj,
                    const Codigo& codigoProjetoObj,
                    const Tempo& estimativaObj,
                    const Codigo& codigoPessoaObj = Codigo(),
                    const Codigo& codigoPlanoSprintObj = Codigo());

    // ========== GETTERS ==========

    /**
     * @brief Retorna o código da história.
     * @return Codigo Objeto Codigo contendo o código.
     * @note Método constante (não modifica o objeto).
     */
    Codigo getCodigo() const;

    /**
     * @brief Retorna o nome da história.
     * @return Nome Objeto Nome contendo o título.
     * @note Método constante (não modifica o objeto).
     */
    Nome getNome() const;

    /**
     * @brief Retorna a descrição da história.
     * @return Texto Objeto Texto contendo a descrição completa.
     * @note Método constante (não modifica o objeto).
     */
    Texto getDescricao() const;

    /**
     * @brief Retorna a prioridade da história.
     * @return Prioridade Objeto Prioridade contendo o valor.
     * @note Método constante (não modifica o objeto).
     */
    Prioridade getPrioridade() const;

    /**
     * @brief Retorna o estado atual da história.
     * @return Estado Objeto Estado contendo o valor atual.
     * @note Método constante (não modifica o objeto).
     */
    Estado getEstado() const;

    /**
     * @brief Retorna o código do projeto associado.
     * @return Codigo Objeto Codigo contendo o código do projeto.
     * @note Método constante (não modifica o objeto).
     */
    Codigo getCodigoProjeto() const;

    /**
     * @brief Retorna a estimativa de esforço da história.
     * @return Tempo Objeto Tempo contendo a estimativa em dias.
     * @note Método constante (não modifica o objeto).
     */
    Tempo getEstimativa() const;

    /**
     * @brief Retorna o código da pessoa (desenvolvedor) responsável.
     * @return Codigo Objeto Codigo contendo o código da pessoa.
     * @note Método constante (não modifica o objeto).
     * @note Retorna código vazio ("") se não houver responsável atribuído.
     */
    Codigo getCodigoPessoa() const;

    /**
     * @brief Retorna o código do plano de sprint associado.
     * @return Codigo Objeto Codigo contendo o código do sprint.
     * @note Método constante (não modifica o objeto).
     * @note Retorna código vazio ("") se não houver sprint associado.
     */
    Codigo getCodigoPlanoSprint() const;

    // ========== SETTERS ==========

    /**
     * @brief Define um novo código para a história.
     * @param novoCodigo Objeto Codigo válido.
     * @post O atributo codigo é atualizado.
     * @throw invalid_argument Se o código for inválido (repassado pelo domínio).
     */
    void setCodigo(const Codigo& novoCodigo);

    /**
     * @brief Define um novo nome para a história.
     * @param novoNome Objeto Nome válido.
     * @post O atributo nome é atualizado.
     * @throw invalid_argument Se o nome for inválido (repassado pelo domínio).
     */
    void setNome(const Nome& novoNome);

    /**
     * @brief Define uma nova descrição para a história.
     * @param novaDescricao Objeto Texto válido.
     * @post O atributo descricao é atualizado.
     * @throw invalid_argument Se a descrição for inválida (repassado pelo domínio).
     */
    void setDescricao(const Texto& novaDescricao);

    /**
     * @brief Define uma nova prioridade para a história.
     * @param novaPrioridade Objeto Prioridade válido.
     * @post O atributo prioridade é atualizado.
     * @throw invalid_argument Se a prioridade for inválida (repassado pelo domínio).
     */
    void setPrioridade(const Prioridade& novaPrioridade);

    /**
     * @brief Define um novo estado para a história.
     * @param novoEstado Objeto Estado válido.
     * @post O atributo estado é atualizado.
     * @throw invalid_argument Se o estado for inválido (repassado pelo domínio).
     *
     * @note A transição de estado deve seguir a ordem:
     *       A FAZER → FAZENDO → FEITO (não é possível retroceder).
     *       Essa regra é aplicada na camada de serviço.
     */
    void setEstado(const Estado& novoEstado);

    /**
     * @brief Define um novo projeto associado à história.
     * @param novoCodigoProjeto Objeto Codigo válido.
     * @post O atributo codigoProjeto é atualizado.
     * @throw invalid_argument Se o código for inválido (repassado pelo domínio).
     */
    void setCodigoProjeto(const Codigo& novoCodigoProjeto);

    /**
     * @brief Define uma nova estimativa para a história.
     * @param novaEstimativa Objeto Tempo válido.
     * @post O atributo estimativa é atualizado.
     * @throw invalid_argument Se a estimativa for inválida (repassado pelo domínio).
     */
    void setEstimativa(const Tempo& novaEstimativa);

    /**
     * @brief Define a pessoa (desenvolvedor) responsável pela história.
     * @param novoCodigoPessoa Objeto Codigo válido.
     * @post O atributo codigoPessoa é atualizado.
     * @throw invalid_argument Se o código for inválido (repassado pelo domínio).
     *
     * @note Pode ser usado um código vazio ("") para remover a associação.
     */
    void setCodigoPessoa(const Codigo& novoCodigoPessoa);

    /**
     * @brief Define o plano de sprint associado à história.
     * @param novoCodigoPlanoSprint Objeto Codigo válido.
     * @post O atributo codigoPlanoSprint é atualizado.
     * @throw invalid_argument Se o código for inválido (repassado pelo domínio).
     *
     * @note Pode ser usado um código vazio ("") para remover a associação.
     */
    void setCodigoPlanoSprint(const Codigo& novoCodigoPlanoSprint);

    // ========== MÉTODOS DE VALIDAÇÃO ==========

    /**
     * @brief Verifica se a história está em estado "A FAZER".
     * @return true se o estado for "A FAZER", false caso contrário.
     * @note Método útil para validar se a história pode ser associada a um sprint.
     */
    bool isAFazer() const;

    /**
     * @brief Verifica se a história está em estado "FAZENDO".
     * @return true se o estado for "FAZENDO", false caso contrário.
     */
    bool isFazendo() const;

    /**
     * @brief Verifica se a história está em estado "FEITO".
     * @return true se o estado for "FEITO", false caso contrário.
     */
    bool isFeito() const;

    /**
     * @brief Verifica se a história tem um responsável atribuído.
     * @return true se codigoPessoa não for vazio, false caso contrário.
     */
    bool temResponsavel() const;

    /**
     * @brief Verifica se a história está associada a um sprint.
     * @return true se codigoPlanoSprint não for vazio, false caso contrário.
     */
    bool estaAssociadaASprint() const;

    /**
     * @brief Avança o estado da história para o próximo estágio.
     * @details A FAZER → FAZENDO → FEITO
     * @return true se o estado foi alterado, false se já está em FEITO.
     * @note Este método aplica a regra de negócio de transição de estado.
     *       A validação do estado é feita pelo domínio Estado.
     */
    bool avancarEstado();

    /**
     * @brief Retorna uma representação textual do estado atual.
     * @return string "A FAZER", "FAZENDO" ou "FEITO".
     */
    string getEstadoStr() const;

    /**
     * @brief Verifica se a história pode ser associada a um sprint.
     * @return true se a história estiver em "A FAZER" e não estiver associada a um sprint.
     */
    bool podeSerAssociadaASprint() const;

    /**
     * @brief Verifica se a história pode ser atribuída a uma pessoa.
     * @return true se a história estiver em "A FAZER" ou "FAZENDO".
     */
    bool podeSerAtribuida() const;
};

// ============================================
// MÉTODOS INLINE: HISTORIAUSUARIO
// ============================================

/**
 * @brief Retorna o código da história.
 * @details Implementação inline que retorna uma cópia do atributo codigo.
 * @return Codigo Cópia do código armazenado.
 */
inline Codigo HistoriaUsuario::getCodigo() const {
    return codigo;
}

/**
 * @brief Retorna o nome da história.
 * @details Implementação inline que retorna uma cópia do atributo nome.
 * @return Nome Cópia do nome armazenado.
 */
inline Nome HistoriaUsuario::getNome() const {
    return nome;
}

/**
 * @brief Retorna a descrição da história.
 * @details Implementação inline que retorna uma cópia do atributo descricao.
 * @return Texto Cópia da descrição armazenada.
 */
inline Texto HistoriaUsuario::getDescricao() const {
    return descricao;
}

/**
 * @brief Retorna a prioridade da história.
 * @details Implementação inline que retorna uma cópia do atributo prioridade.
 * @return Prioridade Cópia da prioridade armazenada.
 */
inline Prioridade HistoriaUsuario::getPrioridade() const {
    return prioridade;
}

/**
 * @brief Retorna o estado atual da história.
 * @details Implementação inline que retorna uma cópia do atributo estado.
 * @return Estado Cópia do estado armazenado.
 */
inline Estado HistoriaUsuario::getEstado() const {
    return estado;
}

/**
 * @brief Retorna o código do projeto associado.
 * @details Implementação inline que retorna uma cópia do atributo codigoProjeto.
 * @return Codigo Cópia do código do projeto.
 */
inline Codigo HistoriaUsuario::getCodigoProjeto() const {
    return codigoProjeto;
}

/**
 * @brief Retorna a estimativa da história.
 * @details Implementação inline que retorna uma cópia do atributo estimativa.
 * @return Tempo Cópia da estimativa armazenada.
 */
inline Tempo HistoriaUsuario::getEstimativa() const {
    return estimativa;
}

/**
 * @brief Retorna o código da pessoa responsável.
 * @details Implementação inline que retorna uma cópia do atributo codigoPessoa.
 * @return Codigo Cópia do código da pessoa.
 */
inline Codigo HistoriaUsuario::getCodigoPessoa() const {
    return codigoPessoa;
}

/**
 * @brief Retorna o código do sprint associado.
 * @details Implementação inline que retorna uma cópia do atributo codigoPlanoSprint.
 * @return Codigo Cópia do código do sprint.
 */
inline Codigo HistoriaUsuario::getCodigoPlanoSprint() const {
    return codigoPlanoSprint;
}

/**
 * @brief Verifica se a história está em estado "A FAZER".
 * @return true se o estado for "A FAZER".
 */
inline bool HistoriaUsuario::isAFazer() const {
    return estado.getValor() == "A FAZER";
}

/**
 * @brief Verifica se a história está em estado "FAZENDO".
 * @return true se o estado for "FAZENDO".
 */
inline bool HistoriaUsuario::isFazendo() const {
    return estado.getValor() == "FAZENDO";
}

/**
 * @brief Verifica se a história está em estado "FEITO".
 * @return true se o estado for "FEITO".
 */
inline bool HistoriaUsuario::isFeito() const {
    return estado.getValor() == "FEITO";
}

/**
 * @brief Verifica se a história tem um responsável atribuído.
 * @return true se codigoPessoa não for vazio.
 */
inline bool HistoriaUsuario::temResponsavel() const {
    return !codigoPessoa.getValor().empty();
}

/**
 * @brief Verifica se a história está associada a um sprint.
 * @return true se codigoPlanoSprint não for vazio.
 */
inline bool HistoriaUsuario::estaAssociadaASprint() const {
    return !codigoPlanoSprint.getValor().empty();
}

/**
 * @brief Retorna uma representação textual do estado atual.
 * @return string "A FAZER", "FAZENDO" ou "FEITO".
 */
inline string HistoriaUsuario::getEstadoStr() const {
    return estado.getValor();
}

/**
 * @brief Verifica se a história pode ser associada a um sprint.
 * @return true se estiver em "A FAZER" e não estiver associada.
 */
inline bool HistoriaUsuario::podeSerAssociadaASprint() const {
    return isAFazer() && !estaAssociadaASprint();
}

/**
 * @brief Verifica se a história pode ser atribuída a uma pessoa.
 * @return true se estiver em "A FAZER" ou "FAZENDO".
 */
inline bool HistoriaUsuario::podeSerAtribuida() const {
    return isAFazer() || isFazendo();
}


#endif // ENTIDADE_HPP_INCLUDED
>>>>>>> 3adc8f729f518f28b82f8769a911d39c615851be
