%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define LIMITE_REAL 32768.00
#define LIMITE_ENTERO 2147483647
#define LIMITE_CADENA 30
#define LIMITE_ID 30

int validarLongitudId();
int validarLongitudReal();
int validarLongitudEntero();
int validarLongitudCadena();
void mostrarError(char*);
void quitarComillas();
int validarVariableDeclarada(char* nombre);

FILE  *yyin;
char auxS[100];
char mensajeDeError[200];
int finDeclaraciones = 0;

%}
%option noyywrap  
%option yylineno 


DIGITO					[0-9]
LETRA					[a-zA-Z]
COMENTARIOS				\-\-\/([^"\/\-"|"\-\/"]|\n)*\/\-\-
COMENTARIOS_ANIDADOS	\-\-\/([^"\/\-"|"\-\/"]|\n)*{COMENTARIOS}*([^"\/\-"|"\-\/"]|\n)*\/\-\-
ID						{LETRA}({LETRA}|{DIGITO}|_)*
REAL					({DIGITO}*"."{DIGITO}+|{DIGITO}+".")
ENTERO					{DIGITO}+
CADENA					\"[^"\n]*\"
DEFAULT 				(.)

%%

{COMENTARIOS}				{}
{COMENTARIOS_ANIDADOS}		{}


"REPEAT"   					{return REPEAT;}
"UNTIL"						{return UNTIL;}
"+"							{return OPERACION_SUMA;}
"-"							{return OPERACION_RESTA;}
"*"							{return OPERACION_MULTIPLICACION;}
"/"							{return OPERACION_DIVISION;}
"\("						{return PARENTESIS_ABIERTO;}
"\)"						{return PARENTESIS_CERRADO;}
","							{return COMA;}
":="						{return OPERADOR_ASIGNACION;}
"READ"						{return READ;}
"PRINT"						{return PRINT;}
"IF"						{return OPERADOR_IF;}
"THEN"						{return OPERADOR_THEN;}
"ELSE"						{return OPERADOR_ELSE;}
"ENDIF"						{return OPERADOR_ENDIF;}
"AND"						{return OPERADOR_AND;}
"OR"						{return OPERADOR_OR;}
"NOT"						{return OPERADOR_NOT;}
">"							{return OPERADOR_MAYOR_A;}
"<"							{return OPERADOR_MENOR_A;}
">="						{return OPERADOR_MAYOR_O_IGUAL_A;}
"<="						{return OPERADOR_MENOR_O_IGUAL_A;}
"=="						{return OPERADOR_IGUAL_A;}
"!="						{return OPERADOR_DISTINTO_A;}
"VAR"						{return VAR;}
"ENDVAR"					{
								finDeclaraciones=1;
								return ENDVAR;
							}
";"							{return PUNTO_Y_COMA;}
":"							{return DOS_PUNTOS;}
"FLOAT"						{return TIPO_REAL;}
"STRING"					{return TIPO_CADENA;}
"INT"						{return TIPO_ENTERO;}
"["							{return CORCHETE_ABIERTO;}
"]"							{return CORCHETE_CERRADO;}
"FILTER"					{return FILTER;}
"_"							{return GUION_BAJO;}


{ID}					{	sprintf(auxS,"%s", yytext);
							if(validarLongitudId() == 0) {
								sprintf(mensajeDeError, "El identificador %s excede los %d caracteres de longitud.", yytext, LIMITE_ID);
				 				mostrarError(mensajeDeError);
							}
							yylval.str_val=auxS;
							if(finDeclaraciones==1){
								validarVariableDeclarada(yytext);
							}
							return ID;
						}

{ENTERO}				{ 	if(validarLongitudEntero() == 0){
								sprintf(mensajeDeError, "El ENTERO %s excede el rango admitido.", yytext);
				 				mostrarError(mensajeDeError);
							}
							yylval.str_val=yytext;
							return ENTERO;
						}

{REAL}					{		
								if(validarLongitudReal() == 0){
								sprintf(mensajeDeError, "El REAL %s excede el rango admitido.", yytext);
				 				mostrarError(mensajeDeError);
							}
							yylval.str_val=yytext;
							return REAL;
						}

{CADENA} 				{	if(validarLongitudCadena() == 0) {
								sprintf(mensajeDeError, "Cadena %s excede los %d caracteres de longitud.", yytext, LIMITE_CADENA);
				 				mostrarError(mensajeDeError);
							}
							sprintf(auxS,"%s", yytext);
							quitarComillas();
							yylval.str_val=auxS; 
							return CADENA;
						}
"\n"      		
"\r"
"\r\n"
"\t"
" "
{DEFAULT}			{
							sprintf(mensajeDeError, "Caracter invalido: %s", yytext);
							mostrarError(mensajeDeError);
						}


%%

int validarLongitudId(){
	if(strlen(yytext) <= LIMITE_ID){
		return 1;
	}
	return 0;
}

int validarLongitudReal(){
	float real;
	sscanf(yytext,"%f", &real);
	if(real >= 0.0 && real < LIMITE_REAL){
		return 1;
	}
	return 0;
}

int validarLongitudEntero(){
	int entero;
	sscanf(yytext,"%d",&entero);
	if(entero >= 0 && entero < LIMITE_ENTERO){
		return 1;
	}
	return 0;
}

int validarLongitudCadena(){
	if((strlen(yytext) - 2) <= LIMITE_CADENA){
		return 1;
	}
	return 0;
}

void quitarComillas() {
	int i = 0;
	while(auxS[i+1] != '\"') {
		auxS[i] = auxS[i+1];
		i++;
	}
	auxS[i] = '\0';
}