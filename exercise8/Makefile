libTrees.a : tree.o element.o
tree.o : tree.h tree.c
element.o : element.c
main.o : main.c
libParser.a : parser.o lexer.o
parser.o : parser.c parser.h
lexer.o : lexer.c lexer.h
parser.c : grammar.g
lexer.c : grammar.g
parser.h : grammar.g
lexer.h : grammar.g
treeApp : libTrees.a libParser.a main.o
