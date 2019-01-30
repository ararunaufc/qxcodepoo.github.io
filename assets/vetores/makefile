CPPFLAGS = -Wall -g -std=gnu99
SOURCE = ../../_posts/0001-02-01-vetores.md 
all: vpl cpp tbase

cpp: solver
	th.py run solver $(SOURCE) -v

vpl: $(SOURCE)
	th.py build t.vpl $(SOURCE)

mbase:
	sed '/\/\/\_B/,\/\/\_E/d' solver.c > base.c

tbase: mbase base
	th.py run base $(SOURCE) -q
