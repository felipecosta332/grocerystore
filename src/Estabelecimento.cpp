/*
• A classe Estabelecimento deverá conter um novo método chamado reabastecer
(esse método é responsável por pegar os produtos na classe Fornecedor e
reabastecer o estoque.csv);
*/

#include "Estabelecimento.h"

Estabelecimento::Estabelecimento() {
  std::ifstream reader("files/estoque.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
      Produto produto;
      produto.preco = 0;
      std::stringstream line(input);
      line >> produto.codigo;
      if (produto.codigo <= 0) {
        continue;
      } else {
        bool found = false;
        char trash;
        float number;
        line >> trash;
        getline(line, produto.produto, ',');
        getline(line, produto.unidadeMedida, ',');
        getline(line, input, ' ');
        line >> number;
        produto.preco += number;
        line >> trash;
        line >> number;
        produto.preco += (number/100);
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
      }
    }
  } else {
    std::cout << "O arquivo de estoque não foi aberto." << std::endl;
  }
  reader.close();
}

Estabelecimento::~Estabelecimento() {
  float faturamento = 0;
  std::ofstream writer("files/caixa.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    writer << vendas.elements[i].codigo << "," << vendas.elements[i].produto << "," 
    << vendas.elements[i].unidadeMedida << ",\"R$ ";
    int number = vendas.elements[i].preco;
    writer << number << ",";
    number = (int) (vendas.elements[i].preco * 100) % 100;
    writer << number << "\"," << vendas.elements[i].quantidade << std::endl;
    faturamento += (vendas.elements[i].preco * vendas.elements[i].quantidade);
  }
  writer << "FATURAMENTO: R$ " << faturamento << std::endl;
  writer.close();
  writer.open("files/estoque.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    writer << estoque.elements[i].codigo << "," << estoque.elements[i].produto << "," 
    << estoque.elements[i].unidadeMedida << ",\"R$ ";
    int number = estoque.elements[i].preco;
    writer << number << ",";
    number = (int) (estoque.elements[i].preco * 100) % 100;
    writer << number << "\"," << estoque.elements[i].quantidade << std::endl;
  }
  writer.close();
}

void Estabelecimento::listar() {
  char key;
  key = system("clear");
  std::cout << "FORMATO: COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  std::cout << "ESTOQUE DO ESTABELECIMENTO DISPONÍVEL:" << std::endl;
  for (int i = 0; i < estoque.size(); i++) {
    std::cout << estoque.elements[i].codigo << "," << estoque.elements[i].produto << "," 
    << estoque.elements[i].unidadeMedida << ",\"R$ ";
    int number = estoque.elements[i].preco;
    std::cout << number << ",";
    number = (int) (estoque.elements[i].preco * 100) % 100;
    std::cout << number << "\"," << estoque.elements[i].quantidade << std::endl;
  }
}

void Estabelecimento::venda(Produto produto) {
  bool sold = false;
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque.elements[i].codigo == produto.codigo) {
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
      if (estoque.elements[i].quantidade == 0) {
        estoque.remove(i);
      }
      return;
    }
  }
  std::cout << "PRODUTO INDISPONÍVEL NO ESTOQUE." << std::endl;
}

void Estabelecimento::caixa() {
  char key;
  float faturamento;
  key = system("clear");
  std::cout << "CAIXA:" << std::endl;
  for (int i = 0; i < vendas.size(); i++) {
    std::cout << vendas.elements[i].codigo << "," << vendas.elements[i].produto << "," 
    << vendas.elements[i].unidadeMedida << ",\"R$ ";
    int number = vendas.elements[i].preco;
    std::cout << number << ",";
    number = (int) (vendas.elements[i].preco * 100) % 100;
    std::cout << number << "\"," << vendas.elements[i].quantidade << std::endl;
    faturamento += (vendas.elements[i].preco * vendas.elements[i].quantidade);
  }
  std::cout << "FATURAMENTO: " << faturamento << std::endl;
  std::cout << "APERTE QUALQUER TECLA PARA CONTINUAR" << std::endl;
  std::cin >> key;
  key = system("clear");
}

bool Estabelecimento::checar(int chave, Produto* produto) {
  for (int i = 0; i < estoque.size(); i++) {
    if (estoque.elements[i].codigo == chave) {
      *produto = estoque.elements[i];
      return true;
    }
  }
  return false;
}

void Estabelecimento::reabastecer(Produto* demanda, int quantidade) {
  this->fornecedor.repassarProdutos(demanda, quantidade);
}