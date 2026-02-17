#include <stdio.h>


typedef struct Person_ {
    const char * name;
    int officeNo;
    const char * officeBuilding;
} Person;


void printPerson(Person);



int main (void) {

    Person drSimari = {.name="Patricio Simari", .officeNo=240, .officeBuilding="Malone Hall"};
    printf("%s's office is %d %s\n", drSimari.name, drSimari.officeNo, drSimari.officeBuilding);

    // original type is still there, too
    struct Person_ drSimarisEvilClone = drSimari;
    drSimarisEvilClone.name = "(Evil) Dr. Patricio Simari";
    printf("%s's office is %d %s\n", drSimarisEvilClone.name, drSimarisEvilClone.officeNo, drSimarisEvilClone.officeBuilding);


    // structs can be passed as parameters to functions, too!
    printPerson(drSimari);

    return 0;

}




void printPerson(Person p){
    printf("%s's office is %d %s\n", p.name, p.officeNo, p.officeBuilding);
}


