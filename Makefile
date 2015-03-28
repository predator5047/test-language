CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g -Werror -MMD
OBJS := main.o lexer.o parser.o ast.o
DEPS := $(OBJS:%.o=%.d)
TARGET := foo
.PHONY: all clean

all: $(TARGET)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

$(TARGET): $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
