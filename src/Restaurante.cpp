#include "Restaurante.h"

Restaurante::Restaurante() {
  this->totalItensVendas = 0;
  this->faturamento = 0;
  std::ifstream reader("files/menu.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
        bool found = false;
        Produto produto;
        std::stringstream line(input);
        getline(line, produto.produto, ',');
        line >> input;
        line >> produto.preco;
        if (produto.produto != "ITEM" && produto.preco > 0) {
          for (int i = 0; i < cardapio.size(); i++) {
            if (cardapio.elements[i].produto == produto.produto) {
                found = true;
                break;
            }
          }
          if (!found) {
              cardapio.push_back(produto);
          }
        }
    }
  } else {
    std::cout << "O arquivo do menu não foi aberto." << std::endl;
  }
  reader.close();
}

Restaurante::~Restaurante() {
  std::ofstream writer("files/caixaRestaurante.csv", std::ios::out);
  writer << "ITEM,PREÇO,QTDVENDIDA" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    writer << vendas.elements[i].produto << ",R$ " << vendas.elements[i].preco << "," << vendas.elements[i].quantidade << std::endl;
  }
  writer << "QUANTIDADE DE ITENS DIFERENTES VENDIDOS: " << vendas.size() << std::endl;
  writer << "TOTAL DE ITENS VENDIDOS: " << totalItensVendas << std::endl;
  writer << "FATURAMENTO: R$ " << faturamento << std::endl;
  writer.close();
}

void Restaurante::listar() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: ITEM,PREÇO" << std::endl;
  std::cout << "QUANTIDADE DE ITENS DIFERENTES NO CARDÁPIO: " << cardapio.size() << std::endl;
  std::cout << "CARDÁPIO DO RESTAURANTE:" << std::endl;
  for (int i = 0; i < cardapio.size(); i++) {
    std::cout << cardapio.elements[i].produto << ",R$ " << cardapio.elements[i].preco << std::endl;
  }
}

void Restaurante::venda(Produto produto) {
  bool sold = false;
  for (int i = 0; i < cardapio.size(); i++) {
    if (cardapio.elements[i].produto == produto.produto) {
      std::cout << "PRODUTO DISPONÍVEL NO CARDÁPIO." << std::endl;
      for (int j = 0; j < vendas.size(); j++) {
        if (vendas.elements[j].produto == produto.produto) {
          vendas.elements[j].quantidade++;
          sold = true;
        }
      }
      if (!sold) {
        produto.quantidade = 1;
        vendas.push_back(produto);
      }
      faturamento += produto.preco;
      totalItensVendas++;
      return;
    }
  }
  std::cout << "PRODUTO INDISPONÍVEL NO CARDÁPIO." << std::endl;
}

void Restaurante::caixa() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: ITEM,PREÇO,QTD" << std::endl;
  std::cout << "CAIXA:" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    std::cout << vendas.elements[i].produto << ",R$ " << vendas.elements[i].preco << "," << vendas.elements[i].quantidade << std::endl;
  }
  std::cout << "QUANTIDADE DE ITENS DIFERENTES VENDIDOS: " << vendas.size() << std::endl;
  std::cout << "TOTAL DE ITENS VENDIDOS: " << totalItensVendas << std::endl;
  std::cout << "FATURAMENTO: R$ " << faturamento << std::endl;
  std::cout << "APERTE QUALQUER TECLA PARA CONTINUAR" << std::endl;
  std::cin >> key;
  key = system("clear");
}

bool Restaurante::checar(std::string nome, Produto* produto) {
  for (int i = 0; i < cardapio.size(); i++) {
    if (cardapio.elements[i].produto == nome) {
      *produto = cardapio.elements[i];
      return true;
    }
  }
  return false;
}