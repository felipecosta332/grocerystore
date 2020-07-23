/*
• Crie a classe Supermercado e Restaurante para que sejam derivada de
Estabelecimento;
• A classe Estabelecimento deve ser modificada para conter apenas os atributos e
métodos comum as outras duas classes que a derivam;
• As classes Supermercado e Restaurante devem fazer as mesmas operações que
o programa Supermercado anterior;
• Deverão ser gerados arquivos de caixa tanto pro Supermercado quanto pro
Restaurante;
• A diferença entre as duas classes consiste que Restaurante não possui estoque e
sim um cardápio e que Restaurante não faz utilização de Fornecedor;
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