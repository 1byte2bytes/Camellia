#include "serial.h"
#include "config.h"
#include "stdio.h"

void kernel_main() {
#ifdef SERIAL_ENABLED // only do serial stuff if serial is enabled
    serial_init();
#endif
    kprintf("Camellia init");
    return;
}