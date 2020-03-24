.global lab1
.syntax unified
#define A #4
#define B #3
#define C #2
lab1:
    push {r0, r1, r2, r3, r4, lr}
    //Set A, B, C to registers 2-4
    mov r2, A
    mov r3, B
    mov r4, C
    // multiplication A*B
    mul r0, r2, r3
    // comparison A*B>=10
    cmp r0, #10
    // if True: r2 (A) | r3 (B)
    ITE GE
    orrGE r1, r2, r3
    //Else: r2(A) & r3(B)
    andLT r1, r2, r3
    //Result: r1 * r4 (C)
    mul r1, r4
    pop { r0, r1, r2,r3, r4, pc }

