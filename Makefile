# Compiler
CC = clang
# Compiler flags
CFLAGS = -Wall -g
# Output executable name
OUTPUT = textadventure
# Source files
SRCS = main.c parsexec.c noun.c object.c location.c
# Object files
OBJS = $(SRCS:.c=.o)

# Build target
all: $(OUTPUT)

# Link the object files into the final executable
$(OUTPUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUTPUT)

# Compile each .c file into an .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) 
