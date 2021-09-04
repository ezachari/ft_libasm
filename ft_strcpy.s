section .text

global _ft_strcpy

_ft_strcpy:
        cmp rsi, 0
        jz null
        mov rcx, 0
        loop:
            mov dl, [rsi + rcx]
            mov BYTE[rdi + rcx], dl
            cmp BYTE[rsi + rcx], 0
            jz return
            inc rcx
            jmp loop
null:
        mov rax, rdi
        ret
return:
        mov BYTE[rax + rcx], 0
        mov rax, rdi
        ret