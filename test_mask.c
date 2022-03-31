/*
To run this test, run:
    python save_array.py && gcc mask.c test_mask.c && ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mask.h"

int test_c_save_load()
{
    // Test saving and loading an array
    const char *filename = "/tmp/mask1.bin";
    int h = 1;
    int w = 3;
    int num_frames = 1;
    float val[] = {0.75, 0.02, 131.12};
    save_mask(filename, val, num_frames, h, w);
    for (int fn = 0; fn < num_frames; fn++) {
        float v[h * w];
        load_mask(filename, v, fn, h, w);
        for (int i = 0; i < w; i++) {
            assert(val[i] == v[i]);
        }
    }
    // print_mask(v, h, w);
    printf("test_c_save_load succeeded.\n");
}

int test_py_save_c_load()
{
    // Load array saved by python and check it matches.
    // Test saving and loading an array
    int h = 18;
    int w = 30;

    // Load array saved by python and check it matches.
    const char *python_filename = "/tmp/mask.bin";
    for (int n = 0; n < 10; n++) {
        float pv[h * w];
        load_mask(python_filename, pv, n, h, w);
        for (int j = 0; j < h * w; j++) {
            assert(pv[j] == (n + 1) * 0.25f);
        }
        // print_mask(pv, h, w);
        // printf("\n");
    }
    printf("test_py_save_c_load succeeded.\n");
}

int main() {
    test_c_save_load();
    test_py_save_c_load();
}