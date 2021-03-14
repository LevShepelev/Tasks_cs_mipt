%include "st_io.inc"
global _start:
section .data
x db 2
a db 7
section .bss
y resb 1
section .text
_start:
mov al, [x]
imul byte[x]
mov bl, al
mov dl, 10
imul dl
add al, 5
mov [y], al
mov al, bl 
imul byte[x]
neg al 
sub al, [y]
cbw
idiv byte[a]
mov bl, ah 
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
mov al, bl
cbw
cwde
SIGNINT eax
PUTCHAR 0xA
FINISH