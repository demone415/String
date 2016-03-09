﻿#ifndef CPP_STRING_H 
#define CPP_STRING_H

class String { 
public: 
	String();
	String(const char *str);
	String(const char *str, unsigned count);
	String(char ch, unsigned count);
	String(const String &other);
	String(String &&other);
	~String();
	String & operator=(const String &other);
	String & operator=(String &&other);
	String & operator+=(const String &suffix);
	String & operator+=(const char *suffix);
	String & operator+=(char suffix);
	void swap(String &other);
	char & operator[](unsigned pos);
	const char operator[](unsigned pos) const;
/** throws an exception if pos >= size() */ 
	char & at(unsigned pos);
/** throws an exception if pos >= size() */ 
	const char at(unsigned pos) const;
/** /return pointer to '\0' terminated C-style string */ 
	const char * data() const;
	unsigned size() const;
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs); };
	String operator+(const String &lhs, const String &rhs);
	String operator+(const String &lhs, const char *rhs);
	String operator+(const char *lhs, const String &rhs);
	bool operator!=(const String &lhs, const String &rhs);
	bool operator<=(const String &lhs, const String &rhs);
	bool operator>(const String &lhs, const String &rhs);
	bool operator>=(const String &lhs, const String &rhs);
#endif


