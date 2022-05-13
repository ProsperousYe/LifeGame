#GameofLife:main.o file.o initialize.o map.o run.o sdl.o
#	gcc main.o file.o initialize.o map.o run.o -o GameofLife -ISDL2_image -ISDL2
#main.o:main.c
# code details

EXE_DIR = ./src
TEST_DIR = ./test
EXE = ./GameofLife
TEST = ./Test

SRC1 = ./src/main.c ./src/file.c ./src/initialize.c ./src/map.c ./src/run.c ./src/sdl.c
SRC2 = ./test/test.c ./src/file.c ./src/initialize.c ./src/map.c ./src/run.c

all:$(EXE) $(TEST)
# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image

# compile to  object code

OBJ1= $(SRC1:.c=.o)
OBJ2= $(SRC2:.c=.o)
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

# build executable

$(EXE): $(OBJ1)
	$(CC) $(OBJ1) -o $(EXE) $(LIBS)

$(TEST): $(OBJ2)
	$(CC) $(OBJ2) -o $(TEST)

# clean up compilation

clean:
	rm -f $(OBJ1) $(EXE)
	rm -f $(OBJ2) $(TEST)

# dependencies

main.o:  src/main.c src/map.h src/file.h src/initialize.h src/run.h src/sdl.h
file.o:  src/map.h
initialize.o:  src/map.h src/file.h
map.o: src/file.h
run.o: src/map.h src/file.h