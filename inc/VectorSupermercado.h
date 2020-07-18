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
    VectorSupermercado() : elements(nullptr), vector_size(0), vector_capacity(1) {
      this->elements = new T[this->vector_capacity];
    }
    VectorSupermercado(int capacity) : elements(nullptr), vector_size(0) {
      if (capacity > 1) {
        this->vector_capacity = capacity;
      } else {
        this->vector_capacity = 1;
      }
      this->elements = new T[this->vector_capacity];
    }
    ~VectorSupermercado() {
      delete[] this->elements;
    }
    T back() {
      return this->elements[this->vector_size - 1];
    }
    int capacity() {
      return this->vector_capacity;
    }
    bool empty() {
      return this->vector_size == 0;
    }
    T front() {
      return this->elements[0];
    }
    void pop_back() {
      T* temp_array = new T[this->vector_capacity];
      std::copy(this->elements, this->elements + this->vector_size - 1, temp_array);
      delete[] this->elements;
      this->elements = temp_array;
      this->vector_size--;
    }
    void push_back(T newElement) {
      if (this->vector_size >= this->vector_capacity) {
        this->doubleCapacity();
      }
      this->elements[this->vector_size] = newElement;
      this->vector_size++;
    }
    void remove(int position) {
      if (position >= 0 && position < this->vector_size) {
        for (int i = position; i < this->vector_size - 1; i++) {
          this->elements[i] = this->elements[i + 1];
        }
        this->pop_back();
      }
    }
    int size() {
      return this->vector_size;
    }
    void doubleCapacity() {
      this->vector_capacity *= 2;
      T* temp_array = new T[this->vector_capacity];
      std::copy(this->elements, this->elements + this->vector_size, temp_array);
      delete[] this->elements;
      this->elements = temp_array;
    }
};

#endif