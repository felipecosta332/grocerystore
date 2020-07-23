#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <fstream>
#include <iostream>
#include <sstream>
#include "Produto.h"
#include "VectorSupermercado.h"

class Fornecedor {
  private:
    int totalItens;
  public:
    VectorSupermercado<Produto> estoque;
    Fornecedor();
    ~Fornecedor();
    void listarProdutos();
    bool repassarProdutos(Produto* produto, int quantidade);
    int getTotalItens();
};

#endif