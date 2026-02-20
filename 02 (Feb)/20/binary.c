#include <stdio.h>

int main (void) {
    // let's see how & and | work!

    // 100_10 == 1100100_2

    // 49_10 ==  0110001_2


    // 100 & 49 ==
    //             1100100_2
    //           & 0110001_2
    //             0100000_2  (==32_10)
    // let's check our work!

    printf("%d & %d = %d\n", 100, 49, 100&49);


    // and now let's try |


    // 100 | 49 ==
    //             1100100_2
    //           | 0110001_2
    //             1110101_2  (==117_10)
    // let's check our work!

    printf("%d | %d = %d\n", 100, 49, 100|49);


    // and finally, ^


    // 100 ^ 49 ==
    //             1100100_2
    //           ^ 0110001_2
    //             1010101_2  (==85_10)
    // let's check our work!

    printf("%d ^ %d = %d\n", 100, 49, 100^49);


    printf("\n\n\n~~~Let's try some shifting~~~\n");


    int c = 1;
    for (int i = 0; i < 9; i++) {
        int res = c << i;
        printf("%d << %d = %d\n", c, i, res);

    }

    c = 1024;
    for (int i = 0; i < 11; i++) {
        int res = c >> i;
        printf("%d >> %d = %d\n", c, i, res);

    }

    return 0;
}
