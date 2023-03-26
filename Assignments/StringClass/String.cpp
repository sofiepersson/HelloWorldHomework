#include "String.h"

const int String::GetLength(const char* text) {
	int count{};
	while (*text) {
		++count;
		++text;
	}
	return count;
}

String::String(const size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
	cout << "Empty string constructed." << endl;
}


String::String(const char* defaultText, const size_t maxSize) : maxSize{ maxSize }, length{ 0 }, buffer{ new char[maxSize] {} } {
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

String String::operator+(String other) {
	int thisLength = GetLength(this->buffer);
	int otherLength = GetLength(other.buffer);
	const size_t newMaxSize = this->maxSize + other.maxSize;
	String newString{ newMaxSize };
	newString.Append(this->buffer);
	newString.Append(other.buffer);
	return newString;
}

void String::operator+=(String other) {
	this->Append(other.buffer);
}

char String::operator[](size_t index) {
	for (size_t i = 0; i < this->length; ++i) {
		if (i == index) return *(this->buffer+i);
	}
}

ostream& operator<<(ostream& os, const String& string) {
	return (os << string.buffer << endl);
}

String* String::operator<(String& other) {
	for (size_t i = 0; i < this->length; ++i) {
		if (*(this->buffer + i) == *(other.buffer + i)) continue;
		if (*(this->buffer + i) < *(other.buffer + i)) return this;
		else return &other;
	}
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
