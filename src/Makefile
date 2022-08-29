CFLAGS = -pg 

output: main.o 
	gcc main.o ${CFLAGS} -o got_simulation

main.o: main.cpp
	gcc -c ${CFLAGS} main.cpp

clean:
	rm main.o 