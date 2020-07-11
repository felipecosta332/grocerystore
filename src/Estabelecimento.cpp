#include "Estabelecimento.h"

Estabelecimento::Estabelecimento(){
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
        for (it = estoque.begin(); it != estoque.end(); ++it) {
          if (it->codigo == produto.codigo) {
            it->quantidade += produto.quantidade;
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

Estabelecimento::~Estabelecimento(){
  float faturamento = 0;
  std::ofstream writer("files/caixa.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (it = vendas.begin(); it != vendas.end(); ++it) {
    writer << it->codigo << "," << it->produto << "," << it->unidadeMedida << ",\"R$ ";
    int number = it->preco;
    writer << number << ",";
    number = (int) (it->preco * 100) % 100;
    writer << number << "\"," << it->quantidade << std::endl;
    faturamento += (it->preco * it->quantidade);
  }
  writer << "FATURAMENTO: R$ " << faturamento << std::endl;
  writer.close();
  writer.open("files/estoque.csv", std::ios::out);
  writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (it = estoque.begin(); it != estoque.end(); ++it) {
    writer << it->codigo << "," << it->produto << "," << it->unidadeMedida << ",\"R$ ";
    int number = it->preco;
    writer << number << ",";
    number = (int) (it->preco * 100) % 100;
    writer << number << "\"," << it->quantidade << std::endl;
  }
  writer.close();
}

void Estabelecimento::listar(){
  char key;
  key = system("clear");
  std::cout << "FORMATO: COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  std::cout << "ESTOQUE DISPONÍVEL:" << std::endl;
  for (it = estoque.begin(); it != estoque.end(); ++it) {
    std::cout << it->codigo << "," << it->produto << "," << it->unidadeMedida << ",\"R$ ";
    int number = it->preco;
    std::cout << number << ",";
    number = (int) (it->preco * 100) % 100;
    std::cout << number << "\"," << it->quantidade << std::endl;
  }
}

void Estabelecimento::venda(Produto produto){
  bool sold = false;
  for (it = estoque.begin(); it != estoque.end(); ++it) {
    if (it->codigo == produto.codigo) {
      std::cout << "PRODUTO DISPONÍVEL NO ESTOQUE." << std::endl;
      it->quantidade--;
      for (it2 = vendas.begin(); it2 != vendas.end(); ++it2) {
        if (it2->codigo == produto.codigo) {
          it2->quantidade++;
          sold = true;
        }
      }
      if (!sold) {
        produto.quantidade = 1;
        vendas.push_back(produto);
      }
      if (it->quantidade == 0) {
        it = estoque.erase(it);
      }
      return;
    }
  }
  std::cout << "PRODUTO INDISPONÍVEL NO ESTOQUE." << std::endl;
}

void Estabelecimento::caixa(){
  char key;
  float faturamento;
  key = system("clear");
  std::cout << "CAIXA:" << std::endl;
  for (it = vendas.begin(); it != vendas.end(); ++it) {
    std::cout << it->codigo << "," << it->produto << "," << it->unidadeMedida << ",\"R$ ";
    int number = it->preco;
    std::cout << number << ",";
    number = (int) (it->preco * 100) % 100;
    std::cout << number << "\"," << it->quantidade << std::endl;
    faturamento += (it->preco * it->quantidade);
  }
  std::cout << "FATURAMENTO: " << faturamento << std::endl;
  std::cout << "APERTE QUALQUER TECLA PARA CONTINUAR" << std::endl;
  std::cin >> key;
  key = system("clear");
}

bool Estabelecimento::checar(int chave, Produto* produto){
  for (it = estoque.begin(); it != estoque.end(); ++it) {
    if (it->codigo == chave) {
      *produto = *it;
      return true;
    }
  }
  return false;
}