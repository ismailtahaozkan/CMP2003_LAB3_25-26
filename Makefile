CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = runTests

all: $(TARGET)

$(TARGET): test_arrayList.cpp
	$(CXX) $(CXXFLAGS) test_arrayList.cpp -o $(TARGET)

test: $(TARGET)
	./$(TARGET) --success --durations yes

clean:
	rm -f $(TARGET)

