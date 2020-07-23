#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Fornecedor.h"
#include "Produto.h"
#include "VectorSupermercado.h"

class Estabelecimento {
  protected:
    int totalItensVendas;
    double faturamento;
  public:
    VectorSupermercado<Produto> vendas;
    int getTotalItensVendas() {
      return this->totalItensVendas;
    };
    double getFaturamento() {
      return this->faturamento;
    }
};

#endif