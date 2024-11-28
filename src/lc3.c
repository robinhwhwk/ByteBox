#include "lc3.h"
#include "input_buffering.h"

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

    int running = 1;
    while (running) {
        /* fetch next instruction */
        uint16_t instr = mem_read(reg[R_PC]++);

    }
}