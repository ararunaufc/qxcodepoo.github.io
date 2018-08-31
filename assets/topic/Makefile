CPPFLAGS = -Wall -std=c++14

FOLDER = ../../_posts/
FILE = 0005-01-01-topic2.md

all: clean solver fall
	./solver < fin.txt > fuser.txt
	diff fall.txt fuser.txt

clean:
	rm -rf solver *.txt

fall:
	@ #                         EXTRACE        TAGS                | REMOVE BLANKS & COMMENTS
	@ cat $(FOLDER)$(FILE) | sed -n '/\__begin__/,/\<\__end__/p' | sed '/^\s*$$/d; /^\#/d' > fall.txt
	@ #     pegando so quem comeca com $ e removendo apenas o primeiro char $
	@ cat fall.txt | sed -n -e '/^\$$/p' | sed 's/^.//' > fin.txt
#fout:
#	@ cat $(FOLDER)$(FILE) | sed -n '/\TagBegin/,/\<\TagEnd/p' | sed '/^\s*$$/d; /^\#/d; /^[a-zA-Z0-9]/d' | sed -e 's/^[ \t]*//' > fout.txt
