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
    FUN(test_simple_crlf_ptr, test_simple_crlf);
    FUN(test_2_ptr, test_2);
    FUN(test_space_key_ptr, test_space_key);
    FUN(test_long_ptr, test_long);
    FUN(test_get_value_simple_ptr, test_get_value_simple);
    FUN(test_get_value_non_existing_ptr, test_get_value_non_existing);
    FUN(test_is_key_in_simple_ptr, test_is_key_in_simple);
    FUN(test_is_key_in_non_existing_ptr, test_is_key_in_non_existing);
    fun tests[] =
    {
        test_simple_ptr,
        test_simple_crlf_ptr,
        test_2_ptr,
        test_space_key_ptr,
        test_long_ptr,

        test_get_value_simple_ptr,
        test_get_value_non_existing_ptr,

        test_is_key_in_simple_ptr,
        test_is_key_in_non_existing_ptr,
    };

    size_t tests_count = 8;

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