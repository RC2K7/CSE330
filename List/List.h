#ifndef LIST_H
#define LIST_H

#include <algorithm>

using namespace std;

template <class T> class Link;
template <class T> class List_iterator;

template <class T>
class List {
public:
   typedef List_iterator<T> iterator;

   List();
   List(const List<T> &);
   ~List();

   bool empty() const;
   unsigned int size() const;

   T & back() const;
   T & front() const;

   void push_front(const T &);
   void push_back(const T &);
   void pop_front();
   void pop_back();

   iterator begin() const;
   iterator end() const;

   void insert(iterator, const T &);
   void erase(iterator &);

   List<T> operator=(const List<T> &);

protected:
   Link<T> * first_link;
   Link<T> * last_link;
   unsigned int my_size;
};

template <class T>
List<T>::List()
{
        first_link = 0;
        last_link = 0;
        my_size = 0;
}

template <class T>
List<T>::List(const List & src)
{
        first_link = 0;
        last_link = 0;
        my_size = 0;
        for (iterator itr = src.begin(); itr != src.end(); itr++)
                push_back(*itr);
}

template <class T>
List<T>::~List() {
    for (iterator itr = this->begin(); itr != this->end(); itr++)
        delete itr.current_link->prev_link;
    delete this->last_link;
}

template <class T>
bool List<T>::empty() const {
    return this->my_size == 0;
}

template <class T>
unsigned int List<T>::size() const {
    return this->my_size;
}

template <class T>
T & List<T>::back() const {
    return this->last_link->value;
}

template <class T>
T & List<T>::front() const {
    return this->first_link->value;
}

template <class T>
void List<T>::push_front(const T & val) {
    Link<T> * tempLink = new Link<T>(val);

    if (this->empty()) {
        this->first_link = this->last_link = tempLink;
    } else {
        this->first_link->prev_link = tempLink;
        tempLink->next_link = this->first_link;
        this->first_link = tempLink;
    }
    this->my_size++;
}

template <class T>
void List<T>::push_back(const T & val) {
    Link<T> * tempLink = new Link<T>(val);

    if (this->empty()) {
        this->first_link = this->last_link = tempLink;
    } else {
        this->last_link->next_link = tempLink;
        tempLink->prev_link = this->last_link;
        this->last_link = tempLink;
    }
    this->my_size++;
}

template <class T>
void List<T>::pop_front() {
    this->first_link = this->first_link->next_link;
    this->my_size--;

    if (this->empty()) {
        this->first_link = this->last_link = 0;
    }
}

template <class T>
void List<T>::pop_back() {
    this->last_link = this->last_link->prev_link;
    this->my_size--;

    if (this->empty()) {
        this->first_link = this->last_link = 0;
    }
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{
    return iterator(this->first_link);
}

template <class T>
typename List<T>::iterator List<T>::end() const {
    return iterator(this->last_link->next_link);
}

template <class T>
void List<T>::insert(iterator itr, const T & val) {
    if (itr == this->begin()) {
        this->push_front(val);
    } else {
        Link<T> *  tempLink = new Link<T>(val);
        tempLink->prev_link = itr.current_link->prev_link;
        tempLink->next_link = itr.current_link;
        tempLink->prev_link->next_link = tempLink;
        tempLink->next_link->prev_link = tempLink;
        this->my_size++;
    }
}

template<class T>
void List<T>::erase(iterator & itr) {
    if (itr.current_link == this->first_link) {
        this->pop_front();
    } else if (itr.current_link == this->last_link) {
        this->pop_back();
    } else {
        itr.current_link->prev_link->next_link = itr.current_link->next_link;
        itr.current_link->next_link->prev_link = itr.current_link->prev_link;
        delete itr.current_link;
        this->my_size--;
    }
}

template <class T>
List<T> List<T>::operator=(const List<T> & src) {
    for (iterator itr = this->begin(); itr != this->end(); itr++)
        delete itr.current_link->prev_link;
    delete this->last_link;
    this->my_size = 0;

    for (iterator itr = src.begin(); itr != src.end(); itr++)
                this->push_back(*itr);
}

template <class T>
class Link {
private:
   Link(const T & x): value(x), next_link(0), prev_link(0) {}

   T value;
   Link<T> * next_link;
   Link<T> * prev_link;

   friend class List<T>;
   friend class List_iterator<T>;
};

template <class T>
class List_iterator {
public:
   typedef List_iterator<T> iterator;

   List_iterator(Link<T> * src): current_link(src) { }
   List_iterator(): current_link(0) { }
   List_iterator(List_iterator<T> * src): current_link(src->current_link) { }

   T & operator*();
   iterator operator=(const iterator & rhs);
   bool operator==(const iterator & rhs) const;
   bool operator!=(const iterator & rhs) const;
   iterator & operator++();
   iterator operator++(int);
   iterator & operator--();
   iterator operator--(int);

protected:
   Link<T> * current_link;

   friend class List<T>;
};

template <class T>
T & List_iterator<T>::operator*()
{
        return current_link->value;
}

template <class T>
typename List_iterator<T>::iterator List_iterator<T>::operator=(const iterator & rhs) {
    this->current_link = rhs.current_link;
    return this;
}

template <class T>
bool List_iterator<T>::operator==(const iterator & rhs) const {
    return this->current_link == rhs.current_link;
}

template <class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const {
    return this->current_link != rhs.current_link;
}


template <class T>
List_iterator<T> & List_iterator<T>::operator++()
{
        current_link = current_link->next_link;
        return *this;
}

template <class T>
typename List_iterator<T>::iterator List_iterator<T>::operator++(int) {
    current_link = current_link->next_link;
    return this;
}

template <class T>
typename List_iterator<T>::iterator & List_iterator<T>::operator--() {
    current_link = current_link->prev_link;
    return *this;
}

template <class T>
typename List_iterator<T>::iterator List_iterator<T>::operator--(int) {
    current_link = current_link->prev_link;
    return this;
}

#endif