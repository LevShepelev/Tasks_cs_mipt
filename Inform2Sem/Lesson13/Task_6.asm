%include "st_io.inc"
global _start
_start:
mov eax, 0
mov ebx, 1
mov edx, 0
GETUN esi; which Fibonachi number do you want to get
call Fibonachi
UNSINT eax
PUTCHAR 0xA
FINISH

Fibonachi:
mov ecx, ebx
add ebx, eax
mov eax, ecx
inc edx
cmp edx, esi
jb Fibonachi
ret


