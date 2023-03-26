#include <iostream>
#include <utility>
#include "String.h"

using namespace std;

int main() {
    String hello{ "Hello", 20 };
    String world{ "World!", 10 };
    String* first = hello < world;
    cout << *first;
}
