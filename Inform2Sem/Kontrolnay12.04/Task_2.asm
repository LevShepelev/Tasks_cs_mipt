%include "st_io.inc"
global _start
section .text
_start:
GETSIG eax
GETSIG ebx
imul eax
mov ecx, eax
mov eax, ebx
imul eax
add eax, ecx
cmp eax, 4
jb L1
PRINT "point doesnt belong to circle"
PUTCHAR 0xA
FINISH
L1:
PRINT "point belong to circle"
PUTCHAR 0xA
FINISH