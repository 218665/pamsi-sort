G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

tabl: obj obj/tabl.o obj/run.o src/main.cpp inc/tabl.hh inc/main.hh inc/run.hh
	$(G) $(GFLAGS) ./obj/tabl.o ./obj/run.o ./src/main.cpp -o tabl

obj:
	mkdir obj

obj/tabl.o: src/tabl.cpp inc/tabl.hh
	$(G) $(GFLAGS) -c ./src/tabl.cpp -o ./obj/tabl.o
	
obj/run.o: src/run.cpp inc/run.hh
	$(G) $(GFLAGS) -c ./src/run.cpp -o ./obj/run.o
	
clean:
	rm -fr ./obj/*.o tabl
