	.text
	.globl asmb
	.globl _asmb
_asmb:
asmb:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    # rsp: Byte shift count
    # rsp+8: Bit shift count
    movq    %rdx, (%rsp)
    shrq    $6, (%rsp)

    movq    %rdx, %r8
    andq    $63, %r8
    movq    %r8, 8(%rsp)

    # Save array length in rax
    movq    %rcx, %rax

    movq    $0, %r8 

.shift_64:
    # Load target address into r11
    movq    (%rsp), %r11
    add     %r8, %r11

    # Overflow check 
    mov     %rcx, %r9
    sub     $1, %r9
    and     %r9, %r11

    # Multiply by field size (8bit = 2^3)
    shlq    $3, %r11
    addq    %rsi, %r11


    # Read source and write to target
    movq    (%rdi, %r8, 8), %r10
    movq    %r10, (%r11)

    add     $1, %r8
    cmpq    %r8, %rax
    jne     .shift_64

    
    # Init counter reg
    movq    $0, %r8 
    # Init shift buffer 
    movq    $0, %r11
    # Save shift count in cl
    mov     8(%rsp), %cl
    cmp     $0, %cl
    je      .done
    
.shift_bit:
    # Shift bits out into temporary buffer (r10)
    movq    (%rsi, %r8, 8), %rdx
    shldq   %cl, %rdx, %r10
    # Shift bits into target from shift buffer
    shldq	%cl, %r11, %rdx
    movq    %rdx, (%rsi, %r8, 8)
    # Move contant of temporary buffer into shift buffer
    movq    %r10, %r11
    rorq	%cl, %r11

    add     $1, %r8
    cmpq    %r8, %rax
    jne     .shift_bit

    # Finally shift buffer into first array field
    movq    $0, %r10
    shldq   %cl, %r11, %r10
    orq 	%r10, (%rsi)

.done: 

    leave
    ret
