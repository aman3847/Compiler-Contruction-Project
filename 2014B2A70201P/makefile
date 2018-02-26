# Name: Aman Gupta
# ID: 2014B2A70201P

all: driver.o lexer.o
	gcc -o stage1exe driver.c lexer.o
	rm *.o

# driver.o: driver.c
	# gcc -c driver.c

lexer.o: lexer.c
	gcc -c lexer.c

clean:
	rm stage1exe
