global Input_dw
section .bss
a resb 10

section .text
Input_dw:
mov eax, 3; Ввод символа или строчки
mov ebx, 2
mov ecx, a
mov edx, 10
int 0x80
mov esi, 0
mov eax, 0
L1:
sub byte[a + esi], '0'
cmp byte[a + esi], 0
jl end
cmp byte[a + esi], 9
jg end
inc esi
jmp L1


end:
mov edi, 0
mov bx, 0
dec esi

L4:
mov ax, 0 
mov al, [a + esi]
call mul_bx_deg_of_10
add bx, ax
inc edi
dec esi
cmp esi, 0
jge L4
mov ax, bx
ret 

mul_bx_deg_of_10:
mov ecx, 10
mov ebp, 0
L3:
cmp ebp, edi
jae FIN
mul cx
inc ebp
jmp L3
FIN:
ret