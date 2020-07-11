#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Produto {
  public:
    unsigned int codigo;
    std::string produto;
    std::string unidadeMedida;
    float preco;
    unsigned int quantidade;
};

void test(){
  std::cout << "before" << std::endl;
  std::cout << "after" << std::endl;
}

int main() {
  std::ifstream reader("./files/estoque.csv", std::ios::in);
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
        std::cout << produto.codigo <<" "<< produto.produto <<" "<< produto.unidadeMedida <<" "<< produto.preco <<" "<< produto.quantidade << std::endl;
      }
    }
  } else {
    std::cout << "O arquivo de estoque não foi aberto." << std::endl;
  }
  reader.close();
  return 0;
}