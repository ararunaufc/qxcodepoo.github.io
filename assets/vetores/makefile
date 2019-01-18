CPPFLAGS = -Wall -g -std=gnu99
SOURCE = ../../_posts/0001-02-01-vetores.md 
all: solver
	th.py run solver $(SOURCE) -v

vpl: $(SOURCE)
	th.py build tests.vpl $(SOURCE)
