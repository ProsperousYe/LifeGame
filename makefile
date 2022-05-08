GameofLife:main.o file.o initialize.o map.o run.o
	gcc main.o file.o initialize.o map.o run.o -o GameofLife
main.o:main.c
	gcc -c main.c
file.o:file.c
	gcc -c file.c
initialize.o:initialize.c
	gcc -c initialize.c
map.o:map.c
	gcc -c map.c
run.o:run.c
	gcc -c run.c