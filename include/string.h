#ifndef CPP_STRING_H
#define CPP_STRING_H
//one definition rule

class String {
private:
    int length; //length of actual string, w/o EOL symvol
    char * _str;
public:
    static char position;
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
    char & operator[](int pos);
    const char operator[](int pos) const;
/**
throws an exception if pos >= size()
*/
    char & at(int pos);

/**
throws an exception if pos >= size()
*/
    const char at(int pos) const;
/**
/return pointer to '\0' terminated C-style string
*/
    const char * data() const;
    int size() const;
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
};
String operator+(const String &lhs, const String &rhs);
String operator+(const String &lhs, const char *rhs);
String operator+(const char *lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
#endif
