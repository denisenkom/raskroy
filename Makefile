CPP_FILES=test.cpp raskroy.cpp
OBJ_FILES=test.o raskroy.o

$(OBJ_FILES): $(CPP_FILES)
	mingw32-g++ -c $?

target: $(OBJ_FILES)
	mingw32-g++ -o hello $(OBJ_FILES)

