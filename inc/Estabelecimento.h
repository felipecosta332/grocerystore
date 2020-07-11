#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Produto.h"

class Estabelecimento {
  public:
    std::list<Produto> estoque;
    std::list<Produto> vendas;
    std::list<Produto>::iterator it;
    std::list<Produto>::iterator it2;
    Estabelecimento();
    ~Estabelecimento();
    void listar();
    void venda(Produto produto);
    void caixa();
    bool checar(int chave, Produto* produto);
};

#endif