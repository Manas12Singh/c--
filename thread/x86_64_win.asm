section .text
global save_context
global restore_context

save_context:
    ; rdi/rcx contains the context pointer (Windows calling convention uses rcx)
    mov [rcx], rax       ; Save rax
    mov [rcx+8], rbx     ; Save rbx
    mov [rcx+16], rdx    ; Save rdx (note: rcx is first param, rdx is second)
    mov [rcx+24], rsi    ; Save rsi
    mov [rcx+32], rdi    ; Save rdi
    mov [rcx+40], rbp    ; Save rbp
    mov [rcx+48], rsp    ; Save stack pointer
    mov rax, [rsp]       ; Get return address
    mov [rcx+56], rax    ; Save return address
    mov [rcx+64], r8     ; Save r8
    mov [rcx+72], r9     ; Save r9
    mov [rcx+80], r10    ; Save r10
    mov [rcx+88], r11    ; Save r11
    mov [rcx+96], r12    ; Save r12
    mov [rcx+104], r13   ; Save r13
    mov [rcx+112], r14   ; Save r14
    mov [rcx+120], r15   ; Save r15
    ret

restore_context:
    ; rcx contains the context pointer
    mov rax, [rcx]       ; Restore rax
    mov rbx, [rcx+8]     ; Restore rbx
    mov rdx, [rcx+16]    ; Restore rdx
    mov rsi, [rcx+24]    ; Restore rsi
    mov rdi, [rcx+32]    ; Restore rdi
    mov rbp, [rcx+40]    ; Restore rbp
    mov rsp, [rcx+48]    ; Restore stack pointer
    mov r8, [rcx+64]     ; Restore r8
    mov r9, [rcx+72]     ; Restore r9
    mov r10, [rcx+80]    ; Restore r10
    mov r11, [rcx+88]    ; Restore r11
    mov r12, [rcx+96]    ; Restore r12
    mov r13, [rcx+104]   ; Restore r13
    mov r14, [rcx+112]   ; Restore r14
    mov r15, [rcx+120]   ; Restore r15
    push qword [rcx+56]  ; Push return address onto stack
    mov rcx, [rcx+0]     ; This is problematic - we need to save rcx differently
    ret                  ; Return to saved address
