calculator:
	bison -d calculator.y
	flex -c++ scanner.flex
	clang++ -o $@ calculator.tab.c lex.yy.cc -lfl

clear:
	rm -rf calculator.tab.*
	rm -rf lex.yy.cc
	rm -rf calculator
