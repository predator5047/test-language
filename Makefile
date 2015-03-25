CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -g -Werror -MMD

OBJS := main.o lexer.o parser.o ast.o
DEPS := $(OBJS:%.o=%.d)
TARGET := foo

-include $(DEPS)

.PHONY: all
all: $(TARGET)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

$(TARGET): $(OBJS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)
