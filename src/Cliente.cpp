#include "Cliente.h"

int Cliente::totalClientes;

Cliente::Cliente(){
  this->totalClientes++;
  this->saldo = 0;
}

Cliente::~Cliente(){
  registro();
}

void Cliente::compra(Produto produto){
  if (produto.preco > saldo) {
    std::cout << "Saldo insuficiente para realizar a compra de " << produto.produto << " por R$" 
    << produto.preco << std::endl;
  } else {
    saldo -= produto.preco;
    for (int i = 0; i < sacola.size(); i++) {
      if (sacola.elements[i].codigo == produto.codigo) {
        sacola.elements[i].quantidade++;
        return;
      }
    }
    produto.quantidade = 1;
    sacola.push_back(produto);
  }
}

void Cliente::verSacola(){
  char key;
  key = system("clear");
  for (int i = 0; i < sacola.size(); i++) {
    std::cout << sacola.elements[i].quantidade << " " << sacola.elements[i].unidadeMedida 
    << "s de " << sacola.elements[i].produto << std::endl;
  }
  std::cout << "Aperte qualquer tecla para sair ";
  std::cin >> key;
  key = system("clear");
}

void Cliente::registro(){
  if (totalClientes > 0) {
    std::stringstream filename;
    filename << "files/cliente_" << totalClientes << ".txt";
    std::ofstream writer(filename.str(), std::ios::out);
    writer << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
    for (int i = 0; i < sacola.size(); i++) {
      writer << sacola.elements[i].codigo << "," << sacola.elements[i].produto << "," << 
      sacola.elements[i].unidadeMedida << ",\"R$ " << sacola.elements[i].preco << "\"," << 
      sacola.elements[i].quantidade << std::endl;
    }
    writer.close();
  }
}