#ifndef CHECK_CONFIG_H
#define CHECK_CONFIG_H

#include "config.h"

int check_pair(struct pair *pair, char *key, char *value);
int check_config(config *config);

#endif /* CHECK_CONFIG_H */