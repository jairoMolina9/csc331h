/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti

   LargeInt Project
   "linkedList.h"

   *********************************************

   This file contains the prototypes of
   the following functions:
   - Insert Front & Back
   - Print Front, Back, Edges
   - Search and Delete
   - Constructors, Operator= Overloaded
   - Remove all, Copy all
   - is_Empty, get_Length

   *********************************************
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Generic node structure
template <class type> struct Node {

  type value;
  Node *next;
  Node *back;
};

template <class type> class List {
private:
  Node<type> *head;
  Node<type> *tail;
  int length;

public:
  List();
  ~List();
  List(const List<type> &);
  List<type> &operator=(const List<type> &);
  void insert_back(type);
  void insert_front(type);
  void removeAll();
  void copyAll(const List &);
  int get_length() const;
  bool isEmpty();
  bool search(type);
  void printFromFront();
  void printFromBack();
  void printEdges();
  bool delete_item(type);
  // iterator function from first to last
  // iterator function from last to first
};

#endif /* LINKEDLIST_H */
