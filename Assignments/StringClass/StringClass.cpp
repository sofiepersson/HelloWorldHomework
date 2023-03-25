#include <iostream>
#include "String.h"

using namespace std;

int main() {
    String a{ "Hello", 10};
    a.Print(); // a is fine
    {
        String b{ "Poop", 5 };
        b = a;
        a.Append(" a");
        b.Print();
        a.Print(); // a is still fine
    }
    a.Print(); // now, a is broken!! :o

    return 0;
}
