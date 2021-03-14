%include "st_io.inc"
section .bss
a resb 3
b resb 3
c resb 3
d resb 3
global _start:
section text
_start:
GETUN [a]
GETUN [b]
GETUN [c]
mov ax, word[b]
add word[a], ax
mov ah, byte[b + 2]
adc byte[a + 2], ah

mov ax, word[c]
sub word[a], ax
mov ah, byte[c + 2]
adc byte[a + 2], ah

dec word[a]
mov ax, word[a]
mov edx, 0
cwd
mov dl, [a + 2]
UNSINT edx
UNSINT eax 
PUTCHAR 0xA
FINISH

