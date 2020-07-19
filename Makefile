
# Variáveis que armazenam os diretórios das pastas
APPS 	= ./apps
BIN 	= ./bin
INCLUDE = ./include
OBJ 	= ./obj
SRC 	= ./src


# Comando executado quando se usa make sem passar nenhum argumento
all:
	gcc -c $(SRC)/pre_processamento.c -I $(INCLUDE) -o $(OBJ)/pre_processamento.o
	gcc -c $(SRC)/util.c -I $(INCLUDE) -o $(OBJ)/util.o
	gcc -c $(SRC)/dicionario.c -I $(INCLUDE) -o $(OBJ)/dicionario.o
	gcc -c $(SRC)/menu.c -I $(INCLUDE) -o $(OBJ)/menu.o

	gcc $(APPS)/main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/main


run: 
	$(BIN)/main ./textoTeste.txt ./dicionario.txt


clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
