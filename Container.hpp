#ifndef CONTAINER_HPP_INCLUDED
#define CONTAINER_HPP_INCLUDED

#include "Dominio.hpp"
#include "Entidade.hpp"

#include <map>
#include <vector>

using namespace std;

/**
 * @brief Contêiner responsável por armazenar objetos Pessoa em memória.
 *
 * @details Implementa armazenamento usando map, tendo o email da pessoa
 *          como chave. A classe segue o padrão Singleton.
 */
class ContainerPessoa {
private:
    map<string, Pessoa> containerPes;
    static ContainerPessoa *instancia;

    /**
     * @brief Construtor privado para aplicação do padrão Singleton.
     */
    ContainerPessoa(){};

public:
    /**
     * @brief Retorna a instância única do contêiner.
     * @return Ponteiro para a instância de ContainerPessoa.
     */
    static ContainerPessoa* getInstancia();

    /**
     * @brief Armazena uma nova pessoa.
     * @param pessoa Pessoa a ser armazenada.
     * @return true se a pessoa foi criada; false caso já exista.
     */
    bool criar(Pessoa pessoa);

    /**
     * @brief Exclui uma pessoa pelo email.
     * @param email Email da pessoa a ser excluída.
     * @return true se a pessoa foi excluída; false caso não exista.
     */
    bool excluir(Email email);

    /**
     * @brief Lê uma pessoa armazenada.
     * @param pessoa Ponteiro para pessoa contendo o email de busca.
     * @return true se a pessoa foi encontrada; false caso contrário.
     */
    bool ler(Pessoa* pessoa);

    /**
     * @brief Atualiza uma pessoa existente.
     * @param pessoa Pessoa com os novos dados.
     * @return true se a pessoa foi atualizada; false caso não exista.
     */
    bool atualizar(Pessoa pessoa);
};

/**
 * @brief Contêiner responsável por armazenar objetos Projeto em memória.
 *
 * @details Implementa armazenamento usando map, tendo o código do projeto
 *          como chave. A classe segue o padrão Singleton.
 */
class ContainerProjeto {
private:
    map<string, Projeto> containerPro;
    static ContainerProjeto *instancia;

    /**
     * @brief Construtor privado para aplicação do padrão Singleton.
     */
    ContainerProjeto(){};

public:
    /**
     * @brief Retorna a instância única do contêiner.
     * @return Ponteiro para a instância de ContainerProjeto.
     */
    static ContainerProjeto* getInstancia();

    /**
     * @brief Armazena um novo projeto.
     * @param projeto Projeto a ser armazenado.
     * @return true se o projeto foi criado; false caso já exista.
     */
    bool criar(Projeto projeto);

    /**
     * @brief Exclui um projeto pelo código.
     * @param codigo Código do projeto a ser excluído.
     * @return true se o projeto foi excluído; false caso não exista.
     */
    bool excluir(Codigo codigo);

    /**
     * @brief Lê um projeto armazenado.
     * @param projeto Ponteiro para projeto contendo o código de busca.
     * @return true se o projeto foi encontrado; false caso contrário.
     */
    bool ler(Projeto* projeto);

    /**
     * @brief Atualiza um projeto existente.
     * @param projeto Projeto com os novos dados.
     * @return true se o projeto foi atualizado; false caso não exista.
     */
    bool atualizar(Projeto projeto);

    /**
     * @brief Verifica se existe projeto com determinado código.
     * @param codigo Código do projeto.
     * @return true se existir; false caso contrário.
     */
    bool existe(const string& codigo) const;

    /**
     * @brief Lista todos os projetos armazenados.
     * @return Vetor contendo todos os projetos.
     */
    vector<Projeto> listarTodas() const;

    /**
     * @brief Busca um projeto pelo código.
     * @param codigo Código do projeto.
     * @return Ponteiro para o projeto, ou nullptr se não encontrado.
     */
    Projeto* buscar(const string& codigo);

    /**
     * @brief Busca um projeto pelo código sem permitir alteração.
     * @param codigo Código do projeto.
     * @return Ponteiro constante para o projeto, ou nullptr se não encontrado.
     */
    const Projeto* buscar(const string& codigo) const;
};

/**
 * @brief Contêiner responsável por armazenar objetos PlanoSprint em memória.
 *
 * @details Implementa armazenamento usando map, tendo o código do plano
 *          de sprint como chave. A classe segue o padrão Singleton.
 */
class ContainerPlanoSprint {
private:
    map<string, PlanoSprint> containerPS;
    static ContainerPlanoSprint *instancia;

    /**
     * @brief Construtor privado para aplicação do padrão Singleton.
     */
    ContainerPlanoSprint(){};

public:
    /**
     * @brief Retorna a instância única do contêiner.
     * @return Ponteiro para a instância de ContainerPlanoSprint.
     */
    static ContainerPlanoSprint* getInstancia();

