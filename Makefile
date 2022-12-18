CC = g++
OPTION = -g
OBJ = readfile.o container.o decisiontree.o
ALL = run

run: run.o $(OBJ)
	$(CC) $(OPTION) $< $(OBJ) -o $@
%:%.o $(OBJ)
	$(CC) $(OPTIONS) $< $(OBJ) -o $@
%.o:%.cc 
	$(CC) $(OPTIONS) -c $<
clean:
	rm *.o
	rm $(ALL)

readfile.o: readfile.hh
container.o: container.hh
decisiontree.o: decisiontree.hh
