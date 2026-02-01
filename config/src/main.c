#include <stdio.h>

#include "config.h"

int main(void)
{
    config *my_config = read_config("example.config");
    if (!my_config)
    {
        printf("Couldn't read config\n");
        return 1;
    }

    printf("Printing config...\n");
    print_config(my_config);
    printf("...done\n");

    return 0;
}