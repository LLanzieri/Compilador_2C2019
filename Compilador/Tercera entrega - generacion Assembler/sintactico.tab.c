
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
#include <string.h>
#include "pila.h"
#include <ctype.h>

	int yystopparser=0;
	FILE  *yyin;
	char *yyltext;
	char *yytext;
	FILE *archivoCodigoIntermedio;
	char mensajeDeError[200];
	char conversionItoA[20];
	char bufferaux1[20];
	char bufferaux2[20];

	/* --------------- CONSTANTES --------------- */

#define TAM_NOMBRE 32	/* Limite tamaño nombre (sumar 1 para _ ) */
#define CteString "CTE_STRING"
#define CteInt "CTE_INT"
#define CteReal "CTE_REAL"

	/* --------------- TABLA DE SIMBOLOS --------------- */

	typedef struct
	{
		char nombre[100];
		char tipo  [11];
		char valor [100];
		int longitud;
	} struct_tabla_de_simbolos;

	struct_tabla_de_simbolos tablaDeSimbolos[200];


	/* --------------- PROTOTIPO DE FUNCIONES --------------- */

	void guardarTabla(void);
	void agregarConstante(char*,char*);
	int buscarCte(char* , char*);
	void validarVariableDeclarada(char* nombre);
	void mostrarError(char *mensaje);
	void guardarTipo(char * tipoVariable);
	void guardarEnVectorTablaSimbolos(int opc, char * cad);
	void acomodarPunterosTS();
	void quitarDuplicados();
	void copiarCharEn(char **, char*);
	int crear_terceto(char*, char*, char*);
	void escribe_arch_tercetos();

	int cantidadTokens = 0;
	int i=0; 
	int j=0;
	int cant_elementos=0;
	int min=0;
	int pos_td=0;
	int pos_cv=0;
	int cant_variables=0;
	int cant_tipo_dato=0; 
	int diferencia=0;
	int cant_ctes=0;
	int finBloqueDeclaraciones=0;
	int ladoDerecho=0;
	int ladoIzquierdo=0;
	int aux1=0;
	int aux2=0;
	char tipoVariableActual[20];

	char* operadorAux;
	char idAux[20];

	int yylex();
	int yyerror();

	/* --------------- TERCETOS -------------- */

#define DEBUG		0

	typedef struct terceto {
		int nroTerceto;
		char ope[35];
		char te1[30];
		char te2[30];
	}	terceto;

	terceto  vector_tercetos[200]; 		// vector de tercetos
	int indice_terceto = 0;	   			// Cantidad de elementos e indice de tercetos

	int F_ind=0;
	int	T_ind=0;
	int E_ind=0;
	int ASIG_ind=0;
	int aux=0;
	
	Pila pilaExpresion;
	Pila pilaTermino;
	Pila pilaFactor;
	Pila pilaTercetoActual;					// para la parte de IF / REPEAT (?)
	Pila pilaIf;
	Pila pilaRepeat;
	



	

/* Line 189 of yacc.c  */
#line 184 "sintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COMENTARIOS = 258,
     COMENTARIOS_ANIDADOS = 259,
     REPEAT = 260,
     UNTIL = 261,
     OPERACION_SUMA = 262,
     OPERACION_RESTA = 263,
     OPERACION_MULTIPLICACION = 264,
     OPERACION_DIVISION = 265,
     ID = 266,
     ENTERO = 267,
     REAL = 268,
     PARENTESIS_ABIERTO = 269,
     PARENTESIS_CERRADO = 270,
     COMA = 271,
     OPERADOR_ASIGNACION = 272,
     CADENA = 273,
     READ = 274,
     PRINT = 275,
     OPERADOR_IF = 276,
     OPERADOR_THEN = 277,
     OPERADOR_ELSE = 278,
     OPERADOR_ENDIF = 279,
     OPERADOR_AND = 280,
     OPERADOR_OR = 281,
     OPERADOR_NOT = 282,
     OPERADOR_MAYOR_A = 283,
     OPERADOR_MENOR_A = 284,
     OPERADOR_MAYOR_O_IGUAL_A = 285,
     OPERADOR_MENOR_O_IGUAL_A = 286,
     OPERADOR_IGUAL_A = 287,
     OPERADOR_DISTINTO_A = 288,
     VAR = 289,
     ENDVAR = 290,
     DOS_PUNTOS = 291,
     PUNTO_Y_COMA = 292,
     TIPO_ENTERO = 293,
     TIPO_REAL = 294,
     TIPO_CADENA = 295,
     CORCHETE_ABIERTO = 296,
     CORCHETE_CERRADO = 297,
     FILTER = 298,
     GUION_BAJO = 299,
     OPERADOR_ASIG_STRING = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 111 "sintactico.y"

	int int_val;
	double float_val;
	char *str_val;



