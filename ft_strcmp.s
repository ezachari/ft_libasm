section .text

global _ft_strcmp

_ft_strcmp:
        mov rcx, 0
        push r14
        push r15
        mov r14, 0
        mov r15, 0
        loop:
            mov r14b, BYTE[rdi + rcx]
            mov r15b, BYTE[rsi + rcx]
            cmp r14b, 0
            jz return
            cmp r15b, 0
            jz return
            cmp r14b, r15b
            jnz return
            inc rcx
            jmp loop
return:
        sub r14, r15
        mov rax, r14
        pop r14
        pop r15
        ret