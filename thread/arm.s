section .text

.global save_context
save_context:
    stmfd sp!, {r0-r12, lr}  ; Save r0 to r12 and lr to stack
    mov r1, sp               ; Save stack pointer to context
    str r1, [r0]             ; Store the saved stack pointer to context
    bx lr                    ; Return from subroutine


.global restore_context
restore_context:
    ldr r1, [r0]             ; Load the saved stack pointer
    mov sp, r1               ; Restore stack pointer
    ldmfd sp!, {r0-r12, lr}  ; Restore r0 to r12 and lr from stack
    bx lr                    ; Return from subroutine