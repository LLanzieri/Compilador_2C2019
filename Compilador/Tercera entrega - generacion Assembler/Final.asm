include macros2.asm 
include number.asm 
.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE EQU 32

.DATA
NEW_LINE DB 0AH,0DH,'$'
CWprevio DW ?
@msj_entero db "Ingrese un valor entero:", '$'
@msj_real db "Ingrese un valor real:", '$'
abbaa dd ?
berta dd ?
b dd ?
var1 dd ?
a dd ?
c dd ?
d dd ?
e dd ?
cont dd ?
pepp dd ?
estoesunid dd ?
q dd ?
x dd ?
valorentero dd ?
_50 dd 50.0
_4 dd 4.0
_2 dd 2.0
@aux4 dd ?
_27_123456789 dd 27.123456789
_Hola12 db "Hola12", '$'
_valor_cont db "valor_cont", '$'
_1 dd 1.0
_3 dd 3.0
_0 dd 0.0
@Filter1 dd ?
_FIN_FILTER_1 db "FIN_FILTER_1", '$'
_5 dd 5.0
@aux39 dd ?
@aux40 dd ?
@aux45 dd ?
@aux47 dd ?
_1_3323 dd 1.3323
_3_4555 dd 3.4555
_7_115 dd 7.115
_3_0 dd 3.0
_7_11 dd 7.11
@Filter2 dd ?
_FIN_FILTER_2 db "FIN_FILTER_2", '$'
@Filter3 dd ?
_valor_berta db "valor_berta", '$'
_FIN_FILTER_3 db "FIN_FILTER_3", '$'
_3_3 dd 3.3
@Filter4 dd ?
_FIN_FILTER_4 db "FIN_FILTER_4", '$'
@aux143 dd ?
_valor_a db "valor_a", '$'
_10 dd 10.0
_REPEAT_AND db "REPEAT_AND", '$'
@aux156 dd ?
_REPEAT_OR db "REPEAT_OR", '$'
@aux174 dd ?
_valor_a_Repeat db "valor_a_Repeat", '$'
_valor_c db "valor_c", '$'
_REPEAT_en_IF db "REPEAT_en_IF", '$'
@aux199 dd ?
_valor_en_if_repeat db "valor_en_if_repeat", '$'
_hola db "hola", '$'
_chau db "chau", '$'
_20 dd 20.0
_CONDICION_AND db "CONDICION_AND", '$'
_100 dd 100.0
_200 dd 200.0
_300 dd 300.0
_valor_q db "valor_q", '$'
_valor_d db "valor_d", '$'
_10_87 dd 10.87
_20_9 dd 20.9
_CONDICION_OR_VERDADERA db "CONDICION_OR_VERDADERA", '$'
_101 dd 101.0
_20_1 dd 20.1
_IF_ELSE_AND_V db "IF_ELSE_AND_V", '$'
_IF_ELSE_AND_F db "IF_ELSE_AND_F", '$'
_102 dd 102.0
_20_2 dd 20.2
_IF_ELSE_OR_V db "IF_ELSE_OR_V", '$'
_IF_ELSE_OR_F db "IF_ELSE_OR_F", '$'
@aux282 dd ?
@Filter5 dd ?
_FIN_FILTER_ADENTRO_IF_ELSE db "FIN_FILTER_ADENTRO_IF_ELSE", '$'
_FIN db "FIN", '$'

.CODE

START:

MOV AX,@DATA
MOV DS, AX
FINIT

fld _50
fstp q
fld _4
fld _2
fadd
fstp @aux4
fld @aux4
fstp c
fld _27_123456789
fstp cont
LEA EAX, _Hola12
 MOV pepp , EAX
DisplayString _valor_cont,1
newLine

DisplayFloat cont,3
newLine

fld _1
fstp var1
fld _3
fstp c
fld _4
fstp d
fld var1
fld _3
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_23

fld var1
fstp @Filter1
JMP etiqueta_32

etiqueta_23:
fld c
fld _3
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_27

fld c
fstp @Filter1
JMP etiqueta_32

etiqueta_27:
fld d
fld _3
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_31

fld d
fstp @Filter1
JMP etiqueta_32

