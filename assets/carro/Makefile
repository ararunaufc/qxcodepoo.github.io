CPPFLAGS = -Wall -std=c++14

FOLDER = ../../_posts/
FILE = 0003-01-01-carro.md

all: clean solver fin fall
	./solver < fin.txt > fout.txt
	diff fall.txt fout.txt

java:
	javac Controller.java
	java Controller
clean:
	rm -rf Controller.class calculadora *.txt
fin:
	@ cat $(FOLDER)$(FILE) | sed -n '/\TagInit/,/\<\TagEnd/p' | sed '/^\s*$$/d; /^\#/d; /^ /d' > fin.txt
fall:
	@ cat $(FOLDER)$(FILE) | sed -n '/\TagInit/,/\<\TagEnd/p' | sed '/^\s*$$/d; /^\#/d' > fall.txt

#fout:
#	@ cat $(FOLDER)$(FILE) | sed -n '/\TagInit/,/\<\TagEnd/p' | sed '/^\s*$$/d; /^\#/d; /^[a-zA-Z0-9]/d' | sed -e 's/^[ \t]*//' > fout.txt
