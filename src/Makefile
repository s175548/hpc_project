
BDIR = ../bin
IDIR =../include
ODIR = ../obj
CC=g++
CFLAGS = -std=gnu++11 -pg -g -O0 -lm



_DEPS =  gof_serial.h gof_serial_contig_mem.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
_BINS = correctness_test performance_contig_mem performance
BINS = $(patsubst %,$(BDIR)/%,$(_BINS))
_OBJ = correctness_test.o gof_serial_contig_mem.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
_OBJ1 = performance_contig_mem.o gof_serial_contig_mem.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(_OBJ1))
_OBJ2 = performance.o gof_serial.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

all: $(BINS) 

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/correctness_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(BDIR)/performance_contig_mem: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(BDIR)/performance: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(ODIR)/*.o 



