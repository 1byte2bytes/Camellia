#include "serial.h"
#include "config.h"

void kernel_main() {
#ifdef SERIAL_ENABLED // only do serial stuff if serial is enabled
    serial_init();
    serial_write_str("Camellia kernel init");
#endif
    return;
}