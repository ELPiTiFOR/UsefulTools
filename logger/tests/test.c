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
    fun tests[] =
    {
        test_simple_ptr,
    };

    size_t tests_count = 1;

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