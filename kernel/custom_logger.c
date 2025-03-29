#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "custom_logger.h"

// Function to log messages with appropriate labels
void log_message(int level, const char *message) {

    if (cpuid() != 0) {
        return; // Ignore logs from other harts
    }
    
    switch (level) {
        case INFO:
            printf("INFO — %s\n", message);
            break;
        case WARN:
            printf("WARNING — %s\n", message);
            break;
        case ERROR:
            printf("ERROR — %s\n", message);
            break;
        default:
            printf("UNKNOWN LOG LEVEL — %s\n", message);
            break;
    }
}
