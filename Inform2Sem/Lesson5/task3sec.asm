%include "st_io.inc"
global _start
section bss
a resb 3
b resb 3
c resb 3
d resd 1
section .text
_start:
GETUN [d]
mov al, byte[d]
mov [a], al
mov al, byte[d + 1]
mov [a + 1], al
mov al, [d + 2]
mov [a + 2], al ; делаем то же самое

mov al, byte[d]
mov [b], al
mov al, byte[d + 1]
mov [b + 1], al
mov al, [d + 2]
mov [b + 2], al

mov al, byte[d]
mov [c], al
mov al, byte[d + 1]
mov [c + 1], al
mov al, [d + 2]
mov [c + 2], al

sub byte[b]
sbb byte[b + 1], 0
sbb byte[b + 2], 0
mov  al, [a]
add [b], al
mov al, [a + 1]
adc [b + 1], al
mov al, [a + 2]
adc [b + 2], al
mov al, [c]
sub [b], al
mov al, [c + 1]
sbb [b + 1], al
mov al, [c + 2]
sbb [b + 2], a
mov al, [b]
mov byte[d], al
mov al, [b + 1]
mov byte[d + 1], al
mov al, [b + 2]
mov byte[d + 2], al
mov byte[d + 3], 0
UNSINT [d]
FINISH
