#include <stdio.h>
#include "string_utils.h"


int main (void) {

    char orig[] = "hello, world!";

    printf("Our original string is: `%s`\n", orig);

    toUpper(orig);

    printf("Our new string is: `%s`\n", orig);


}
