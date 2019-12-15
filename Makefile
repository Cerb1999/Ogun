#OBJS specifies which files to compile as part of the project
OBJS = $(wildcard *.cpp)

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -lmingw32 -lSDL2main -lSDL2

#LINKER_FLAGS specifies the libraries we're linking against
#LINKER_FLAGS = `sdl2-config --libs`

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = jeu

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean: rm -rf *.o *~

mrproper: clean rm -rf $(EXEC)
