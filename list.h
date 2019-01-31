#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class arrayList
{
private:

  int length;
  int data[100];

public:
  //constructor
  arrayList();

  //to make list empty
  void makeEmpty();

  //to check if list is full
  bool isFull() const;

  //show how many elements are inside collection
  int getLength();

  //show elements in list
  void show();

  void insertItem(int);
  void deleteItem(int);

};

#endif /* LIST_H */
