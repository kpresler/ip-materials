// 601.220 - example of inheritance, virtual functions, dynamic binding

#include "Aclass.h"
#include "Bclass.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main (void) {
  A aobj(1);
  A* aptr;
  B bobj(2);
  B* bptr;

  aptr = &aobj;
  aptr->show();
  aptr->display(); 
  cout << endl;
  // commenting out because A::d is protected and this is not a member function
  //aobj.d = 17.5;

  bptr = &bobj;
  aptr = bptr;
  // Commenting out because A does not have a member function setb
  //aptr->setb(15);
  aptr->seta(3);
  aptr->show();     
  cout << endl;
  aptr->display();  

  cout << endl;
  aobj = A(10);
  aobj.show();
  aobj = bobj;
  aobj.show();
  A a5(5);
  // commenting out because B does not define an assignment operator from type A 
  //bobj = a5;

}


