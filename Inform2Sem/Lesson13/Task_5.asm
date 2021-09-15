%include "st_io.inc"
global _start
section .data
array dd 1, 4, 7, -2, 3, 2, -8, 5
size dd 8
section .text

_start:
mov eax, array
mov ebx, [size]
call Searching_min
FINISH

Searching_min:
mov ecx, 0; min
mov edx, 0; индекс
L2:
cmp [eax + 4 * edx], ecx
jg L1
mov ecx, [eax + 4 * edx]
L1:
inc edx
cmp edx, ebx
jl L2
SIGNINT ecx
PUTCHAR 0xA
ret