//
// Created by Lotte Erickson on 27/11/2019.
//

#include <modules/serial/serial.h>
#include <modules/vga/vga.h>
#include <config.h>

// TODO: make a better printf
void kprintf(const char* str) {
#ifdef SERIAL_ENABLED
    serial_write_str(str);
#endif
#ifdef VGA_ENABLED
    vga_write_str(str);
#endif
}