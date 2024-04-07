CFLAGS = -std=c++14 -Wall -g

evaluator:	Main.o TreeNode.o Table.o Letters.o Tree.o
	g++ Main.o TreeNode.o Table.o Letters.o Tree.o -o huffman $(CFLAGS)

Main.o:	Main.cpp TreeNode.h Table.h Letters.h Tree.h
	g++ -c Main.cpp $(CFLAGS)

TreeNode.o: Tree.cpp Tree.h
	g++ -c TreeNode.cpp $(CFLAGS)

Table.o: Table.cpp Table.h
	g++ -c Table.cpp $(CFLAGS)

Letters.o: Letters.cpp Letters.h
	g++ -c Letters.cpp $(CFLAGS)

Tree.o: Tree.cpp Tree.h
	g++ -c Tree.cpp $(CFLAGS)


clean:
	rm -f *.o huffman
