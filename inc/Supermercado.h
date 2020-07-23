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