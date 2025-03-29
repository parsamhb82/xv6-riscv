#ifndef CUSTOM_LOGGER_H
#define CUSTOM_LOGGER_H

// Enum for log levels
typedef enum {
    INFO,
    WARN,
    ERROR
} LogLevel;

// Function prototype
void log_message(int level, const char *message);

#endif // CUSTOM_LOGGER_H
