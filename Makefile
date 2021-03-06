CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g -Werror -pipe -MP -MMD
OBJS := main.o lexer.o parser.o ast.o
DEPS := $(OBJS:%.o=%.d)
TARGET := foo
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
