//
// Created by Lotte Erickson on 25/11/2019.
//

#include <config.h>
#ifdef SERIAL_ENABLED

#ifndef CAMELLIA_SERIAL_H
#define CAMELLIA_SERIAL_H

extern void serial_write_str(const char* str);
extern void serial_init();

#endif //CAMELLIA_SERIAL_H

#endif