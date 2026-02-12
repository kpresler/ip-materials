#include <stdio.h>
#include <stdlib.h>




void print_array(int nums[], int size){
    for (int i = 0; i < size; i++) printf("%d\n", nums[i]);

}




int main (void) {


    int nums[] = {1,2,4,8,16};


    print_array(nums, 5);


    int age;

    printf("Please enter your age:\n");
    scanf("%d", &age);

    printf("In 10 years, you will be %d\n", age + 10);


    return 0;
}
