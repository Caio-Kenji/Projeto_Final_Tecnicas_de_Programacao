// Este é o arquivo Dominio.hpp

#ifndef DOMINIO_HPP_INCLUDED
#define DOMINIO_HPP_INCLUDED

#include <string>
#include<cctype>
#include<stdexcept>

using namespace std;

/**
 * @brief Classe base abstrata para todos os domínios do sistema.
 *
 * @details Esta classe fornece a estrutura fundamental para qualquer domínio,
 *          garantindo que todo valor atribuído seja validado antes do armazenamento.
 *          O método setValor() lança exceção se o formato for inválido.
 *
 * @invariant O atributo 'valor' sempre armazena uma string válida para o domínio.
 *
 * @see Codigo, Data, Estado
 */
class Dominio{
protected:
    string valor; ///< Valor armazenado do domínio

     /**
     * @brief Método virtual puro para validação do valor.
     * @param valor String a ser validada.
     * @throw invalid_argument Se o valor não atender ao formato do domínio.
     */
    virtual void validar(string)=0;
public:
     /**
     * @brief Define um novo valor para o domínio.
     * @param valor Valor a ser atribuído.
     * @throw invalid_argument Repassa exceção do método validar().
     *
     * @post O atributo 'valor' é atualizado apenas se a validação for bem-sucedida.
     */
    void setValor(string);

     /**
     * @brief Retorna o valor atual armazenado.
     * @return string Cópia do valor interno.
     * @note Este método não modifica o objeto (const).
     * @see setValor()
     */
    string getValor() const;
};






// -----------DEFINIÇÕES: CÓDIGO---------------------------------------------------------





/**
 * @brief Domínio para identificadores alfanuméricos com formato fixo de 5 caracteres.
 *
 * @details Armazena e valida strings que seguem a seguinte estrutura:
 *          - Posição 1 e 2: duas letras maiúsculas (A a Z)
 *          - Posição 3, 4 e 5: três dígitos numéricos (0 a 9)
 *
 * @note Este formato é comumente utilizado para identificação de tarefas,
 *       projetos ou itens no sistema.
 *
 * @exceptions
 * @throw invalid_argument "Codigo invalido." se:
 *         - A string não tiver exatamente 5 caracteres
 *         - O 1º ou 2º caractere não for letra maiúscula
 *         - O 3º, 4º ou 5º caractere não for dígito
 */
class Codigo:public Dominio{
private:

     /**
     * @brief Valida o formato do código conforme especificação.
     * @param valor String de 5 caracteres.
     * @throw invalid_argument "Codigo invalido." para qualquer violação.
     */
    void validar(string);
};






// -----------DEFINIÇÕES: DATA---------------------------------------------------------








/**
 * @brief Domínio para representar um ponto específico no calendário gregoriano.
 *
 * @details Armazena e valida strings que seguem a estrutura "DD/MM/AAAA", onde:
 *          - DD: número de dois dígitos entre 01 e 31 (dia do mês)
 *          - MM: número de dois dígitos entre 01 e 12 (mês do ano)
 *          - AAAA: número de quatro dígitos entre 2000 e 2999 (ano)
 *
 * @note A combinação dia-mês-ano deve corresponder a uma data real existente,
 *       considerando a quantidade de dias de cada mês e anos bissextos.
 *
 * @details Validação especial para anos bissextos:
 *          - Ano bissexto: divisível por 4, exceto se divisível por 100
 *            (a menos que também seja divisível por 400)
 *          - Fevereiro pode ter 29 dias apenas em anos bissextos
 *
 * @exceptions
 * @throw invalid_argument "Data invalida." se:
 *         - Formato não for DD/MM/AAAA (10 caracteres)
 *         - Dia for 00 ou maior que o máximo do mês
 *         - Mês for 00 ou maior que 12
 *         - Ano for menor que 2000 ou maior que 2999
 *         - 29/02 em ano não bissexto
 *
 * @see Dominio
 */

class Data:public Dominio{
private:

     /**
     * @brief Valida se a string representa uma data real.
     * @param valor String no formato "DD/MM/AAAA".
     * @throw invalid_argument "Data invalida." para qualquer violação.
     */
    void validar(string);
};








