global main
extern scanf
extern printf

section .data
s_scanf_int          db "%d"
s_printf_int         db "%d", 0xa, 0
s_printf_unsigned_dd db "%u", 0xa, 0
s_printf_string      db "%s", 0xa, 0
s_printf_signed_dq   db "%lld", 0xa, 0
s_printf_unsigned_dq db "%llu", 0xa, 0
s_printf_signed_dw   db "%hd", 0xa, 0
s_printf_unsigned_dw db "%hu", 0xa, 0
s_printf_unsigned_db db "%c", 0xa, 0
s_printf_signed_db   db "%hhd", 0xa, 0
a dd 1234
c dw 65231
d db -5
str1 db 'hello_world'
section .bss
b resd 1

section .text
main:
mov rdi, s_printf_int
mov esi, [a]
xor rax, rax
call printf

mov rdi, s_printf_unsigned_dw
mov esi, [c]
xor rax, rax
call printf

mov rdi, s_printf_signed_db
mov esi, [d]
xor rax, rax
call printf

mov rdi, s_printf_string
mov esi, str1
xor rax, rax
call printf

;mov rdi, s_scanf_int; сканф не работает, выдает seg fault
;mov esi, b
;xor rax, rax
;call scanf

mov eax, 1
mov ebx, 0
int 0x80