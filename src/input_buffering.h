#ifndef INPUT_BUFFERING_H
#define INPUT_BUFFERING_H
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>


void disable_input_buffering();

void restore_input_buffering();

void handle_interrupt(int);

uint16_t check_key();

#endif