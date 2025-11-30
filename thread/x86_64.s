.section .text
.global save_context
save_context:
    ; rdi already contains the context pointer (first argument)
    mov [rdi], rax       ; Save rax
    mov [rdi+8], rbx     ; Save rbx
    mov [rdi+16], rcx    ; Save rcx
    mov [rdi+24], rdx    ; Save rdx
    mov [rdi+32], rsi    ; Save rsi
    mov [rdi+40], rdi    ; Save rdi (but we need to save original rdi)
    mov [rdi+48], rbp    ; Save rbp
    mov [rdi+56], rsp    ; Save stack pointer
    mov rax, [rsp]       ; Get return address
    mov [rdi+64], rax    ; Save return address
    mov [rdi+72], r8     ; Save r8
    mov [rdi+72], r8     ; Save r8
    mov [rdi+80], r9     ; Save r9
    mov [rdi+88], r10    ; Save r10
    mov [rdi+96], r11    ; Save r11
    mov [rdi+104], r12   ; Save r12
    mov [rdi+112], r13   ; Save r13
    mov [rdi+120], r14   ; Save r14
    mov [rdi+128], r15   ; Save r15
    ret


.global restore_context
restore_context:
    ; rdi contains the context pointer
    mov rax, [rdi]       ; Restore rax
    mov rbx, [rdi+8]     ; Restore rbx
    mov rcx, [rdi+16]    ; Restore rcx
    mov rdx, [rdi+24]    ; Restore rdx
    mov rsi, [rdi+32]    ; Restore rsi
    mov rbp, [rdi+48]    ; Restore rbp
    mov rsp, [rdi+56]    ; Restore stack pointer
    mov r8, [rdi+72]     ; Restore r8
    mov r9, [rdi+80]     ; Restore r9
    mov r10, [rdi+88]    ; Restore r10
    mov r11, [rdi+96]    ; Restore r11
    mov r12, [rdi+104]   ; Restore r12
    mov r13, [rdi+112]   ; Restore r13
    mov r14, [rdi+120]   ; Restore r14
    mov r15, [rdi+128]   ; Restore r15
    push qword [rdi+64]  ; Push return address onto stack
    mov rdi, [rdi+40]    ; Restore rdi last
    ret                  ; Return to saved address
