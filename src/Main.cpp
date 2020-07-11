#include "Cliente.h"
#include "Estabelecimento.h"

int main() {
  bool reset = false;
  char input;
  int code;
  float currency;
  Estabelecimento mercado;
  Produto produto;
  while (true) {
    Cliente cliente;
    while (true) {
      code = system("clear");
      std::cout << "SEJA BEM-VINDO AO MERCADO" << std::endl;    
      std::cout << "\n### MENU PRINCIPAL ###\n" << std::endl;
      std::cout << "Cliente #" << cliente.totalClientes << std::endl;
      std::cout << "Total de produtos diferentes no estoque: " << mercado.estoque.size() << std::endl;
      std::cout << "Saldo atual: R$ " << cliente.saldo << std::endl;
      std::cout << "Total de produtos diferentes na sacola: " << cliente.sacola.size() << std::endl;
      std::cout << "\nSELECIONE UMA OPÇÃO:\n" << std::endl;
      std::cout << "1) Adicionar valor ao meu saldo." << std::endl;
      std::cout << "2) Verificar os produtos da loja." << std::endl;
      std::cout << "3) Ver o conteúdo da minha sacola." << std::endl;
      std::cout << "4) Comprar produto." << std::endl;
      std::cout << "\n0) Finalizar compra.\n" << std::endl;
      std::cout << "Digite o código de uma das opções para continuar: ";
      std::cin >> input;
      code = system("clear");
      switch (input) {
        case '1':
          std::cout << "Digite o valor para ser adicionado: R$ ";
          std::cin >> currency;
          if (currency > 0) {
            code = currency * 100;
            cliente.saldo += ((float) code / 100);
          }
          break;
        case '2':
          mercado.listar();
          std::cout << "Deseja comprar um dos produtos listados (s/n)? ";
          std::cin >> input;
          if (input == 's') {
            std::cout << "Digite o código do produto: ";
            std::cin >> code;
            if (mercado.checar(code, &produto)) {
              if (cliente.saldo >= produto.preco) {
                mercado.venda(produto);
                cliente.compra(produto);
              } else {
                std::cout << "Saldo insuficiente." << std::endl;
                std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
                std::cin >> input;
              }
            } else {
              std::cout << "Código inválido." << std::endl;
              std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
              std::cin >> input;
            }
          }
          break;
        case '3':
          cliente.verSacola();
          break;
        case '4':
          mercado.listar();
          std::cout << "Digite o código do produto: ";
          std::cin >> code;
          if (mercado.checar(code, &produto)) {
            if (cliente.saldo >= produto.preco) {
              mercado.venda(produto);
              cliente.compra(produto);
            } else {
              std::cout << "Saldo insuficiente." << std::endl;
              std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
              std::cin >> input;
            }
          } else {
            std::cout << "Código inválido." << std::endl;
            std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
            std::cin >> input;
          }
          break;
        case '0':
          std::cout << "Deseja realizar compras com um novo cliente?" << std::endl;
          std::cout << "Aperte a tecla \'s\' para inicializar novo cliente." << std::endl;
          std::cout << "Aperte qualquer outra tecla para finalizar o programa." << std::endl;
          std::cin >> input;
          if (input == 's') {
            reset = true;
          } else {
            return 0;
          }
          break;
      }
      if (reset) {
        reset = false;
        break;
      }
    }
  }
}