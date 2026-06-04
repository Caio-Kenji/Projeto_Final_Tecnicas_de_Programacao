*   **Prioridade.cpp** (contém a lógica do método):
    ```cpp
    #include "Prioridade.h"

    void Prioridade::setValor(std::string valor) {
        if (valor == "ALTA" || valor == "MEDIA" || valor == "BAIXA") {
            this->valor = valor;
        } else {
            throw std::invalid_argument("Prioridade invalida.");
        }
    }

    std::string Prioridade::getValor() const {
        return valor;
    }
