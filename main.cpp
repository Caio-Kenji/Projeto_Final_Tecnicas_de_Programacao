/**
 * @file main.cpp
 * @brief Ponto de entrada do programa
 *
 * @details Instancia todos os serviços e inicia o menu principal.
 *
 * @author Seu Nome
 * @date 2024
 */

#include "Apresentacao.hpp"
#include "Servico.hpp"

using namespace std;

int main() {
    try {
        cout << "╔═══════════════════════════════════════════════════════╗" << endl;
        cout << "║                                                       ║" << endl;
        cout << "║   SISTEMA DE GERENCIAMENTO DE PROJETOS SCRUM         ║" << endl;
        cout << "║                                                       ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════╝" << endl;
        cout << endl;

        // ============================================
        // 1. CRIAR OS SERVIÇOS (usam Singleton internamente)
        // ============================================

        ServicoPessoa servicoPessoa;
        ServicoProjeto servicoProjeto;
        ServicoPlanoSprint servicoPlanoSprint;
        ServicoHistoriaUsuario servicoHistoria;

        cout << "✓ Serviços inicializados com sucesso!" << endl;
        cout << endl;

        // ============================================
        // 2. CRIAR O MENU PRINCIPAL (INJETANDO OS SERVIÇOS)
        // ============================================

        MenuPrincipal menu(&servicoPessoa,
                          &servicoProjeto,
                          &servicoPlanoSprint,
                          &servicoHistoria);

        // ============================================
        // 3. EXECUTAR O SISTEMA
        // ============================================

        menu.executar();

        cout << "\n╔═══════════════════════════════════════════════════════╗" << endl;
        cout << "║           Sistema finalizado com sucesso!             ║" << endl;
        cout << "╚═══════════════════════════════════════════════════════╝" << endl;

    } catch (const exception& e) {
        cout << "\n❌ ERRO FATAL: " << e.what() << endl;
        cout << "O programa sera encerrado." << endl;
        return 1;
    }

    return 0;
}



using namespace std;