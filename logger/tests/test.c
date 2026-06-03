#include <stdio.h>
#include <stddef.h>

#include "test_fun.h"

#define FUN(id, name) fun id = {name, #name}

typedef struct
{
    int (*ptr)(void);
    char *id;
} fun;

int test(void)
{

    FUN(test_simple_ptr, test_simple);
    FUN(test_file_ptr, test_file);
    FUN(test_file_append_ptr, test_file_append);
    fun tests[] =
    {
        test_simple_ptr,
        test_file_ptr,
        test_file_append_ptr,
    };

    size_t tests_count = 3;

    for (size_t i = 0; i < tests_count; i++)
    {
        if (tests[i].ptr())
        {
            return 1;
        }

        printf("[  OK  ] %s\n", tests[i].id);
    }

    return 0;
}

int main(void)
{
    return test();
}