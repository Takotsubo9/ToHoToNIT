#!/bin/bash
for file in `\find -name '*.cpp'`; do
    filelist="${filelist} ${file}"
done

echo "CXXFLAGS = -Wall -Wextra -static-libgcc -static-libstdc++" > makefile
echo "LDFLAGS = -lm -lSDL2 -lSDL2_image" >> makefile
echo "OBJECTS = "${filelist} >> makefile
echo "all : ""$""(OBJECTS) bin" >> makefile
echo "	g++ ""$""(CXXFLAGS) -o bin/Touhou-Koumatou ""$""(OBJECTS) ""$""(LDFLAGS)" >> makefile
echo "" >> makefile
echo "bin :" >> makefile
echo "	mkdir bin" >> makefile
echo "" >> makefile
echo ".PHONY : clean" >> makefile
echo "remake : clean all" >> makefile
echo "clean :" >> makefile
echo "	-rm -rf bin/Touhou-Koumatou" >> makefile