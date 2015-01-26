	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$0, -4(%rbp)
	callq	_puts
	leaq	L_.str1(%rip), %rdi
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	callq	_puts
	leaq	L_.str2(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_puts
	movl	$0, %ecx
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello world."

L_.str1:                                ## @.str1
	.asciz	"One more time"

L_.str2:                                ## @.str2
	.asciz	"And agaiiiin!"


.subsections_via_symbols
