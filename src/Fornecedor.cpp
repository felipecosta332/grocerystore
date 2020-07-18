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
*/

#include "Fornecedor.h"

Fornecedor::Fornecedor() {
  std::ifstream reader("files/fornecedor.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
      Produto produto;
      bool found = false;
      std::stringstream line(input);
      getline(line, produto.produto, ',');
      line >> produto.quantidade;
      if (produto.quantidade <= 0) {
        continue;
      }
      for (int i = 0; i < estoque.size(); i++) {
        if (estoque.elements[i].produto == produto.produto) {
          estoque.elements[i].quantidade += produto.quantidade;
          found = true;
          break;
        }
      }
      if (!found) {
        estoque.push_back(produto);
      }
    }
  } else {
    std::cout << "O arquivo de estoque do fornecedor não foi aberto." << std::endl;
  }
  reader.close();
}

Fornecedor::~Fornecedor() {
  std::ofstream writer("files/fornecedor.csv", std::ios::out);
  writer << "PRODUTO,QUANTIDADE" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    writer << estoque.elements[i].produto << "," << estoque.elements[i].quantidade 
    << std::endl;
  }
  writer.close();
}

void Fornecedor::listarProdutos() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: PRODUTO,QUANTIDADE" << std::endl;
  std::cout << "ESTOQUE DO FORNECEDOR DISPONÍVEL:" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    std::cout << estoque.elements[i].produto << "," << estoque.elements[i].quantidade 
    << std::endl;
  }
}

void Fornecedor::repassarProdutos(Produto* demanda, int quantidade) {
  if (quantidade > 0) {
    int oferta;
    bool disponivel = false;
    for (int i = 0; i < estoque.size(); i++) {
      if (estoque.elements[i].produto == demanda->produto) {
        oferta = i;
        disponivel = true;
      }
    }
    if (disponivel) {
      if (quantidade <= estoque.elements[oferta].quantidade) {
        estoque.elements[oferta].quantidade -= quantidade;
        demanda->quantidade += quantidade;
        if (estoque.elements[oferta].quantidade == 0) {
          estoque.remove(oferta);
        }
        std::cout << "REPASSE REALIZADO COM SUCESSO." << std::endl;
      } else {
        std::cout << "QUANTIDADE INSUFICIENTE NO ESTOQUE DO FORNECEDOR." << std::endl;
      }
    } else {
      std::cout << "PRODUTO INDISPONÍVEL NO ESTOQUE DO FORNECEDOR." << std::endl;
    }
  }
}