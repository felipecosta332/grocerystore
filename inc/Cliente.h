#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Produto.h"
#include "VectorSupermercado.h"

class Cliente {
  public:
    static int totalClientes;
    float saldo;
    VectorSupermercado<Produto> sacola;
    Cliente();
    ~Cliente();
    void compra(Produto produto);
    void verSacola();
    void registro();
};

#endif