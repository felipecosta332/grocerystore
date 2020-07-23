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

#include "Supermercado.h"

Supermercado::Supermercado() {
  this->totalItens = 0;
  this->totalItensVendas = 0;
  this->faturamento = 0;
  std::ifstream reader("files/estoque.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
      Produto produto;
      produto.preco = 0;
      std::stringstream line(input);
      line >> produto.codigo;
      if (produto.codigo > 0) {
        bool found = false;
        char trash;
        float number;
        line >> trash;
        getline(line, produto.produto, ',');
        getline(line, produto.unidadeMedida, ',');
        getline(line, input, ' ');
        line >> produto.preco;
        getline(line, input, ',');
        line >> produto.quantidade;
        for (int i = 0; i < estoque.size(); i++) {
          if (estoque.elements[i].codigo == produto.codigo) {
            estoque.elements[i].quantidade += produto.quantidade;
            found = true;
            break;
          }
        }
        if (!found) {
          estoque.push_back(produto);
        }
        totalItens += produto.quantidade;
      }
    }
  } else {
    std::cout << "O arquivo de estoque não foi aberto." << std::endl;
  }
  reader.close();
}

Supermercado::~Supermercado() {
  std::ofstream writer("files/caixaSupermercado.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    writer << vendas.elements[i].codigo << "," << vendas.elements[i].produto << "," 
    << vendas.elements[i].unidadeMedida << ",R$ " << vendas.elements[i].preco << "," 
    << vendas.elements[i].quantidade << std::endl;
  }
  writer << "QUANTIDADE DE ITENS DIFERENTES VENDIDOS: " << vendas.size() << std::endl;
  writer << "TOTAL DE ITENS VENDIDOS: " << totalItensVendas << std::endl;
  writer << "FATURAMENTO: R$ " << faturamento << std::endl;
  writer.close();
  writer.open("files/estoque.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    writer << estoque.elements[i].codigo << "," << estoque.elements[i].produto << "," 
    << estoque.elements[i].unidadeMedida << ",R$ " << estoque.elements[i].preco << "," 
    << estoque.elements[i].quantidade << std::endl;
  }
  writer.close();
}

void Supermercado::listar() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  std::cout << "TOTAL DE ITENS DIFERENTES NO ESTOQUE: " << estoque.size() << std::endl;
  std::cout << "TOTAL DE ITENS NO ESTOQUE: " << totalItens << std::endl;
  std::cout << "ESTOQUE DO SUPERMERCADO DISPONÍVEL:" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    std::cout << estoque.elements[i].codigo << "," << estoque.elements[i].produto << "," 
    << estoque.elements[i].unidadeMedida << ",R$ " << estoque.elements[i].preco << "," 
    << estoque.elements[i].quantidade << std::endl;
  }
}

void Supermercado::venda(Produto produto) {
  bool sold = false;
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque.elements[i].codigo == produto.codigo && estoque.elements[i].quantidade > 0) {
      std::cout << "PRODUTO DISPONÍVEL NO ESTOQUE." << std::endl;
      estoque.elements[i].quantidade--;
      for (int j = 0; j < vendas.size(); j++) {
        if (vendas.elements[j].codigo == produto.codigo) {
          vendas.elements[j].quantidade++;
          sold = true;
        }
      }
      if (!sold) {
        produto.quantidade = 1;
        vendas.push_back(produto);
      }
      faturamento += produto.preco;
      totalItens--;
      totalItensVendas++;
      return;
    }
  }
  std::cout << "PRODUTO INDISPONÍVEL NO ESTOQUE." << std::endl;
}

void Supermercado::caixa() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  std::cout << "CAIXA:" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    std::cout << vendas.elements[i].codigo << "," << vendas.elements[i].produto << "," 
    << vendas.elements[i].unidadeMedida << ",R$ " << vendas.elements[i].preco << "," 
    << vendas.elements[i].quantidade << std::endl;
  }
  std::cout << "QUANTIDADE DE ITENS DIFERENTES VENDIDOS: " << vendas.size() << std::endl;
  std::cout << "TOTAL DE ITENS VENDIDOS: " << totalItensVendas << std::endl;
  std::cout << "FATURAMENTO: R$ " << faturamento << std::endl;
  std::cout << "APERTE QUALQUER TECLA PARA CONTINUAR" << std::endl;
  std::cin >> key;
  key = system("clear");
}

bool Supermercado::checar(std::string nome, Produto* produto) {
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque.elements[i].produto == nome) {
      *produto = estoque.elements[i];
      return true;
    }
  }
  return false;
}

void Supermercado::reabastecer(Produto* demanda, int quantidade) {
  if (fornecedor.repassarProdutos(demanda, quantidade)) {
    totalItens += quantidade;
  }
}

long Supermercado::getTotalItens() {
  return this->totalItens;
}