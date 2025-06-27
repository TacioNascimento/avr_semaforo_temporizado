#ifndef SEMAFORO_H
#define SEMAFORO_H

#define RED 0
#define YELLOW 1
#define GREEN 2
#define RED_PD 3
#define GREEN_PD 4

#define SETLIGHT(reg, bit, value) value ? (reg|= (1<<bit)):(reg&=~(1<<bit))

void semaforoInit(void);
void setLight(unsigned char bit, unsigned char value);

#endif