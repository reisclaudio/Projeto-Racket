CC = gcc
COMPILER_FLAGS = -std=c99
LINKER_FLAGS = -lm
EXEC_NAME = siguel
OBJECTS = siguel.o leitura.o leituraQRY.o leituraGEO.o svgprint.o consultas.o arquivos.o Elementos/circulo.o Elementos/retangulo.o Elementos/quadra.o Elementos/semaforo.o Elementos/hidrante.o Elementos/radioBase.o lista.o 

siguel: $(OBJECTS)
		$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

clean: 
		rm -rf ./*.o
		rm -rf Elementos/*.o