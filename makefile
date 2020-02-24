TAR1 = sigcont.out
OBJ1= sigcont.o

TAR2 = realtimesig.out
OBJ2 = realtimesig.o

TAR3 = sigwaitinfo.out
OBJ3= sigwaitinfo.o
CC = gcc

all : $(TAR1) $(TAR2) 
$(TAR1): $(OBJ1)
	$(CC) -o $(TAR1) $(OBJ1)
$(OBJ1): sigcont.c
	$(CC) -c sigcont.c

$(TAR2): $(OBJ2)
	$(CC) -o $(TAR2) $(OBJ2)
$(OBJ2) : realtime_stdsignal.c
	$(CC) -c realtime_stdsignal.c

$(TAR3):$(OBJ3)
	$(CC) -o $(TAR3) $(OBJ3)
$(OBJ3) : sigsuspend_and_sigwaitinfo.c
	$(CC) -c sigsuspend_and_sigwaitinfo.c

clean :
	rm -f *.o 


