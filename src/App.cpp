#include "App.h"

App::App() : reset(true) {}

void App::runApp() {
  while (reset) {
    Cliente cliente;
    addSaldo(&cliente);
    selectApp(&cliente);
  }
}

void App::selectApp(Cliente* cliente) {
  while (true) {
    code = system("clear");
    std::cout << "### MENU PRINCIPAL ###\n" << std::endl;
    std::cout << "Cliente #" << cliente->getTotalClientes() << std::endl;
    std::cout << "Faturamento do supermercado: R$ " << mercado.getFaturamento() << std::endl;
    std::cout << "Faturamento do restaurante: R$ " << restaurante.getFaturamento() << std::endl;
    std::cout << "Quantidade de itens diferentes na sacola: " << cliente->sacola.size() << std::endl;
    std::cout << "Quantidade de itens diferentes consumidos no restaurante: " << cliente->conta.size() << std::endl;
    std::cout << "Quantidade de itens comprados no supermercado: " << cliente->getTotalItensMercado() << std::endl;
    std::cout << "Quantidade de itens consumidos no restaurante: " << cliente->getTotalItensRestaurante() << std::endl;
    std::cout << "Quantidade de itens comprados/consumidos ao todo: " << cliente->getTotalItens() << std::endl;
    std::cout << "Valor total gasto no supermercado: R$ " << cliente->getContaMercado() << std::endl;
    std::cout << "Valor total gasto no restaurante: R$ " << cliente->getContaRestaurante() << std::endl;
    std::cout << "Valor total gasto ao todo: R$ " << cliente->getContaTotal() << std::endl;
    std::cout << "Saldo atual: R$ " << cliente->getSaldo() << std::endl;
    std::cout << "\nSELECIONE UMA OPÇÃO:\n" << std::endl;
    std::cout << "1) Entrar no supermercado." << std::endl;
    std::cout << "2) Entrar no restaurante." << std::endl;
    std::cout << "3) Ver o conteúdo da minha sacola." << std::endl;
    std::cout << "4) Ver minha conta do restaurante." << std::endl;
    std::cout << "\n0) Inicializar novo cliente ou finalizar programa.\n" << std::endl;
    std::cout << "Digite o código de uma das opções para continuar: ";
    std::cin >> input;
    code = system("clear");
    switch (input) {
      case '1':
        appSupermercado(cliente);
        break;
      case '2':
        appRestaurante(cliente);
        break;
      case '3':
        cliente->verSacola();
        break;
      case '4':
        cliente->verConta();
        break;
      case '0':
        resetar(&reset);
        return;
      default:
        warning();
    }
  }
}

void App::appSupermercado(Cliente* cliente) {
  while (true) {
    code = system("clear");
    std::cout << "SEJA BEM-VINDO AO SUPERMERCADO" << std::endl;
    std::cout << "\n### MENU PRINCIPAL ###\n" << std::endl;
    std::cout << "Cliente #" << cliente->getTotalClientes() << std::endl;
    std::cout << "Quantidade de itens na sacola: " << cliente->getTotalItensMercado() << std::endl;
    std::cout << "Quantidade de itens no estoque: " << mercado.getTotalItens() << std::endl;
    std::cout << "Quantidade de itens do fornecedor: " << mercado.fornecedor.getTotalItens() << std::endl;
    std::cout << "Quantidade de itens vendidos ao todo: " << mercado.getTotalItensVendas() << std::endl;
    std::cout << "Total de itens diferentes na sacola: " << cliente->sacola.size() << std::endl;
    std::cout << "Total de itens diferentes no estoque: " << mercado.estoque.size() << std::endl;
    std::cout << "Total de itens diferentes do fornecedor: " << mercado.fornecedor.estoque.size() << std::endl;
    std::cout << "Total de itens diferentes vendidos ao todo: " << mercado.vendas.size() << std::endl;
    std::cout << "Valor total gasto no supermercado: R$ " << cliente->getContaMercado() << std::endl;
    std::cout << "Faturamento do supermercado: R$ " << mercado.getFaturamento() << std::endl;
    std::cout << "Saldo atual: R$ " << cliente->getSaldo() << std::endl;
    std::cout << "\nSELECIONE UMA OPÇÃO:\n" << std::endl;
    std::cout << "1) Verificar os produtos da loja." << std::endl;
    std::cout << "2) Ver o conteúdo da minha sacola." << std::endl;
    std::cout << "3) Comprar produto." << std::endl;
    std::cout << "4) Listar os produtos do fornecedor." << std::endl;
    std::cout << "5) Reabastecer o estoque." << std::endl;
    std::cout << "6) Exibir caixa do supermercado." << std::endl;
    std::cout << "\n0) Sair do mercado.\n" << std::endl;
    std::cout << "Digite o código de uma das opções para continuar: ";
    std::cin >> input;
    code = system("clear");
    switch (input) {
      case '1':
        mostrarVitrine(cliente);
        break;
      case '2':
        cliente->verSacola();
        break;
      case '3':
        comprarMercado(cliente);
        break;
      case '4':
        mostrarFornecedor();
        break;
      case '5':
        reabastecer();
        break;
      case '6':
        mercado.caixa();
        break;
      case '0':
        return;
      default:
        warning();
    }
  }
}

