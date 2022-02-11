# Makefile: PhotoLab (Version 2)

# The executable program target when input in terminal is either: make all, make
all: PhotoLab

# Generate PhotoLab executable image by linking objects and static library (equivalent to input:  make all, make)
PhotoLab: PhotoLab.o FileIO.o libfilter.a
	gcc PhotoLab.o FileIO.o -lfilter -L. -Wall -o PhotoLab

# Test the executable image when input in terminal: make test
test: PhotoLab
	./PhotoLab

# Run the executable program in DEBUG Mode when input in terminal: make PhotoLabTest
PhotoLabTest: PhotoLabTest.o FileIO.o libfiltertest.a
	gcc PhotoLabTest.o -g FileIO.o -lfiltertest -L. -Wall -o PhotoLabTest
	./PhotoLabTest

# Clean up directory of intermediate files when input in terminal: make clean
clean:
	rm -f *.o *.a PhotoLab PhotoLabTest
	rm -f border.ppm bw.ppm colorfilter.ppm edge.ppm
	rm -f negative.ppm shuffle.ppm vflip.ppm vmirror.ppm
	rm -f blur.ppm noise.ppm posterize.ppm sharpen.ppm

# Create the PhotoLab object from source code and needed header files
PhotoLab.o: PhotoLab.c Constants.h FileIO.h DIPs.h Advanced.h
	gcc PhotoLab.c -c -std=c11 -Wall -o PhotoLab.o

# Create the DEBUG PhotoLab object version
PhotoLabTest.o: PhotoLab.c Constants.h FileIO.h DIPs.h Advanced.h
	gcc PhotoLab.c -c -DDEBUG -std=c11 -Wall -o PhotoLabTest.o

# Create the FileIO object from source code and corresponding header file
FileIO.o: FileIO.c FileIO.h Constants.h
	gcc FileIO.c -c -std=c11 -Wall -o FileIO.o

# Create the DIPs object from source code and corresponding header file
DIPs.o: DIPs.c DIPs.h Constants.h
	gcc DIPs.c -c -std=c11 -Wall -o DIPs.o

# Create the Advanced object from source code and corresponding header file
Advanced.o: Advanced.c Advanced.h Constants.h
	gcc Advanced.c -c -std=c11 -Wall -o Advanced.o

# Create the DEBUG Advanced.o PhotoLab object version
AdvancedTest.o: Advanced.c Advanced.h Constants.h
	gcc Advanced.c -c -DDEBUG -std=c11 -Wall -o AdvancedTest.o

# Create the static library of standard and advanced DIP operations
libfilter.a: DIPs.o Advanced.o
	ar rc libfilter.a DIPs.o Advanced.o
	ranlib libfilter.a

# Create the DEBUG static library of standard and advanced DIP operations
libfiltertest.a: DIPs.o AdvancedTest.o
	ar rc libfiltertest.a DIPs.o AdvancedTest.o
	ranlib libfiltertest.a