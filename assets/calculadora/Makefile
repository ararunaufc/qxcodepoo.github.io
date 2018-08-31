CPPFLAGS = -Wall -std=c++14

FOLDER = ../../_posts/
FILE = 0002-01-01-calculadora.md

all: clean solver fall
	./solver < fin.txt > fuser.txt
	diff fall.txt fuser.txt

java:fall
	javac Controller.java
	java Controller < fin.txt > fuser.txt
	diff fall.txt fuser.txt

clean:
	rm -rf solver *.txt

fall:
	@ cat $(FOLDER)$(FILE) | sed -n '/\__begin__/,/\<\__end__/p' | sed '/^\s*$$/d; /^\#/d' > fall.txt
	@ cat fall.txt | sed -n -e '/^\$$/p' | sed 's/^.//' > fin.txt