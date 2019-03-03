/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedList.h
 * Author: molin
 *
 * Created on March 2, 2019, 9:48 PM
 */

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

public:
  List();
  ~List();
  List(const List<type> &);
  List<type> &operator=(const List<type> &);
  void insert_back(type);
  void insert_front(type);
  void removeAll();
  void copyAll(const List &);
  int get_length();
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
