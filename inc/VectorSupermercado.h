/*
• Deverá ser criada uma classe genérica chama vector_supemercado, onde essa
classe deve funcionar da mesma forma que a estrutura vector. A sacola (classe
Cliente), os produtos (classe Estabelecimento) e os produtos (classe
Fornecedor) deverão utilizar a implementação do vector_supemercado ao invés
do vector tradicional.
*/

#ifndef VECTORSUPERMERCADO_H
#define VECTORSUPERMERCADO_H

#include <iostream>

template <class T> 
class VectorSupermercado {
  private:
    unsigned int vector_capacity;
    unsigned int vector_size;
  public:
    T* elements;
    VectorSupermercado();
    VectorSupermercado(int capacity);
    ~VectorSupermercado();
    T back();
    int capacity();
    bool empty();
    T front();
    void pop_back();
    void push_back(T newElement);
    void remove(int position);
    int size();
    void doubleCapacity();
};

#endif