PROJECT = matrix
CXX = g++
CXXFLAGS = -Wall -Wextra -pthread 
GTEST_LIBS = -lgtest -lgtest_main -pthread 
SRC = Rational.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean cleanall

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(GTEST_LIBS) 

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(PROJECT)