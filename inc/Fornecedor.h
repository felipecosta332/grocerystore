/*
Continuando o programa do Supermercado vocês irão criar uma classe
chamada Fornecedor que será responsável por reabastecer o estoque;
• A classe Fornecedor deverá conter apenas um atributo que é um vector
genérico (explicado mais abaixo) de produtos (serão lidos do arquivo
fornecedor.csv).
• A classe Fornecedor deverá conter os seguintes métodos: listarProdutos
(mostra todos os produtos disponíveis) e repassarProdutos (repassa para o
estabelecimento os produtos solicitados na quantidade solicitada, diminuindo
seus valores em fornecedor.csv);
*/

#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <fstream>
#include <iostream>
#include <sstream>
#include "Produto.h"
#include "VectorSupermercado.h"

class Fornecedor {
  public:
    VectorSupermercado<Produto> estoque;
    Fornecedor();
    ~Fornecedor();
    void listarProdutos();
    void repassarProdutos(Produto* produto, int quantidade);
};

#endif