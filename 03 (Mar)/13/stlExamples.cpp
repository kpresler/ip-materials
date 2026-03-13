#include <vector>
#include <iostream>


using std::vector;
using std::cout;
using std::endl;


bool isPrime(int num) {
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;


    return true;

}

vector<int> getPrimes(int limit) {

    vector<int> primes;

    for (int i = 2; i <= limit; i++)
        if (isPrime(i))
            // note: we don't have to worry about running out of space
            // or resizing things -- it just happens!
            primes.push_back(i);

            // if we want reverse order, we could do
            // the `vector` class will handle moving over the other elements
            // to make space for the new one
//            primes.insert(primes.begin(), i);


    return primes;
}



int main (void) {

    int limit = 100;

    vector<int> primes = getPrimes(limit);

    cout << "Primes up to " << limit << endl;


    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i] << endl;

    }


    // another way to traverse a data structure -- using an _iterator_
    // the idea behind iterators is that it lets you traverse the elements
    // of a data structure, independently of how they are actually stored
    // this becomes more useful when we get to maps (tomorrow!)


    for (
      vector<int>::iterator it = primes.begin(); // grab the iterator
      it != primes.end();                        // loop until we hit the end.
                                                 // Java uses `hasNext()` which is
                                                 // more elegant, but this does (basically) the same
      ++it                                       // increment the iterator.  operator overloading!
      ) {
         cout << *it << endl;                    // dereference the iterator to grab the thing out of it

    }


    // other fun things you can do with iterators
    cout << "Let's go through these backwards, and see if it's any better" << endl;
    for (
      vector<int>::reverse_iterator it = primes.rbegin();
      it != primes.rend();
      ++it
    ) {
        cout << *it << endl;
    }



}
