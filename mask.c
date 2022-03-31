#include "mask.h"

void save_mask(const char *filename, float mask[], int num_frames, int h, int w)
{
    /*
    Load a num_frames x h x w mask.
    */
    FILE *output_file = fopen(filename, "wb");

    if (!output_file)
    {
        exit(1);
    }
    fwrite(mask, __SIZEOF_FLOAT__, h * w * num_frames, output_file);
    fclose(output_file);
}

void load_mask(const char *filename, float mask[], int frame_number, int h, int w)
{
    /*
    Load the mask for frame frame_number.
    */
    FILE *in_file = fopen(filename, "rb");
    if (!in_file)
    {
        printf("Importance mask file not found\n");
        exit(1);
    }
    fseek(in_file, __SIZEOF_FLOAT__ * h * w * frame_number, SEEK_SET);
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

void create_test_mask(float mask[], int h, int w, float low)
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
        printf("%2.1f ", mask[idx]);
        if (i == w - 1)
        {
            printf("\n");
        }
    }
}