/* Line 214 of yacc.c  */
#line 273 "sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 285 "sintactico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    15,    17,    25,    29,
      31,    33,    35,    37,    41,    43,    46,    48,    50,    52,
      54,    56,    58,    60,    63,    66,    69,    70,    76,    77,
      83,    84,    90,    94,    98,   100,   104,   108,   110,   112,
     114,   116,   120,   122,   124,   125,   133,   134,   135,   146,
     147,   148,   149,   161,   162,   163,   176,   177,   178,   179,
     195,   196,   197,   198,   199,   216,   220,   226,   232,   239,
     246,   250,   254,   258,   262,   266,   270,   279,   283,   287,
     292,   294,   298,   302,   306,   310,   314,   318,   326,   330,
     332,   336,   340,   342,   346,   350,   352,   354,   356,   358,
     362
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    55,    -1,    34,    50,
      35,    -1,    50,    51,    -1,    51,    -1,    41,    52,    42,
      36,    41,    54,    42,    -1,    52,    16,    53,    -1,    53,
      -1,    38,    -1,    39,    -1,    40,    -1,    54,    16,    11,
      -1,    11,    -1,    55,    56,    -1,    56,    -1,    61,    -1,
      67,    -1,    89,    -1,    59,    -1,    57,    -1,    58,    -1,
      19,    11,    -1,    20,    18,    -1,    20,    11,    -1,    -1,
       5,    60,    55,     6,    84,    -1,    -1,    11,    62,    17,
      64,    37,    -1,    -1,    11,    63,    45,    18,    37,    -1,
      64,     7,    65,    -1,    64,     8,    65,    -1,    65,    -1,
      65,     9,    66,    -1,    65,    10,    66,    -1,    66,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    64,    15,    -1,
      86,    -1,    68,    -1,    -1,    21,    14,    85,    69,    15,
      55,    24,    -1,    -1,    -1,    21,    14,    85,    70,    25,
      85,    71,    15,    55,    24,    -1,    -1,    -1,    -1,    21,
      14,    85,    72,    26,    85,    73,    15,    74,    55,    24,
      -1,    -1,    -1,    21,    21,    14,    85,    75,    15,    22,
      55,    76,    23,    55,    24,    -1,    -1,    -1,    -1,    21,
      21,    14,    85,    77,    25,    85,    78,    15,    22,    55,
      79,    23,    55,    24,    -1,    -1,    -1,    -1,    -1,    21,
      21,    14,    85,    80,    26,    85,    81,    15,    82,    22,
      55,    83,    23,    55,    24,    -1,    14,    85,    15,    -1,
      14,    85,    25,    85,    15,    -1,    14,    85,    26,    85,
      15,    -1,    14,    27,    14,    84,    15,    15,    -1,    14,
      27,    14,    85,    15,    15,    -1,    64,    28,    64,    -1,
      64,    29,    64,    -1,    64,    30,    64,    -1,    64,    31,
      64,    -1,    64,    32,    64,    -1,    64,    33,    64,    -1,
      43,    14,    87,    16,    41,    54,    42,    15,    -1,    88,
      25,    88,    -1,    88,    26,    88,    -1,    27,    14,    88,
      15,    -1,    88,    -1,    44,    28,    91,    -1,    44,    29,
      91,    -1,    44,    30,    91,    -1,    44,    31,    91,    -1,
      44,    32,    91,    -1,    44,    33,    91,    -1,    41,    54,
      42,    17,    41,    90,    42,    -1,    90,    16,    91,    -1,
      91,    -1,    91,     7,    92,    -1,    91,     8,    92,    -1,
      92,    -1,    92,     9,    93,    -1,    92,    10,    93,    -1,
      93,    -1,    11,    -1,    12,    -1,    13,    -1,    14,    91,
      15,    -1,    86,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   168,   171,   179,   180,   182,   185,   186,
     189,   194,   199,   206,   211,   217,   218,   220,   221,   222,
     223,   224,   225,   227,   229,   230,   232,   232,   235,   235,
     242,   242,   247,   254,   261,   266,   272,   279,   284,   290,
     295,   300,   305,   307,   309,   309,   316,   316,   316,   326,
     326,   326,   326,   339,   339,   339,   353,   353,   354,   353,
     373,   373,   373,   374,   373,   392,   393,   394,   395,   396,
     399,   408,   418,   428,   438,   447,   457,   460,   461,   462,
     463,   465,   466,   467,   468,   469,   470,   473,   476,   477,
     480,   481,   482,   484,   485,   486,   488,   489,   490,   491,
     492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMENTARIOS", "COMENTARIOS_ANIDADOS",
  "REPEAT", "UNTIL", "OPERACION_SUMA", "OPERACION_RESTA",
  "OPERACION_MULTIPLICACION", "OPERACION_DIVISION", "ID", "ENTERO", "REAL",
  "PARENTESIS_ABIERTO", "PARENTESIS_CERRADO", "COMA",
  "OPERADOR_ASIGNACION", "CADENA", "READ", "PRINT", "OPERADOR_IF",
  "OPERADOR_THEN", "OPERADOR_ELSE", "OPERADOR_ENDIF", "OPERADOR_AND",
  "OPERADOR_OR", "OPERADOR_NOT", "OPERADOR_MAYOR_A", "OPERADOR_MENOR_A",
  "OPERADOR_MAYOR_O_IGUAL_A", "OPERADOR_MENOR_O_IGUAL_A",
  "OPERADOR_IGUAL_A", "OPERADOR_DISTINTO_A", "VAR", "ENDVAR", "DOS_PUNTOS",
  "PUNTO_Y_COMA", "TIPO_ENTERO", "TIPO_REAL", "TIPO_CADENA",
  "CORCHETE_ABIERTO", "CORCHETE_CERRADO", "FILTER", "GUION_BAJO",
  "OPERADOR_ASIG_STRING", "$accept", "start_programa", "programa",
  "bloque_declaracion", "lista_definiciones", "definicion",
  "lista_tipo_dato", "tipo_dato", "lista_ids", "bloque_programa",
  "sentencia", "entrada_datos", "salida_datos", "bloque_iteracion", "$@1",
  "asignacion", "$@2", "$@3", "expresion", "termino", "factor",
  "bloque_condicional", "bloque_if", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "condicion", "comparacion", "filtro", "condicion_filter",
  "comparacion_filter", "asignacion_multiple", "lista_expresiones",
  "expresion_numerica", "termino_numerico", "factor_numerico", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    50,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    58,    58,    60,    59,    62,    61,
      63,    61,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    67,    69,    68,    70,    71,    68,    72,
      73,    74,    68,    75,    76,    68,    77,    78,    79,    68,
      80,    81,    82,    83,    68,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    85,    85,    86,    87,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    89,    90,    90,
      91,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     2,     1,     7,     3,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     0,     5,     0,     5,
       0,     5,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     0,     7,     0,     0,    10,     0,
       0,     0,    11,     0,     0,    12,     0,     0,     0,    15,
       0,     0,     0,     0,    16,     3,     5,     5,     6,     6,
       3,     3,     3,     3,     3,     3,     8,     3,     3,     4,
       1,     3,     3,     3,     3,     3,     3,     7,     3,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     0,     6,     1,    26,
      28,     0,     0,     0,     0,     3,    16,    21,    22,    20,
      17,    18,    43,    19,    10,    11,    12,     0,     9,     4,
       5,     0,     0,     0,    23,    25,    24,     0,     0,    14,
       0,    15,     0,     0,     0,     0,     0,    38,    39,    40,
       0,     0,     0,    34,    37,    44,    42,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    13,     0,     0,     0,    27,    29,    31,    41,     0,
       0,     0,    80,    32,    33,    70,    71,    72,    73,    74,
      75,    35,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    50,     0,     0,     0,    96,
      97,    98,     0,   100,     0,    89,    92,    95,     7,     0,
      65,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,    77,    78,    45,     0,     0,     0,    57,    61,     0,
       0,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,    51,    54,     0,     0,    99,    88,
      90,    91,    93,    94,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,    62,    68,    69,    76,    48,     0,
       0,     0,     0,    52,     0,    58,     0,    55,     0,    63,
       0,     0,     0,     0,    59,     0,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     6,     7,    27,    28,    40,    15,
      16,    17,    18,    19,    31,    20,    32,    33,    52,    53,
      54,    21,    22,    77,    78,   154,    79,   155,   191,   106,
     192,   107,   176,   208,   108,   177,   202,   211,    85,   112,
      56,    91,    92,    23,   134,   135,   136,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     -29,   -33,    17,   -80,   200,    40,    82,   -80,   -80,   -80,
     -26,    51,    -4,     7,    63,   200,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,     2,   -80,   -80,
     -80,   200,    60,    42,   -80,   -80,   -80,    72,    86,   -80,
      39,   -80,    40,    69,     4,    72,    98,   -80,   -80,   -80,
      72,   111,   223,    37,   -80,    77,   -80,    72,   124,   121,
     -80,   107,   136,     5,   118,    53,   -24,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,   147,   149,   155,
      87,   -80,   154,    63,    45,   -80,   -80,   -80,   -80,   194,
     207,   180,   103,    37,    37,   134,   134,   134,   134,   134,
     134,   -80,   -80,   200,    72,    72,   192,   184,   189,   108,
      47,   196,     1,   172,   108,   108,   108,   108,   108,   108,
     177,   172,   172,    90,   -80,   -80,   204,    72,    72,   -80,
     -80,   -80,   108,   -80,    48,   157,   143,   -80,   -80,   145,
     -80,    72,    72,   212,   157,   157,   157,   157,   157,   157,
      63,   -80,   -80,   -80,   213,   214,   200,   -80,   -80,   132,
     108,   -80,   108,   108,   108,   108,    45,   218,   227,   228,
     229,   -80,    49,   200,   -80,   200,   242,   243,   -80,   157,
     143,   143,   -80,   -80,   217,   244,   245,   -80,   -80,   246,
     113,   200,   199,   240,   -80,   -80,   -80,   -80,   -80,   125,
     200,   200,   241,   -80,   158,   200,   200,   -80,   247,   200,
     200,   248,   182,   200,   -80,   193,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   -80,   -80,   -80,   258,   -80,   224,   -79,   -30,
     -15,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -39,   100,
      97,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   126,   -35,
     -66,   -80,   -46,   -80,   -80,   -78,    23,    27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int16 yytable[] =
{
      41,    44,    55,    89,   110,     1,    63,    35,     5,     9,
      62,    65,    67,    68,    36,    10,   140,     8,    42,   -30,
      90,    37,    80,    11,    12,    13,   141,   142,    38,    41,
      95,    96,    97,    98,    99,   100,   144,   145,   146,   147,
     148,   149,    86,   133,    43,    14,    75,    76,   133,   133,
     133,   133,   133,   133,   159,    58,    47,    48,    49,    50,
      67,    68,    34,    58,   160,    58,   133,   143,    88,   124,
     125,   172,   111,   123,    39,   151,   152,    45,    24,    25,
      26,    59,   179,    47,    48,    49,    50,    46,    51,   138,
     161,   189,   157,   158,   133,     9,   133,   133,   133,   133,
      57,    10,   -46,   -49,   168,    61,   169,   170,    41,    11,
      12,    13,   -56,   -60,   153,    51,    64,    29,     9,   129,
     130,   131,   132,     5,    10,    66,   175,   184,   121,   122,
       9,    14,    11,    12,    13,    81,    10,   198,    82,   162,
     163,    67,    68,   190,    11,    12,    13,   178,    83,   203,
      84,    51,   164,   165,    14,    87,    47,    48,    49,   166,
      41,   199,   103,     9,   162,   163,    14,    93,    94,    10,
     204,   205,   101,   102,   104,    41,   209,    11,    12,    13,
     212,   105,   207,   215,    41,   180,   181,     9,    51,    41,
      41,   182,   183,    10,    41,   109,   120,    41,     9,    14,
      41,    11,    12,    13,    10,     9,   214,   126,   113,   127,
     139,    10,    11,    12,    13,   128,    90,   216,   150,    11,
      12,    13,   200,    14,    67,    68,   156,   171,   173,   174,
      67,    68,    88,   185,    14,   114,   115,   116,   117,   118,
     119,    14,   186,   187,   188,    69,    70,    71,    72,    73,
      74,    69,    70,    71,    72,    73,    74,   193,   194,   195,
     196,   197,   201,   206,    30,   167,    60,     0,     0,     0,
     210,   213
};

