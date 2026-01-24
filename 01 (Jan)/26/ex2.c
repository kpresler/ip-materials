#include <stdio.h>

int main(void){
    int first, second;

    printf("Enter two integers: ");

    scanf("%d %d", &first, &second);


    printf("%d + %d = %d\n", first, second, first+second);
    printf("%d - %d = %d\n", first, second, first-second);
    printf("%d * %d = %d\n", first, second, first*second);
    printf("%d / %d = %d\n", first, second, first/second);
    printf("%d %% %d = %d\n", first, second, first%second);

}
