#include "delay.h"

void _delay(unsigned long i) {
    volatile unsigned long a = i;
    while (a--);
}
