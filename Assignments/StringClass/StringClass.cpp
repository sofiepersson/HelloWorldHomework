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
    String zeusName{ "Zeus", 100 };
    Hero zeus{ move(zeusName) };
    Hero hercules{ String{ "Hercules", 100 } };
    return 0;
}