    /**
     * @brief Armazena um novo plano de sprint.
     * @param planoSprint Plano de sprint a ser armazenado.
     * @return true se o plano foi criado; false caso já exista.
     */
    bool criar(PlanoSprint planoSprint);

    /**
     * @brief Exclui um plano de sprint pelo código.
     * @param codigo Código do plano de sprint.
     * @return true se o plano foi excluído; false caso não exista.
     */
    bool excluir(Codigo codigo);

    /**
     * @brief Lê um plano de sprint armazenado.
     * @param planoSprint Ponteiro para plano contendo o código de busca.
     * @return true se o plano foi encontrado; false caso contrário.
     */
    bool ler(PlanoSprint* planoSprint);

    /**
     * @brief Atualiza um plano de sprint existente.
     * @param planoSprint Plano de sprint com os novos dados.
     * @return true se o plano foi atualizado; false caso não exista.
     */
    bool atualizar(PlanoSprint planoSprint);

    /**
     * @brief Verifica se existe plano de sprint com determinado código.
     * @param codigo Código do plano.
     * @return true se existir; false caso contrário.
     */
    bool existe(const string& codigo) const;

    /**
     * @brief Lista todos os planos de sprint armazenados.
     * @return Vetor contendo todos os planos de sprint.
     */
    vector<PlanoSprint> listarTodas() const;

    /**
     * @brief Busca um plano de sprint pelo código.
     * @param codigo Código do plano.
     * @return Ponteiro para o plano, ou nullptr se não encontrado.
     */
    PlanoSprint* buscar(const string& codigo);

    /**
     * @brief Busca um plano de sprint pelo código sem permitir alteração.
     * @param codigo Código do plano.
     * @return Ponteiro constante para o plano, ou nullptr se não encontrado.
     */
    const PlanoSprint* buscar(const string& codigo) const;
};

/**
 * @brief Contêiner responsável por armazenar objetos HistoriaUsuario em memória.
 *
 * @details Implementa armazenamento usando map, tendo o código da história
 *          como chave. A classe segue o padrão Singleton.
 */
class ContainerHistoriaUsuario {
private:
    map<string, HistoriaUsuario> containerHU;
    static ContainerHistoriaUsuario *instancia;

    /**
     * @brief Construtor privado para aplicação do padrão Singleton.
     */
    ContainerHistoriaUsuario(){};

public:
    /**
     * @brief Retorna a instância única do contêiner.
     * @return Ponteiro para a instância de ContainerHistoriaUsuario.
     */
    static ContainerHistoriaUsuario* getInstancia();

    /**
     * @brief Armazena uma nova história de usuário.
     * @param historia História de usuário a ser armazenada.
     * @return true se a história foi criada; false caso já exista.
     */
    bool criar(HistoriaUsuario historia);

    /**
     * @brief Exclui uma história de usuário pelo código.
     * @param codigo Código da história.
     * @return true se a história foi excluída; false caso não exista.
     */
    bool excluir(Codigo codigo);

    /**
     * @brief Lê uma história de usuário armazenada.
     * @param historia Ponteiro para história contendo o código de busca.
     * @return true se a história foi encontrada; false caso contrário.
     */
    bool ler(HistoriaUsuario* historia);

    /**
     * @brief Atualiza uma história de usuário existente.
     * @param historia História de usuário com os novos dados.
     * @return true se a história foi atualizada; false caso não exista.
     */
    bool atualizar(HistoriaUsuario historia);

    /**
     * @brief Verifica se existe história com determinado código.
     * @param codigo Código da história.
     * @return true se existir; false caso contrário.
     */
    bool existe(const string& codigo) const;

    /**
     * @brief Lista todas as histórias armazenadas.
     * @return Vetor contendo todas as histórias.
     */
    vector<HistoriaUsuario> listarTodas() const;

    /**
     * @brief Busca uma história pelo código.
     * @param codigo Código da história.
     * @return Ponteiro para a história, ou nullptr se não encontrada.
     */
    HistoriaUsuario* buscar(const string& codigo);

    /**
     * @brief Busca uma história pelo código sem permitir alteração.
     * @param codigo Código da história.
     * @return Ponteiro constante para a história, ou nullptr se não encontrada.
     */
    const HistoriaUsuario* buscar(const string& codigo) const;

    /**
     * @brief Lista histórias associadas a um projeto.
     * @param codigoProjeto Código do projeto.
     * @return Vetor contendo as histórias associadas ao projeto.
     */
    vector<HistoriaUsuario> listarPorProjeto(const string& codigoProjeto) const;
};

#endif // CONTAINER_HPP_INCLUDED