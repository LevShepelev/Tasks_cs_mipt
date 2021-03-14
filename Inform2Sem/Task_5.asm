%include "st_io.inc"
global _start
section text
_start:
mov ecx, 3*(5684/4 + 357/3 + 245/5)
UNSINT ecx
PUTCHAR 0xA
FINISH