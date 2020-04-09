CC=gcc
SRC_DIR=src/
OBJ_DIR=obj/
NON_VERBOSE_FLAGS =-framework GLUT -framework OPENGL -Wno-deprecated-declarations -lm

dijkstra: $(OBJ_DIR)main.o 
	$(CC) $(OBJ_DIR)main.o -o dijkstra $(NON_VERBOSE_FLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.c
	$(CC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o $(NON_VERBOSE_FLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o *~ core $(INCDIR)/*~ dijkstra