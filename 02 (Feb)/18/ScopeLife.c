#include <stdio.h>

int j;

void func1(void);

int incrementAndGet();

void globalShadow();


int main (void) {

    int x = 10;
    printf("x=%d\n", x);

    for (int x = 0; x < 5; x++){
         printf("x=%d\n", x);
    }

    printf("x=%d\n", x);


    // while we're inside of the call to func1, x is out of scope
    // but, it's still alive, and we can still see it with GDB if we go poking around
    // we could also probably do something horrible to figure outs its address on the
    // stack in func1, but that's a hack and I won't show you how

    func1();



    // demonstration of static variables
	// we see that the variable retains its value between function calls
    printf("staticX=%d\n", incrementAndGet());
    printf("staticX=%d\n", incrementAndGet());
    printf("staticX=%d\n", incrementAndGet());
    printf("staticX=%d\n", incrementAndGet());

    // global variables are initialised by the compiler to zero automatically
    printf("globalJ=%d\n", j);

    // now, we store a value
    j = 10;

    // and can see the value we stored
    printf("globalJ=%d\n", j);


    // when we call into this function, J is _shadowed_ -- we have another (local) variable
	// called J, so you can't see the global one
    globalShadow();


    // but, the global variable definitely still remains, and after we exit that function call we can see it again
    printf("globalJ=%d\n", j);


}





void func1 (void) {

    int j = 20;


    // j goes out of scope & is destroyed as soon as we
    return ;
}

int incrementAndGet(){

    static int x;
    return ++x;

}

void globalShadow(){

    int j = 101;

    printf("within function, global j is shadowed; current j = %d\n", j);

}

