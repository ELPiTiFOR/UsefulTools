#include <stdio.h>
#include <string.h>

#include "check_config.h"
#include "config.h"

int test_simple(void)
{
    config *simple_config = read_config("./tests/simple.config");
    if (check_config(simple_config))
    {
        return 1;
    }

    size_t expected_count = 1;
    if (simple_config->pairs_count != expected_count)
    {
        printf("[FAILED] test_simple | pairs_count is not %zu", expected_count);
        return 1;
    }
    
    struct pair *first_pair = simple_config->pairs;

    if (check_pair(first_pair, "key", "value"))
    {
        return 1;
    }

    return 0;
}

int test_simple_crlf(void)
{
    config *simple_config = read_config("./tests/simple_crlf.config");
    if (check_config(simple_config))
    {
        return 1;
    }

    size_t expected_count = 2;
    if (simple_config->pairs_count != expected_count)
    {
        printf("[FAILED] test_simple | pairs_count is not %zu", expected_count);
        return 1;
    }

    struct pair *p = simple_config->pairs;

    if (check_pair(p, "path_game", "/some/path/"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "path_other", "/some/really/long/and/tiring/path/to/somewhere/or/something"))
    {
        return 1;
    }

    return 0;
}

int test_2(void)
{
    config *simple_config = read_config("./tests/double.config");
    if (check_config(simple_config))
    {
        return 1;
    }

    size_t expected_count = 2;
    if (simple_config->pairs_count != expected_count)
    {
        printf("[FAILED] test_simple | pairs_count is not %zu", expected_count);
        return 1;
    }
    
    struct pair *p = simple_config->pairs;

    if (check_pair(p, "path_game", "/some/path/"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "path_other", "/some/really/long/and/tiring/path/to/somewhere/or/something"))
    {
        return 1;
    }

    return 0;
}

int test_space_key(void)
{
    config *simple_config = read_config("./tests/space.config");
    if (check_config(simple_config))
    {
        return 1;
    }

    size_t expected_count = 1;
    if (simple_config->pairs_count != expected_count)
    {
        printf("[FAILED] test_simple | pairs_count is not %zu", expected_count);
        return 1;
    }
    
    struct pair *first_pair = simple_config->pairs;

    if (check_pair(first_pair, "key with spaces", "valuewithoutspaces"))
    {
        return 1;
    }

    return 0;
}

int test_long(void)
{
    config *long_config = read_config("./tests/long.config");
    if (check_config(long_config))
    {
        return 1;
    }

    size_t expected_count = 9;
    if (long_config->pairs_count != expected_count)
    {
        printf("[FAILED] test_simple | pairs_count is not %zu", expected_count);
        return 1;
    }
    
    struct pair *p = long_config->pairs;

    if (check_pair(p, "path-game", "/home/fran/"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "path-thing", "/home/fran/somewhere/"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "LOG-LEVEL", "ERROR"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "DIFFICULTY", "HARD"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "DEFAULT-NAME", "vivapinata"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "BACKGROUND_COLOR", "#ff0088"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "display", "flex"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "position", "absolute"))
    {
        return 1;
    }

    p++;
    if (check_pair(p, "error-message", "I'm sorry, an error ocurred."))
    {
        return 1;
    }

    return 0;
}

int test_get_value_simple(void)
{
    config *simple_config = read_config("./tests/simple.config");
    char *value = get_config_value(simple_config, "key");
    if (!value)
    {
        fprintf(stderr, "[FAILED] test_get_value_simple | key `key` not found\n");
        return 1;
    }
    
    if (strcmp(value, "value") != 0)
    {
        fprintf(stderr, "[FAILED] test_get_value_simple | value is not `value`\n");
        return 1;
    }

    return 0;
}

int test_get_value_non_existing(void)
{
    config *simple_config = read_config("./tests/simple.config");
    char *value = get_config_value(simple_config, "non_existing_key");
    if (value)
    {
        fprintf(stderr, "[FAILED] test_get_value | `non_existing_key` found: %s\n", value);
        return 1;
    }

    return 0;
}

int test_is_key_in_simple(void)
{
    config *simple_config = read_config("./tests/simple.config");
    int exists = is_key_in_config(simple_config, "key");
    if (!exists)
    {
        fprintf(stderr, "[FAILED] test_is_key_in_simple | key `key` not found\n");
        return 1;
    }

    return 0;
}

int test_is_key_in_non_existing(void)
{
    config *simple_config = read_config("./tests/simple.config");
    int exists = is_key_in_config(simple_config, "non_existing_key");
    if (exists)
    {
        fprintf(stderr, "[FAILED] test_is_key_in_non_existing| `non_existing_key` found\n");
        return 1;
    }

    return 0;
}