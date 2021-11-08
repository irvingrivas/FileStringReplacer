# Obtained from https://www.gnu.org/software/make/manual/html_node/Simple-Makefile.html

stringreplace : stringreplace.o
	cc -o stringreplace stringreplace.o

stringreplace.o : stringreplace.c
	cc -c -Wall -Werror -Wextra stringreplace.c
clean :
	rm stringreplace stringreplace.o