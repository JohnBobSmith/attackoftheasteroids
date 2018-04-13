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
	#install -Dm644 -t "$(DESTDIR)/usr/share/$(PROG)/textures" textures/*
	#install -Dm644 "textures/bg.png" "$(DESTDIR)/usr/share/$(PROG)/textures/bg.png"
	#install -Dm644 "textures/bullet.png" "$(DESTDIR)/usr/share/$(PROG)/textures/bullet.png"
	#install -Dm644 "textures/easyAsteroid.png" "$(DESTDIR)/usr/share/$(PROG)/textures/easyAsteroid.png"
	#install -Dm644 "textures/laser.png" "$(DESTDIR)/usr/share/$(PROG)/textures/laser.png"
	#install -Dm644 "textures/moonbase.png" "$(DESTDIR)/usr/share/$(PROG)/textures/moonbase.png"
	#install -Dm644 "textures/shield.png" "$(DESTDIR)/usr/share/$(PROG)/textures/shield.png"
	#install -Dm644 "textures/ui/help.png" "$(DESTDIR)/usr/share/$(PROG)/textures/ui/help.png"
	#install -Dm644 "textures/ui/start.png" "$(DESTDIR)/usr/share/$(PROG)/textures/ui/start.png"
	#install -Dm644 "textures/ui/quit.png" "$(DESTDIR)/usr/share/$(PROG)/textures/ui/quit.png"
	#install -Dm644 "textures/ui/helppage.png" "$(DESTDIR)/usr/share/$(PROG)/textures/ui/helppage.png"
	install -Dm644 "fonts/ehsmb.ttf" "$(DESTDIR)/usr/share/$(PROG)/fonts/ehsmb.ttf"
	install -Dm644 -t "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/" audio/*.wav
	#install -Dm644 "audio/sfx/bulletFire.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/bulletFire.wav"
	#install -Dm644 "audio/sfx/enemyDeath.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/enemyDeath.wav"
	#install -Dm644 "audio/sfx/laserFire.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/laserFire.wav"
	#install -Dm644 "audio/sfx/shieldImpact.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/sfx/shieldImpact.wav"
	install -Dm644 "audio/music/mainMenuTheme.wav" "$(DESTDIR)/usr/share/$(PROG)/audio/music/mainMenuTheme.wav"
	
