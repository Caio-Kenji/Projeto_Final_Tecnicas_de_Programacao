/**
 * @file main.cpp
 * @brief Ponto de entrada do programa
 *
 * @author Seu Nome
 * @date 2024
 */

#include "Apresentacao.hpp"
#include "Servico.hpp"

using namespace std;

int main() {
    try {
        // ============================================
        // 1. CRIAR OS SERVIÇOS
        // ============================================

        ServicoPessoa servicoPessoa;
        ServicoProjeto servicoProjeto;
        ServicoPlanoSprint servicoPlanoSprint;
        ServicoHistoriaUsuario servicoHistoria;

        // ============================================
        // 2. CRIAR E EXECUTAR A CONTROLADORA PRINCIPAL
        // ============================================

        MenuPrincipal menu(&servicoPessoa,
                        &servicoProjeto,
                        &servicoPlanoSprint,
                        &servicoHistoria);


        menu.executar();

        return 0;

    } catch (const exception& e) {
        cout << "\n❌ ERRO FATAL: " << e.what() << endl;
        cout << "O programa sera encerrado." << endl;
        return 1;
    }
}