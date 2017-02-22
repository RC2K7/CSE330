#ifndef VECTOR_H
#define VECTOR_H

using namespace std;

template <class T>
class Vector {
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int);
   Vector(unsigned int, const T &);
   Vector(const Vector<T> &);
   ~Vector();

   unsigned int capacity() const;
   unsigned int size() const;
   bool empty() const;

   iterator begin();
   iterator end();
   T & front();
   T & back();
   void push_back(const T &);
   void pop_back();

   void reserve(unsigned int);
   void resize(unsigned int);

   T & operator[](unsigned int);
   T & operator[](unsigned int) const;
   Vector<T> operator=(const Vector<T> &);

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

template <class T>
Vector<T>::Vector() {
    my_size = 0;
    my_capacity = 0;
    buffer = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size) {
    this->my_size = size;
    this->reserve(size);
}

template <class T>
Vector<T>::Vector(unsigned int size, const T & initial) {
    this->my_size = size;
    this->reserve(size);

    for (int i = 0; i < size; i++)
        this->buffer[i] = initial;
}

template <class T>
Vector<T>::Vector(const Vector<T> & src) {
    this->my_size = src.size();
    this->reserve(src.capacity());

    for (int i = 0; i < src.size(); i++)
        this->buffer[i] = src[i];
}

template <class T>
Vector<T>::~Vector() {
    delete[] this->buffer;
}

template <class T>
unsigned int Vector<T>::capacity() const {
    return this->my_capacity;
}

template <class T>
unsigned int Vector<T>::size() const {
    return this->my_size;
}

template <class T>
bool Vector<T>::empty() const {
    return this->my_size == 0;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
    return this->buffer;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
    return this->buffer + this->my_size;
}

template <class T>
T & Vector<T>::front() {
    return *(this->begin());
}

template <class T>
T & Vector<T>::back() {
    return *(this->end());
}

template <class T>
void Vector<T>::push_back(const T & val) {
    if (this->my_size == this->my_capacity)
        this->reserve(this->my_capacity + 5);
    
    this->buffer[this->my_size++] = val;
}

template <class T>
void Vector<T>::pop_back() {
    this->my_size--;
}

template <class T>
void Vector<T>::reserve(unsigned int cap) {
    T * tempBuffer = new T[cap];
    this->my_capacity = cap;

    if (this->buffer == 0) {
        this->buffer = tempBuffer;
        return;
    }

    for (int i = 0; i < this->my_size; i++)
        tempBuffer[i] = this->buffer[i];
    
    delete[] this->buffer;
    this->buffer = tempBuffer;
    return;
}

template <class T>
void Vector<T>::resize(unsigned int size) {
    if (size > this->my_size)
        this->reserve(size);
    
    this->my_size = size;
}

template <class T>
T & Vector<T>::operator[](unsigned int index) {
    return this->buffer[index];
}

template <class T>
T & Vector<T>::operator[](unsigned int index) const {
    return this->buffer[index];
}

template <class T>
Vector<T> Vector<T>::operator=(const Vector<T> & src) {
    delete[] this->buffer;

    this->my_size = src.size();
    this->reserve(src.capacity());

    for (int i = 0; i < src.size(); i++)
        this->buffer[i] = src[i];
}

#endif