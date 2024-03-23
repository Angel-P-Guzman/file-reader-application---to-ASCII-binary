#######################################################################
# Exd makefile For CS530 Assignment #1
# Angel Guzman
#######################################################################

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
TARGET = xed

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

	
#################################[End: Makefile]#######################
