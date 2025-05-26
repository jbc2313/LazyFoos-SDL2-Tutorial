#OBJS specifies which files to compile as part of the project
OBJS = getting_an_image.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 02_getting_an_image_SDL2

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#Removes the executable ie cleans up the folder
.PHONEY: clean
clean:
	rm 02_getting_an_image_SDL2
	echo Clean done
	
