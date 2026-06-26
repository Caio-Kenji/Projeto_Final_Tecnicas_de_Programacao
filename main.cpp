#include <iostream>
#include <limits>

#include "Servico.hpp"
#include "Apresentacao.hpp"
#include "Sessao.hpp"

using namespace std;

Pessoa criarPessoaTemporaria() {
    Email email("temp@gmail.com");

    Nome nome;
    nome.setNome("Temp");

    Senha senha;
    senha.setSenha("a1B2c3");

    Papel papel("DESENVOLVEDOR");

    return Pessoa(email, nome, senha, papel);
}

void limparBufferMain() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ServicoPessoa servPessoa;
    ServicoProjeto servProjeto;
    ServicoPlanoSprint servPlano;
    ServicoHistoriaUsuario servHistoria;
    ServicoAutenticacao servAuth;

    int opcao;

    do {
        Sessao::logout = false;

        limparTela();

        cout << "\n==================================" << endl;
        cout << "          TELA INICIAL" << endl;
        cout << "==================================" << endl;
        cout << "1 - Criar conta" << endl;
        cout << "2 - Login" << endl;
        cout << "0 - Sair" << endl;
        cout << "==================================" << endl;
        cout << "Opcao: ";

        cin >> opcao;
        limparBufferMain();

        if (opcao == 1) {
            string email, nome, senha, papel;

            limparTela();

            cout << "\n=== CRIAR CONTA ===" << endl;

            cout << "Email: ";
            getline(cin, email);

            cout << "Nome: ";
            getline(cin, nome);

            cout << "Senha: ";
            getline(cin, senha);

            cout << "Papel (DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO): ";
            getline(cin, papel);

            try {
                servPessoa.criarPessoa(email, nome, senha, papel);
                pausar();
            }
            catch (exception& e) {
                cout << "[ERRO] " << e.what() << endl;
                pausar();
            }
        }

        else if (opcao == 2) {
            string email, senha;

            limparTela();

            cout << "\n=== LOGIN ===" << endl;

            cout << "Email: ";
            getline(cin, email);

            cout << "Senha: ";
            getline(cin, senha);

            Pessoa pessoaLogada = criarPessoaTemporaria();

            try {
                if (servAuth.autenticar(email, senha, &pessoaLogada)) {
                    cout << "\n[SUCESSO] Login realizado!" << endl;
                    cout << "Usuario: " << pessoaLogada.getNome().getNome() << endl;
                    cout << "Email: " << pessoaLogada.getEmail().get() << endl;
                    cout << "Papel: " << pessoaLogada.getPapel().getValor() << endl;
                    pausar();

                    Sessao::emailLogado = pessoaLogada.getEmail().get();
                    Sessao::papelLogado = pessoaLogada.getPapel().getValor();
                    Sessao::logout = false;

                    MenuPrincipal menu(&servPessoa,
                                       &servProjeto,
                                       &servPlano,
                                       &servHistoria);

                    menu.executar();

                    Sessao::emailLogado.clear();
                    Sessao::papelLogado.clear();
                    Sessao::logout = false;

                    cout << "\n[INFO] Logout realizado." << endl;
                    pausar();
                }
                else {
                    cout << "[ERRO] Email ou senha invalidos." << endl;
                    pausar();
                }
            }
            catch (exception& e) {
                cout << "[ERRO] " << e.what() << endl;
                pausar();
            }
        }

        else if (opcao == 0) {
            cout << "Encerrando sistema..." << endl;
        }

        else {
            cout << "[ERRO] Opcao invalida." << endl;
            pausar();
        }

    } while (opcao != 0);

    return 0;
}