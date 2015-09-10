/* Student ID#: 003914325
   Name: Samuel Marrujo
   Date: 11/17/11
   Professor: Dr. Murphy
   Class: CSCI202
   Project: Lab 10
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class T>
   class Mlist
   {
      public:
        Mlist(T firstinline);//creates the list with a firstinline entry
        void add(T entry);//add entry to the back of the list
        T next();//returns the front of the list and moves every entry up one position;
        bool empty() { return mlist.size() == 0; }// returns true if the list is empty
        void remove(T n);//searches the list and removes the entry with value n
      private:
        vector<T> mlist;
   }; // Mlist

template<class T>
  Mlist<T>::Mlist(T firstinline) {
     mlist.push_back(firstinline);
  }

template<class T>
  void Mlist<T>::add(T entry) {
    mlist.push_back(entry);
  }

template<class T>
  T Mlist<T>::next() {
    T x; 
    if (mlist.size() > 0) {
      x= mlist[0]; 
      for (int i=0; i < mlist.size()-1; i++) {
         mlist[i] = mlist[i+1];
      } 
      mlist.pop_back(); 
    } 
    return x;
  }

template<class T>
  void Mlist<T>::remove(T n) {
    //The function delete is a bit tricky. You first have to find the value to be deleted, and then move up every entry in the list that occurs after the deleted object. 
    typename vector<T>::iterator it;
    if (empty() == true) {
      return;
    }
    else {
      for (it = mlist.begin(); it != mlist.end(); it++) {
        if (*it == n) {
          mlist.erase(it);
        }
      }
    }
  }

int main () {
  Mlist<int> test1(10);
  test1.add(5);
  test1.add(7);
  test1.add(4);
  test1.remove(7);
  cout << test1.next() << endl;
  cout << test1.next() << endl;
  cout << test1.next() << endl;
  Mlist<string> test2("John");
  test2.add("Paul");
  test2.add("Mary");
  test2.add("Kate");
  test2.remove("Paul");
  cout << test2.next() << endl;
  cout << test2.next() << endl;
  cout << test2.next() << endl;
  cin.ignore();
  cin.get();
  return 0;
}
