CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g -Werror

SRCS := main.cpp lexer.cpp parser.cpp ast.cpp
OBJS := $(SRCS:%.cpp=%.o)


TARGET := foo

.PHONY: all
all: $(TARGET)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(OBJS) -o $(TARGET)


$(TARGET): $(OBJS)

main.o: lexer.h parser.h
parser.o: parser.h lexer.h
lexer.o: lexer.h
ast.o: ast.h lexer.h

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)
