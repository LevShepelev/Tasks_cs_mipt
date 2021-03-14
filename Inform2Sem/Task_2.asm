  global _start
  section .text
  _start:
  mov eax, 4; Вывод msgt
  mov ebx, 1
  mov ecx, msgt
  mov edx, msgtl
  int 0x80
  mov eax, 3; Ввод символа или строчки
  mov ebx, 2
  mov ecx, a
  mov edx, 10
  int 0x80
  mov eax, 4; Вывод символа или строчки
  mov ebx, 1
  mov ecx, a
  mov edx, 10
  int 0x80
  mov eax, 1; Завершение работы программы
  mov ebx, 0
  int 0x80
  section .data
  msgt db 'MIPT', 0, 0xA
  msgtl equ $-msgt
  section .bss
  a resb 10

