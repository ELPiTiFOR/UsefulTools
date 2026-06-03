#include "logger.h"

int test_simple(void)
{
    log_msg(LOGA, "test_simple is running...");
    return 0;
}

int test_file(void)
{
    set_log_file("test_file.log", "wb");
    log_msg(LOGA, "test_file is running...");
    close_log_file();
    return 0;
}

int test_file_append(void)
{
    set_log_file("test_file_append.log", "ab");
    log_msg(LOGA, "test_file_append is running...");
    close_log_file();
    return 0;
}