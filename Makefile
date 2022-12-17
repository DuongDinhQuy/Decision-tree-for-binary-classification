CC = g++
OPTION = -g
OBJ = readfile.o
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