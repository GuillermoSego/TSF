# Directory structure
OBJECT_DIR = .\\build\\Debug
TARGET_DIR = .\\build

# Target name
LINK_TARGET = .\build\MatrixProduct.exe

# Macro with object files
_OBJS =  \
 Matrix.o \
 MatrixProduct.o 

OBJS = $(patsubst %,$(OBJECT_DIR)\\%,$(_OBJS))

# Target Build
all : $(LINK_TARGET)

# Linker command
$(LINK_TARGET) : $(OBJS)
	gcc -g -o $@ $^

# Compiler command
$(OBJECT_DIR)\\%.o : %.c
	gcc -g -o $@ -c $<

# Dependency Rules
$(OBJECT_DIR)\\MatrixProduct.o : MatrixProduct.c Matrix.h
$(OBJECT_DIR)\\Matrix.o : Matrix.c Matrix.h

# Cleaning files
REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean :
	del $(REBUILDABLES)
