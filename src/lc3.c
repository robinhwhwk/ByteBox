#include "lc3.h"
#include "input_buffering.h"
#include "instructions.h"

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        /* show usage string */
        printf("lc3 [vm-image-file1] ...\n");
        exit(2);
    }
    for (int i = 1; i < argc; ++i) {
        if (!read_image(argv[i])) {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }

    signal(SIGINT, handle_interrupt);
    disable_input_buffering();

    /* Set the condition flag to Zero */
    reg[R_COND] = FL_ZRO;

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    running = 1;
    while (running) {
        /* fetch next instruction */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12; /* opcode is the first 4 bits of instruction */

        switch (op)
        {
            case OP_ADD:
                instruction_add(reg, instr);
                break;
            case OP_AND:
                instruction_and(reg, instr);
                break;
            case OP_NOT:
                instruction_not(reg, instr);
                break;
            case OP_BR:
                instruction_br(reg, instr);
                break;
            case OP_JMP:
                instruction_jmp(reg, instr);
                break;
            case OP_JSR:
                instruction_jsr(reg, instr);
                break;
            case OP_LD:
                instruction_ld(reg, instr);
                break;
            case OP_LDI:
                instruction_ldi(reg, instr);
                break;
            case OP_LDR:
                instruction_ldr(reg, instr);
                break;
            case OP_LEA:
                instruction_lea(reg, instr);
                break;
            case OP_ST:
                instruction_st(reg, instr);
                break;
            case OP_STI:
                instruction_sti(reg, instr);
                break;
            case OP_STR:
                instruction_str(reg, instr);
                break;
            case OP_TRAP:
                instruction_trap(reg, instr);
                break;
            case OP_RES:
            case OP_RTI:
            default:
                /* Bad Opcode */
                break;
        }

    }
}

uint16_t sign_extend(uint16_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1) {
        x |= (0xFFFF << bit_count);
    }
    return x;
}

void update_flags(uint16_t r)
{
    if (reg[r] == 0)
    {
        reg[R_COND] = FL_ZRO;
    }
    else if (reg[r] >> 15) /* a 1 in the left-most bit indicates negative */
    {
        reg[R_COND] = FL_NEG;
    }
    else
    {
        reg[R_COND] = FL_POS;
    }
}   