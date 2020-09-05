//
// Created by Sydney Anne on 25/11/2019.
//

#include <config.h>
#ifdef VGA_ENABLED

#ifndef KERNELTEST_VGA_H
#define KERNELTEST_VGA_H

extern void vga_initialize(void);
extern void vga_write_str(const char* data);

#endif //KERNELTEST_VGA_H

#endif