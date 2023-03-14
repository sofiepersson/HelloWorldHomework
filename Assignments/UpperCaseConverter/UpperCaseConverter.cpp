#include <iostream>
#include <array>

using namespace std;

char* ConvertToUpperCase(char*, int);

int main()
{
    char input[100]{};
    cin.getline(input, 100);
    char* result = ConvertToUpperCase(input, size(input)); 
    cout << result << endl;
    return 0;
}

char* ConvertToUpperCase(char* text, int size) {
    for (int i = 0; i < size; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
        }
    }
    return text;
}
