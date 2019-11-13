flex lexico.l
bison -dyv sintactico.y
gcc.exe lex.yy.c y.tab.c pila.c pila.h -o Grupo01.exe
pause
Grupo01.exe prueba.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
pause