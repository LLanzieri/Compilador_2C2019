flex lexico.l
bison -dyv sintactico.y
gcc.exe lex.yy.c y.tab.c pila.c pila.h -o segunda.exe
pause
segunda.exe prueba.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del execute.exe
pause