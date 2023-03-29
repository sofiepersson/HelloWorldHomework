#include <iostream>
#include <array>
#include <concepts>

using namespace std;

template<typename T>
concept Averageable = is_default_constructible_v<T>
&& requires (T a, T b) {
    a += b;
    a /= b;
    {(a += b) / 2 } -> convertible_to<T>;
};

auto Average(Averageable auto* array, size_t size) {
    auto sum = *array;
    sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += *array;
        ++array;
    }
    sum /= size;
    return sum;
}

int main() {
    double doubleArray[]{ 2.6, 5.0, 1.4, 3.6 };
    double result = Average(doubleArray, size(doubleArray));
    cout << result << endl;

    int intArray[]{ 8, 6, 9, 4, 5 };
    int result2 = Average(intArray, size(intArray));
    cout << result2 << endl;

    float floatArray[]{ 2.6, 5.0, 1.4, 3.6 };
    float result3 = Average(floatArray, size(floatArray));
    cout << result3 << endl;

    
}