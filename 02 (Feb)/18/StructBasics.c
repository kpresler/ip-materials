#include <stdio.h>
#include <stdlib.h>


struct Person {
    const char * name;
    int officeNo;
    const char * officeBuilding;
};



int main (void) {

    struct Person drKai;
    drKai.name = "Kai Presler-Marshall";
    drKai.officeNo = 337;
    drKai.officeBuilding = "Malone Hall";


    printf("%s's office is %d %s\n", drKai.name, drKai.officeNo, drKai.officeBuilding);


    // structs can be initialised with array-initialisation-style syntax
    struct Person drSimari = {"Patricio Simari", 240, "Malone Hall"};

    printf("%s's office is %d %s\n", drSimari.name, drSimari.officeNo, drSimari.officeBuilding);

    // personally, I strongly prefer doing it like this, explicitly specifying what field is what
    // easier to read, and it lets you do it out of order
    struct Person drDarvish = {.name="Ali Darvish", .officeBuilding= "Malone Hall", .officeNo=205};

    printf("%s's office is %d %s\n", drDarvish.name, drDarvish.officeNo, drDarvish.officeBuilding);


    // we can have pointers to structs, too

    struct Person * drSelinski = (struct Person *) malloc (sizeof (struct Person) );

    // since it's a pointer, make sure to dereference

    (*drSelinski).name = "Joanne Selinski";
    (*drSelinski).officeNo = 225;


    // C gives nicer syntax for this dereference-and-access field:
    drSelinski -> officeBuilding = "Malone Hall";

    printf("%s's office is %d %s\n", drSelinski -> name, drSelinski -> officeNo, drSelinski -> officeBuilding);


    // Make sure to free heap-allocated memory

    free(drSelinski);

}
