# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -I/usr/include/SDL2 -D_REENTRANT

# Libraries
LDFLAGS = -L/usr/lib -lSDL2 -lSDL2_gfx

# Directories
OBJDIR = obj
BINDIR = bin

# Output executable
TARGET = $(BINDIR)/project

# Source and object files
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
