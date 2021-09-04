section .text

global _ft_strlen

_ft_strlen:
        mov rcx, 0
        loop:
        cmp BYTE[rdi + rcx], 0
        jz return
        inc rcx
        jmp loop
return:
        mov rax, rcx
        ret