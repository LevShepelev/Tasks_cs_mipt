%include "st_io.inc"
global _start
section .data
a dd 0
b dd 0
section .text

Sum:
pushad
add eax, ebx
SIGNINT eax
PUTCHAR 0xA
popad
ret

_start:
GETSIG [a]
GETSIG [b]
mov eax, [a]
mov ebx, [b]
call Sum
call Sub

FINISH

Sub:
pushad
sub eax, ebx
SIGNINT eax
PUTCHAR 0xA
popad
ret