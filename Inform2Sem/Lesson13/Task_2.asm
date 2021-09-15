%include "st_io.inc"
global _start
section .data
a dd 0
b dd 0
c dd 0
section .bss
adr resd 1
section .text

Sum:
mov eax, [a]
add eax, [b]
SIGNINT eax
PUTCHAR 0xA
ret

_start:
GETSIG [a]
GETSIG [b]
call Sum
call Sub
FINISH

Sub:
mov eax, [a]
sub eax, [b]
SIGNINT eax
PUTCHAR 0xA
ret