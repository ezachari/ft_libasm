section .text

global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
        call _ft_strlen
        inc rax
        push rdi
        mov rdi, rax
        call _malloc
        cmp rax, 0
        jz err
        pop rdi
        mov rsi, rdi
        mov rdi, rax
        call _ft_strcpy
        ret
err:
        pop rdi
        mov rax, 0
        ret