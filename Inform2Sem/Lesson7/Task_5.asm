%include "st_io.inc"
global _start
section .text
_start:
mov cx, 0
mov ebp, 0; количество отрицательных
mov edx, 0; индекс массива
mov ebx, 0; сумма отрицательных

BEGIN:
cmp [a + 2 * edx], di
jl L2
mov di, [a + 2 * edx]; Максимум храниться в di
jmp Compare

L2:
cmp [a + 2 * edx], si
jng L1
jmp Compare

L1:
mov si, [a + 2 * edx]; Минимум храниться в si

Compare:
cmp [a + 2 * edx], cx 
jnl Pos
jmp Neg

Pos:
inc edx
cmp [a + 2 * edx], cx
jne BEGIN
jmp FIN

Neg:
inc ebp
mov ax, [a + 2 * edx]
cwde
add ebx, eax
inc edx
cmp [a + 2 * edx], cx
jne BEGIN

FIN:
PRINT "Max = "
mov ax, di
cwde
SIGNINT eax
PUTCHAR 0xA
mov ax, si
cwde
PRINT "Min = "
SIGNINT eax
PUTCHAR 0xA
PRINT "Sum_Neg = "
SIGNINT ebx
PUTCHAR 0xA
PRINT "Number of negative = "
SIGNINT ebp
PUTCHAR 0xA
FINISH

section .data
a dw -2, -2, 3, -2, 2, -4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
max dw 0
min dw 0