#ifndef BITS_H
#define BITS_H
#include <avr/io.h>

// Definições globais
#define SETBIT(reg, bit, value) value ? (reg|=(1<<bit)):(reg &= ~(1<<bit))
#define READBIT(reg, bit) (reg & (1<<bit))

#endif