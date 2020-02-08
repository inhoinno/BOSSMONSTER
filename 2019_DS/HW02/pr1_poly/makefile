# 32152332 º€¿Œ»£
# makefile
#
CC= gcc -g
all: poly
poly: main.o poly_interface.o printfile.o polynomial.o polycalc.o func_min.o func_zero.o
	$(CC) -o poly main.o printfile.o poly_interface.o polynomial.o polycalc.o func_min.o func_zero.o
main.o: poly.h main.c
	$(CC) -c main.c -o main.o

printfile.o: poly.h printfile.c
	$(CC) -c printfile.c -o printfile.o

poly_interface.o: poly.h poly_interface.c
	$(CC) -c poly_interface.c -o poly_interface.o

polynomial.o: poly.h polynomial.c
	$(CC) -c polynomial.c -o polynomial.o

polycalc.o: poly.h calc.c
	$(CC) -c calc.c -o polycalc.o

func_min.o: poly.h func_MIN_x.c
	$(CC) -c func_MIN_x.c -o func_min.o

func_zero.o: poly.h func_zero_find_x.c 
	$(CC) -c func_zero_find_x.c -o func_zero.o


clean:
	del -f poly.exe
	del -f *.o
