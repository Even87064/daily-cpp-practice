# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = wordcount
OBJS = main.o word_utils.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 一般情況下，.o 只需要對應自己的 .cpp 和必要的 .h
main.o: main.cpp word_utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

word_utils.o: word_utils.cpp word_utils.h
	$(CXX) $(CXXFLAGS) -c word_utils.cpp

clean:
	rm -f $(OBJS) $(TARGET)
