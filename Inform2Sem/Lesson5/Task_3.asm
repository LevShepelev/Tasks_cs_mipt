%include "st_io.inc"
section .bss
a resb 3
b resb 3
c resb 3
d resb 3
buf resb 4
global _start:
section text
_start:
GETUN eax
mov [buf], eax
mov bx, [buf]
mov word [a], bx
mov bl, [buf + 2]
mov byte [a + 2], bl

GETUN eax
mov [buf], eax
mov bx, [buf]
mov word [b], bx
mov bl, [buf + 2]
mov byte [b + 2], bl

GETUN eax
mov [buf], eax
mov bx, [buf]
mov word [c], bx
mov bl, [buf + 2]
mov byte [c + 2], bl

sub byte[b], 1
sbb byte[b+1], 0
sbb byte[b+2], 0

mov al, [a]
add [b], al
mov al, [a+1]
adc [b+1], al
mov al, [a+2]
adc [b+2], al

mov al, [c]
sub [b], al
mov al, [c+1]
sbb [b+1], al
mov al, [c+2]
sbb [b+2], al

mov al, [b]
mov byte[d], al
mov al, [b+1]
mov byte[d+1], al
mov al, [b+2]
mov byte[d+2], al
mov byte[d+3], 0
UNSINT [d]
FINISH

