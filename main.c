#include "serial.h"
#include "config.h"
#include "stdio.h"
#include "stdint.h"

uintptr_t early_init[] = {
#ifdef SERIAL_ENABLED
        (uintptr_t)serial_init
#endif
};

void kernel_main() {
    // Init early modules
    for (size_t i = 0; i < sizeof(early_init); i++) {
        uintptr_t (*early_init[i])(void);
    }
    kprintf("Camellia init");
}