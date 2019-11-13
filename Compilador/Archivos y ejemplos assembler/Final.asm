include macros2.asm
include number.asm

.MODEL	LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA

	_n1			dd	?
	_n2			dd	?
	T_Ingrese_un_numero			db	"Ingrese un numero",'$', 33 dup (?)
	T_Ingrese_otro_numero			db	"Ingrese otro numero",'$', 31 dup (?)
	T_El_primer_numero_ingresado_es_mayor_al_segundo			db	"El primer numero ingresado es mayor al segundo",'$', 4 dup (?)
	T_El_primer_numero_ingresado_es_menor_al_segundo			db	"El primer numero ingresado es menor al segundo",'$', 4 dup (?)
	T_Los_numeros_son_iguales			db	"Los numeros son iguales",'$', 27 dup (?)
	_aux			db	MAXTEXTSIZE dup (?),'$'
	_msgPRESIONE			db	0DH,0AH,"Presione una tecla para continuar...",'$'
	_NEWLINE			db	0DH,0AH,'$'

.CODE

;************************************************************
; devuelve en BX la cantidad de caracteres que tiene un string
; DS:SI apunta al string.
;
STRLEN PROC
	mov bx,0
STRL01:
	cmp BYTE PTR [SI+BX],'$'
	je STREND
	inc BX
	jmp STRL01
STREND:
	ret
STRLEN ENDP


;*********************************************************************8
; copia DS:SI a ES:DI; busca la cantidad de caracteres
;
COPIAR PROC
	call STRLEN
	cmp bx,MAXTEXTSIZE
	jle COPIARSIZEOK
	mov bx,MAXTEXTSIZE
COPIARSIZEOK:
	mov cx,bx
	cld
	rep movsb
	mov al,'$'
	mov BYTE PTR [DI],al
	ret
COPIAR ENDP


;*******************************************************
; concatena DS:SI al final de ES:DI.
;
; busco el size del primer string
; sumo el size del segundo string
; si la suma excede MAXTEXTSIZE, copio solamente MAXTEXTSIZE caracteres
; si la suma NO excede MAXTEXTSIZE, copio el total de caracteres que tiene el segundo string
;
CONCAT PROC
	push ds
	push si
	call STRLEN
	mov dx,bx
	mov si,di
	push es
	pop ds
	call STRLEN
	add di,bx
	add bx,dx
	cmp bx,MAXTEXTSIZE
	jg CONCATSIZEMAL
CONCATSIZEOK:
	mov cx,dx
	jmp CONCATSIGO
CONCATSIZEMAL:
	sub bx,MAXTEXTSIZE
	sub dx,bx
	mov cx,dx
CONCATSIGO:
	push ds
	pop es
	pop si
	pop ds
	cld
	rep movsb
	mov al,'$'
	mov BYTE PTR [DI],al
	ret
CONCAT ENDP


START:
	mov AX,@DATA
	mov DS,AX
	mov es,ax
	mov dx,OFFSET T_Ingrese_un_numero
	mov ah,9
	int 21h
	newLine 1
	GetFloat _n1
	mov dx,OFFSET T_Ingrese_otro_numero
	mov ah,9
	int 21h
	newLine 1
	GetFloat _n2
	fld _n1
	fld _n2
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf
	JBE ET_12
	mov dx,OFFSET T_El_primer_numero_ingresado_es_mayor_al_segundo
	mov ah,9
	int 21h
	newLine 1
	JMP ET_18
ET_12:
	fld _n1
	fld _n2
	fxch
	fcomp
	fstsw ax
	ffree st(0)
	sahf
	JAE ET_22
	mov dx,OFFSET T_El_primer_numero_ingresado_es_menor_al_segundo
	mov ah,9
	int 21h
	newLine 1
	JMP ET_28
ET_22:
	mov dx,OFFSET T_Los_numeros_son_iguales
	mov ah,9
	int 21h
	newLine 1
ET_28:
ET_18:
	mov dx,OFFSET _NEWLINE
	mov ah,09
	int 21h
	mov dx,OFFSET _msgPRESIONE
	mov ah,09
	int 21h
	mov ah, 1
	int 21h
	mov ax, 4C00h
	int 21h
END START
