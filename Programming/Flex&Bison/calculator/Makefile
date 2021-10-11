calculator:
	bison -d calculator.y
	flex scanner.flex
	cc -o $@ calculator.tab.c lex.yy.c -lfl

clear:
	rm -rf calculator.tab.*
	rm -rf lex.yy.c
	rm -rf calculator
