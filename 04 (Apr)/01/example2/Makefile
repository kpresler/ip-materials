CPP = g++
CPPFLAGS = -std=c++11 -Wall -Wextra -pedantic -g


objectmain: ObjectMain.o person.o
	$(CPP) -o objectmain ObjectMain.o person.o

ObjectMain.o: ObjectMain.cpp
	$(CPP) $(CPPFLAGS) -c ObjectMain.cpp

person.o: person.cpp
	$(CPP) $(CPPFLAGS) -c person.cpp

clean:
	rm -f *.o *~ objectmain
