%include "st_io.inc"
global _start
section text
_start:
GETCHAR
GETUN [unsign_number]
GETSIG [sign_number]
PUTCHAR al
UNSINT [unsign_number]
SIGNINT [sign_number]
PUTCHAR 0xA
FINISH
section .bss
symb resb 1
unsign_number resd 1
sign_number resd 1