// -----------DEFINIÇÕES: ESTADO---------------------------------------------------------







/**
 * @brief Representa em qual etapa do fluxo de trabalho uma tarefa se encontra.
 *
 * @details
 * - "A FAZER" : Tarefa aguardando na fila, nenhum trabalho realizado
 * - "FAZENDO" : Tarefa sendo executada neste momento, trabalho em andamento
 * - "FEITO" : Tarefa completa, trabalho finalizado
 *
 * @exceptions
 * @throw invalid_argument "Estado invalido." se o valor não for exatamente
 *         um dos três strings definidos (case-sensitive).
 *
 * @note A transição entre estados segue a ordem natural:
 *       A FAZER → FAZENDO → FEITO (não é possível retroceder ou pular fases)
 */
class Estado:public Dominio{
private:

     /**
     * @brief Valida se o valor está entre os estados permitidos.
     * @param valor String a ser validada.
     * @throw invalid_argument "Estado invalido." se não for um dos três estados.
     */
    void validar(string);
};












// -----------DEFINIÇÕES: PAPEL---------------------------------------------------------




/**
* @brief Domínio que representa o papel/função de uma pessoa no projeto Scrum.
*
* @details A classe Papel define e valida os três papéis possíveis que um
*          usuário pode assumir dentro de um projeto Scrum:
*          - **DESENVOLVEDOR**: Responsável pela implementação técnica
*          - **MESTRE SCRUM**: Facilitador do processo, remove impedimentos
*          - **PROPRIETARIO DE PRODUTO**: Responsável pelo backlog e requisitos
*
* @invariant O valor armazenado é sempre uma das três strings válidas.
*
* @exceptions
* @throw std::invalid_argument "Papel invalido. Opcoes validas: ..."
*         quando o valor fornecido não corresponde a nenhum papel permitido.
*
* @note A comparação é case-sensitive e não considera acentuação conforme
*       requisito não funcional 12.
*
* @example
* @code
* try {
*     Papel dev("DESENVOLVEDOR");      // Válido
*     Papel scrum("MESTRE SCRUM");     // Válido
*     Papel po("PROPRIETARIO DE PRODUTO"); // Válido
*     Papel invalido("GERENTE");       // Lança exceção
* } catch (const invalid_argument& e) {
*     cout << e.what() << endl;
* }
* @endcode
*
* @see Pessoa, Projeto
*/
class Papel {
private:

   string valor;  // atributo privado (nome sugestivo: "valor")

   /**
   * @brief Valida se a string corresponde a um papel permitido.
   *
   * @param papel String a ser validada.
   *
   * @throw std::invalid_argument Se o papel não for um dos três permitidos.
   *
   * @note Método privado, usado internamente por setValor() e pelo construtor.
   *       Não deve ser chamado diretamente pelos usuários da classe.
   */
   void validar(const string& papel);

public:



   /**
   * @brief Construtor da classe Papel.
   *
   * @param papel String contendo o papel a ser armazenado.
   *             Deve ser exatamente "DESENVOLVEDOR", "MESTRE SCRUM" ou
   *             "PROPRIETARIO DE PRODUTO".
   *
   * @throw std::invalid_argument Se o papel fornecido for inválido.
   *
   * @post O objeto é criado apenas se a validação for bem-sucedida.
   *
   * @see setValor(), validar()
   */
   Papel(const string& papel);




   /**
   * @brief Define/atualiza o valor do papel.
   *
   * @param papel Nova string a ser validada e armazenada.
   *
   * @throw std::invalid_argument Se o papel fornecido for inválido.
   *
   * @post O valor antigo é preservado se a validação falhar.
   *       O valor é atualizado apenas se a validação passar.
   *
   * @note Este método é usado tanto pelo construtor quanto para atualizações.
   *
   * @see getValor(), validar()
   */
   void setValor(const string& papel);





   /**
   * @brief Retorna o valor atual do papel.
   *
   * @return std::string Cópia do valor armazenado ("DESENVOLVEDOR",
   *         "MESTRE SCRUM" ou "PROPRIETARIO DE PRODUTO").
   *
   * @note Método constante (não modifica o objeto).
   *
   * @see setValor()
   */
   string getValor() const;
};




