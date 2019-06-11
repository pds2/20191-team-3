CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++11 -ggdb

TESTER := program/tester.cpp

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
TSTDIR := tests

LIBRARIES	:=
EXECUTABLE	:= main
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.cpp)

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

bin/tests: $(SRC)/w*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $(TESTER) $(TSTSOURCES) $^ -o $@ $(LIBRARIES)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
