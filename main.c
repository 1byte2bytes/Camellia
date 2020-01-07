#include "serial.h"
#include "vga.h"
#include "config.h"
#include "stdio.h"
#include "stdint.h"

void kernel_main() {
    // Init early modules
#ifdef SERIAL_ENABLED
    serial_init();
#endif
#ifdef VGA_ENABLED
    vga_initialize();
#endif
    kprintf("Camellia init");
}