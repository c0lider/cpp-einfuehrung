CPP_OPTS= -std=c++11

abenteuer: src/main.cpp held.o include/held.h elf.o include/elf.h mensch.o include/mensch.h zwerg.o include/zwerg.h
	g++ $(CPP_OPTS) src/main.cpp bin/held.o bin/elf.o bin/mensch.o bin/zwerg.o -o bin/executable
	bin/executable

held.o: src/held.cpp include/held.h
	g++ $(CPP_OPTS) -c src/held.cpp -o bin/held.o

elf.o: src/elf.cpp include/elf.h
	g++ $(CPP_OPTS) -c src/elf.cpp -o bin/elf.o

mensch.o: src/mensch.cpp include/mensch.h
	g++ $(CPP_OPTS) -c src/mensch.cpp -o bin/mensch.o

zwerg.o: src/zwerg.cpp include/zwerg.h
	g++ $(CPP_OPTS) -c src/zwerg.cpp -o bin/zwerg.o
