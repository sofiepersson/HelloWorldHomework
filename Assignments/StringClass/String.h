#pragma once
#include <iostream>
using namespace std;
class String
{
	int length{};
	char* buffer{};
	size_t maxSize{};

	const int GetLength(const char* text);

public:
	String(size_t maxSize);

	String(const char* defaultText, size_t maxSize);

	String(const String& other);

	String& operator=(const String& other);

	String(String&& other) noexcept;

	String& operator=(String&& other) noexcept;

	~String();

	const void Append(const char* text);

	const void AppendLine(const char* text);

	const void Print();

	const char* GetString();
};

