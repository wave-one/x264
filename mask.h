#include <stdio.h>
#include <stdlib.h>

void save_mask(const char *filename, float mask[], int h, int w);
void load_mask(const char *filename, float mask[], int n, int h, int w);
void create_mask(float mask[], int h, int w, float low);
void print_mask(float mask[], int h, int w);
void rescale_mask(float mask[], int h, int w, float weight);
