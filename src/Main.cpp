/*
Atividade VI
Linguagem de Programação I
Instituto Metrópole Digital
2020.5
• Crie a classe Supermercado e Restaurante para que sejam derivada de
Estabelecimento;
• A classe Estabelecimento deve ser modificada para conter apenas os atributos e
métodos comum as outras duas classes que a derivam;
• As classes Supermercado e Restaurante devem fazer as mesmas operações que
o programa Supermercado anterior;
• Deverão ser gerados arquivos de caixa tanto pro Supermercado quanto pro
Restaurante;
• A diferença entre as duas classes consiste que Restaurante não possui estoque e
sim um cardápio e que Restaurante não faz utilização de Fornecedor;
• Na inicialização do programa o usuário deverá decidir se quer usar o
Supermercado ou o Restaurante;
• Quando o usuário utiliza o restaurante ele deve fazer um pedido informando o
item do menu e a quantidade;
• O usuário deve receber um saldo para gastar durante a inicialização do
programa;
• Para todo caso de erro inesperado, o programa deve usar exceção para tratar o
problema;
A pontuação se dará da seguinte forma: A implementação adequada da herança e as
classes que a compõem valem 3 pontos. O uso adequado de exceções vale 1 ponto e
as mudanças realizadas no main valem 1 ponto.
*/

#include "App.h"

int main() {
  App app;
  app.runApp();
}