%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
GETUN ebx
and al, 1111b
and bl, 11110000b
or al, bl
UNSINT eax
FINISH