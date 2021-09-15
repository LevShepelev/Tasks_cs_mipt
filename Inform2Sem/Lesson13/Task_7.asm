%include "st_io.inc"
global _start
_start:
mov eax, 1
mov ecx, 1
GETUN esi; which Factorial do you want to get ?
call Factorial
UNSINT eax
PUTCHAR 0xA
FINISH

Factorial:
mul ecx
inc ecx
cmp ecx, esi
jbe Factorial
ret