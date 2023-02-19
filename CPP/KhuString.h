#pragma once

namespace khu {
	char* gString = nullptr;

	const char* Construct(const char* str);
	unsigned int GetLength();
	void Append(const char* str);
	bool RemoveAt(unsigned int i);
	void Reverse();
	void ToUpper();
	void ToLower();
	const char* Copy(const char* str);
}