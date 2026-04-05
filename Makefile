CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++23

TARGET = giuda
ODIR = src

SRC := $(wildcard $(ODIR)/*.cpp)
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $+

clean:
	rm $(ODIR)/*.o
