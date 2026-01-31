#include <stdio.h>
#include <locale.h>



int main(){


    FILE * data = fopen("cities.txt", "r");

    if (NULL == data) {
        printf("Could not open file for reading\n");
        return 0;

    }

    char city[20];
    int population;

    // for nice commas in the output, not required for this example :)
    setlocale(LC_NUMERIC, "");

    int numRead;

    while ( ( numRead = fscanf(data, "%s%d", city, &population)) == 2) {
        printf("%s has a population of %'d\n", city, population); 

    }

    // other error checking to make sure we didn't fall over and die partway through a line could go here
	
	fclose(data);


    return 0;

}
