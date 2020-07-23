#ifndef APP_H
#define APP_H

#include "Cliente.h"
#include "Restaurante.h"
#include "Supermercado.h"
#include "Produto.h"
#include "VectorSupermercado.h"

class App {
  private:
    std::string line;
    bool reset;
    char input;
    int code;
    double currency;
    Supermercado mercado;
    Restaurante restaurante;
    Produto produto;
  public:
    App();
    void runApp();
    void selectApp(Cliente* cliente);
    void appSupermercado(Cliente* cliente);
    void appRestaurante(Cliente* cliente);
    void addSaldo(Cliente* cliente);
    void mostrarVitrine(Cliente* cliente);
    void comprarMercado(Cliente* cliente);
    void mostrarFornecedor();
    void reabastecer();
    void listarCardapio(Cliente* cliente);
    void fazerPedido(Cliente* cliente);
    void resetar(bool* reset);
    void warning();
};

#endif