#include "Fornecedor.h"

Fornecedor::Fornecedor() : totalItens(0) {
  std::ifstream reader("files/fornecedor.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
      Produto produto;
      bool found = false;
      std::stringstream line(input);
      getline(line, produto.produto, ',');
      line >> produto.quantidade;
      if (produto.quantidade > 0) {
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
        totalItens += produto.quantidade;
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
  std::cout << "QUANTIDADE DE ITENS DIFERENTES NO ESTOQUE: " << estoque.size() << std::endl;
  std::cout << "TOTAL DE ITENS NO ESTOQUE: " << totalItens << std::endl;
  std::cout << "ESTOQUE DO FORNECEDOR DISPONÍVEL:" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    std::cout << estoque.elements[i].produto << "," << estoque.elements[i].quantidade 
    << std::endl;
  }
}

bool Fornecedor::repassarProdutos(Produto* demanda, int quantidade) {
  if (quantidade > 0) {
    char input;
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
        totalItens -= quantidade;
        estoque.elements[oferta].quantidade -= quantidade;
        demanda->quantidade += quantidade;
        if (estoque.elements[oferta].quantidade == 0) {
          estoque.remove(oferta);
        }
        std::cout << "REPASSE REALIZADO COM SUCESSO." << std::endl;
        std::cout << "Aperte qualquer tecla para continuar." << std::endl;
        std::cin >> input;
        return true;
      } else {
        std::cout << "QUANTIDADE INSUFICIENTE NO ESTOQUE DO FORNECEDOR." << std::endl;
      }
    } else {
      std::cout << "PRODUTO INDISPONÍVEL NO ESTOQUE DO FORNECEDOR." << std::endl;
    }
    std::cout << "Aperte qualquer tecla para continuar." << std::endl;
    std::cin >> input;
  }
  return false;
}

int Fornecedor::getTotalItens() {
  return this->totalItens;
}