#include "logger.h"

#include <stdio.h>
#include <string.h>

int is_file = 0;
FILE *logs_stream = NULL;
FILE *errors_stream = NULL;
LOG_LEVEL log_level = NONE;
char *log_prefixes[] = { "NONE", "ERRO", "WARN", "LOGA", "LOGM" };

void setup_default(void)
{
    logs_stream = stdout;
    errors_stream = stderr;
    log_level = LOGA;
    is_file = 0;
}

int close_log_file()
{
    if (!is_file)
    {
        fprintf(stderr, "WARN: There are no log files. Returning.");
        return 1;
    }

    fclose(logs_stream);
    fclose(errors_stream);
}

void log(LOG_LEVEL level, char *msg)
{
    if (!logs_stream)
    {
        setup_default();
    }

    if (level > log_level)
    {
        return;
    }

    FILE *final_stream = logs_stream;
    if (level == ERROR || level == WARN)
    {
        final_stream = errors_stream;
    }

    //           01234567
    // TODO: add [ ERRO ] at the start of the message and time
    char lf[1] = {'\n'};
    char tag[9];
    sprintf(tag, "[ %s ] ", log_prefixes[level]);
    fwrite(tag, 1, 9, logs_stream);
    fwrite(msg, 1, strlen(msg), logs_stream);
    fwrite(lf, 1, 1, logs_stream);
    //fflush(logs_stream);
}

int set_log_file(char *path, char *mode)
{
    FILE *file = fopen(path, mode);
    if (!file)
    {
        fprintf(stderr, "ERROR: Couldn't open file %s\n", path);
        return 1;
    }

    is_file = 1;
    logs_stream = file;
    errors_stream = file;
    return 0;
}