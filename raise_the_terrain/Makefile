ALL: a.out

a.out:
	gcc -Wall -Werror -Wextra -pedantic main.c `sdl2-config --cflags --libs`

clean:
	rm a.out

re: clean ALL

run: ALL
	./a.out

rerun: clean run
