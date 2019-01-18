CPPFLAGS = -Wall -std=c++14
SOURCE = ../../_posts/0002-01-01-calculadora.md 

cpp: solver 
	th.py run solver $(SOURCE)

java:
	th.py run "java Controller" $(SOURCE)

list:
	th.py list $(SOURCE)

vpl:
	th.py build tests.vpl $(SOURCE)