#include <stdio.h>


int main(void){


    char c = 'H';

    printf("A character, interpreted as a character: %c\n", c);
    printf("A character, interpreted as an integer : %d\n", c);


    // this works, because as far as the computer is concerned, characters are just
    // small integer values.
    char c2 = 73;

    printf("A character, interpreted as a character: %c\n", c2);
    printf("A character, interpreted as an integer : %d\n", c2);


    // character math!

    char c3 = 'A' + 17;
    printf("A character, interpreted as a character: %c\n", c3);
    printf("A character, interpreted as an integer : %d\n", c3);


    char c4 = 'Э';
    printf("A character, interpreted as a character: %c\n", c4);
    printf("A character, interpreted as an integer : %d\n", c4);



    return 0;
}
