CXX = g++
CXXFLAGS = -Wall --std=c++17
TARGET = runTests

all: $(TARGET)

$(TARGET): test_arrayList.cpp catch_amalgamated.cpp MainProgram.cpp
	$(CXX) $(CXXFLAGS) -c catch_amalgamated.cpp -o catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -Dmain=student_main -c MainProgram.cpp -o MainProgram.o
	$(CXX) $(CXXFLAGS) -c test_arrayList.cpp -o test_arrayList.o
	$(CXX) $(CXXFLAGS) catch_amalgamated.o MainProgram.o test_arrayList.o -o $(TARGET)

test: $(TARGET)
	./$(TARGET) --success --durations yes

clean:
	rm -f *.o $(TARGET)

