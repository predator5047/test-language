CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g -Werror

SRCS := main.cpp lexer.cpp parser.cpp ast.cpp
OBJS := $(SRCS:%.cpp=%.o)


TARGET := foo

.PHONY: all
all: $(TARGET)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(OBJS) -o $(TARGET)


$(TARGET): $(OBJS)

main.o parser.o lexer.o: lexer.h parser.h
ast.o: lexer.h

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
