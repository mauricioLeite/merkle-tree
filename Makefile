CFLAGS= -O -std=c++17 
INCLUDE= -I ./sha256
SRC = main.cc merkle_tree/merkle_tree.cc merkle_tree/merkle_node.cc sha256/sha256.cc
OBJ = $(SRC:.cpp = .o)
LIBS = -lcrypto

Start: $(OBJ)
	g++ $(CFLAGS) $(INCLUDE) -o start.out $(OBJ) $(LIBS)

clean:
	rm -f *.o