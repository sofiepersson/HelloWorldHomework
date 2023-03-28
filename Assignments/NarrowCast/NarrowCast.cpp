#include <iostream>

using namespace std;

template<typename TTo, typename TFrom>
TTo narrow_cast(TFrom original) {
    TTo cast = static_cast<TTo>(original);
    TFrom castedOriginal = static_cast<TFrom>(cast);
    if (original != castedOriginal) {
        cout << "Warning: Loss of precision " << original << " casted to " << cast << endl;
    }
    return cast;
}

int main() {
    int a = narrow_cast<int>(2.3f);
    cout << a << endl;
    int b = narrow_cast<int>(7.0f);
    cout << b << endl;
    short c = narrow_cast<short>(100);
    cout << c << endl;
    short d = narrow_cast<short>(500000);
    cout << d << endl;
    int e = narrow_cast<int>('B');
    cout << e << endl;
}
