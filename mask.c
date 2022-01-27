#include "mask.h"

void save_mask(const char *filename, float mask[], int h, int w)
{
    FILE *output_file = fopen(filename, "wb");

    if (!output_file)
    {
        exit(1);
    }
    fwrite(mask, __SIZEOF_FLOAT__, h * w, output_file);
    fclose(output_file);
}

void load_mask(const char *filename, float mask[], int h, int w)
{
    FILE *in_file = fopen(filename, "rb");
    if (!in_file)
    {
        printf("File not found\n");
        exit(1);
    }
    fread(mask, __SIZEOF_FLOAT__, h * w, in_file);
    fclose(in_file);
}

void rescale_mask(float mask[], int h, int w, float weight)
{
    for (int idx = 0; idx < h * w; idx++)
    {
        if (mask[idx] < 0.5)
        {
            mask[idx] = weight;
        }
    }
}

void create_mask(float mask[], int h, int w, float low)
{
    /*
    Create a floating point mask to reweight the loss.
    */

    int i, j;
    for (int idx = 0; idx < h * w; idx++)
    {
        i = idx % w;
        j = idx / w;
        int cond = (j > 4 && j < 12 && i > 5 && i < 20);
        mask[idx] = cond ? 1. : low;
    }
}

void print_mask(float mask[], int h, int w)
{
    int i, j;
    for (int idx = 0; idx < h * w; idx++)
    {
        i = idx % w;
        j = idx / w;
        // int v = (int)(mask[idx] * 10);
        // printf("%d ", v);
        printf("%2.1f ", mask[idx]);
        if (i == w - 1)
        {
            printf("\n");
        }
    }
}