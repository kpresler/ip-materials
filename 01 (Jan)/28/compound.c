#include <stdio.h>


int main(void){

    char weather;
    int temp;

    printf("Enter temperature, and additional weather conditions (single letter only)\n");

    scanf("%d %c", &temp, &weather);

    if (temp > 25 && weather != 'R' /* rain */){
        printf("Let's go swimming!\n");
    }

    else if (weather == 'R' && temp > 20){
        printf("Let's run around in the rain, but not for too long!\n");
    }


    else if (temp > 5 && weather == 'W'){
        printf("Let's go fly a kite!\n");
    }

    else if (temp < 25 && temp > 5 && weather != 'R'){
        printf("Great day for hiking!\n");
    }

    else if ( (temp < -2 && temp > -10) || weather == 'S' /* snow */){
        printf("How about snowboarding?\n");
    }

    else if (temp < -20){
        printf("Too cold, stay inside\n");
    }

    else {
        printf("I'm not sure what to do -- you choose!\n");
    }

    return 0;
}
