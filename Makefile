CC=g++

CFLAGS=-c -Wall -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
          -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
		  -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		  -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		  -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
		  -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
		  -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: Onegin.exe


Onegin.exe: Onegin.o Qsort.o Text_Funcs.o
	$(CC) $^ -o $@

Onegin.o: Onegin.cpp Text_Funcs.h Qsort.h
	$(CC) $(CFLAGS) $<

Qsort.o: Qsort.cpp Qsort.h
	$(CC) $(CFLAGS) $<

Text_Funcs.o: Text_Funcs.cpp Text_Funcs.h
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o main.exe
