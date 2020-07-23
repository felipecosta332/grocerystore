#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Produto.h"
#include "VectorSupermercado.h"

class Cliente {
  private:
    static int totalClientes;
    int totalItens;
    int totalItensMercado;
    int totalItensRestaurante;
    double saldo;
    double contaMercado;
    double contaRestaurante;
    double contaTotal;
  public:
    VectorSupermercado<Produto> conta;
    VectorSupermercado<Produto> sacola;
    Cliente();
    ~Cliente();
    void compraMercado(Produto produto);
    void compraRestaurante(Produto produto);
    void verSacola();
    void verConta();
    void registro();
    int getTotalClientes();
    int getTotalItens();
    int getTotalItensMercado();
    int getTotalItensRestaurante();
    double getSaldo();
    double getContaMercado();
    double getContaRestaurante();
    double getContaTotal();
    void setSaldo(double saldo);
};

#endif