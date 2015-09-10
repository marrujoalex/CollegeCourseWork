/************************************************************************************
*  Samuel Marrujo
*  List.h
*  02/16/13
*  Program Description:  This program defines the STL class List.
*
* Time Complexity:
* Space Complexity:
************************************************************************************/

#ifndef LIST_H
#define LIST_H

// List.h - a doubly-linked list

#include <algorithm>

using namespace std;

// forward declaration of classes defined in this header
template <class T> class Link;
template <class T> class List_iterator;

template <class T> 
class List
{
public:
   typedef List_iterator<T> iterator;

   List();
   List(const List<T> & l);
   ~List();

   bool empty() const;
   unsigned int size() const; 
   T & back() const;
   T & front() const;
   void push_front(const T & x);
   void push_back(const T & x);
   void pop_front();
   void pop_back();
   iterator begin() const;
   iterator end() const;
   void insert(iterator pos, const T & x); // insert x before pos
   void erase(iterator & pos);             // pos must be valid after erase() returns
   List<T> & operator=(const List<T> & l);

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
List<T>::List(const List & l) {
        first_link = 0;
        last_link = 0;
        my_size = 0;
        for (Link<T> * current = l.first_link; current != 0; current = current -> next_link)
                push_back(current -> value);
}

template <class T>
List<T>::~List() {
    delete[] first_link;
    delete[] last_link;
    my_size(0);
}

template <class T>
bool List<T>::empty() {
    if (first_link == 0)
        return true;
    return false;
}

template <class T>
unsigned int List<T>::size() const {
    size(0);
    for (int i = 0; i < ; i++) {
        size++;
    }
    return size;
}

template <class T>
T & List<T>::back() {
    return first_link;
}

template <class T>
T & List<T>::front() {
    return last_link;
}

template <class T>
void List<T>::push_front (const T & x) {
    ;
}

template <class T>
void List<T>::push_back (const T & x) {
    ;
}

template <class T>
void List<T>::pop_front() {
    ;
}

template <class T>
void List<T>::pop_front() {
    ;
}

template <class T>
typename List<T>::iterator List<T>::begin() const
{
        return iterator(first_link);
}

template <class T>
typename List<T>::iterator List<T>::end() const {
    return iterator(last_link);
}
// Your code goes here ...

template <class T> 
class Link 
{
private:
   Link(const T & x): value(x), next_link(0), prev_link(0) {}
                
   T value;     
   Link<T> * next_link;
   Link<T> * prev_link;

   friend class List<T>;
   friend class List_iterator<T>;
};

template <class T> class List_iterator
{
public:
   typedef List_iterator<T> iterator;

   List_iterator(Link<T> * source_link): current_link(source_link) { }
   List_iterator(): current_link(0) { }
   List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }

   T & operator*();  // dereferencing operator
   iterator & operator=(const iterator & rhs);
   bool operator==(const iterator & rhs) const;
   bool operator!=(const iterator & rhs) const;
   iterator & operator++();  // pre-increment, ex. ++it
   iterator operator++(int); // post-increment, ex. it++
   iterator & operator--();  // pre-decrement
   iterator operator--(int); // post-decrement

protected:
   Link<T> * current_link;

   friend class List<T>;
};

template <class T>
T & List_iterator<T>::operator*()
{
        return current_link -> value;
}

template <class T>
List_iterator<T> & List_iterator<T>::operator++() // pre-increment
{
        current_link = current_link -> next_link;
        return *this;
}

template <class T>
List
// more code goes here

#endif
