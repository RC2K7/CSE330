#ifndef STRING_H
#define STRING_H

#include <iostream>

using namespace std;

class String {
public:
    String();
    String(const String &);
    String(const char *);
    ~String();

    int length() const;
    char * getBuffer() const;
    
    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);
    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend ostream & operator<<(ostream &, const String &);
    
    String & operator=(const String &);
    String & operator=(const char *);
    String & operator+=(const String &);
    char operator[](unsigned int) const;
private:
    char *buffer;
    int size;
protected:
};

#endif // STRING_H