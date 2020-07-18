/*
• O menu no main deverá conter uma opção para listar os produtos do
fornecedor e outra para o estabelecimento reabastecer o estoque, solicitando o
produto e a quantidade;
*/

#include "App.h"

App::App() : reset(false) {}

void App::runApp() {
  while (true) {
    Cliente cliente;
    while (true) {
      showMenu(&cliente);
      switch (input) {
        case '1':
          addSaldo(&cliente);
          break;
        case '2':
          mostrarVitrine(&cliente);
          break;
        case '3':
          cliente.verSacola();
          break;
        case '4':
          comprar(&cliente);
          break;
        case '5':
          mostrarFornecedor();
          break;
        case '6':
          reabastecer();
          break;
        case '0':
          std::cout << "Deseja realizar compras com um novo cliente?" << std::endl;
          std::cout << "Aperte a tecla \'s\' para inicializar novo cliente." << std::endl;
          std::cout << "Aperte qualquer outra tecla para finalizar o programa." << std::endl;
          std::cin >> input;
          if (input == 's') {
            reset = true;
          } else {
            return;
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

void App::showMenu(Cliente* cliente) {
  code = system("clear");
  std::cout << "SEJA BEM-VINDO AO MERCADO" << std::endl;    
  std::cout << "\n### MENU PRINCIPAL ###\n" << std::endl;
  std::cout << "Cliente #" << cliente->totalClientes << std::endl;
  std::cout << "Total de produtos diferentes no estoque: " << mercado.estoque.size() << std::endl;
  std::cout << "Saldo atual: R$ " << cliente->saldo << std::endl;
  std::cout << "Total de produtos diferentes na sacola: " << cliente->sacola.size() << std::endl;
  std::cout << "\nSELECIONE UMA OPÇÃO:\n" << std::endl;
  std::cout << "1) Adicionar valor ao meu saldo." << std::endl;
  std::cout << "2) Verificar os produtos da loja." << std::endl;
  std::cout << "3) Ver o conteúdo da minha sacola." << std::endl;
  std::cout << "4) Comprar produto." << std::endl;
  std::cout << "5) Listar os produtos do fornecedor." << std::endl;
  std::cout << "6) Reabastecer o estoque." << std::endl;
  std::cout << "\n0) Finalizar compra.\n" << std::endl;
  std::cout << "Digite o código de uma das opções para continuar: ";
  std::cin >> input;
  code = system("clear");
}

void App::addSaldo(Cliente* cliente) {
  std::cout << "Digite o valor para ser adicionado: R$ ";
  std::cin >> currency;
  if (currency > 0) {
    code = currency * 100;
    cliente->saldo += ((float) code / 100);
  }
}

void App::mostrarVitrine(Cliente* cliente) {
  // A compra deve ser feita pelo nome do produto, o código deve ser usado apenas internamente.
  mercado.listar();
  std::cout << "Deseja comprar um dos produtos listados (s/n)? ";
  std::cin >> input;
  if (input == 's') {
    std::cout << "Digite o código do produto: ";
    std::cin >> code;
    if (mercado.checar(code, &produto)) {
      if (cliente->saldo >= produto.preco) {
        mercado.venda(produto);
        cliente->compra(produto);
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
}

void App::comprar(Cliente* cliente) {
  // A compra deve ser feita pelo nome do produto, o código deve ser usado apenas internamente.
  mercado.listar();
  std::cout << "Digite o código do produto: ";
  std::cin >> code;
  if (mercado.checar(code, &produto)) {
    if (cliente->saldo >= produto.preco) {
      mercado.venda(produto);
      cliente->compra(produto);
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

void App::mostrarFornecedor() {
  /*
• O menu no main deverá conter uma opção para listar os produtos do
fornecedor e outra para o estabelecimento reabastecer o estoque, solicitando o
produto e a quantidade;
*/
  mercado.fornecedor.listarProdutos();
  std::cout << "Digite qualquer tecla para continuar: ";
  std::cin >> input;
}

void App::reabastecer() {
  /*
• O menu no main deverá conter uma opção para listar os produtos do
fornecedor e outra para o estabelecimento reabastecer o estoque, solicitando o
produto e a quantidade;
*/
  int quantidade;
  std::string nomeProduto;
  Produto* produto = nullptr;
  mercado.fornecedor.listarProdutos();
  std::cout << "Digite o nome do produto para ser reabastecido:" << std::endl;
  getline(std::cin, nomeProduto);
  getline(std::cin, nomeProduto);
  std::cout << "Digite a quantidade desejada: ";
  std::cin >> quantidade;
  for (int i = 0; i < mercado.estoque.size(); i++) {
    if (mercado.estoque.elements[i].produto == nomeProduto) {
      produto = &mercado.estoque.elements[i];
      mercado.fornecedor.repassarProdutos(produto, quantidade);
      return;
    }
  }
  std::cout << "ESSE PRODUTO NÃO EXISTE NO ESTOQUE." << std::endl;
}