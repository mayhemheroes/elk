#include <stdint.h>
#include <stdio.h>
#include "elk.h"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{

    char mem[8192];
    struct js *js = js_create(mem, sizeof(mem));
    js_eval(js, (char*) data, ~0U);

    return 0;
}