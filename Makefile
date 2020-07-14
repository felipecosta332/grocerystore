CC = g++
FLAGS = -I inc -std=c++11 -O2 -o
OBJECT = bin/Cliente.o bin/Estabelecimento.o bin/Main.o
PROGRAM = ./Supermercado.exe

all: $(PROGRAM)

run: $(PROGRAM)
	./$<

$(PROGRAM): $(OBJECT)
	$(CC) $(FLAGS) $@ $^

bin/%.o: src/%.cpp bin
	$(CC) $(FLAGS) $@ -c $<

bin:
	mkdir bin

test: src/Test.cpp
	$(CC) -std=c++11 -O2 -o bin/Test.exe $<
	./bin/Test.exe

trash:
	rm -rf files/*.txt
	rm -rf files/caixa.csv

clean:
	rm -rf bin

rmproper: clean
	rm $(PROGRAM)