CPPFLAGS = -Wall -std=c++14
SOURCE = ../../_posts/0001-01-01-shell.md 

all: cpp java vpl

cpp: solver 
	th.py run solver $(SOURCE) -v

java:
	javac Solver.java
	th.py run "java Solver" $(SOURCE) -v

list:
	th.py list $(SOURCE)

vpl:
	th.py build tests.vpl $(SOURCE)
	sed -n '/^```bash/,/^```/p' $(SOURCE) > t.md
