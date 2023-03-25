#include <iostream>
#include <utility>
#include "String.h"

using namespace std;

class Hero {
    String _name;
public:
    Hero(const String& name) : _name{ name } { }
    Hero(String&& name) : _name{ move(name) } { }
};

int main() {
    String zeus{ "Zeus", 7 };
    String hercules{ "Hercules", 10 }; // here, hercules gets constructed
    // moves value from zeus to hercules using move assignment operator:
    hercules = move(zeus);
    // should not use value of zeus anymore!
    return 0;
}
