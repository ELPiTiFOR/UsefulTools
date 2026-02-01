#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

extern FILE *logs_stream;

typedef enum
{
    NONE = 0,
    ERRO,
    WARN,
    LOGA,
    LOGM
} LOG_LEVEL;

extern LOG_LEVEL log_level;

void log(LOG_LEVEL level, char *msg);

#endif /* LOGGER_H */