#include <stdio.h>
#include <string.h>


int main(void){

    char class[] = "CS 220";


    // this also works, but please don't
	// note, if you do specify all of the characters one-by-one, 
	// you have to manually add the null terminator to the end 
    char class2[] = {67, 83, 32, 50, 50, 48, 0};

    printf("This class is %s\n", class);
    printf("This class is %s\n", class2);


    // because Strings are really handled as arrays, we can modify them like arrays

    char ds[] = {'2', '2', '6'};


    class[5] = ds[2]; // remember, C converts char <-> int automagically



    // look at that, now we're in Data Structures!
    printf("This class is %s\n", class);

    char * classStr = "CS 220";

    printf("This is a different way of declaring things, but still a string: %s\n", classStr);

    // when we declare a string using `char *` instead of the `char []`, now it's unmodifiable
//    classStr[5] = '6'; /// Segmentation fault: core dumped

    // of course, you can also wander past the end of the array, with tragic consequences

//    for (int i = 6; i < 100; i++){
//        class[i] = '!'; // we are _really_ excited!
//    }
    printf("This class is %s\n", class);


    printf("\n");
    // let's figure out the size of things!

    printf("%s has %lu characters\n", class, strlen(class));    // strlen doesn't include the null terminator

    printf("%s takes up %lu bytes\n", class, sizeof(class));    // but sizeof does.


    // this is obviously not an array of strings, but shows more of how sizeof works

    printf("\n");

    int grades[] = {78, 83, 90, 84, 95};

    printf("our grades array occupies %lu bytes; each int occupies %lu bytes\n", sizeof(grades), sizeof(int));


    printf("\n");


    char hw [100] = "Hello";
    char w [] = ", World";

    strcat(hw, w);

    printf("Concatenated result: %s\n", hw);


}
