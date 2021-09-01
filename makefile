CXXFLAGS = -Wall -Wextra -static-libgcc -static-libstdc++
LDFLAGS = -lm -lSDL2 -lSDL2_image
VPATH = src
OBJDIR = obj
BINDIR = bin
OBJECTS = src/main.cpp src/Operate.cpp src/Screens/TitleScreen.cpp src/Screens/GameScreen.cpp src/GameWindow.cpp src/InputManager/JoystickManager.cpp src/InputManager/KeyboardManager.cpp src/ScreenManager.cpp src/ImageManager.cpp src/Game/Chara/Character.cpp src/Game/Chara/TestChara.cpp

all : $(OBJECTS) bin
	g++ $(CXXFLAGS) -o $(BINDIR)/Touhou-Koumatou $(OBJECTS) $(LDFLAGS)

bin :
	mkdir bin

.PHONY : clean

remake: clean all

clean:
	-rm -rf *.o *~
