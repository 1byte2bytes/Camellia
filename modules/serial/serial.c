//
// Created by Sydney Anne on 25/11/2019.
//

#include <config.h>
#ifdef SERIAL_ENABLED

#include <io.h>
#include <string.h>

#define PORT 0x3f8   /* COM1 */

void serial_init() {
    outb(PORT + 1, 0x00);    // Disable all interrupts
    outb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(PORT + 1, 0x00);    //                  (hi byte)
    outb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

int serial_received() {
    return inb(PORT + 5) & 1;
}

char serial_read() {
    while (serial_received() == 0);

    return inb(PORT);
}

int serial_is_transmit_empty() {
    return inb(PORT + 5) & 0x20;
}

void serial_write(char a) {
    while (serial_is_transmit_empty() == 0);

    outb(PORT,a);
}

void serial_write_str(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        serial_write(str[i]);
    }
}

#endif