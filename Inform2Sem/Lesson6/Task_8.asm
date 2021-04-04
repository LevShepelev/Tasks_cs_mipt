%include "st_io.inc"
global _start
section .text
_start:
mov ecx, 0
GETUN eax
GETUN ebx
mul ebx
mov dword[ans], eax
mov dword[ans + 4], edx
mov ebx, 10
L1:
div ebx
add edx, '0'
mov [s + ecx], dl
inc ecx
mov edx, 0
cmp eax, 0
ja L1
L2:
PUTCHAR byte[s + ecx]
dec ecx
cmp ecx, 0
ja L2
PUTCHAR byte[s]
PUTCHAR 0xA
FINISH
section .bss
ans resq 1
s resb 20