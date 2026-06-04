#ifndef TEXTO_H
#define TEXTO_H

#include <string>

/**
 * @brief Classe de dominio para Texto.
 */
class Texto {
private:
    std::string valor;
public:
    void setValor(std::string v);
    std::string getValor() const;
};

#endif
