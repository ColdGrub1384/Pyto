/* strdup() replacement (from stdwin, if you must know) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
strdup(const char *str)
{
    if (str != NULL) {
        char *copy = malloc(strlen(str) + 1);
        if (copy != NULL)
            return strcpy(copy, str);
    }
    return NULL;
}
