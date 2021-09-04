section .text

global _ft_write
extern ___error

_ft_write:
        mov rax, 0x2000004
        syscall
        jc err
        ret
err:
        mov r8, rax
        push rax
        call ___error
        mov [rax], r8
        pop rax
        mov rax, -1
        ret