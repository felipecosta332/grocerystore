/*
• Na inicialização do programa o usuário deverá decidir se quer usar o
Supermercado ou o Restaurante;
• Quando o usuário utiliza o restaurante ele deve fazer um pedido informando o
item do menu e a quantidade;
• O usuário deve receber um saldo para gastar durante a inicialização do
programa;
• Para todo caso de erro inesperado, o programa deve usar exceção para tratar o
problema;
*/

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