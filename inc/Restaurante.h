#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Estabelecimento.h"

class Restaurante : public Estabelecimento {
    public:
        VectorSupermercado<Produto> cardapio;
        Restaurante();
        ~Restaurante();
        void listar();
        void venda(Produto produto);
        void caixa();
        bool checar(std::string nome, Produto* produto);
};

#endif