	.text
	.globl asma
	.globl _asma
_asma:
asma:
	enter 	$0, $0

	# Move count to cl register
	mov		%dl, %cl

	# Initialize buffer register
	movq	$0, %r11

	# Load source number
	and 	$127, %cl 

	movq	(%rdi), %r8
	movq	8(%rdi), %r9

	cmp 	$64, %cl
	jb		.rotate

	movq	%r9, %r8
	movq	(%rdi), %r9

.rotate:
	and 	$63, %cl 
	# Perform rotation
	shldq	%cl, %r9, %r11
	shldq	%cl, %r8, %r9
	rorq	%cl, %r11
	shldq	%cl, %r11, %r8
	
	# Write result
	movq	%r8, (%rsi)
	movq	%r9, 8(%rsi)
	leave 
	ret
