#include <stdio.h>
#include <stdlib.h>


typedef struct Picture_ {

    int rows;
    int cols;

    struct Pixel_ {
        int x, y;
        int r, g, b;
    } **pixels;

} Picture;


Picture * newPicture(int rows, int cols);


int main (void) {
    Picture * p = newPicture(640, 480);

    printf("Picture dimensions: %dx%d\n", p->rows, p->cols);

    // let's look at just one of the pixels

    struct Pixel_ px = p -> pixels[35][90];

    printf("Pixel location (%d, %d) with colours (%d, %d, %d)\n", px.x, px.y, px.r, px.g, px.b);

}



Picture * newPicture(int rows, int cols) {

    Picture * p = malloc(sizeof(Picture));
    p -> rows = rows;
    p -> cols = cols;

    // dynamically-allocated 2D arrays like we saw last class
    p -> pixels = malloc(rows * sizeof(struct Pixel_ *));

    for (int i = 0; i < rows; i++) {
        p -> pixels[i] = calloc (cols, sizeof(struct Pixel_));

        // this is _not_ required -- but it makes our data structure a bit more interesting
        // also, you'll do something like this as part of your project in a bit
        for (int j = 0; j < cols; j++ ) {
            p -> pixels[i][j].x = i;
            p -> pixels[i][j].y = j;
            
            // can assign multiple variables a value in one expression
			p -> pixels[i][j].r = p -> pixels[i][j].g = p -> pixels[i][j].b = 255;
        }
    }
    return p;

}







