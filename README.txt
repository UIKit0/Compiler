

                                   ---------------------------------------
				   |COMPILER FOR C-like LANGUAGE (Pazcal)|
				   ---------------------------------------

This project has been implemented in the course of "Compilers" of National Technical University of Athens.
It is an implementation of a compiler for a language called Pazcal, that implementents most of the elements of C.
The grammar of this language can be found in the document Pazcal_grammar.pdf


This compilers is consisted of 5 pieces, each of one implementing a different stage. These stages are :
- Lexical Analysis
- Syntactical Analysis
- Semantic Analysis
- Intermediate Code (quadruples)
- Executable Code (x8086)


1. Lexical Analysis 
-----------------------------------------------------------------------------
The lexical analysis can be tested in the following way :
./myparser < test_programs/hanoi.pzc

2 files were created for the testing of the lexer : hanoi.pzc, test.pzc


2. Syntactical Analysis
-----------------------------------------------------------------------------
The syntactical analysis can be tested in the following way :
./parser < bubblesort.pzc

The following files were created for the testing of the parser : bubblesort.pzc, hello.pzc, middle_value.pzc, prime.pzc
There are also 2 files containing errors to test the error checking of the parser : buggy1.pzc, buggy2.pzc


3. Semantic Analysis
------------------------------------------------------------------------------
The semantic analysis can be tested in the following way :
./semantic < test.pzc


4. Intermediate Code
-------------------------------------------------------------------------------
The intermediate code was implemented in quadruples.
The intermediate code can be tested in the following way :
./quadruples < final_test.pzc

The following files were created for the testing of the intermediate code : test_do_while.pzc, test_for.pzc, test_expressions.pzc, test_functions.pzc, test_switch.pzc, test_while.pzc, final_test.pzc


