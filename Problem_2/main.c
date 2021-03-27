/*
 * main.c
 *

 */

#include "main.h"






void delay(volatile uint32_t);

int main(void) {

	BSP_init();

    return 0;
}

void delay(volatile uint32_t s) {
    for(; s>0; s--);
}