etiqueta_31:
fld _0
fstp @Filter1
etiqueta_32:
fld @Filter1
fstp abbaa
DisplayFloat abbaa,1
newLine

DisplayString _FIN_FILTER_1,1
newLine

fld _5
fld _3
fmul
fstp @aux39
fld _4
fld @aux39
fadd
fstp @aux40
fld @aux40
fstp a
DisplayFloat a,1
newLine

fld a
fld _1
fsub
fstp @aux45
fld @aux45
fld _3
fdiv
fstp @aux47
fld @aux47
fstp estoesunid
DisplayFloat estoesunid,1
newLine

fld _1_3323
fstp e
fld _3_4555
fstp b
fld _7_115
fstp cont
fld e
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_64

fld e
fld _7_11
fxch
fcomp
fstsw ax
sahf
JA etiqueta_64

fld e
fstp @Filter2
JMP etiqueta_77

etiqueta_64:
fld b
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_70

fld b
fld _7_11
fxch
fcomp
fstsw ax
sahf
JA etiqueta_70

fld b
fstp @Filter2
JMP etiqueta_77

etiqueta_70:
fld cont
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_76

fld cont
fld _7_11
fxch
fcomp
fstsw ax
sahf
JA etiqueta_76

fld cont
fstp @Filter2
JMP etiqueta_77

etiqueta_76:
fld _0
fstp @Filter2
etiqueta_77:
fld @Filter2
fstp berta
DisplayFloat berta,3
newLine

DisplayString _FIN_FILTER_2,1
newLine

fld _1_3323
fstp e
fld _3_4555
fstp b
fld _7_115
fstp cont
fld e
fld _1_3323
fxch
fcomp
fstsw ax
sahf
JE etiqueta_92

fld e
fstp @Filter3
JMP etiqueta_101

etiqueta_92:
fld cont
fld _1_3323
fxch
fcomp
fstsw ax
sahf
JE etiqueta_96

fld cont
fstp @Filter3
JMP etiqueta_101

etiqueta_96:
fld b
fld _1_3323
fxch
fcomp
fstsw ax
sahf
JE etiqueta_100

fld b
fstp @Filter3
JMP etiqueta_101

etiqueta_100:
fld _0
fstp @Filter3
etiqueta_101:
fld @Filter3
fstp berta
DisplayString _valor_berta,1
newLine

DisplayFloat berta,3
newLine

DisplayString _FIN_FILTER_3,1
newLine

fld _1_3323
fstp e
fld _3_4555
fstp b
fld _7_115
fstp cont
fld e
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_120

fld e
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_120

fld e
fstp @Filter4
JMP etiqueta_133

etiqueta_120:
fld b
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_126

fld b
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_126

fld b
fstp @Filter4
JMP etiqueta_133

etiqueta_126:
fld cont
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_132

fld cont
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_132

fld cont
fstp @Filter4
JMP etiqueta_133

etiqueta_132:
fld _0
fstp @Filter4
etiqueta_133:
fld @Filter4
fstp berta
DisplayFloat berta,3
newLine

DisplayString _FIN_FILTER_4,1
newLine

fld _5
fstp a
fld _1
fstp estoesunid
etiqueta_141:
fld a
fld _1
fadd
fstp @aux143
fld @aux143
fstp a
DisplayString _valor_a,1
newLine

DisplayFloat a,1
newLine

fld a
fld _10
fxch
fcomp
fstsw ax
sahf
JNE etiqueta_141

fld _5
fstp a
DisplayString _REPEAT_AND,1
newLine

etiqueta_154:
fld a
fld _1
fadd
fstp @aux156
fld @aux156
fstp a
DisplayString _valor_a,1
newLine

DisplayFloat a,1
newLine

fld a
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_169

fld estoesunid
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_169

JMP etiqueta_154

etiqueta_169:
fld _5
fstp a
DisplayString _REPEAT_OR,1
newLine

etiqueta_172:
fld a
fld _1
fadd
fstp @aux174
fld @aux174
fstp a
DisplayString _valor_a_Repeat,1
newLine

DisplayFloat a,1
newLine

fld a
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_183

JMP etiqueta_172

etiqueta_183:
fld estoesunid
fld _10
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_188

JMP etiqueta_172

etiqueta_188:
fld c
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_213

