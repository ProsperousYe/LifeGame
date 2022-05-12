#GameofLife:main.o file.o initialize.o map.o run.o sdl.o
#	gcc main.o file.o initialize.o map.o run.o -o GameofLife -ISDL2_image -ISDL2
#main.o:main.c
#	gcc -c main.c
#file.o:file.c
#	gcc -c file.c
#initialize.o:initialize.c
#	gcc -c initialize.c
#map.o:map.c
#	gcc -c map.c
#run.o:run.c
#	gcc -c run.c
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/GameofLife

SRC= main.c file.c initialize.c map.c run.c sdl.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c map.h file.h initialize.h run.h sdl.h
file.o:  map.h
initialize.o:  map.h file.h
map.o: file.h
run.o: map.h file.h