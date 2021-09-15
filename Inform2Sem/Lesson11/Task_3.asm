%include "st_io.inc"
global _start
section .text
_start:
mov cl, 8
GETUN eax
rol ax, 8
UNSINT eax
FINISH