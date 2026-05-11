#include <stdlib.h>
#include "key.h"

/* SECTION: Generate a pseudo-random integer from a user-provided seed. */
int key(unsigned int seed) {
    int generated = 0;

    srand(seed);
    generated = rand();
    return generated;
}