// -----------DEFINIÇÕES: EMAIL---------------------------------------------------------




/**
 * @brief Domínio que representa um endereço de email válido.
 *
 * @details A classe Email valida endereços de email seguindo uma gramática
 *          específica conforme especificação do trabalho:
 *
 *          **Formato geral:** `local@dominio`
 *
 *          **Regras para PARTE LOCAL (antes do @):**
 *          - Máximo de 64 caracteres
 *          - Caracteres permitidos: letras (a-z), dígitos (0-9), ponto (.), hífen (-)
 *          - Não pode começar ou terminar com ponto ou hífen
 *          - Após ponto ou hífen deve vir letra ou dígito (não pode ter dois símbolos seguidos)
 *
 *          **Regras para DOMÍNIO (depois do @):**
 *          - Máximo de 255 caracteres
 *          - Composto por partes separadas por ponto (.)
 *          - Cada parte pode conter letras, dígitos e hífen (-)
 *          - Cada parte não pode começar ou terminar com hífen
 *          - Não pode ter pontos consecutivos (parte vazia)
 *
 * @invariant O valor armazenado é sempre um email que passou por todas as validações.
 *
 * @exceptions
 * @throw std::invalid_argument com mensagens descritivas específicas para cada
 *         tipo de erro de validação.
 *
 * @example
 * @code
 * try {
 *     Email e1("usuario@exemplo.com");        // Válido
 *     Email e2("nome.sobrenome@empresa.com.br"); // Válido
 *     Email e3("nome@dominio");               // Inválido (domínio sem ponto)
 *     Email e4("nome..sobrenome@exemplo.com"); // Inválido (pontos consecutivos)
 * } catch (const invalid_argument& e) {
 *     cout << "Erro: " << e.what() << endl;
 * }
 * @endcode
 *
 * @note As mensagens de erro são descritivas para facilitar a depuração
 *       e permitir que a camada de apresentação mostre erros específicos.
 *
 * @see Pessoa
 */
class Email {
private:

   string valor;


   /**
   * @brief Valida completamente um email conforme especificação.
   *
   * @param email String a ser validada.
   *
   * @throw std::invalid_argument Com mensagem específica do erro encontrado.
   *
   * @details Etapas de validação na ordem:
   *          - Verifica existência e posição do @
   *          - Separa parte local e domínio
   *          - Valida tamanhos máximos (64 e 255 caracteres)
   *          - Valida caractere por caractere da parte local
   *          - Valida domínio (quebra por pontos e valida cada parte)
   *
   * @note Método privado, usado internamente. As validações são sequenciais
   *       e param no primeiro erro encontrado.
   */
   void validar(const std::string& email) const;

public:


   /**
   * @brief Construtor da classe Email.
   *
   * @param novoValor String contendo o email a ser validado e armazenado.
   *
   * @throw std::invalid_argument Se o email não passar nas validações.
   *
   * @post Um objeto Email válido é criado apenas se a validação for bem-sucedida.
   *
   * @see set(), validar()
   */
   Email(const string& novoValor);




   /**
   * @brief Define um novo valor para o email.
   *
   * @param novoValor String com o novo email a ser validado e armazenado.
   *
   * @throw std::invalid_argument Se o email não passar nas validações.
   *
   * @post O valor antigo é preservado se a validação falhar.
   *       O valor é atualizado apenas se todas as regras forem satisfeitas.
   *
   * @note Realiza todas as 4 etapas de validação:
   *       1. Verificação do @ e estrutura básica
   *       2. Validação da parte local
   *       3. Validação do domínio
   *       4. Verificação de tamanhos máximos
   *
   * @see get(), validar()
   */
   void set(const std::string& novoValor);




   /**
   * @brief Retorna o valor atual do email.
   *
   * @return std::string Cópia do email armazenado (já validado).
   *
   * @note Método constante (não modifica o objeto).
   *
   * @see set()
   */
   string get() const;
};





// -----------DEFINIÇÕES: NOME---------------------------------------------------------




