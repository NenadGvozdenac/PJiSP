	.file	"obimKvadrata.c"
	.text
	.globl	_povrsinaKvadrata
	.def	_povrsinaKvadrata;	.scl	2;	.type	32;	.endef
_povrsinaKvadrata:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	flds	8(%ebp)
	fmuls	8(%ebp)
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "Unesite duzinu stranice kvadrata -> \0"
LC3:
	.ascii "%lf\0"
	.align 4
LC5:
	.ascii "Stranica kvadrata je nevazeca.\0"
LC6:
	.ascii "Povrsina kvadrata je : \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	fldz
	fstps	28(%esp)
	movl	$LC2, (%esp)
	call	_printf
	flds	28(%esp)
	fstpl	4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	fldz
	flds	28(%esp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	ja	L4
	flds	28(%esp)
	flds	LC4
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jbe	L8
L4:
	movl	$LC5, (%esp)
	call	_printf
	movl	$0, %eax
	jmp	L7
L8:
	flds	28(%esp)
	fstps	(%esp)
	call	_povrsinaKvadrata
	fstpl	4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$1, %eax
L7:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
	.align 4
LC4:
	.long	1120403456
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
