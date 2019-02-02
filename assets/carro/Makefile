CPPFLAGS = -Wall -std=c++14
SOURCE = ../../_posts/0003-01-01-carro.md

all: solver 
	th.py run solver $(SOURCE)

list:
	th.py list $(SOURCE)

vpl:
	th.py build tests.vpl $(SOURCE)
	../bin/filter_md.sh $(SOURCE) > t.md