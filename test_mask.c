/*
To run this test, run: 
    python save_array.py && gcc mask.c test_mask.c && ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mask.h"

int main1()
{
    // Test saving and loading an array
    const char *filename = "output.bin";
    int h = 1;
    int w = 2;
    float val[] = {0.75, 0.02, 131.12};
    save_mask(filename, val, h, w);
    float v[2];
    load_mask(filename, v, 1, h, w);
    print_mask(v, h, w);
}

int main()
{
    // Load array saved by python and check it matches.
    // Test saving and loading an array
    // const char *filename = "output.bin";
    // int factor = 3;
    int h = 18;
    int w = 30;

    // Load array saved by python and check it matches.
    const char *python_filename = "/tmp/mask.bin";
    for (int n = 0; n<10; n++) {
        float pv[h * w];
        load_mask(python_filename, pv, n, h, w);
        for (int j = 0; j < h * w; j++) {
            assert(pv[j] == (n + 1) * 0.25f);
        }
        // print_mask(pv, h, w);
        // printf("\n");
    }
}