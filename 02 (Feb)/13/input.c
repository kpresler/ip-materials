#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*

char * readInput(){
    char input[100];

    printf("Please enter some text, I don't care how much:\n");

    fgets(input, sizeof(input), stdin);

    // VERY BAD!  This is returning a pointer to a local variable
    // which will be undefined as soon as this function returns
    return input;
}


void readInput(char dest[], int length){

    printf("Please enter some text, I don't care how much:\n");

    // merely somewhat bad.  this actually will work totally fine
    // but, I'm now limited to `length` -- I can't read any more than this
    fgets(dest, length, stdin);

    return ;

}

*/

// solution!

char * readInput(){


    // we'll read in input in small chunks, `bufferSize` at a time
    int bufferSize = 10;

    // this is where we'll (temporarily) store data
    char input[bufferSize];


    // create space where we'll build up the entire user input, of unknown size
    // start it small, we'll make it bigger over time as necessary
    char * dest = (char * ) malloc (bufferSize * sizeof(char));
    int destSize = bufferSize;

    // since we'll be adding to this block of memory we're building up
    // we need to keep track of where within it we are
    int loc = 0;


    printf("Please enter some text, I don't care how much:\n");


    // so long as there is input for us to read in
    // fgets behaves like scanf, but it lets us control how much input we read
    // and ignore whitespace -- read in everything on a line
    while (fgets(input, sizeof(input), stdin) != 0){

        // if we have run out of space to add the extra text we just read
        if (loc + bufferSize > destSize){

            // reallocate -- make space for more
            destSize *= 2;
            dest = realloc(dest, destSize);

        }

        // copy the new input to the end of the extended input we're making
        memcpy(dest + loc, input, bufferSize);

        // keep track of the total amount of input we read in
        loc += strlen(input);

        // and clear our temporary buffer to prepare for next time
        memset(input, 0, bufferSize);

    }


    return dest;

}




int main (void) {



    char * res = readInput();


    printf("Your input was: `%s`\n", res);



    free (res);

    return 0;

}
