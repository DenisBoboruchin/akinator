CFLAGS = -c -Wall -Wextra -Werror -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds -Wcast-align -Wcast-qual               \
            -Wchar-subscripts -Wconversion -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral         \
            -Wformat-security -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Winline -Wlarger-than=8192      \
            -Wvla-larger-than=8192 -Wlogical-op -Wmissing-declarations -Wopenmp-simd -Wpacked -Wpointer-arith -Wredundant-decls         \
            -Wrestrict -Wshadow -Wstack-usage=8192 -Wstrict-overflow=2 -Wstringop-overflow=4 -Wsuggest-attribute=noreturn               \
            -Wsuggest-final-types -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros      \
            -Wno-missing-field-initializers -Wnarrowing -Wvarargs -fcheck-new -fstrict-overflow -flto-odr-type-merging 	

all: main.o akinator.o tree.o graphviz.o
	g++ akinator/akinator.cpp tree/tree.cpp graphviz/graphviz.cpp main.cpp -o main

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

akinator.o: akinator/akinator.cpp
	g++ $(CFLAGS) akinator/akinator.cpp

tree.o: tree/tree.cpp
	g++ $(CFLAGS) tree/tree.cpp

graphviz.o: graphviz/graphviz.cpp
	g++ $(CFLAGS) graphviz/graphviz.cpp

clean:
	rm -rf *.out *.o main
