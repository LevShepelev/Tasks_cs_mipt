%include "st_io.inc"
global _start
section .text
_start:
mov si, 20
GETUN eax; вводим сколько символов пропускать
cmp si, ax
ja L4
PRINT "ERROR: k >= 20"
FINISH
L4:
mov edx, eax; индекс массива
sub si, ax
mov cx, si; счетчик
mov ebx, 0; сумма отрицательных
L1:
mov eax, 0
cmp [a + 2 * edx], ax
jl L2
inc edx
cmp ecx, 1
je L3
loop L1
L2:
add bx, [a + 2 * edx]
inc edx
dec cx
cmp cx, ax
je L3
jmp L1
L3:
mov ax, bx
cwde
SIGNINT eax
PUTCHAR 0xA
FINISH
section .data
a dw -2, -1, 0, 0, 0, 0, 23, 0, 0, 0, -34, 0, 243, 0, 0, 0, 0, 0, -23, 23