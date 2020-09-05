//
// Created by Sydney Anne on 25/11/2019.
//

#ifndef CAMELLIA_IO_H
#define CAMELLIA_IO_H

#include "stdint.h"

extern void outb(uint16_t port, uint8_t val);
extern uint8_t inb(uint16_t port);

#endif //CAMELLIA_IO_H
