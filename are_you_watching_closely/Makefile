all: libprintf.a

libprintf.a:
	gcc -g -Wall -Werror -Wextra -pedantic -c printf.c inttostr.c strncat.c replace_functions_1.c replace_functions_2.c
	ar -rc libprintf.a printf.o inttostr.o strncat.o replace_functions_1.o replace_functions_2.o
	rm printf.o inttostr.o strncat.o replace_functions_1.o replace_functions_2.o

clean:
	rm libprintf.a

re: clean all
