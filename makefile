CPPC=gcc
SRC_DIR=src/
OBJ_DIR=obj/

dijkstra: $(OBJ_DIR)main.o 
	$(CPPC) $(OBJ_DIR)main.o -o dijkstra 

$(OBJ_DIR)main.o: $(SRC_DIR)main.c
	$(CPPC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o

clean:
	rm -f $(OBJ_DIR)/*.o *~ core $(INCDIR)/*~ dijkstra