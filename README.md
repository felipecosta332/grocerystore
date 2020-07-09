# Atividade IV - Linguagem de Programação I - Instituto Metrópole Digital - 2020.5

- Criar um programa Supermercado;
- O programa deve possuir duas classes: Estabelecimento e Cliente;
- A classe Estabelecimento deverá consultar os produtos através do arquivo
estoque.csv. A classe também deve gerar um arquivo de saída chamado
caix.csv, esse arquivo deve conter os produtos vendidos e o total de dinheiro
ganho nas vendas;
- O arquivo caixa.csv deve conter o código do produto, nome, preço, a
quantidade vendida de cada produto e o total de vendas;
- A classe Estabelecimento deve possuir os seguintes atributos: codigo, produto
(lista de string), unidadeMedida, preco;
- A classe Estabelecimento deve possuir os seguintes métodos: listar (lista os
produtos disponíveis), venda (recebe como parâmetro o código do produto,
verifica se ainda existe esse produto no estoque, se não retorna uma mensagem
de insucesso, se sim, retorna uma mensagem de sucesso e escreve no arquivo
de saída a venda efetuada), caixa (retorna tudo o que foi vendido e o total
ganho);
- A classe Cliente deve ter os atributos: saldo, sacola (vector de string);
- No saldo vai conter quanto o cliente tem em dinheiro e pode gastar em
compras;
- Na sacola vai conter todas as compras do cliente;
- A classe Cliente deve ter os métodos: compra (recebe o produto e o preço, o
método deve verificar se o cliente tem saldo suficiente para comprar o produto,
se não, emite um aviso, se sim, faz a compra, diminui o saldo e adiciona o
produto na sacola), verSacola (mostra o conteúdo da sacola) e registro(esse
método escreve o conteúdo da sacola em um arquivo chamado cliente_x.txt,
onde para cada cliente dever um arquivo próprio mudando x para 1, 2, 3, etc.
Até a quantidade de clientes existentes;
- As classes deve fazer uso de construtores que não sejam os construtores
padrão. Como os construtores serão implementados fica a critério de vocês;
- No main deve conter um menu inicializando o programa e os objetos clientes.
Através do menu é possível adicionar o saldo do cliente, verificar os produtos
da loja e ver o conteúdo da sacola do cliente. Quando o cliente acaba as
compras, o programa deve perguntar se quer inicializar um novo cliente (novo
objeto), se não, o programa pode encerrar.
A implementação correta da classe Estabelecimento valerá 2 pontos a classe Cliente
valerá 2 pontos e o método main valerá 1 ponto.
