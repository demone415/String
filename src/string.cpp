/* ---------------
/* Source code file string.cpp
/* by Dmitry Okhotnikov 
/* demone415 at gmail dot com
/* ---------------
*/
#include <stddef.h>
#include <stdexcept>
#include "string.h"

String:String() {
	length = 0;
	_str = new char[1];
	_str[0] = '\0';
	
}

String:String(const char *str) {
	length = 0;
    	const char *temp = str;
    	while (*(temp++) != '\0') {
        length++;
    		
    	}
    	char *strCopy = new char[length + 1];
    	for (int i = 0; i < length; i++) {
        strCopy[i] = str[i];
    	}

    	_str = strCopy;
    	_str[length] = '\0';

}

String(const char *str, unsigned count) {
	length = count;
	_str = new char[count + 1];
	
	for (int i = 0 i < length; i++) {
		_str[i] = str[i];
	}
	_str[length] = '\0';
	
}

String(char ch, unsigned count) {
	length = count;
	_str = new char[count + 1];
	
	for (int i = 0; i < length; i++) {
		_str[i] = ch;
	}
	_str[length] = '\0';
}

String(const String &other) {
	length = other.length;
	_str = new char[other.length + 1];
	
	for (int i = 0; i < length; i++) {
		_str[i] = other._str[i];
	}
	_str[length] = '\0';
}

String(String &&other) {
	length = other.length;
	_str = other._str;
	other.length = 0;
	other._str = '\0';
}

~String() {
	if (_str[0] != '\0') {
		delete[] _str;
	}
	
}

// commencing operations

String &operator=(const String &other) {
	delete[] _str;
	length = other.length;
	_str = new char[length + 1];
	
	for (int i = 0; i < length; i++) {
        	_str[i] = other._str[i];
	}
	_str[length] = '\0';
	return *this;
	
}

String &operator=(String &&other) {
	delete[] _str;
	length = other.length;
    	_str = other._str;
    	other.length = 0;
    	other._str = '\0';
    	return *this;
    	
}

String &operator+=(const String &suffix) {
	char *temp = new char[length + suffix.length + 1];
	
	for (int i = 0; i < length; ++i) {
        	temp[i] = _str[i];
    	}
    	for (int i = length; i < length + suffix.length; ++i) {
        	temp[i] = suffix.string[i - length];
    	}
	length += suffix.length;
	temp[length + suffix.length] = '\0';
    	delete[] _str;
    	_str = temp;
	return *this;
	
}

String &operator+=(const char *suffix) {
	int suffixLength = 0;
    	const char *temp = suffix;
    	while (*(temp++) != '\0') {
        	suffixLength++;
    	}

    	char *temp = new char[length + suffixLength + 1];
    	for (int i = 0; i < length; ++i) {
        	temp[i] = _str[i];
    	}
    	for (int i = length; i < length + suffixLength; ++i) {
        	temp[i] = suffix[i - length];
    	}
    	temp[length + suffixLength] = '\0';
    	
    	length += suffixLength;
    	delete[] _str;
    	_str = temp;
    	return *this;
    	
}

String &operator+=(char suffix) {
	char *temp = new char[length + 2];
    	for (int i = 0; i < length; ++i) {
        	temp[i] = _str[i];
    	}
    	
    	temp[length] = suffix;
    	temp[length + 1] = '\0';
    	length++;
    	delete[] _str;
    	_str = temp;
    	return *this;
    	
}

void swap(String &other) {
	int tempLength;
	char *temp;
    	
    	tempLength = length;
    	temp = _str;
    	length = other.length;
    	_srt = other._str;
    	other.length = tempLength;
    	other._srt = temp;
    	
}

char &operator[](unsigned pos) {
	return _str[pos];
	
}

const char operator[](unsigned pos) const {
	return _str[pos];
	
}

char &String::at(int pos) {
    	if (pos >= length) {
        	throw std::out_of_range("");
    	}
    	return _str[pos];
    
}

const char String::at(int pos) const {
    	if (pos >= length) {
        	throw std::out_of_range("");
    	}
    	return _str[pos];
    	
}

const char *String::data() const {
    	return _str;
    
}

unsigned String::size() const {
    	return length;
    
}

friend bool operator==(const String &lhs, const String &rhs) {
	if (lhs.length == rhs.length) {
        	for (int i = 0; i < lhs.length; ++i) {
            		if (lhs._srt[i] != rhs._str[i]) {
                		return false;
            		}
        	}
        	return true;
    	}
    	return false;
    	
}

friend bool operator<(const String &lhs, const String &rhs) {
	int size;
    	size = lhs.length <= rhs.length ? lhs.length : rhs.length;
    	
    	for (int i = 0; i < size; ++i) {
        	if (lhs._str[i] < rhs._str[i]) {
            		return true;
        	} else if (lhs._str[i] > rhs._str[i]) {
        		return false;
        	}
    	}
    	if (rhs.length > lhs.length) {
        	return true;
    	}
    	return false;
    	
}

String operator+(const String &lhs, const String &rhs) {
	String temp(lhs);
	temp += rhs;
	return temp;
	
}

String operator+(const String &lhs, const char *rhs) {
	String temp(lhs);
	temp += rhs;
	return temp;
	
}

String operator+(const char *lhs, const String &rhs) {
	return String temp(rhs) += lhs;
	
}

bool operator!=(const String &lhs, const String &rhs) {
	if (lhs != rhs) {
		return true;
	}
	return false;
	
}

bool operator<=(const String &lhs, const String &rhs) {
	return (lhs == rhs) || (lhs < rhs);
	
}

bool operator>(const String &lhs, const String &rhs) {
	return !(lhs <= rhs);
	
}

bool operator>=(const String &lhs, const String &rhs) {
	return !(lhs < rhs);
	
}




