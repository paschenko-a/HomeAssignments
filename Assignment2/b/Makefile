PROJECT = calculate
CXX = g++
CXXFLAGS = -Wall -Wextra
SRC = calculate.cpp main.cpp
OBJ = $(SRC: .cpp=.o)

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm −f $(OBJ) $(PROJECT)
