CPP_FILES=$(wildcard src/*.cpp)
CPP_OBJ_FILES:=$(patsubst src/%.cpp,obj/%.cpp.o,$(CPP_FILES))
OBJDIR:=obj
BINDIR:=bin
CC_FLAGS=-c -Wall --std=c++11 -Iinc
ifeq ($(OS),Windows_NT)
	CC_FLAGS+= -IC:\libs\sfml\SFML-2.4.2\include -DSFML_STATIC
	LDFLAGS:= -LC:\libs\sfml\SFML-2.4.2\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -ljpeg -lfreetype
else
	CC_FLAGS+= -I/usr/local/include -g
	LDFLAGS:= -L/usr/local/lib -F/Library/Frameworks -framework SFML -framework sfml-audio -framework sfml-system -framework sfml-window -framework sfml-graphics
endif
EXEC_NAME:=astar_sfml

build: bin/$(EXEC_NAME)

bin/$(EXEC_NAME): $(CPP_OBJ_FILES) | $(BINDIR)
	g++ -o $@ $^ $(LDFLAGS)

obj/%.cpp.o: src/%.cpp $(CPP_FILES) | $(OBJDIR)
	g++ $< -o $@ $(CC_FLAGS)

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