	.file	"bubble.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	xor	edi, edi
	mov	r8d, 8
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	sub	rsp, 48
	.cfi_def_cfa_offset 80
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR 40[rsp], rax
	xor	eax, eax
	lea	r9, 28[rsp]
	movabs	rax, 17179869182
	mov	QWORD PTR [rsp], rax
	movabs	rax, 4294967300
	mov	QWORD PTR 8[rsp], rax
	movabs	rax, 21474836477
	mov	QWORD PTR 16[rsp], rax
	movabs	rax, 4294967301
	mov	QWORD PTR 24[rsp], rax
	movabs	rax, 21474836447
	mov	QWORD PTR 32[rsp], rax
	cmp	edi, 8
	ja	.L17
	.p2align 4,,10
	.p2align 3
.L7:
	mov	edx, r8d
	mov	rsi, r9
	lea	rax, 32[rsp]
	sub	edx, edi
	sal	rdx, 2
	sub	rsi, rdx
	.p2align 4,,10
	.p2align 3
.L4:
	mov	edx, DWORD PTR 4[rax]
	mov	ecx, DWORD PTR [rax]
	cmp	edx, ecx
	jge	.L3
	mov	DWORD PTR 4[rax], ecx
	mov	DWORD PTR [rax], edx
.L3:
	sub	rax, 4
	cmp	rax, rsi
	jne	.L4
.L5:
	add	edi, 1
	cmp	edi, 8
	jbe	.L7
.L17:
	cmp	edi, 9
	jne	.L5
	mov	rbx, rsp
	lea	r12, 40[rsp]
	lea	rbp, .LC0[rip]
	.p2align 4,,10
	.p2align 3
.L9:
	mov	edx, DWORD PTR [rbx]
	mov	rsi, rbp
	mov	edi, 1
	xor	eax, eax
	add	rbx, 4
	call	__printf_chk@PLT
	cmp	r12, rbx
	jne	.L9
	mov	rax, QWORD PTR 40[rsp]
	xor	rax, QWORD PTR fs:40
	jne	.L18
	add	rsp, 48
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xor	eax, eax
	pop	rbx
	.cfi_def_cfa_offset 24
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
