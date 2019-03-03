/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti

   LargeInt Project
   "linkedList.h"

   --------------------------------------------
               <In this File>

   You will find the generic structure of the
   nodes, and the prototypes of every function

   --------------------------------------------
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

/*Generic node structure*/
template <class type>
struct Node {

  type value;
  Node *next;
  Node *back;
};

/*Generic list class*/
template <class type>
class List {
private:
  Node<type> *head;
  Node<type> *tail;
  int length;

public:
  List();
  ~List();
  List(const List<type> &);
  List<type> &operator=(const List<type> &);
  void copyAll(const List &);
  void insert_front(type);
  void insert_back(type);
  void removeAll();
  void printFromFront();
  void printFromBack();
  void printEdges();
  bool isEmpty();
  bool delete_item(type);
  bool search(type);
  int get_length() const;
  // iterator function from first to last
  // iterator function from last to first
};

#endif /* LINKEDLIST_H */
