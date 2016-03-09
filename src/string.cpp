/* ---------------
/* Source code file string.cpp
/* by Dmitry Okhotnikov 
/* demone415 at gmail dot com
/* ---------------
*/

#include "../include/string.h"

private:
	int length;
	char string;

String:String() {
	int length = 0;
	char _str = new char[1];
	_str[0] = 0x00;
	
}

String:String(const char *str) {
	int length = 0;
	char _str = new char[length];
	_str[length] = 0x00;
	
}