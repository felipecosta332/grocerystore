#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
  public:
    unsigned int codigo;
    std::string produto;
    std::string unidadeMedida;
    float preco;
    unsigned int quantidade;
};

#endif