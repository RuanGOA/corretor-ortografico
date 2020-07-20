
# Variáveis que armazenam os diretórios das pastas
APPS 	= ./apps
BIN 	= ./bin
INCLUDE = ./include
OBJ 	= ./obj
SRC 	= ./src


# Comando executado quando se usa make sem passar nenhum argumento
all:
	gcc -c $(SRC)/preProcessamento.c -I $(INCLUDE) -o $(OBJ)/preProcessamento.o
	gcc -c $(SRC)/util.c -I $(INCLUDE) -o $(OBJ)/util.o
	gcc -c $(SRC)/dicionario.c -I $(INCLUDE) -o $(OBJ)/dicionario.o
	gcc -c $(SRC)/menu.c -I $(INCLUDE) -o $(OBJ)/menu.o

	gcc $(APPS)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main

run: 
	$(BIN)/main ./data/texto.txt 


clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
