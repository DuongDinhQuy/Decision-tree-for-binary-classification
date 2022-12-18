CC = g++
OPTION = -g
OBJ = fileIO.o container.o decisiontree.o
ALL = getaccuracy predict

all: $(ALL)
tags: *.cc *.hh
	$(CTAG) -R *

getaccuracy: getaccuracy.o $(OBJ)
	$(CC) $(OPTION) $< $(OBJ) -o $@
predict: predict.o $(OBJ)
	$(CC) $(OPTION) $< $(OBJ) -o $@
%:%.o $(OBJ)
	$(CC) $(OPTIONS) $< $(OBJ) -o $@
%.o:%.cc 
	$(CC) $(OPTIONS) -c $<
clean:
	rm *.o
	rm $(ALL)

fileIO.o: fileIO.hh
container.o: container.hh
decisiontree.o: decisiontree.hh
