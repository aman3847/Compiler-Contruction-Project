# Name: Aman Gupta
# ID: 2014B2A70201P

all: driver.o utilities.o lexer.o
	gcc -o compiler driver.c utilities.c lexer.c 
	rm *.o

driver.o: driver.c
	gcc -c driver.c

utilities.o: utilities.c
	gcc -c utilities.c

lexer.o: lexer.c
	gcc -c lexer.c

clean:
	rm compiler