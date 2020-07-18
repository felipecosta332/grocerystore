/*
• A classe Estabelecimento deverá conter um novo método chamado reabastecer
(esse método é responsável por pegar os produtos na classe Fornecedor e
reabastecer o estoque.csv);
*/

#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Fornecedor.h"
#include "Produto.h"
#include "VectorSupermercado.h"

class Estabelecimento {
  public:
    Fornecedor fornecedor;
    VectorSupermercado<Produto> estoque;
    VectorSupermercado<Produto> vendas;
    Estabelecimento();
    ~Estabelecimento();
    void listar();
    void venda(Produto produto);
    void caixa();
    bool checar(int chave, Produto* produto);
    void reabastecer(Produto* demanda, int quantidade);
};

#endif