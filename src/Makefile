all: cw2

cw2: component.o main.o CircleFromSquare.o CircleFromCenter.o Square.o TurnImage.o WriteImage.o Swap.o ReadImage.o FreeMemory.o help.o information.o
	gcc component.o main.o CircleFromSquare.o CircleFromCenter.o Square.o TurnImage.o WriteImage.o Swap.o ReadImage.o FreeMemory.o help.o information.o -o cw2

main.o: main.c
	gcc -c main.c

component.o: component.c component.h
	gcc -c component.c

CircleFromSquare.o: CircleFromSquare.c CircleFromSquare.h
	gcc -c CircleFromSquare.c

CircleFromCenter.o: CircleFromCenter.c CircleFromCenter.h
	gcc -c CircleFromCenter.c

Square.o: Square.c Square.h
	gcc -c Square.c

TurnImage.o: TurnImage.c TurnImage.h
	gcc -c TurnImage.c

WriteImage.o: WriteImage.c WriteImage.h
	gcc -c WriteImage.c

Swap.o: Swap.c Swap.h
	gcc -c Swap.c

ReadImage.o: ReadImage.c ReadImage.h
	gcc -c ReadImage.c

FreeMemory.o: FreeMemory.c FreeMemory.h
	gcc -c FreeMemory.c

help.o: help.c help.h
	gcc -c help.c

information.o: information.c information.h
	gcc -c information.c

clear:
	rm *.o
	rm cw2