DisplayString _valor_c,1
newLine

DisplayFloat c,1
newLine

fld _5
fstp a
DisplayString _REPEAT_en_IF,1
newLine

etiqueta_197:
fld a
fld _1
fadd
fstp @aux199
fld @aux199
fstp a
DisplayString _valor_en_if_repeat,1
newLine

DisplayFloat a,1
newLine

fld a
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_208

JMP etiqueta_197

etiqueta_208:
fld estoesunid
fld _10
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_213

JMP etiqueta_197

etiqueta_213:
fld c
fld _10
fxch
fcomp
fstsw ax
sahf
JA etiqueta_219

DisplayString _hola,1
newLine

JMP etiqueta_220

etiqueta_219:
DisplayString _chau,1
newLine

etiqueta_220:
fld c
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_229

fld q
fld _20
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_229

DisplayString _CONDICION_AND,1
newLine

etiqueta_229:
fld _100
fstp q
fld _200
fstp c
fld _300
fstp d
DisplayString _valor_q,1
newLine

DisplayFloat q,1
newLine

DisplayString _valor_c,1
newLine

DisplayFloat c,1
newLine

DisplayString _valor_d,1
newLine

DisplayFloat d,1
newLine

fld cont
fld _10_87
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_243

JMP etiqueta_247

etiqueta_243:
fld e
fld _20_9
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_248

etiqueta_247:
DisplayString _CONDICION_OR_VERDADERA,1
newLine

etiqueta_248:
fld c
fld _101
fxch
fcomp
fstsw ax
sahf
JA etiqueta_258

fld e
fld _20_1
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_258

DisplayString _IF_ELSE_AND_V,1
newLine

JMP etiqueta_259

etiqueta_258:
DisplayString _IF_ELSE_AND_F,1
newLine

etiqueta_259:
fld c
fld _102
fxch
fcomp
fstsw ax
sahf
JA etiqueta_264

JMP etiqueta_268

etiqueta_264:
fld e
fld _20_2
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_270

etiqueta_268:
DisplayString _IF_ELSE_OR_V,1
newLine

JMP etiqueta_271

etiqueta_270:
DisplayString _IF_ELSE_OR_F,1
newLine

etiqueta_271:
fld c
fld _101
fxch
fcomp
fstsw ax
sahf
JA etiqueta_298

fld e
fld _20_1
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_298

DisplayString _REPEAT_en_IF,1
newLine

etiqueta_280:
fld a
fld _1
fadd
fstp @aux282
fld @aux282
fstp a
DisplayString _valor_en_if_repeat,1
newLine

DisplayFloat a,1
newLine

fld a
fld _10
fxch
fcomp
fstsw ax
sahf
JAE etiqueta_291

JMP etiqueta_280

etiqueta_291:
fld estoesunid
fld _10
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_296

JMP etiqueta_280

etiqueta_296:
DisplayString _IF_ELSE_AND_V,1
newLine

JMP etiqueta_329

etiqueta_298:
fld _1_3323
fstp e
fld _3_4555
fstp b
fld _7_115
fstp cont
fld e
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_312

fld e
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_312

fld e
fstp @Filter5
JMP etiqueta_325

etiqueta_312:
fld b
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_318

fld b
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_318

fld b
fstp @Filter5
JMP etiqueta_325

etiqueta_318:
fld cont
fld _3_0
fxch
fcomp
fstsw ax
sahf
JNA etiqueta_324

fld cont
fld _3_3
fxch
fcomp
fstsw ax
sahf
JA etiqueta_324

fld cont
fstp @Filter5
JMP etiqueta_325

etiqueta_324:
fld _0
fstp @Filter5
etiqueta_325:
fld @Filter5
fstp berta
DisplayString _FIN_FILTER_ADENTRO_IF_ELSE,1
newLine

DisplayString _IF_ELSE_AND_F,1
newLine

etiqueta_329:
DisplayString @msj_entero 
int 21h 
newLine 1
GetFloat a 
DisplayFloat a,1
newLine

DisplayString @msj_real 
int 21h 
newLine 1
GetFloat e 
DisplayFloat e,3
newLine

DisplayString _FIN,1
newLine


MOV AH, 1
INT 21h
MOV AX, 4C00h
INT 21h

END START
