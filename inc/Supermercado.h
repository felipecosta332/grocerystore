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

#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include "Estabelecimento.h"

class Supermercado : public Estabelecimento {
    private:
        long totalItens;
    public:
        Fornecedor fornecedor;
        VectorSupermercado<Produto> estoque;
        Supermercado();
        ~Supermercado();
        void listar();
        void venda(Produto produto);
        void caixa();
        bool checar(std::string nome, Produto* produto);
        void reabastecer(Produto* demanda, int quantidade);
        long getTotalItens();
};

#endif