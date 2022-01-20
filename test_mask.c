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
    load_mask(filename, v, h, w);
    print_mask(v, h, w);

    // Load array saved by python and check it matches.
    const char *python_filename = "/tmp/arr.bin";
    float pv[2];
    load_mask(python_filename, pv, h, w);

    for (int i = 0; i < h * w; i++)
    {
        assert(pv[i] == v[i]);
    }
    printf("Done");
}

int main()
{
    // Test saving and loading an array
    const char *filename = "output.bin";
    int factor = 3;
    int h = 60 / factor;
    int w = 120 / factor;

    // Load array saved by python and check it matches.
    const char *python_filename = "/Users/alexanderson/code/sources/soccer_close/importance/d_3.0_fidx_0001.bin";
    float pv[h * w];
    load_mask(python_filename, pv, h, w);
    print_mask(pv, h, w);
    rescale_mask(pv, h, w, 0.1);
    printf("\n");
    print_mask(pv, h, w);
}