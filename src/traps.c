#include "traps.h"
#include "stdio.h"

/*
    Read a single character from the keyboard. The character is not echoed onto the
console. Its ASCII code is copied into R0. The high eight bits of R0 are cleared.
*/
void trap_getc() {
    /* one char per word (16 bits) */
    uint16_t c = getchar();
    reg[R_RO] = c;
    update_flags(R_RO);
}

/*
    Write a character in R0[7:0] to the console display.
*/
void trap_out() {
    uint16_t* c = reg[R_RO];
    putc((char) *c, stdout);
    fflush(stdout);
}
/*
    Write a string of ASCII characters to the console display. The characters are contained
    in consecutive memory locations, one character per memory location, starting with
    the address specified in R0. 
    Writing terminates with the occurrence of x0000 in a memory location.
*/
void trap_puts() {
    /* one char per word (16 bits) */
    uint16_t* c = memory + reg[R_RO];
    while (*c) {
        putc((char) *c, stdout);
        ++c;
    }
    fflush(stdout);
}
/*
    Print a prompt on the screen and read a single character from the keyboard. The
    character is echoed onto the console monitor, and its ASCII code is copied into R0.
    The high eight bits of R0 are cleared.
*/
void trap_in() {
    printf("Enter a character:");
    char c = getchar();
    putc(c, stdout);
    fflush(stdout);
    reg[R_RO] = (uint16_t) c;
    update_flags(R_RO);
}

/*
    Write a string of ASCII characters to the console. The characters are contained in
    consecutive memory locations, two characters per memory location, starting with the
    address specified in R0. The ASCII code contained in bits [7:0] of a memory location
    is written to the console first. Then the ASCII code contained in bits [15:8] of that
    memory location is written to the console. (A character string consisting of an odd
    number of characters to be written will have x00 in bits [15:8] of the memory
    location containing the last character to be written.) Writing terminates with the
    occurrence of x0000 in a memory location.
*/
void trap_putsp() {
    /* two chars per word (16 bits) */
    uint16_t *c = memory + reg[R_RO];
    while (*c)
    {
        char c1 = (*c) & 0xFF;
        putc(c1, stdout);
        char c2 = (*c) >> 8;
        if (c2) putc(c2, stdout);
        ++c;
    }
    fflush(stdout);
}

/*
    Halt execution and print a message on the console.
*/
void trap_halt() {
    puts("HALT");
    fflush(stdout);
    running = 0;
}