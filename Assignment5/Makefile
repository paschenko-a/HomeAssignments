PROJECT = matrix
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -pthread
GTEST_LIBS = -lgtest -lgtest_main -pthread

LIB_SRC = Rational.cpp
LIB_OBJ = $(LIB_SRC:.cpp=.o)
TEST_SRC = test_Matrix.cpp test_Rational.cpp tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

.PHONY: all clean cleanall test

all: $(PROJECT)

$(PROJECT): $(LIB_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(PROJECT)
	./$(PROJECT)

clean:
	rm -f *.o

cleanall: clean
	rm -f $(PROJECT)