void App::appRestaurante(Cliente* cliente) {
  while (true) {
    code = system("clear");
    std::cout << "SEJA BEM-VINDO AO RESTAURANTE" << std::endl;
    std::cout << "\n### MENU PRINCIPAL ###\n" << std::endl;
    std::cout << "Cliente #" << cliente->getTotalClientes() << std::endl;
    std::cout << "Total de opções diferentes no cardápio: " << restaurante.cardapio.size() << std::endl;
    std::cout << "Faturamento do restaurante: R$ " << restaurante.getFaturamento() << std::endl;
    std::cout << "Conta total: R$ " << cliente->getContaRestaurante() << std::endl;
    std::cout << "Saldo atual: R$ " << cliente->getSaldo() << std::endl;
    std::cout << "\nSELECIONE UMA OPÇÃO:\n" << std::endl;
    std::cout << "1) Listar as opções do cardápio." << std::endl;
    std::cout << "2) Fazer pedido." << std::endl;
    std::cout << "3) Ver minha conta." << std::endl;
    std::cout << "4) Exibir caixa do restaurante." << std::endl;
    std::cout << "\n0) Sair do restaurante.\n" << std::endl;
    std::cout << "Digite o código de uma das opções para continuar: ";
    std::cin >> input;
    code = system("clear");
    switch (input) {
      case '1':
        listarCardapio(cliente);
        break;
      case '2':
        fazerPedido(cliente);
        break;
      case '3':
        cliente->verConta();
        break;
      case '4':
        restaurante.caixa();
        break;
      case '0':
        return;
      default:
        warning();
    }
  }
}

void App::addSaldo(Cliente* cliente) {
  code = system("clear");
  std::cout << "Digite o valor inicial do saldo: R$ ";
  try {
    std::cin >> currency;
    if (currency > 0) {
      code = currency * 100;
      cliente->setSaldo((float) code / 100);
    } else {
      throw (currency);
    }
  } catch (double num) {
    std::cout << "O saldo deve ser maior que zero." << std::endl;
    std::cout << num << " não é maior que zero!" << std::endl;
    std::cout << "Digite qualquer tecla para continuar: ";
    std::cin >> input;
  }
}

void App::mostrarVitrine(Cliente* cliente) {
  mercado.listar();
  std::cout << "Deseja comprar um dos produtos listados (s/n)? ";
  std::cin >> input;
  if (input == 's') {
    std::cout << "Digite o nome do produto: " << std::endl;
    getline(std::cin, line);
    getline(std::cin, line);
    std::cout << "Digite a quantidade do produto: ";
    std::cin >> code;
    if (code > 0) {
      if (mercado.checar(line, &produto)) {
        if (cliente->getSaldo() >= (produto.preco * code)) {
          for (int i = 0; i < code; i++) {
            mercado.venda(produto);
            cliente->compraMercado(produto);
          }
        } else {
          std::cout << "Saldo insuficiente." << std::endl;
          std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
          std::cin >> input;
        }
      } else {
        std::cout << "Produto inexistente no estoque." << std::endl;
        std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
        std::cin >> input;
      }
    } else {
      std::cout << "A quantidade tem que ser pelo menos 1." << std::endl;
      std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
      std::cin >> input;
    }
  }
}

