# Makefile -- creates myparser from "scanner.lex" and 

$CC=gcc
LEX=flex

myparser: scanner.o 
	$(CC) -o $@ $(LDFLAGS) $^ -lfl
	
scanner.o: scanner.c
	$(CC) $(CPFLAGS) $(CFLAGS) -o $@ -c $^ 

scanner.c: scanner.lex
	$(LEX) $(LFLAGS) -o $@ $^ 

clean:
	$(RM) *.o scanner.c
