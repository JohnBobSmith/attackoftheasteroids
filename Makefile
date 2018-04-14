CXX ?= g++
CXXFLAGS ?= -g -Wall
PREFIX ?= /usr/
PROG  = attackoftheasteroids
ODIR  = obj
SRC = $(wildcard *.cpp $(wildcard src/*.cpp))
OBJS = $(addprefix $(ODIR)/,$(SRC:.cpp=.o))
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(PROG)

$(ODIR)/%.o: %.cpp
	mkdir -p $(ODIR)/src/
	$(CXX) -DPREFIX=\"$(PREFIX)\" -c -o $@ $^ $(CXXFLAGS)

$(PROG): $(OBJS)
	$(CXX) -o $(PROG) $^ $(LDLIBS)

clean:
	rm -f $(ODIR)/src/*.o $(PROG)
	
.PHONY: clean

install:
	install -Dm644 License.md "$(DESTDIR)$(PREFIX)/share/licenses/$(PROG)/LICENSE"
	install -Dm755 attackoftheasteroids "$(DESTDIR)$(PREFIX)/bin/attackoftheasteroids"
	install -Dm644 -t "$(DESTDIR)$(PREFIX)/share/$(PROG)/textures" textures/*.png
	install -Dm644 -t "$(DESTDIR)$(PREFIX)/share/$(PROG)/textures/ui" textures/ui/*.png
	install -Dm644 -t "$(DESTDIR)$(PREFIX)/share/$(PROG)/audio/sfx/" audio/sfx/*.wav
	install -Dm644 "fonts/ehsmb.ttf" "$(DESTDIR)$(PREFIX)/share/$(PROG)/fonts/ehsmb.ttf"
	install -Dm644 "audio/music/mainMenuTheme.wav" "$(DESTDIR)$(PREFIX)/share/$(PROG)/audio/music/mainMenuTheme.wav"
	