void App::comprarMercado(Cliente* cliente) {
  mercado.listar();
  std::cout << "Digite o nome do produto: " << std::endl;
  getline(std::cin, line);
  getline(std::cin, line);
  std::cout << "Digite a quantidade do produto: ";
  std::cin >> code;
  if (code > 0) {
    if (mercado.checar(line, &produto)) {
      if (cliente->getSaldo() >= (produto.preco * code)) {
        for (int i = 0; i < code; i++) {
          mercado.venda(produto);
          cliente->compraMercado(produto);
        }
      } else {
        std::cout << "Saldo insuficiente." << std::endl;
        std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
        std::cin >> input;
      }
    } else {
      std::cout << "Produto inexistente no estoque." << std::endl;
      std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
      std::cin >> input;
    }
  } else {
    std::cout << "A quantidade tem que ser pelo menos 1." << std::endl;
    std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
    std::cin >> input;
  }
}

void App::mostrarFornecedor() {
  mercado.fornecedor.listarProdutos();
  std::cout << "Digite qualquer tecla para continuar: ";
  std::cin >> input;
}

void App::reabastecer() {
  int quantidade;
  std::string nomeProduto;
  Produto* produto = nullptr;
  mercado.fornecedor.listarProdutos();
  std::cout << "Digite o nome do produto para ser reabastecido:" << std::endl;
  getline(std::cin, nomeProduto);
  getline(std::cin, nomeProduto);
  std::cout << "Digite a quantidade desejada: ";
  try {
    std::cin >> quantidade;
    if (quantidade < 1) {
      throw (quantidade);
    }
    for (int i = 0; i < mercado.estoque.size(); i++) {
      if (mercado.estoque.elements[i].produto == nomeProduto) {
        produto = &mercado.estoque.elements[i];
        mercado.reabastecer(produto, quantidade);
        return;
      }
    }
    std::cout << "ESSE PRODUTO NÃO EXISTE NO ESTOQUE." << std::endl;
  } catch (int num) {
    std::cout << "A quantidade deve ser de no mínimo UM." << std::endl;
    std::cout << num << " é menor que UM!" << std::endl;
    std::cout << "Digite qualquer tecla para continuar: ";
    std::cin >> input;
  }
}

void App::listarCardapio(Cliente* cliente) {
  restaurante.listar();
  std::cout << "Deseja comprar um dos produtos listados (s/n)? ";
  std::cin >> input;
  if (input == 's') {
    std::cout << "Digite o nome do produto:" << std::endl;
    getline(std::cin, line);
    getline(std::cin, line);
    std::cout << "Digite a quantidade desejada: ";
    std::cin >> code;
    if (code > 0) {
      if (restaurante.checar(line, &produto)) {
        if (cliente->getSaldo() >= (produto.preco * code)) {
          for (int i = 0; i < code; i++) {
            restaurante.venda(produto);
            cliente->compraRestaurante(produto);
          }
        } else {
          std::cout << "Saldo insuficiente." << std::endl;
          std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
          std::cin >> input;
        }
      } else {
        std::cout << "Produto inexistente no cardápio." << std::endl;
        std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
        std::cin >> input;
      }
    } else {
      std::cout << "A quantidade tem que ser pelo menos 1." << std::endl;
      std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
      std::cin >> input;
    }
  }
}

void App::fazerPedido(Cliente* cliente) {
  restaurante.listar();
  std::cout << "Digite o nome do produto:" << std::endl;
  getline(std::cin, line);
  getline(std::cin, line);
  std::cout << "Digite a quantidade desejada: ";
  std::cin >> code;
  if (code > 0) {
    if (restaurante.checar(line, &produto)) {
      if (cliente->getSaldo() >= (produto.preco * code)) {
        for (int i = 0; i < code; i++) {
          restaurante.venda(produto);
          cliente->compraRestaurante(produto);
        }
      } else {
        std::cout << "Saldo insuficiente." << std::endl;
        std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
        std::cin >> input;
      }
    } else {
      std::cout << "Produto inexistente no cardápio." << std::endl;
      std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
      std::cin >> input;
    }
  } else {
    std::cout << "A quantidade tem que ser pelo menos 1." << std::endl;
    std::cout << "Digite qualquer tecla para voltar ao menu" << std::endl;
    std::cin >> input;
  }
}

void App::resetar(bool* reset) {
  std::cout << "Deseja realizar compras com um novo cliente?" << std::endl;
  std::cout << "Aperte a tecla \'s\' para inicializar novo cliente." << std::endl;
  std::cout << "Aperte qualquer outra tecla para finalizar o programa." << std::endl;
  std::cin >> input;
  if (input == 's') {
    *reset = true;
  } else {
    *reset = false;
  }
}

void App::warning() {
  std::cout << "Código inválido." << std::endl;
  std::cout << "Aperte qualquer tecla para continuar:" << std::endl;
  std::cin >> input;
}