#!/bin/bash
for file in `\find -name '*.cpp'`; do
    filelist="${filelist} ${file}"
done

echo "CXX = g++" > makefile
echo "CXXFLAGS = -Wall -Wextra -static-libgcc -static-libstdc++" >> makefile
echo "LDFLAGS = -lm -lSDL2 -lSDL2_image -lSDL2_mixer" >> makefile
echo "SRCS = "${filelist} >> makefile
echo "OBJECTS = ""$""(SRCS:%cpp=%o)" >> makefile
echo "all : ""$""(OBJECTS) bin" >> makefile
echo "	""$""(CXX) ""$""(CXXFLAGS) -o bin/Touhou-Koumatou ""$""(OBJECTS) ""$""(LDFLAGS)" >> makefile
echo "%.o: %.c" >> makefile
echo "	""$""(CXX) ""$""(CXXFLAGS) -c ""$""< -o ""$""@ ""$""(LDFLAGS)" >> makefile
echo "" >> makefile
echo "bin :" >> makefile
echo "	mkdir bin" >> makefile
echo "" >> makefile
echo ".PHONY : clean" >> makefile
echo "remake : clean all" >> makefile
echo "clean :" >> makefile
echo "	-rm -rf bin/Touhou-Koumatou" >> makefile
echo "	-rm ""$""(OBJECTS)" >> makefile