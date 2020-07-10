/*
- A classe Cliente deve ter os atributos: saldo, sacola (vector de string);
- No saldo vai conter quanto o cliente tem em dinheiro e pode gastar em
compras;
- Na sacola vai conter todas as compras do cliente;
- As classes deve fazer uso de construtores que não sejam os construtores
padrão. Como os construtores serão implementados fica a critério de vocês;
*/
#include "Cliente.h"

Cliente::Cliente(float saldo){
  this->totalClientes++;
  if (saldo < 0) {
    this->saldo = 0;
  } else {
    int cleaner = saldo * 100;
    this->saldo = cleaner / 100;
  }
}

void Cliente::compra(Produto produto){
  /*compra (recebe o produto e o preço, o
método deve verificar se o cliente tem saldo suficiente para comprar o produto,
se não, emite um aviso, se sim, faz a compra, diminui o saldo e adiciona o
produto na sacola)*/
  if (produto.preco > saldo) {
    std::cout << "Saldo insuficiente para realizar a compra de " << produto.produto << " por R$" 
    << produto.preco << std::endl;
  } else {
    saldo -= produto.preco;
    for (int i = 0; i < sacola.size(); i++) {
      if (sacola[i].codigo == produto.codigo) {
        sacola[i].quantidade++;
        return;
      }
    }
    sacola.push_back(produto);
    sacola[sacola.size()-1].quantidade = 1;
  }
}

void Cliente::verSacola(){
  /*verSacola (mostra o conteúdo da sacola)*/
  char key;
  system("clear");
  for (int i = 0; i < sacola.size(); i++) {
    std::cout << sacola[i].quantidade << " " << sacola[i].unidadeMedida << "s de " << 
    sacola[i].produto << std::endl;
  }
  std::cout << "Aperte qualquer tecla para sair ";
  std::cin >> key;
  system("clear");
}

void Cliente::registro(){
  /*registro(esse método escreve o conteúdo da sacola em um arquivo chamado cliente_x.txt,
onde para cada cliente dever um arquivo próprio mudando x para 1, 2, 3, etc.
Até a quantidade de clientes existentes;*/
  if (totalClientes > 0) {
    std::stringstream filename;
    filename << "files/cliente_" << totalClientes << ".txt";
    std::ofstream writer(filename.str(), std::ios::out);
    for (int i = 0; i < sacola.size(); i++) {
      writer << sacola[i].codigo << "," << sacola[i].produto << "," << 
      sacola[i].unidadeMedida << ",\"R$ " << sacola[i].preco << "\"," << 
      sacola[i].quantidade << std::endl;
    }
    writer.close();
  }
}