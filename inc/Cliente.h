/*
- A classe Cliente deve ter os atributos: saldo, sacola (vector de string);
- No saldo vai conter quanto o cliente tem em dinheiro e pode gastar em
compras;
- Na sacola vai conter todas as compras do cliente;
- A classe Cliente deve ter os métodos: compra (recebe o produto e o preço, o
método deve verificar se o cliente tem saldo suficiente para comprar o produto,
se não, emite um aviso, se sim, faz a compra, diminui o saldo e adiciona o
produto na sacola), verSacola (mostra o conteúdo da sacola) e registro(esse
método escreve o conteúdo da sacola em um arquivo chamado cliente_x.txt,
onde para cada cliente dever um arquivo próprio mudando x para 1, 2, 3, etc.
Até a quantidade de clientes existentes;
- As classes deve fazer uso de construtores que não sejam os construtores
padrão. Como os construtores serão implementados fica a critério de vocês;
A implementação correta da classe Estabelecimento valerá 2 pontos a classe Cliente
valerá 2 pontos e o método main valerá 1 ponto.
*/

#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <Produto.h>

class Cliente {
  public:
    static int totalClientes;
    float saldo;
    std::vector<Produto> sacola;
    Cliente(float saldo);
    void compra(Produto produto);
    void verSacola();
    void registro();
};

#endif