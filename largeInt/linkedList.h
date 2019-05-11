#ifndef LINKEDLIST_H

#define LINKEDLIST_H

#include <iostream>
using namespace std;

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

  void copyAll(const List &);

public:
  List();
  ~List();
  List(const List<type> &);
  List<type> &operator=(const List<type> &);

  void insert_front(type);
  void insert_back(type);
  void deleteFromFront();
  void removeAll();
  void printFromFront();
  void printFromBack();
  void printEdges();
  bool isEmpty();
  bool delete_item(type);
  bool search(type);
  int get_length() const;

  // Implementation in .cpp
  class Iterator;
  // sets iterator to head must be const because we
  Iterator begin(void) { return Iterator(head); }

  Iterator end(void) {
      return Iterator(tail);
  }
};

#endif /* LINKEDLIST_H */
