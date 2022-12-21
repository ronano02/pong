# derived from https://youtu.be/noBh17uxQ1E
# compiler and linker flags
CC 		  := g++
SRC_DIR   := src
BIN_DIR   := bin
BIN_EXE   := $(BIN_DIR)/pong1
OUTPUT 	  := $(if $(findstring Windows_NT, $(OS)), $(BIN_EXE).exe, $(BIN_EXE))
OBJ_DIR	  := $(BIN_DIR)/obj
INC_DIRS  := -I$(SRC_DIR)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
H_FILES	  := $(wildcard $(SRC_DIR)/*.h)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
CPP_FLAGS := -std=c++14 -Wall -Werror 
#TNAME 	  := pong1

# compile the object files and place them into their own directories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(H_FILES)
	$(CC) $(CPP_FLAGS) $(INC_DIRS) -c -o $@ $<

# link the object files together to create the final executable
$(OUTPUT): $(OBJ_FILES) Makefile
	$(CC) $(OBJ_FILES) -o $(OUTPUT)

# when we type make, compile and link the executable
all: $(OUTPUT)

# if we type 'make run' it will build and then run the executable
run: $(OUTPUT)
	$(if $(findstring Windows_NT, $(OS)), cd bin && pong1.exe && cd .., cd bin && ./pong1 && cd ..)

# if we type 'make clean' it will clean up all the object files and the executable
clean:
	$(if $(findstring Windows_NT, $(OS)), del bin\obj\*.o && del bin\pong1.exe, rm $(OBJ_DIR)/*.o && rm $(OUTPUT))