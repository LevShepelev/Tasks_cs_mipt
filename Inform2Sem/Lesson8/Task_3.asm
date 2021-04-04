%include "st_io.inc"
global _start
section .text
_start:

mov ebx, 0
mov ecx, 0
mov edx, 0; min
mov eax, 0; max
L4:
mov al, [ext]
cmp [A + ebx + ecx], al
jl L2
mov al, [A + ebx + ecx]; Максимум храниться в [ext]
mov [ext], al
mov [exti], bl
mov [extj], cl
jmp L3

L2:
mov al, [ext + 1]
cmp [A + ebx + ecx], al
jl L1
jmp L3

L1:
mov al, [A + ebx + ecx]; Минимум храниться в [ext + 1]
mov [ext + 1], al
mov [exti + 1], bl
mov [extj + 1], cl

L3:
inc ebx
cmp ebx, 3
jb L4
add ecx, 3
mov ebx, 0
cmp ecx, 12
jb L4

PRINT "MAX: "
mov al, [ext]
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
mov eax, 0
mov al, [exti]
UNSINT eax
PUTCHAR 0xA
mov eax, 0
mov al, [extj]
mov cl, 3
div cl
mov ecx, 0
mov cl, al
UNSINT ecx
PUTCHAR 0xA

PRINT "MIN: "
mov al, [ext + 1]
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
mov eax, 0
mov al, [exti + 1]
UNSINT eax
PUTCHAR 0xA
mov eax, 0
mov al, [extj + 1]
mov cl, 3
div cl
mov ecx, 0
mov cl, al
UNSINT ecx
PUTCHAR 0xA


FINISH


section .data
A db 2, -3, 4, 5, 2, 4, 5, 7, 2, -2, 3, 1; 4x3
ext db 0, 0
section bss
section .bss
exti resb 2
extj resb 2