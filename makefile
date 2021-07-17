CXXFLAGS = -Wall -Wextra -std=gnu++17 -static-libgcc -static-libstdc++
LDFLAGS = -lSDL2
VPATH = src
OBJDIR = obj
BINDIR = bin
OBJECTS = src/main.cpp src/Screens/TitleScreen.cpp src/GameWindow.cpp src/InputManager/JoystickManager.cpp src/InputManager/KeyboardManager.cpp src/ScreenManager.cpp src/ImageManager.cpp

all : $(OBJECTS) bin
	g++ $(CXXFLAGS) -o $(BINDIR)/Touhou-Koumatou $(OBJECTS) $(LDFLAGS)

bin :
	mkdir bin

.PHONY : clean

remake: clean all

clean:
	-rm -rf *.o *~
