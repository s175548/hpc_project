CFLAGS = -std=gnu99 -pg -g -O0 -lm

output: decay.o io.o rand.o
	gcc decay.o io.o rand.o ${CFLAGS} -o decay

decay.o: decay.c io.h rand.h
	gcc -c ${CFLAGS} decay.c

io.o: io.c io.h
	gcc -c ${CFLAGS} io.c

rand.o: rand.c rand.h
	gcc -c ${CFLAGS} rand.c

clean:
	rm decay.o io.o rand.o decay