static const yytype_int16 yycheck[] =
{
      15,    31,    37,    27,    83,    34,    45,    11,    41,     5,
       6,    50,     7,     8,    18,    11,    15,     0,    16,    45,
      44,    14,    57,    19,    20,    21,    25,    26,    21,    44,
      69,    70,    71,    72,    73,    74,   114,   115,   116,   117,
     118,   119,    37,   109,    42,    41,     9,    10,   114,   115,
     116,   117,   118,   119,   132,    16,    11,    12,    13,    14,
       7,     8,    11,    16,    16,    16,   132,   113,    15,   104,
     105,   150,    27,   103,    11,   121,   122,    17,    38,    39,
      40,    42,   160,    11,    12,    13,    14,    45,    43,    42,
      42,    42,   127,   128,   160,     5,   162,   163,   164,   165,
      14,    11,    25,    26,   139,    36,   141,   142,   123,    19,
      20,    21,    25,    26,    24,    43,    18,    35,     5,    11,
      12,    13,    14,    41,    11,    14,   156,   166,    25,    26,
       5,    41,    19,    20,    21,    11,    11,    24,    17,     7,
       8,     7,     8,   173,    19,    20,    21,    15,    41,    24,
      14,    43,     9,    10,    41,    37,    11,    12,    13,    14,
     175,   191,    15,     5,     7,     8,    41,    67,    68,    11,
     200,   201,    75,    76,    25,   190,   206,    19,    20,    21,
     210,    26,    24,   213,   199,   162,   163,     5,    43,   204,
     205,   164,   165,    11,   209,    41,    16,   212,     5,    41,
     215,    19,    20,    21,    11,     5,    24,    15,    14,    25,
      14,    11,    19,    20,    21,    26,    44,    24,    41,    19,
      20,    21,    23,    41,     7,     8,    22,    15,    15,    15,
       7,     8,    15,    15,    41,    28,    29,    30,    31,    32,
      33,    41,    15,    15,    15,    28,    29,    30,    31,    32,
      33,    28,    29,    30,    31,    32,    33,    15,    15,    15,
      15,    15,    22,    22,     6,   139,    42,    -1,    -1,    -1,
      23,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    47,    48,    49,    41,    50,    51,     0,     5,
      11,    19,    20,    21,    41,    55,    56,    57,    58,    59,
      61,    67,    68,    89,    38,    39,    40,    52,    53,    35,
      51,    60,    62,    63,    11,    11,    18,    14,    21,    11,
      54,    56,    16,    42,    55,    17,    45,    11,    12,    13,
      14,    43,    64,    65,    66,    85,    86,    14,    16,    42,
      53,    36,     6,    64,    18,    64,    14,     7,     8,    28,
      29,    30,    31,    32,    33,     9,    10,    69,    70,    72,
      85,    11,    17,    41,    14,    84,    37,    37,    15,    27,
      44,    87,    88,    65,    65,    64,    64,    64,    64,    64,
      64,    66,    66,    15,    25,    26,    75,    77,    80,    41,
      54,    27,    85,    14,    28,    29,    30,    31,    32,    33,
      16,    25,    26,    55,    85,    85,    15,    25,    26,    11,
      12,    13,    14,    86,    90,    91,    92,    93,    42,    14,
      15,    25,    26,    88,    91,    91,    91,    91,    91,    91,
      41,    88,    88,    24,    71,    73,    22,    85,    85,    91,
      16,    42,     7,     8,     9,    10,    14,    84,    85,    85,
      85,    15,    54,    15,    15,    55,    78,    81,    15,    91,
      92,    92,    93,    93,    64,    15,    15,    15,    15,    42,
      55,    74,    76,    15,    15,    15,    15,    15,    24,    55,
      23,    22,    82,    24,    55,    55,    22,    24,    79,    55,
      23,    83,    55,    23,    24,    55,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 166 "sintactico.y"
    { printf("Compilacion exitosa\n\n"); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 169 "sintactico.y"
    { printf("Programa OK\n\n"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 172 "sintactico.y"
    { 
	finBloqueDeclaraciones=1;
	quitarDuplicados(); 
	printf("bloque_definiciones OK\n\n");
	cant_ctes=cantidadTokens;	
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 179 "sintactico.y"
    {	printf("lista_definiciones -> lista_definiciones definicion OK\n\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 180 "sintactico.y"
    {	printf("lista_definiciones -> definicion OK\n\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 183 "sintactico.y"
    { acomodarPunterosTS(); printf("definicion OK\n\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 185 "sintactico.y"
    { printf("lista_tipo_dato -> lista_tipo_dato , tipo_dato OK\n\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 186 "sintactico.y"
    {printf("lista_tipo_dato -> tipo_dato OK \n\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 189 "sintactico.y"
    { 
	guardarTipo("ENTERO");
	guardarEnVectorTablaSimbolos(1,tipoVariableActual);
	printf("TIPO_ENTERO en tipo_variable OK\n\n");
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 194 "sintactico.y"
    {
	guardarTipo("REAL");
	guardarEnVectorTablaSimbolos(1,tipoVariableActual);
	printf("TIPO_REAL en tipo_variable OK\n\n");
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 199 "sintactico.y"
    {
	guardarTipo("CADENA");
	guardarEnVectorTablaSimbolos(1,tipoVariableActual);
	printf("TIPO_CADENA en tipo_variable OK\n\n");
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 206 "sintactico.y"
    {
	printf("%s\n", yylval.str_val);
	guardarEnVectorTablaSimbolos(2,yylval.str_val);
	printf("lista_ids -> lista_ids , ID OK\n\n");
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 211 "sintactico.y"
    {
	printf("%s\n", yylval.str_val);
	guardarEnVectorTablaSimbolos(2,yylval.str_val);
	printf("lista_ids -> ID OK\n\n");
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 217 "sintactico.y"
    {printf("bloque_programa -> bloque_programa sentencia OK \n\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 218 "sintactico.y"
    {printf("bloque_programa -> sentencia OK \n\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 220 "sintactico.y"
    {printf("sentencia -> asignacion OK \n\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 221 "sintactico.y"
    {printf("sentencia -> bloque_condicional OK \n\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 222 "sintactico.y"
    {printf("sentencia -> asignacion_multiple OK \n\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 223 "sintactico.y"
    {printf("sentencia -> bloque_iteracion OK \n\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 224 "sintactico.y"
    {printf("sentencia -> entrada_datos OK \n\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 225 "sintactico.y"
    {printf("sentencia -> salida_datos OK \n\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 227 "sintactico.y"
    { printf("READ ID OK \n\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 229 "sintactico.y"
    {printf("PRINT CADENA OK \n\n"); agregarConstante(yylval.str_val,CteString);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 230 "sintactico.y"
    { printf("PRINT ID OK\n\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 232 "sintactico.y"
    {apilar(&pilaRepeat,indice_terceto);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 233 "sintactico.y"
    {printf("bloque REPEAT-UNTIL OK\n\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 235 "sintactico.y"
    {strcpy(idAux,yylval.str_val);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 235 "sintactico.y"
    {printf("asignacion OK\n\n");
	E_ind = desapilar(&pilaExpresion);
	itoa(E_ind,conversionItoA,10);
	ASIG_ind = crear_terceto("=",idAux,conversionItoA);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 242 "sintactico.y"
    {strcpy(idAux,yylval.str_val);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 242 "sintactico.y"
    {printf("asignacion_string -> Cte_String OK \n\n");
	agregarConstante(yylval.str_val,CteString);		// +++------------------   validar que el ID sea string ------------+++++++++++++++
	crear_terceto("=",idAux,yylval.str_val);
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 247 "sintactico.y"
    {printf("expresion -> exp + term OK \n\n");
	itoa(desapilar(&pilaExpresion),bufferaux1,10);
	itoa(desapilar(&pilaTermino),bufferaux2,10);
	E_ind = crear_terceto("+",bufferaux1,bufferaux2 );
	apilar(&pilaExpresion,E_ind);

;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 254 "sintactico.y"
    {printf("expresion -> exp - term OK \n\n");
	itoa(desapilar(&pilaExpresion),bufferaux1,10);
	itoa(desapilar(&pilaTermino),bufferaux2,10);
	E_ind = crear_terceto("-",bufferaux1,bufferaux2 );
	apilar(&pilaExpresion,E_ind);
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 261 "sintactico.y"
    {printf("expresion -> term OK \n\n");
	E_ind = desapilar(&pilaTermino);
	apilar(&pilaExpresion,E_ind);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 266 "sintactico.y"
    {printf("term -> term * factor OK \n\n");
	itoa(desapilar(&pilaTermino),bufferaux1,10);
	itoa(desapilar(&pilaFactor),bufferaux2,10);
	T_ind=crear_terceto("*",bufferaux1,bufferaux2);
	apilar(&pilaTermino,T_ind);
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 272 "sintactico.y"
    {printf("term -> term / factor OK \n\n");
	itoa(desapilar(&pilaTermino),bufferaux1,10);
	itoa(desapilar(&pilaFactor),bufferaux2,10);
	T_ind=crear_terceto("/",bufferaux1,bufferaux2);
	apilar(&pilaTermino,T_ind);
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 279 "sintactico.y"
    {printf("term -> factor OK \n\n");
	T_ind = desapilar(&pilaFactor);
	apilar(&pilaTermino,T_ind);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 284 "sintactico.y"
    {
	printf("factor -> ID OK\n\n");
	F_ind = crear_terceto(yylval.str_val,"_","_");
	apilar(&pilaFactor,F_ind);
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 290 "sintactico.y"
    {
	printf("factor -> Cte_entera OK\n\n");agregarConstante(yylval.str_val,CteInt);
	F_ind = crear_terceto(yylval.str_val,"_","_");
	apilar(&pilaFactor,F_ind);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 295 "sintactico.y"
    {printf("factor -> Cte_Real OK\n\n");agregarConstante(yylval.str_val,CteReal);
	F_ind = crear_terceto(yylval.str_val,"_","_");
	apilar(&pilaFactor,F_ind);
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 300 "sintactico.y"
    {printf("factor -> ( expresion ) OK\n\n");
	F_ind = desapilar(&pilaExpresion);
	apilar(&pilaFactor,F_ind);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 305 "sintactico.y"
    {printf("factor -> filtro OK\n\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 307 "sintactico.y"
    {printf("bloque_condicional OK\n\n\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 309 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 310 "sintactico.y"
    {
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					
	strcpy(vector_tercetos[aux].te1,bufferaux1);		// desapilo y voy al final
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 316 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 316 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 317 "sintactico.y"
    {
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// desapilo y pongo donde voy en la segunda cond - voy al final
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// desapilo y pongo donde voy en la primer cond - voy al final
	strcpy(vector_tercetos[aux].te1,bufferaux1);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 326 "sintactico.y"
    {apilar(&pilaIf,aux); apilar(&pilaIf,crear_terceto("JMP","_","_"));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 326 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 326 "sintactico.y"
    {aux1=indice_terceto;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 327 "sintactico.y"
    {
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					//	desapilo y pongo donde salto con la segunda cond - voy al final
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux=desapilar(&pilaIf);
	itoa(aux1,bufferaux1,10);						// desapilo y pongo donde voy con el JMP
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux=desapilar(&pilaIf);
	itoa(aux+2,bufferaux1,10);							// desapilo y pongo donde voy si la primer condicion es falsa
	strcpy(vector_tercetos[aux].te1,bufferaux1);
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 339 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 339 "sintactico.y"
    {
	crear_terceto("JMP","_","_");			
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// paso a char[] el valor indice
	strcpy(vector_tercetos[aux].te1,bufferaux1);		// asigno el lugar donde salto
	apilar(&pilaIf,indice_terceto-1);
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 346 "sintactico.y"
    {
	printf("bloque_if -> IF condicion programa ELSE programa ENDIF\n\n");
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// paso a char[] el valor indice
	strcpy(vector_tercetos[aux].te1,bufferaux1);		// asigno el lugar donde salto
;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 353 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 353 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 354 "sintactico.y"
    {
	aux=crear_terceto("JMP","_","_");			// guardo el numero de terceto donde voy a poner el salto desde el fin del THEN al FINAL
	aux1=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// paso a char[] el valor indice
	strcpy(vector_tercetos[aux1].te1,bufferaux1);		// SALTO AL PRINCIPIO DEL ELSE
	aux1=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// paso a char[] el valor indice
	strcpy(vector_tercetos[aux1].te1,bufferaux1);		// SALTO AL PRINCIPIO DEL ELSE
	apilar(&pilaIf,aux);											// apilo el terceto que salta al final del THEN
;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 365 "sintactico.y"
    {
	printf("bloque_if -> IF CON ELSE\n\n");
	aux=desapilar(&pilaIf);
	itoa(indice_terceto,bufferaux1,10);					// paso a char[] el valor indice
	strcpy(vector_tercetos[aux].te1,bufferaux1);		// SALTO AL FINAL DEL ELSE

;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 373 "sintactico.y"
    {apilar(&pilaIf,aux); apilar(&pilaIf,crear_terceto("JMP","_","_"));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 373 "sintactico.y"
    {apilar(&pilaIf,aux);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 373 "sintactico.y"
    {aux1=indice_terceto;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 374 "sintactico.y"
    {apilar(&pilaIf,crear_terceto("JMP","_","_"));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 375 "sintactico.y"
    {
	aux=desapilar(&pilaIf);								// cargo el salto al final cuando termina el THEN
	itoa(indice_terceto,bufferaux1,10);
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux2 = aux+1;										// cargo la posicion donde empieza el ELSE
	aux=desapilar(&pilaIf);
	itoa(aux2,bufferaux1,10);					//	desapilo y pongo donde salto con la segunda cond - voy al ELSE
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux=desapilar(&pilaIf);
	itoa(aux1,bufferaux1,10);						// desapilo y pongo donde voy con el JMP - en el aux1 tengo la posicion donde empieza el THEN
	strcpy(vector_tercetos[aux].te1,bufferaux1);
	aux=desapilar(&pilaIf);
	itoa(aux+2,bufferaux1,10);							// desapilo y pongo donde voy si la primer condicion es falsa
	strcpy(vector_tercetos[aux].te1,bufferaux1);
;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 400 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JNBE","_","_");							// pongo en aux el numero de terceto donde usaria el salto
;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 409 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JNAE","_","_");		
;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 419 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JNB","_","_");		
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 429 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JNA","_","_");		
;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 439 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JE","_","_");		
;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 448 "sintactico.y"
    {
	ladoDerecho = desapilar(&pilaExpresion);
	ladoIzquierdo = desapilar(&pilaExpresion);
	itoa(ladoIzquierdo,bufferaux1,10);
	itoa(ladoDerecho,bufferaux2,10);
	crear_terceto("CMP",bufferaux1,bufferaux2);
	aux = crear_terceto("JNE","_","_");		
;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 458 "sintactico.y"
    {printf("FILTER OK\n\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 474 "sintactico.y"
    {printf("ASIGNACION MULTIPLE OK\n\n");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 480 "sintactico.y"
    {printf("expresion_numerica -> exp + term OK \n\n");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 481 "sintactico.y"
    {printf("expresion_numerica -> exp - term OK \n\n");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 482 "sintactico.y"
    {printf("expresion_numerica -> term OK \n\n");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 484 "sintactico.y"
    {printf("term -> term * factor_numerico OK \n\n");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 485 "sintactico.y"
    {printf("term -> term / factor_numerico OK \n\n");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 486 "sintactico.y"
    {printf("term -> factor_numerico OK \n\n");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 489 "sintactico.y"
    {	agregarConstante(yylval.str_val, CteInt);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 490 "sintactico.y"
    {	agregarConstante(yylval.str_val, CteReal);;}
    break;



/* Line 1455 of yacc.c  */
#line 2420 "sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 494 "sintactico.y"


int main(int argc,char *argv[]){

	if ((yyin = fopen(argv[1], "rt")) == NULL){
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
	}else {

		// inicializo las pilas
		pilaExpresion = crearPila();
		pilaTermino	= crearPila();
		pilaTercetoActual = crearPila();
		pilaFactor = crearPila();
		pilaIf = crearPila();
		pilaRepeat = crearPila();

		yyparse();

		guardarTabla();
		escribe_arch_tercetos();
	}
	fclose(yyin);
	return 0;
}

void mostrarError(char *mensaje) {
	printf("%s\n", mensaje);
	yyerror();
}

int yyerror(void){
	printf("ERROR EN COMPILACION.\n");
	system ("Pause");
	exit (1);
}

void guardarEnVectorTablaSimbolos(int opc, char * cad){
	if(finBloqueDeclaraciones==0){
		if(opc==1){
			strcpy(tablaDeSimbolos[pos_td].tipo,cad);
			cant_tipo_dato++;
			pos_td++;
		}else{
			strcpy(tablaDeSimbolos[pos_cv].nombre,cad);
			pos_cv++;
			cant_variables++;
		}
	}
}

void guardarTipo(char * tipoVariable) {
	strcpy(tipoVariableActual, tipoVariable);
}

void acomodarPunterosTS(){
	int indice=0;
	if(cant_tipo_dato!=cant_variables){
		if(pos_td<pos_cv){	
			min=pos_td;
			cant_elementos=min;
			pos_td=pos_cv=min;
			diferencia=(cant_variables-cant_tipo_dato);
			indice=min;
			while(diferencia>0){
				strcpy(tablaDeSimbolos[indice].tipo, "");
				strcpy(tablaDeSimbolos[indice].nombre, "");
				diferencia--;
				indice++;
			}
		}else{
			min=pos_cv;
			cant_elementos=min;
			pos_td=pos_cv=min;
			diferencia=(cant_tipo_dato-cant_variables);
			indice=min;
			while(diferencia>0){
				strcpy(tablaDeSimbolos[indice].tipo, "");
				strcpy(tablaDeSimbolos[indice].nombre, "");
				diferencia--;
				indice++;
			}
		}
	}else{
		cant_elementos=pos_cv;
		cant_tipo_dato=cant_variables=0;
	}
}

void quitarDuplicados(){
	for(i=0;i<cant_elementos;i++){
		if(strcmp(tablaDeSimbolos[i].nombre,"@")!=0){
			cantidadTokens++;
			for(j=i+1;j<cant_elementos;j++){
				if(strcmp(tablaDeSimbolos[i].tipo,tablaDeSimbolos[j].tipo)==0 && strcmp(tablaDeSimbolos[i].nombre,tablaDeSimbolos[j].nombre)==0){		// si los dos son iguales
					strcpy(tablaDeSimbolos[j].tipo, "@");
					strcpy(tablaDeSimbolos[j].nombre, "@");				// doy de baja a todos los proximos que son iguales
				}
			}
		}else{
			j=i+1;
			while(j<cant_elementos && strcmp(tablaDeSimbolos[j].tipo,"@")==0)
			j++;
			if(j<cant_elementos){
				strcpy(tablaDeSimbolos[i].nombre,tablaDeSimbolos[j].nombre);
				strcpy(tablaDeSimbolos[i].tipo,tablaDeSimbolos[j].tipo);
				i--;
			}else{
				i=cant_elementos;
			}

		}
	}
}

/* Guarda la tabla generada en un txt */
void guardarTabla(){

	// Verifico si se cargo algo en la tabla
	if(cantidadTokens == -1)
	yyerror();

	FILE* arch = fopen("ts.txt", "w+");
	if(!arch){
		printf("No pude crear el archivo ts.txt\n");
		return;
	}

	fprintf(arch,"%-30s%-20s%-30s%-5s\n","NOMBRE","TIPO","VALOR", "LONGITUD");
	fprintf(arch, "======================================================================================================\n");
	//lo mismo que guarda en archivo lo imprimo en pantalla
	//printf("%-30s%-20s%-30s%-5s\n","NOMBRE","TIPO","VALOR", "LONGITUD");
	//printf("======================================================================================================\n");
	// Recorro la tabla
	int i = 0;
	while (i < cant_ctes) {

		fprintf(arch, "%-30s%-20s%-30s%-5d\n", &(tablaDeSimbolos[i].nombre), &(tablaDeSimbolos[i].tipo) , &(tablaDeSimbolos[i].valor), tablaDeSimbolos[i].longitud);
		//printf( "%-30s%-20s%-30s%-5d\n", &(tablaDeSimbolos[i].nombre), &(tablaDeSimbolos[i].tipo) , &(tablaDeSimbolos[i].valor), tablaDeSimbolos[i].longitud);
		i++;
	}

	fclose(arch);
}


/* Agregar una constante a la tabla de simbolos */

void agregarConstante(char* nombre,char* tipo) {
	printf("Agregar cte %s: %s .\n\n",nombre, tipo);

	// Formateo la cadena
	int length = strlen(nombre);

	char nombre_nuevo[length];

	strcpy(nombre_nuevo, "_");
	strcat(nombre_nuevo, nombre);

	strcpy(nombre_nuevo + strlen(nombre_nuevo), "\0");

	// Verificamos si ya esta cargada
	if (buscarCte(nombre_nuevo, tipo) == 0) {

		// Agrego nombre a la tabla
		strcpy(tablaDeSimbolos[cant_ctes].nombre, nombre_nuevo);

		// Agrego el tipo (Se utiliza para imprimir tabla)
		strcpy(tablaDeSimbolos[cant_ctes].tipo, tipo);	

		// Agrego valor
		strcpy(tablaDeSimbolos[cant_ctes].valor, nombre_nuevo+1);		// Omito el _

		// Agrego la longitud
		if(strcmp(tipo, CteString)==0){
			tablaDeSimbolos[cant_ctes].longitud = length;
		}
		cant_ctes++;
		printf("AGREGO A LA TABLA: %s\n", nombre_nuevo);
	}
}

int buscarCte(char* nombre, char* tipo){			//return 1 = ya esta, return 0 = no esta , cad1 es nombre a buscar cad2 es el tipo 
	int i = cantidadTokens;
	for( i ; i < cant_ctes ; i++){
		if(strcmp(tablaDeSimbolos[i].nombre, nombre)==0 
				&& strcmp(tablaDeSimbolos[i].tipo,tipo)==0){
			printf("%s DUPLICADA\n\n", tipo);
			return 1;
		}
	}
	return 0;
}

void validarVariableDeclarada(char* nombre){
	int i;
	for(i=0 ; i< cantidadTokens; i++){
		if(strcmp(tablaDeSimbolos[i].nombre,nombre)==0)
		return;

	}
	sprintf(mensajeDeError, "La Variable: %s - No esta declarada.\n", nombre);
	mostrarError(mensajeDeError);	
}

/* Funciones tercetos */ 

// escribe los tercetos en un archivo
void escribe_arch_tercetos()
{
	FILE* arch;
	int i;
	terceto aux;
	arch = fopen("intermedia.txt", "w+");

	for(i = 0; i < indice_terceto; i++)
	{
		aux =  vector_tercetos[i];
		if(strcmp(aux.te1,"_")==0)					// si el primer operando es un guion bajo , grabo como esta
		fprintf(arch, "[%d] (%s,%s,%s)\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );
		else
		{	if(strcmp(aux.te2,"_")==0)					// si el segundo operando es un guion bajo, es un terceto JMP
			fprintf(arch, "[%d] (%s,[%s],%s)\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );
			else
			{
				if(*aux.te1>='a' && *aux.te1<='z')			// si el primer operando es una letra, puede que sea una asignacion o similar, pongo corchetes en el 2do operando
				fprintf(arch, "[%d] (%s,%s,[%s])\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );
				else
				fprintf(arch, "[%d] (%s,[%s],[%s])\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );				// sino, los dos operandos son otros tercetos, pongo corchetes a los dos
			}

		}

	}
	fclose(arch);
}

//Crea el terceto con los indices de los tercetos. Si no existen tiene -1
int  crear_terceto(char* p_ope, char* p_te1, char* p_te2)
{
	terceto res;
	res.nroTerceto = indice_terceto;
	strcpy(res.ope, p_ope);
	strcpy(res.te1, p_te1);
	strcpy(res.te2, p_te2);
	vector_tercetos[indice_terceto] = res;
	indice_terceto++;
	return indice_terceto-1;
}
