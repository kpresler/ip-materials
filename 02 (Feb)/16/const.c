


int main (void) {


    int a = 10;
    int b = 20;


    const int * myPtr = &a;


    // verboten -- as far as the pointer is concerned, the
    // thing you're pointing at is const, so you can't change it

    *myPtr = 11;

    // fine -- pointer can be reassigned
    myPtr = &b;



    // "legal", but gcc complains.
    // as long as you don't use the pointer to modify the variable, should work
    // if you _do_ modify the variable....who knows
    const int c = 10;
    int * mutablePtr = &c;


    int * const myConstPtr = &a;

    // fine -- can change the variable through the pointer
    *myConstPtr = 12;

    // but can't reassign the pointer
    myConstPtr = &b;


    const int * const veryConstPtr = &a;

    // can't change variable through pointer
    *veryConstPtr = 100;

    // nor can you reassign the pointer
    veryConstPtr = &b;

    // magic hacks!
    int * brokenPtr = veryConstPtr;
    *brokenPtr = 111;
    brokenPtr = &b;
	
	
	return 0;

}
