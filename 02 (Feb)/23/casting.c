#include <stdio.h>

void printBits(int num) {
    for(int bit = 0; bit < 32; bit++) {
        printf("%i ", num & 0x01);
        num = num >> 1;
    }
    printf("\n");
}

int sq(int num) {
    return num * num;
}

int main (void) {

    // suppose we've got the following:

    int i1 = 10;
    double d1 = 13.7;
    double res = i1 + d1;

    // clearly, C can't just take the 10 and the 13.7 and add them as-is
    // one is an int, the other is a double -- not only are they different sizes
    // (the int is 32 bits, the double 64), _but_ the representations (2s complement
    // vs IEEE-754 64b) are totally different.  So, the computer must _convert_ one
    // type into that of the other, so that the arithmetic can proceed
    // in this case, the int is _promoted_ into a double (how much of a pay raise comes with that?)
    // and then the arithmetic can proceed


    // type conversion comes into play in many other scenarios, too


    int a = 2048;

    // automatic type conversion -- in this case, narrowing
    char c = a;


    // output: 2048, 0
    printf("a=%d, c=%d\n", a, c);


    /// why ?
    // 2048 == 0000 1000 0000 0000
    // when we cast to a char, only the part that fits
    // (the last 1 byte / 8 bits) are kept
    // everything else -- gone

    // let's go see another example
    // 1135 == 0000 0100 0110 1111

    // cast this to char, should keep 0110 1111 (== 111_10)

    a = 1135;
    c = a;
    printf("a=%d, c=%d\n", a, c);

    // and we do: 1135, 111


    // more automatic conversion -- promotion

    c = 37;
    a = c;    // the char is promoted to an int
    printf("a=%d, c=%d\n", a, c);


    double d = 13.7;
    double squared = sq(d);

    printf("%f squared is %f\n", d, squared);


    // casting can also be used if we want to do integer/floating point arithmetic when it would default to something else

    int celsius = 20;
    int fahrenheit = 9/5 * celsius + 32;

    // prints: 20c = 52f
    // not so sure about that one
    printf("%dc = %df\n", celsius, fahrenheit);

    // typecast has a higher precedence than arithmetic, so this first casts the 9 to a float, then proceeds from there
    fahrenheit = (float)9/5 * celsius + 32;
    printf("%dc = %df\n", celsius, fahrenheit);


    // just for fun, let's go look at the bits of a float
    float f = 20.3f;

    // this hack is done to get the bits of a float into an int
    // a typecast will be cleverer and convert the float to an int,
    // keeping the value, but rearranging the bits to do so.  We want
    // the bits exactly as-is, ignoring the value
    int i = *(int*) &f;

    printBits(i);

    return 0;
}
