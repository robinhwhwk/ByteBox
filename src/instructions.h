#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

void instruction_add(uint16_t [], uint16_t);
void instruction_and(uint16_t[], uint16_t);
void instruction_not(uint16_t[], uint16_t);
void instruction_br(uint16_t[], uint16_t);
void instruction_jmp(uint16_t[], uint16_t);
void instruction_jsr(uint16_t[], uint16_t);
void instruction_ld(uint16_t[], uint16_t);
void instruction_ldi(uint16_t[], uint16_t);
void instruction_ldr(uint16_t[], uint16_t);
void instruction_lea(uint16_t[], uint16_t);
void instruction_st(uint16_t[], uint16_t);
void instruction_sti(uint16_t[], uint16_t);
void instruction_str(uint16_t[], uint16_t);
void instruction_trap(uint16_t[], uint16_t);
void instruction_res(uint16_t[], uint16_t);
void instruction_rti(uint16_t[], uint16_t);

#endif