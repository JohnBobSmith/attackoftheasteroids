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
	install -Dm644 License.md "${pkgdir}/usr/share/licenses/${_pkgname}/LICENSE"
	install -Dm755 "src/aota" "${pkgdir}/usr/bin/aota"
	install -Dm644 -t "$(DESTDIR)/$(PROG)/textures" textures/*
	#install -Dm644 "textures/bg.png" "${pkgdir}/usr/share/${_pkgname}/textures/bg.png"
	#install -Dm644 "textures/bullet.png" "${pkgdir}/usr/share/${_pkgname}/textures/bullet.png"
	#install -Dm644 "textures/easyAsteroid.png" "${pkgdir}/usr/share/${_pkgname}/textures/easyAsteroid.png"
	#install -Dm644 "textures/laser.png" "${pkgdir}/usr/share/${_pkgname}/textures/laser.png"
	#install -Dm644 "textures/moonbase.png" "${pkgdir}/usr/share/${_pkgname}/textures/moonbase.png"
	#install -Dm644 "textures/shield.png" "${pkgdir}/usr/share/${_pkgname}/textures/shield.png"
	#install -Dm644 "textures/ui/help.png" "${pkgdir}/usr/share/${_pkgname}/textures/ui/help.png"
	#install -Dm644 "textures/ui/start.png" "${pkgdir}/usr/share/${_pkgname}/textures/ui/start.png"
	#install -Dm644 "textures/ui/quit.png" "${pkgdir}/usr/share/${_pkgname}/textures/ui/quit.png"
	#install -Dm644 "textures/ui/helppage.png" "${pkgdir}/usr/share/${_pkgname}/textures/ui/helppage.png"
	#install -Dm644 "fonts/ehsmb.ttf" "${pkgdir}/usr/share/${_pkgname}/fonts/ehsmb.ttf"
	#install -Dm644 "audio/sfx/bulletFire.wav" "${pkgdir}/usr/share/${_pkgname}/audio/sfx/bulletFire.wav"
	#install -Dm644 "audio/sfx/enemyDeath.wav" "${pkgdir}/usr/share/${_pkgname}/audio/sfx/enemyDeath.wav"
	#install -Dm644 "audio/sfx/laserFire.wav" "${pkgdir}/usr/share/${_pkgname}/audio/sfx/laserFire.wav"
	#install -Dm644 "audio/sfx/shieldImpact.wav" "${pkgdir}/usr/share/${_pkgname}/audio/sfx/shieldImpact.wav"
	#install -Dm644 "audio/music/mainMenuTheme.wav" "${pkgdir}/usr/share/${_pkgname}/audio/music/mainMenuTheme.wav"
	
