#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template<class x>
class ulist{
private:
   int length, max;
   x *info; //ptr

public:
   ulist(int);
   ulist(const ulist<x> & other); //copy constructor
   ~ulist(); //destructor
   void makeEmpty();
   bool isFull() const;
   bool isEmpty() const;
   int getLength() const;
   void insertItem( x item);
   void deleteItem( x item);
   bool searchItem( x item);
   void printList();

};

#endif /* LIST_H */
