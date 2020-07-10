#include "Estabelecimento.h"

Estabelecimento::Estabelecimento(){
  /*- A classe Estabelecimento deverá consultar os produtos através do arquivo
estoque.csv.*/
  std::ifstream reader("files/estoque.csv", std::ios::in);
  if (reader.is_open()) {
    std::string input;
    while (getline(reader, input)) {
      Produto produto;
      std::stringstream line(input);
      line >> produto.codigo;
      if (produto.codigo <= 0) {
        continue;
      } else {
        
      }
    }
  } else {
    std::cout << "O arquivo de estoque não foi aberto." << std::endl;
  }
  reader.close();
}

Estabelecimento::~Estabelecimento(){
  /*A classe também deve gerar um arquivo de saída chamado
caix.csv, esse arquivo deve conter os produtos vendidos e o total de dinheiro
ganho nas vendas;
- O arquivo caixa.csv deve conter o código do produto, nome, preço, a
quantidade vendida de cada produto e o total de vendas;*/
}

void Estabelecimento::listar(){
  /*listar (lista os
produtos disponíveis)*/
}

void Estabelecimento::venda(Produto produto){
  /*venda (recebe como parâmetro o código do produto,
verifica se ainda existe esse produto no estoque, se não retorna uma mensagem
de insucesso, se sim, retorna uma mensagem de sucesso e escreve no arquivo
de saída a venda efetuada)*/
}

void Estabelecimento::caixa(){
  /*caixa (retorna tudo o que foi vendido e o total
ganho)*/
}