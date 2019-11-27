#include "serial.h"
#include "vga.h"
#include "config.h"
#include "stdio.h"
#include "stdint.h"

typedef struct {
    char *name;
    void (*init_func)();
} init_func_t;

init_func_t early_init[] = {
#ifdef SERIAL_ENABLED
        {"Serial", serial_init},
#endif
#ifdef VGA_ENABLED
        {"VGA", vga_initialize}
#endif
};

void kernel_main() {
    // Init early modules
    for (size_t i = 0; i < sizeof(early_init); i++) {
        early_init[i].init_func();
    }
    kprintf("Camellia init");
}