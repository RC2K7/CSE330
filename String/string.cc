#include "String.h"
/*
Function: Default Constructor
Summary: Sets NULLs
Time Complexity: O(1)
*/
String::String() {
    this->buffer = 0;
    this->size = 0;
}

/*
Function: Copy String Constructor
Summary: Copies source String into itself
Params:
    src: Source String that will be copied
Time Complexity: O(n) where n is the length of src
*/
String::String(const String &src) {
    this->size = src.length();
    this->buffer = new char[this->size];
    for (int i = 0; i < this->size; i++)
        this->buffer[i] = src.getBuffer()[i];
}

/*
Function: Copy Char * Constructor
Summary: Copies source Char * into itself
Params:
    str: Source String that will be copied
Time Complexity: O(n) where n is the length of str
*/
String::String(const char *str) {
    this->size = strlen(str);
    this->buffer = new char[this->size];
    for (int i = 0; i < this->size; i++)
        this->buffer[i] = str[i];
}

/*
Function: Destructor
Summary: Cleans up String on deletion
Time Complexity: O(1)
*/
String::~String() {
    delete[] this->buffer;
}

/*
Function: length
Summary: Returns the size of the String
Time Complexity: O(1)
*/
int String::length() const {
    return this->size;
}

/*
Function: getBuffer
Summary: Returns an immutable buffer
Time Complexity: O(1)
*/
char * String::getBuffer() const {
    return this->buffer;
}

/*
Function: operator==
Summary: Returns True if both Strings are exactly the same
Params:
    a: String Reference -> LHS
    b: String Reference -> RHS
*/
bool operator==(const String &a, const String &b) {
    if (a.length() != b.length())
        return false;
    
    for (int i = 0; i < a.length(); i++)
        if (a.getBuffer()[i] != b.getBuffer()[i])
            return false;
    
    return true;
}

/*
Function: operator<=
Summary: Returns True if a is less or equal to b
Params:
    a: String Reference -> LHS
    b: String Reference -> RHS
*/
bool operator<=(const String &a, const String &b) {
    return !(a > b);
}

/*
Function: operator>=
Summary: Returns True if a is greater than or equals to b
Params:
    a: String Reference -> LHS
    b: String Reference -> RHS
*/
bool operator>=(const String &a, const String &b) {
    return !(a < b);
}

/*
Function: operator<
Summary: Returns True if a is less than b
Params:
    a: String Reference -> LHS
    b: String Reference -> RHS
*/
bool operator<(const String &a, const String &b) {
    for (int i = 0; i < a.length() && i < b.length(); i++)
        if (a.getBuffer()[i] < b.getBuffer()[i])
            return true;
    
    if (a.length() < b.length())
        return true;

    return false;
}

/*
Function: operator>
Summary: Returns True if a is greater than b
Params:
    a: String Reference -> LHS
    b: String Reference -> RHS
*/
bool operator>(const String &a, const String &b) {
    for (int i = 0; i < a.length() && i < b.length(); i++)
        if (a.getBuffer()[i] > b.getBuffer()[i])
            return true;
    
    if (a.length() > b.length())
        return true;

    return false;
}

/*
Function: operator<<
Summary: Pushes each char in buffer to output stream
Params:
    stream: ostream Reference -> LHS
    str: String Reference -> RHS
*/
ostream & operator<<(ostream &stream, const String &str) {
    for (int i = 0; i < str.length(); i++)
        stream << str.getBuffer()[i];
    return stream;
}

/*
Function: operator=
Summary: Assignment operator for String input
Params:
    src: String Reference
*/
String & String::operator=(const String &src) {
    delete[] this->buffer;
    this->buffer = new char[src.length()];
    
    for (int i = 0; i < src.length(); i++)
        this->buffer[i] = src.getBuffer()[i];
    
    this->size = src.length();
    return *this;
}

/*
Function: operator=
Summary: Assignment operator for Char * input
Params:
    src: Char *
*/
String & String::operator=(const char *src) {
    return this->operator=(String(src));
}

/*
Function: operator+=
Summary: Appends src buffer onto this
Params:
    src: String Reference
*/
String & String::operator+=(const String &src) {
    int newSize = this->size + src.length();
    char *newBuffer = new char[newSize];

    for (int i = 0; i < this->size; i++)
        newBuffer[i] = this->buffer[i];
    
    for (int i = 0; i < src.length(); i++)
        newBuffer[this->size + i] = src.getBuffer()[i];
    
    delete[] this->buffer;
    this->buffer = newBuffer;
    this->size = newSize;
    return *this;
}

/*
Function: operator[]
Summary: Returns a char within buffer at index
Params:
    index: Int representation of location of wanted char
*/
char String::operator[](unsigned int index) const {
    if (index > this->size)
        return '\0';
    
    return this->buffer[index];
}