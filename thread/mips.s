.section .text
.global save_context
save_context:
    sw $sp, 0($a0)          # Save stack pointer
    sw $ra, 4($a0)          # Save return address
    sw $s0, 8($a0)          # Save s0
    sw $s1, 12($a0)         # Save s1
    sw $s2, 16($a0)         # Save s2
    sw $s3, 20($a0)         # Save s3
    sw $s4, 24($a0)         # Save s4
    sw $s5, 28($a0)         # Save s5
    sw $s6, 32($a0)         # Save s6
    sw $s7, 36($a0)         # Save s7
    sw $t0, 40($a0)         # Save t0
    sw $t1, 44($a0)         # Save t1
    sw $t2, 48($a0)         # Save t2
    sw $t3, 52($a0)         # Save t3
    sw $t4, 56($a0)         # Save t4
    sw $t5, 60($a0)         # Save t5
    sw $t6, 64($a0)         # Save t6
    sw $t7, 68($a0)         # Save t7
    sw $t8, 72($a0)         # Save t8
    sw $t9, 76($a0)         # Save t9
    jr $ra                  # Return from subroutine

.global restore_context
restore_context:
    lw $sp, 0($a0)          # Restore stack pointer
    lw $ra, 4($a0)          # Restore return address
    lw $s0, 8($a0)          # Restore s0
    lw $s1, 12($a0)         # Restore s1
    lw $s2, 16($a0)         # Restore s2
    lw $s3, 20($a0)         # Restore s3
    lw $s4, 24($a0)         # Restore s4
    lw $s5, 28($a0)         # Restore s5
    lw $s6, 32($a0)         # Restore s6
    lw $s7, 36($a0)         # Restore s7
    lw $t0, 40($a0)         # Restore t0
    lw $t1, 44($a0)         # Restore t1
    lw $t2, 48($a0)         # Restore t2
    lw $t3, 52($a0)         # Restore t3
    lw $t4, 56($a0)         # Restore t4
    lw $t5, 60($a0)         # Restore t5
    lw $t6, 64($a0)         # Restore t6
    lw $t7, 68($a0)         # Restore t7
    lw $t8, 72($a0)         # Restore t8
    lw $t9, 76($a0)         # Restore t9
    jr $ra                  # Return from subroutine