/**
 * @brief Classe que representa um nome válido.
 *
 * O nome deve possuir no máximo 10 caracteres,
 * contendo apenas letras e espaços.
 */

 class Nome {
    private:
     /**
     * Armazena o nome.
     */
        string nome;
     /**
     * Verifica se o formato do nome é válido ou não.
     * @throw invalid_argument caso o formato seja inválido.
     * @param nome Nome a ser validado
     */
        void validar(string nome);
    public:
     /**
     * Define o nome.
     * @param nome Nome a ser guardado.
     */
        void setNome(string nome);
     /**
     * Retorna o nome.
     */
        string getNome();

 };

// -----------DEFINIÇÕES SENHA---------------------------------------------------------

/**
 * @brief Classe que representa uma senha válida.
 *
 * A senha deve possuir exatamente 6 caracteres,
 * contendo apenas letras e dígitos.
 * Letra não pode ser seguida por letra e dígito não
 * pode ser seguido por dígito. Deve existir ao menos
 * uma letra minúscula, uma maiúscula e um dígito.
 */

 class Senha {
    private:
     /**
     * Armazena a senha.
     */
        string senha;
     /**
     * Verifica se o formato do senha é válido ou não.
     * @throw invalid_argument caso o formato seja inválido.
     * @param senha senha a ser validado
     */
        void validar(string senha);
    public:
     /**
     * Define a senha.
     * @param senha senha a ser guardada.
     */
        void setSenha(string senha);
     /**
     * Retorna a senha.
     */
        string getSenha();

 };

// -----------DEFINIÇÕES: TEMPO---------------------------------------------------------

/**
 * @brief Classe que representa o tempo.
 *
 * Deve ser um inteiro entre
 * 1 e 365.
 */

 class Tempo {
    private:
     /**
     * Armazena o tempo.
     */
        int tempo;
     /**
     * Verifica se o número é válido ou não.
     * @throw invalid_argument caso o número seja inválido.
     * @param tempo número a ser validado.
     */
        void validar(int tempo);
    public:
     /**
     * Define o tempo.
     * @param tempo tempo a ser guardado.
     */
        void setTempo(int tempo);
     /**
     * Retorna o tempo.
     */
        int getTempo() const;

 };

// -----------DEFINIÇÕES: TEXTO---------------------------------------------------------

/**
 * @brief Classe de dominio para Texto.
 */
class Texto {
private:
    string valor;
public:
    void setValor(string v);
    string getValor() const;
};

// -----------DEFINIÇÕES: PRIORIDADE---------------------------------------------------------

/**
 * @brief Classe domínio que representa a prioridade de uma história de usuário.
 *
 * @details Armazena e valida strings que representam a prioridade de uma
 *          história de usuário no backlog do produto.
 *
 * @invariant O valor armazenado é sempre "ALTA", "MEDIA" ou "BAIXA".
 *
 * @exceptions
 * @throw invalid_argument se o valor fornecido não for uma prioridade válida.
 *
 * @note O formato segue a especificação do PDF:
 *       - ALTA: prioridade alta
 *       - MEDIA: prioridade média (sem acento, conforme requisito 12)
 *       - BAIXA: prioridade baixa
 */
class Prioridade {
private:
    string valor;  ///< Valor armazenado da prioridade

    /**
     * @brief Valida se a string é uma prioridade válida.
     * @param prioridade String a ser validada.
     * @throw invalid_argument se prioridade não for ALTA, MEDIA ou BAIXA.
     */
    void validar(const string& prioridade) const;

public:
    /**
     * @brief Construtor da classe Prioridade.
     * @param prioridade Valor inicial da prioridade.
     * @throw invalid_argument Se o valor for inválido.
     */
    Prioridade(const string& prioridade);

    /**
     * @brief Define um novo valor para a prioridade.
     * @param prioridade Novo valor a ser atribuído.
     * @throw invalid_argument Se o valor for inválido.
     * @post O valor anterior é preservado se a validação falhar.
     */
    void setValor(const string& prioridade);

    /**
     * @brief Retorna o valor atual da prioridade.
     * @return String com o valor armazenado (ALTA, MEDIA ou BAIXA).
     * @note Este método não modifica o objeto (const).
     */
    string getValor() const;
};

#endif // DOMINIO_HPP_INCLUDED
