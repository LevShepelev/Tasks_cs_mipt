%include "st_io.inc"
global _start
section .text
_start:
mov edx, 0
mov ecx, 16
L1:
GETUN ebx
cmp ebx, 2
je FIN
shr ebx, 1
rcl edx, 1
dec ecx
cmp ecx, 0
ja L1
FIN:
UNSINT edx
FINISH