CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack-test heap-test

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ llrec-test.o llrec.o

llrec-test.o: llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp

heap-test: heap-test.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ heap-test.o

heap-test.o: heap-test.cpp heap.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c heap-test.cpp

stack-test: stack-test.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ stack-test.o

stack-test.o: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c stack-test.cpp


#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 