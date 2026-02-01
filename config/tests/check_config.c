#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "config.h"

int check_pair(struct pair *pair, char *key, char *value)
{
    if (!pair)
    {
        printf("[FAILED] test_simple | pair is NULL\n");
        return 1;
    }

    if (!key)
    {
        printf("[FAILED] test_simple | key is NULL\n");
        return 1;
    }

    if (!value)
    {
        printf("[FAILED] test_simple | value is NULL\n");
        return 1;
    }

    if (strcmp(pair->key, key) != 0)
    {
        printf("ERROR_TEST: key is not \"%s\"\n", key);
        return 1;
    }

    if (strcmp(pair->value, value) != 0)
    {
        printf("ERROR_TEST: value is not \"%s\"\n", value);
        return 1;
    }

    return 0;
}

int check_config(config *config)
{
    if (!config)
    {
        fprintf(stderr, "ERROR_CHECK: config is NULL");
        return 1;
    }

    if (!config->pairs)
    {
        fprintf(stderr, "ERROR_CHECK: config->pairs is NULL");
        return 1;
    }

    return 0;
}