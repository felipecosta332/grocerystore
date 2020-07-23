#include "Cliente.h"

int Cliente::totalClientes;

Cliente::Cliente() {
  this->totalClientes++;
  this->totalItens = 0;
  this->totalItensMercado = 0;
  this->totalItensRestaurante = 0;
  this->saldo = 0;
  this->contaMercado = 0;
  this->contaRestaurante = 0;
  this->contaTotal = 0;
}

Cliente::~Cliente(){
  registro();
}

void Cliente::compraMercado(Produto produto){
  if (produto.preco > saldo) {
    std::cout << "Saldo insuficiente para realizar a compra de " << produto.produto << " por R$" 
    << produto.preco << std::endl;
  } else {
    saldo -= produto.preco;
    totalItens++;
    totalItensMercado++;
    contaTotal += produto.preco;
    contaMercado += produto.preco;
    for (int i = 0; i < sacola.size(); i++) {
      if (sacola.elements[i].produto == produto.produto) {
        sacola.elements[i].quantidade++;
        return;
      }
    }
    produto.quantidade = 1;
    sacola.push_back(produto);
  }
}

void Cliente::compraRestaurante(Produto produto){
  if (produto.preco > saldo) {
    std::cout << "Saldo insuficiente para realizar a compra de " << produto.produto << " por R$" 
    << produto.preco << std::endl;
  } else {
    saldo -= produto.preco;
    totalItens++;
    totalItensRestaurante++;
    contaTotal += produto.preco;
    contaRestaurante += produto.preco;
    for (int i = 0; i < conta.size(); i++) {
      if (conta.elements[i].produto == produto.produto) {
        conta.elements[i].quantidade++;
        return;
      }
    }
    produto.quantidade = 1;
    conta.push_back(produto);
  }
}

void Cliente::verSacola(){
  char key;
  key = system("clear");
  std::cout << "CONTA DO MERCADO" << std::endl;
  for (int i = 0; i < sacola.size(); i++) {
    std::cout << sacola.elements[i].quantidade << " " << sacola.elements[i].unidadeMedida 
    << "s de " << sacola.elements[i].produto << " por R$ " << sacola.elements[i].preco 
    << " cada." << std::endl;
  }
  std::cout << "VALOR TOTAL: R$ " << contaMercado << std::endl;
  std::cout << "Aperte qualquer tecla para sair ";
  std::cin >> key;
  key = system("clear");
}

void Cliente::verConta(){
  char key;
  key = system("clear");
  std::cout << "CONTA DO RESTAURANTE" << std::endl;
  for (int i = 0; i < conta.size(); i++) {
    std::cout << conta.elements[i].quantidade << " unidades de " << conta.elements[i].produto << " por R$ " 
    << conta.elements[i].preco << " cada." << std::endl;
  }
  std::cout << "VALOR TOTAL: R$ " << contaRestaurante << std::endl;
  std::cout << "Aperte qualquer tecla para sair ";
  std::cin >> key;
  key = system("clear");
}

void Cliente::registro(){
  std::stringstream filename;
  filename << "files/cliente_" << totalClientes << ".csv";
  std::ofstream writer(filename.str(), std::ios::out);
  writer << "CLIENTE #" << totalClientes << std::endl;
  writer << "Quantidade de itens comprados no supermercado: " << totalItensMercado << std::endl;
  writer << "Quantidade de itens consumidos no restaurante: " << totalItensRestaurante << std::endl;
  writer << "Quantidade de itens comprados/consumidos ao todo: " << totalItens << std::endl;
  writer << "Valor total gasto no supermercado: R$ " << contaMercado << std::endl;
  writer << "Valor total gasto no restaurante: R$ " << contaRestaurante << std::endl;
  writer << "Valor total gasto ao todo: R$ " << contaTotal << std::endl;
  writer << "Saldo final: R$ " << saldo << std::endl;
  writer << "\nSACOLA COM COMPRAS DO SUPERMERCADO:" << std::endl;
  writer << "FORMATO: COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < sacola.size(); i++) {
    writer << sacola.elements[i].codigo << "," << sacola.elements[i].produto << "," << 
    sacola.elements[i].unidadeMedida << ",R$ " << sacola.elements[i].preco << "," << 
    sacola.elements[i].quantidade << std::endl;
  }
  writer << "\nLISTA DE ITENS CONSUMIDOS NO RESTAURANTE:" << std::endl;
  writer << "FORMATO: ITEM,PREÇO,QUANTIDADE" << std::endl;
  for (int i = 0; i < conta.size(); i++) {
    writer << conta.elements[i].produto << ",R$ " << conta.elements[i].preco << "," 
    << conta.elements[i].quantidade << std::endl;
  }
  writer.close();
}

int Cliente::getTotalClientes() {
  return this->totalClientes;
}

int Cliente::getTotalItens() {
  return this->totalItens;
}

int Cliente::getTotalItensMercado() {
  return this->totalItensMercado;
}

int Cliente::getTotalItensRestaurante() {
  return this->totalItensRestaurante;
}

double Cliente::getSaldo() {
  return this->saldo;
}

double Cliente::getContaMercado() {
  return this->contaMercado;
}

double Cliente::getContaRestaurante() {
  return this->contaRestaurante;
}

double Cliente::getContaTotal() {
  return this->contaTotal;
}

void Cliente::setSaldo(double saldo) {
  this->saldo = saldo;
}