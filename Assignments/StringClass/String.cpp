#include "String.h"

const int String::GetLength(const char* text) {
	int count{};
	while (*text) {
		++count;
		++text;
	}
	return count;
}

String::String(size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
	cout << "Empty string constructed." << endl;
}


String::String(const char* defaultText, size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
	cout << "Non-empty string " << defaultText << " constructed." << endl;
	Append(defaultText);
}

String::String(const String& other) {
	cout << "Deep copies " << other.buffer << endl;
	length = other.length;
	maxSize = other.maxSize;
	buffer = new char[maxSize] {};
	for (int i = 0; i < length; ++i) {
		*(buffer + i) = *(other.buffer + i);
	}
}

String& String::operator=(const String& other) {
	cout << "Deep copies " << other.buffer << endl;
	if (this == &other) return *this; // performance benefit if `a = a`
	// first, clean up this object, e.g. delete existing Items, Buffers, etc.
	delete[] buffer;
	// then, clone the other object, e.g. copy their Items, Buffers etc.
	length = other.length;
	maxSize = other.maxSize;
	buffer = new char[maxSize] {};
	for (int i = 0; i < length; ++i) {
		*(buffer + i) = *(other.buffer + i);
	}
	return *this;
}

String::String(String&& other) noexcept { // noexcept is necessary, because else the compiler will prefer using the String& constructor
	cout << "Moving " << other.buffer << endl;
	// move all arguments from the other string to this string
	length = other.length;
	maxSize = other.maxSize;
	buffer = other.buffer;
	// set the arguments to null on the other string
	// to ensure that the other string won't delete our buffer when it gets destructed
	other.buffer = nullptr;
	other.length = NULL;
	other.maxSize = NULL;
}

String& String::operator=(String&& other) noexcept { //noexcept is needed again
	if (this == &other) return *this;
	// clean up own values
	length = 0;
	maxSize = 0;
	buffer = nullptr;
	// assign other values to own values
	length = other.length;
	maxSize = other.maxSize;
	buffer = other.buffer;
	// set other values to null
	other.buffer = nullptr;
	other.length = NULL;
	other.maxSize = NULL;
	return *this;
}

String::~String() {
	if (buffer) {
		cout << buffer << " is destructed." << endl;
		delete[] buffer;
	}
	else cout << "null is destructed." << endl;
}

const void String::Append(const char* text) {
	int textLength = GetLength(text);
	length += textLength;
	if (length > maxSize) {
		throw exception("Text can not be longer than max size.");
	}
	for (int i = 0; i < textLength; ++i) {
		*(buffer + length - textLength + i) = *(text + i);
	}
}

const void String::AppendLine(const char* text) {
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

const void String::Print() {
	for (int i = 0; i < length; ++i) {
		cout << buffer[i];
	}
}

const char* String::GetString() {
	return buffer;
}