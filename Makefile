CXX = g++
CXXFLAGS = -g -Wall
PROG  = attackoftheasteroids
ODIR  = obj
SRC = $(wildcard *.cpp $(wildcard src/*.cpp))
#SRC = $(wildcard *.cpp)
OBJS = $(addprefix $(ODIR)/,$(SRC:.cpp=.o))
LD = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(PROG)

$(ODIR)/%.o: %.cpp
	mkdir -p $(ODIR)/src/
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

$(PROG): $(OBJS)
	$(CXX) -o $(PROG) $^ $(LD)

clean:
	rm -f $(ODIR)/*.o $(PROG)
	
.PHONY: clean

install:
	install -Dm644 License.md "$(DESTDIR)/usr/share/licenses/$(PROG)/LICENSE"
	install -Dm755 attackoftheasteroids "$(DESTDIR)/usr/bin/attackoftheasteroids"
	install -Dm644 -t "$(DESTDIR)/usr/share/$(PROG)/textures" textures/*.png
	install -Dm644 -t "$(DESTDIR)/usr/share/$(PROG)/textures/ui" textures/ui/*.png
	install -Dm644 "fonts/ehsmb.ttf" "$(DESTDIR)/usr/share/$(PROG)/fonts/ehsmb.ttf"
	install -Dm644 -t "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/" audio/sfx/*.wav
	install -Dm644 "audio/music/mainMenuTheme.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/music/mainMenuTheme.wav"
	
