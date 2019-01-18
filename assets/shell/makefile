CPPFLAGS = -Wall -g -std=c++14
SOURCE = ../../_posts/0001-01-01-shell.md 
all: solver
	th.py run solver $(SOURCE) -v

vpl: $(SOURCE)
	th.py build tests.vpl $(SOURCE)
