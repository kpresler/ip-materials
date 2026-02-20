#include <stdio.h>


typedef struct Person_ {

    char name[30];
    int officeNo;
    char officeBuilding[20];

} Person;

void printPerson(Person p);

int main (void) {

    Person p = {.name="Kai Presler-Marshall", .officeNo=337, .officeBuilding="Malone Hall"};
    Person p2 = {.name="Patricio Simari", .officeNo=240, .officeBuilding="Malone Hall"};

    Person persons[2] = {p, p2};


    FILE * fp = fopen("persons.dat", "wb");
    if (NULL == fp) { printf("File open error\n"); return -8;}
    fwrite(persons, sizeof(Person), 2, fp);
    fclose(fp);


    Person personsRead[2];
    fp = fopen("persons.dat", "rb");
    if (NULL == fp) { printf("File open error\n"); return -8;}
    int res = fread(personsRead, sizeof(Person), 2, fp);

    if (2 != res) { printf("Read error\n"); return -6;}

    printPerson(personsRead[0]);
    printPerson(personsRead[1]);


    return 0;

}

void printPerson(Person p){
    printf("%s's office is %d %s\n", p.name, p.officeNo, p.officeBuilding);
}
