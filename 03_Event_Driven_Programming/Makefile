#OBJS specifies which files to compile as part of the project
OBJS = event_driven_programming.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 03_event_driven_programming_SDL2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#Removes the executable ie cleans up the folder
.PHONEY: clean
clean:
	rm 03_event_driven_programming_SDL2
	echo Clean done
	
