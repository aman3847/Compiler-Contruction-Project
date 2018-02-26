# Name: Aman Gupta
# ID: 2014B2A70201P

all: lexer.o parser.o
	gcc -o stage1exe driver.c lexer.o parser.o
	rm *.o

# driver.o: driver.c
	# gcc -c driver.c

lexer.o: lexer.c
	gcc -c lexer.c

parser.o: parser.c
	gcc -c parser.c

clean:
	rm stage1exe
