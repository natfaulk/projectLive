CPP_FILES=$(wildcard src/*.cpp)
CPP_OBJ_FILES:=$(patsubst src/%.cpp,obj/%.cpp.o,$(CPP_FILES))
OBJDIR:=obj
BINDIR:=bin
EXEC_NAME:=astar

build: bin/$(EXEC_NAME)

bin/$(EXEC_NAME): $(CPP_OBJ_FILES) | $(BINDIR)
	g++ -o $@ $^

obj/%.cpp.o: src/%.cpp $(CPP_FILES) | $(OBJDIR)
	g++ $< -o $@ -c -Iinc -Wall --std=c++11 -g

.PHONY: test clean

ifeq ($(OS),Windows_NT)
clean:
	del /Q obj\*.* bin\*.*

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

run: build
	.\bin\$(EXEC_NAME).exe
else
clean:
	rm -rf obj/* bin/*

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

run: build
	./bin/$(EXEC_NAME)
endif