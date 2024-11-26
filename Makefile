CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

# Google Test
GTEST_DIR = /path/to/googletest
GTEST_LIB = -lgtest -lgtest_main -pthread

# Source files
SRC = Queue.cpp QueueTest.cpp

# Output binary
OUT = QueueTest

# Build the test executable
$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(GTEST_LIB)

# Run the tests
test: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT) *.gcda *.gcno
