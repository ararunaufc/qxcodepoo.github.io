CFLAGS = -Wall -g -std=gnu99
CPPFLAGS = -Wall -g -std=c++14
SOURCE = ../../_posts/0001-02-01-vetores.md 
all: vpl c cpp tbase

c: solver
	th.py run solver $(SOURCE) -v

cpp: solver_cpp
	th.py run solver_cpp $(SOURCE) -v

vpl: $(SOURCE)
	th.py build t.vpl $(SOURCE)

mbase:
	sed '/\/\/\_B/,\/\/\_E/d' solver.c > base.c
	sed '/\/\/\_B/,\/\/\_E/d' solver_cpp.cpp > base_cpp.cpp

tbase: mbase base base_cpp
	th.py run base $(SOURCE) -q
	th.py run base_cpp $(SOURCE) -q
