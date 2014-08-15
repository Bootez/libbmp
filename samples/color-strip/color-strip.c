#include <stdio.h>
#include <libbmp/bmpfile.h>

#define WIDTH 640
#define HEIGHT 480
#define DEPTH 24
#define outputfile "out.bmp"

int main(int argc, const char *argv[])
{
    bmpfile_t *bmp = bmp_create(WIDTH, HEIGHT, DEPTH);
    rgb_pixel_t pixel_b = {255, 0 , 0, 0};
    rgb_pixel_t pixel_g = {0, 255 , 0, 0};
    rgb_pixel_t pixel_r = {0, 0 , 255, 0};

    int i, j;

    if (bmp == NULL) {
        printf("Invalid depth value\n");
    }

    for (i = 0; i < HEIGHT / 3; i++) {
        for (j = 0; j < WIDTH; j++) {
            bmp_set_pixel(bmp, j, i, pixel_b);
        }
    }
    for (i = HEIGHT / 3; i < HEIGHT / 3 * 2; i++) {
        for (j = 0; j < WIDTH; j++) {
            bmp_set_pixel(bmp, j, i, pixel_g);
        }
    }
    for (i = HEIGHT / 3 * 2; i < HEIGHT / 3 * 3; i++) {
        for (j = 0; j < WIDTH; j++) {
            bmp_set_pixel(bmp, j, i, pixel_r);
        }
    }

    bmp_save(bmp, outputfile);
    bmp_destroy(bmp);

    return 0;
}
