CC=gcc
SRC_DIR=src/
OBJ_DIR=obj/
OS := $(shell uname)

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif
ifeq ($(detected_OS),Darwin)        # Mac OS X
	NON_VERBOSE_FLAGS =-framework GLUT -framework OPENGL -Wno-deprecated-declarations -lm
endif
ifeq ($(detected_OS),Linux)
	NON_VERBOSE_FLAGS=-lGL -lGLU -lglut
endif
	
dijkstra: $(OBJ_DIR)main.o
	$(CC) $(OBJ_DIR)main.o -o dijkstra $(NON_VERBOSE_FLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.c
	$(CC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o $(NON_VERBOSE_FLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o *~ core $(INCDIR)/*~ dijkstra