#include <iostream>

using namespace std;

class String {
    int length{};
    char* buffer{};
    size_t maxSize{};

    int GetLength(const char* text) {
        int count{};
        while (*text) {
            ++count;
            ++text;
        }
        return count;
    }

public:
    String(size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
        cout << "Empty string constructed." << endl;
    }

    String(const char* defaultText, size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
        cout << "Non-empty string " << defaultText << " constructed." << endl;
        Append(defaultText);
    }

    ~String(){
        cout << buffer << " is destructed." << endl;
        delete[] buffer;
    }

    void Append(const char* text) {
        int textLength = GetLength(text);
        length += textLength;
        if (length > maxSize) {
            throw exception("Text can not be longer than max size.");
        }
        for (int i = 0; i < textLength; ++i) {
            *(buffer + length - textLength + i) = *(text + i);
        }
    }

    void AppendLine(const char* text) {
        int textLength = GetLength(text);
        if (textLength + length > maxSize) {
            throw exception("Text can not be longer than max size.");
        }
        for (int i = 0; i < textLength; ++i) {
            *(buffer + length + i) = *(text + i);
        }
        *(buffer + length + textLength) = '\n';
        length += textLength + 1;
    }

    void Print() {
        for (int i = 0; i < length; ++i) {
            cout << buffer[i];
        }
    }

    char* GetString() {
        return buffer;
    }
};

int main() {
    String a(20);
    String b("Hello b", 20);

    a.Append("Hello a");
    b.AppendLine("Hello B");

    a.Print();
    b.Print();

    char* aString = a.GetString();
    cout << aString << endl;

    return 0;
}
