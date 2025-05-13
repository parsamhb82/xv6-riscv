#include "syscall.h"

.globl start
start:
    # تلاش برای exec("/init")
    la a0, init
    la a1, argv
    li a7, SYS_exec
    ecall

    # اگر exec شکست خورد، پیام بده
    li a0, 1                  # fd = 1
    la a1, failed_msg
    li a2, 23
    li a7, SYS_write
    ecall

exit:
    li a7, SYS_exit
    ecall
    jal exit

init:
    .string "/init\0"

failed_msg:
    .string "exec(/init) failed!\n"

.p2align 2
argv:
    .quad init
    .quad 0
