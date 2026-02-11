#include <stdio.h>

void increment(int * a);

int main (void) {

    // create two variables, `a` and `b `.  each of these will live in `main`'s _stack frame_ on the _call stack_
    int a;
    int b = 20;

    // we read the variable declaration `int * pa` as "pa is a pointer-to-int"
    // and here I was, thinking that PA was Pennsylvania...

	// we set pa to store the _address_ (or location) the variable `a`.  alternatively, you think
    // of this as "pa _points to_ a".
    // `&` is the "address-of" operator.
    // the fact that `a` currently has no (defined) value is fine
    // we can point to that slot of memory, even if we don't know what is actually stored there
    int * pa = &a;

    // pb is also a pointer-to-int, pointing to the variable `b`.
    int * pb = &b;

    a = 10;

    // let's look at what is stored in a, a's location in memory, and what is stored in pa
    printf("a=%d; &a=%p, pa=%p\n", a, &a, pa);

    // this _dereferences_ the pointer `pa`, to access the memory location that it points to.
    // that location is `a`, so this assigns `a` to store the value 11.
    *pa = 11;

    // now, look to see what's stored in our variables
    printf("a=%d; &a=%p, pa=%p\n", a, &a, pa);


    // same deal as above, but for our other variable
    *pb = 22;

    printf("b=%d; &b=%p, pb=%p\n", b, &b, pb);

    // just like we can _assign_ a value through a pointer, we can also _access_ a value through a pointer

    printf("a=%d, b=%d\n", *pa, *pb);

    // now, let's see how we can use this with a function
    // we can pass a pointer stored either in a variable, or use address-of
    // both do exactly the same thing
    increment(pa);
    increment(&b);


    // let's check our work
    printf("After incrementing a & b:\n");
    printf("a=%d, b=%d\n", *pa, *pb);

    // just because a variable is used to _store_ an address doesn't mean it doesn't have an address of its own
    // here we've got a pointer-to-pointer-to-int
    // alternatively, ppa stores the address-of a pointer-to-int

    int ** ppa = &pa;


    // pointer-to-pointer-to-something does end up being reasonably useful, in spite of this example
    // I do not recall seeing any useful code that takes it further than this (such as `int *** pppa;
    // or "pointer-to-pointer-to-pointer-to-int")
    **ppa = 111;

    printf("a=%d\n", a);

    return 0;

}


void increment(int * a) {
    // this dereferences the pointer a to access the value it's pointing to.  it then adds 1 to that, and then assigns that updated
    // value back to the thing that a is pointing to.
    *a = *a + 1;

    // could also be written as:
    // *a += 1;
    // ++*a;
    // (*a)++; // parentheses needed here, or it'll do something very different

}
