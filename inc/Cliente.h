#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Produto.h"

class Cliente {
  public:
    static int totalClientes;
    float saldo;
    std::vector<Produto> sacola;
    Cliente();
    ~Cliente();
    void compra(Produto produto);
    void verSacola();
    void registro();
};

#endif