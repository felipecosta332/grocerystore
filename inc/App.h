/*
• O menu no main deverá conter uma opção para listar os produtos do
fornecedor e outra para o estabelecimento reabastecer o estoque, solicitando o
produto e a quantidade;
*/

#ifndef APP_H
#define APP_H

#include "Cliente.h"
#include "Estabelecimento.h"
#include "Produto.h"
#include "VectorSupermercado.h"

class App {
  private:
    bool reset;
    char input;
    int code;
    float currency;
    Estabelecimento mercado;
    Produto produto;
  public:
    App();
    void runApp();
    void showMenu(Cliente* cliente);
    void addSaldo(Cliente* cliente);
    void mostrarVitrine(Cliente* cliente);
    void comprar(Cliente* cliente);
    void mostrarFornecedor();
    void reabastecer();
};

#endif

/*
Continuando o programa do Supermercado vocês irão criar uma classe
chamada Fornecedor que será responsável por reabastecer o estoque;
• A classe Fornecedor deverá conter apenas um atributo que é um vector
genérico (explicado mais abaixo) de produtos (serão lidos do arquivo
fornecedor.csv).
• A classe Fornecedor deverá conter os seguintes métodos: listarProdutos
(mostra todos os produtos disponíveis) e repassarProdutos (repassa para o
estabelecimento os produtos solicitados na quantidade solicitada, diminuindo
seus valores em fornecedor.csv);
• A classe Estabelecimento deverá conter um novo método chamado reabastecer
(esse método é responsável por pegar os produtos na classe Fornecedor e
reabastecer o estoque.csv);
• O menu no main deverá conter uma opção para listar os produtos do
fornecedor e outra para o estabelecimento reabastecer o estoque, solicitando o
produto e a quantidade;
• Deverá ser criada uma classe genérica chama vector_supemercado, onde essa
classe deve funcionar da mesma forma que a estrutura vector. A sacola (classe
Cliente), os produtos (classe Estabelecimento) e os produtos (classe
Fornecedor) deverão utilizar a implementação do vector_supemercado ao invés
do vector tradicional.
A atividade será avaliada de forma que a implementação e utilização correta da classe
vector_supermercado valerá 2,5. A implementação e utilização correta da classe
Fornecedor valerá 1,0 e as mudanças no main, Estabelecimento e Cliente valerão 0,5
cada.
*/