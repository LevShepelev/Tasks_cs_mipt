%include "st_io.inc"
global _start
section .text
_start:
GETUN eax
GETUN ebx
and eax, 11b
and ebx, 11b
cmp eax, ebx
je EQUAL
PRINT "NOT EQUAL"
FINISH
EQUAL:
PRINT "EQUAL"
FINISH