/************************************************************************************
*  Samuel Marrujo
*  List.h
*  02/25/13
*  Program Description:  This program defines the STL class Deque.
*
*  Status: 100% Complete
*
*  Implementation:       Similar uses to the Vector.h and List.h header files, such as
*                        push_back(), push_front(), pop_front(), and empty().
************************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

// Deque.h - an implementation of double-ended queue

#include <vector>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
        typedef DequeIterator<T> iterator;
        
        Deque(): vecOne(), vecTwo() { }
        Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
        Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
        ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
        Deque & operator=(const Deque<T> & d);

        T & operator[](unsigned int);
        T & front();
        T & back();
        bool empty();
        iterator begin();
        iterator end();
        void erase(const iterator &);
        void erase(const iterator &, const iterator &);
        void insert(const iterator &, const T &);
        int size();
        void push_front(const T & value);
        void push_back(const T & value);
        void pop_front();
        void pop_back();
protected:
        vector<T> vecOne;
        vector<T> vecTwo;
};

// Your code goes here ...

template <class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & d) {
    if (!(vecOne.empty() && vecTwo.empty())) {
        delete[] vecOne;
        delete[] vecTwo;
    }
    vecOne = d.vecOne;
    vecTwo = d.vecTwo;
    for (int i = 0; i < d.size(); i++) {
        *this[i] = d[i];
    }
    return *this;

    /*if (buffer != 0)
        delete[] buffer;
    my_size = object.my_size;
    my_capacity = object.my_capacity;
    buffer = new T[my_capacity];
    for (int i = 0; i < my_size; i++)
        buffer[i] = object.buffer[i];
    return *this;
    */
}

template <class T>
T & Deque<T>::operator[](unsigned int index) {
    int size = vecOne.size();
    if (index < size-1)
        return vecOne[size-1-index];
    else
        return vecTwo[index-size];
}

template <class T>
T & Deque<T>::front() {
    if (vecOne.empty())
        return vecTwo.front();
    else if (vecTwo.empty())
        return vecOne.back();
    else
        return vecOne.back();
}

template <class T>
T & Deque<T>::back() {
    if (vecOne.empty())
        return vecTwo.back();
    else if (vecTwo.empty())
        return vecOne.front();
    else 
        return vecTwo.back();
}

template <class T>
bool Deque<T>::empty() {
    return (vecOne.empty() && vecTwo.empty());
}

template <class T>
typename Deque<T>::iterator Deque<T>::begin() {
    if (vecOne.empty())
        return iterator(vecTwo.begin());
    else if (vecTwo.empty())
        return iterator(vecOne.end());
    else
        return iterator(vecOne.end());
}

template <class T>
typename Deque<T>::iterator Deque<T>::end() {
    if (vecOne.empty())
        return iterator(vecTwo.end());
    else if (vecTwo.empty())
        return iterator(vecOne.begin());
    else
        return iterator(vecTwo.end());
}

template <class T>
void Deque<T>::erase(const iterator & itr) {
    int index = itr.index;
    int size = vecOne.size();
    if (index < size)
        vecOne.erase(vecOne.begin() + (size-1-index));
    else
        vecTwo.erase(vecTwo.begin() + (size-index));
}

template <class T>
void Deque<T>::erase(const iterator & itr_one, const iterator & itr_two) {
    int size = vecOne.size();
    if (stop.index < size)
        vecOne.erase(vecOne.begin() + ((size-1) - itr_two.index), vecOne.begin() + ((size-1) - itr_one.index)); 
    else if(itr_one.index > size)
        vecTwo.erase(vecTwo.begin() + (itr_one.index-size), vecTwo.begin() + (itr_two.index-size)); 
    else {
       vecOne.erase(vecOne.begin(), vecOne.begin() + ((size-1) - itr_one.index)+1);
       vecTwo.erase(vecTwo.begin(), vecTwo.begin() + (itr_two.index-size));
    }
}

template <class T>
void Deque<T>::insert(const iterator & itr, const T & value) {
    int index = itr.index;
    int size = vecOne.size();
    if (index < size)
        vecOne.insert(vecOne.begin()+(size-index), value);
    else
        vecTwo.insert(vecTwo.begin()+(index-size), value);
}

template <class T>
int Deque<T>::size() {
    return (vecOne.size() + vecTwo.size());
}

template <class T>
void Deque<T>::push_front(const T & value) {
    vecOne.push_back(value);
}

template <class T>
void Deque<T>::push_back(const T & value) {
    vecTwo.push_back(value);
}

template <class T>
void Deque<T>::pop_front() {
    if (vecOne.empty() && vecTwo.empty())
        return;
    else if (vecOne.empty()) {
        if (vecTwo.size() == 1)
            vecTwo.pop_back();
        else {
            for (int i = 0; i < vecTwo.size()-1; i++)
                vecTwo[i] = vecTwo[i+1];
        }
    }
    else
        vecOne.pop_back();
}

template <class T>
void Deque<T>::pop_back() {
    if (vecOne.empty() && vecTwo.empty())
        return;
    else if (vecTwo.empty()) {
        if (vecOne.size() == 1)
            vecOne.pop_back();
        else {
            for (int i = 0; i < vecOne.size()-1; i++)
                vecOne[i] = vecOne[i+1];
        }
    }
    else
        vecTwo.pop_back();
}

//Iterator Class
template <class T>
class DequeIterator {
        friend class Deque<T>;
        typedef DequeIterator<T> iterator;
public:
        DequeIterator(): theDeque(0), index(0) { }
        DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
        DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

        T & operator*();
        iterator & operator++();
        iterator operator++(int);
        iterator & operator--();
        iterator operator--(int);
        bool operator==(const iterator & r);
        bool operator!=(const iterator & r);
        bool operator<(const iterator & r);
        T & operator[](unsigned int i);
        iterator operator=(const iterator & r);
        iterator operator+(int i);
        iterator operator-(int i);
protected:
        Deque<T> * theDeque;
        int index;
};

template <class T>
T & DequeIterator<T>::operator*() {
    return theDeque;
}

template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator++() {
    return iterator(theDeque, ++index);
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator++(int) {
    return iterator(theDeque, index++);
}

template <class T>
typename DequeIterator<T>::iterator & DequeIterator<T>::operator--() {
    return iterator(theDeque, --index);
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator--(int) {
    return iterator(theDeque, index--);
}

template <class T>
bool DequeIterator<T>::operator==(const iterator & r) {
    return index == r.index;
}

template <class T>
bool DequeIterator<T>::operator!=(const iterator & r) {
    return index != r.index;
}

template <class T>
bool DequeIterator<T>::operator<(const iterator & r) {
    return index < r.index;
}

template <class T>
T & DequeIterator<T>::operator[](unsigned int i) {
    return theDeque(index+i);
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator=(const iterator & r) {
    return iterator(theDeque, r);
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator+(int i) {
    return iterator(theDeque, index+i);
}

template <class T>
typename DequeIterator<T>::iterator DequeIterator<T>::operator-(int i) {
    return iterator(theDeque, index-i);
}

#endif
