/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti

   LargeInt Project
   "linkedList.cpp"

   *********************************************

   This file implements the following functions:
   - Insert Front & Back
   - Print Front, Back, Edges
   - Search and Delete
   - Remove all, Copy all
   - Constructors, Operator= Overloaded
   - is_Empty, get_Length

   *********************************************
*/

#include "linkedList.h"

template <class type> List<type>::List() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <class type> void List<type>::copyAll(const List &other) {
  if (other.get_length() == 0) {
    head = tail = nullptr;
    length = 0;
  } else {
    length = other.length;
    head = new Node<type>;
    head->value = other.head->value;
    head->back = nullptr;
    head->next = nullptr;
    Node<type>* other_walker = other.head->next;
    Node<type>* this_walker = head;
    while(other_walker != nullptr)
    {
      this_walker->next = new Node<type>;
      this_walker->next->value = other_walker->value;
      this_walker->next->next = nullptr;
      this_walker->next->back = this_walker;

      this_walker = this_walker->next;
      other_walker = other_walker->next;
   }
   tail = this_walker;
  }
}

template <class type> int List<type>::get_length() const{
  return length;
}

template <class type> List<type>::List(const List<type> &other) {
  copyAll(other);
}

template <class type>
List<type> &List<type>::operator=(const List<type> &other) {
  if (head == other.head) {
    cerr << "They are the same" << endl;
  } else {
    removeAll();
    copyAll(other);
  }
  return *this;
}

template <class type> List<type>::~List() {
  removeAll();
  cout << "Object List Deleted" << endl;
}

template <class type> void List<type>::removeAll() {
  Node<type> *walker;

  while (head != nullptr) {
    walker = head;
    head = head->next;
    delete walker;
  }
  tail = nullptr;
  length = 0;
}

template <class type> void List<type>::insert_front(type info) {
  if (isEmpty()) {
    head = new Node<type>;
    head->back = nullptr;
    head->next = nullptr;
    head->value = info;
    tail = head;
    length++;
  } else {
    Node<type> *new_Node = new Node<type>; // creates new node
    new_Node->value = info;                // stores user info into node
    new_Node->back = nullptr;              // sets new head back pointer to null
    new_Node->next = head; // sets new head next pointer to current head
    head->back = new_Node; // sets current head back pointer to new head

    head = new_Node; // sets current head to new head
    length++;
  }

  cout << "Value inserted into Node[1]" << endl;
}

template <class type> void List<type>::insert_back(type info) {
  if (isEmpty()) {
    head = new Node<type>;
    head->back = nullptr;
    head->next = nullptr;
    head->value = info;
    tail = head;
    length++;
  } else {
    Node<type> *new_Node = new Node<type>; // creates new node
    new_Node->value = info;                // stores user info into node
    new_Node->back = tail;                 // sets new head back pointer to null
    new_Node->next = nullptr; // sets new head next pointer to current head
    tail->next = new_Node;    // sets current head back pointer to new head

    tail = new_Node; // sets current head to new head
    length++;
  }

  cout << "Value inserted into Node[" << length << "]" << endl;
}

template <class type> bool List<type>::isEmpty() { return (length == 0); }

template <class type> void List<type>::printEdges() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  cout << "The HEAD value ";
  cout << "[ " << head->value << " ]" << endl;
  cout << "\n";
  cout << "The TAIL value ";
  cout << "[ " << tail->value << " ]" << endl;
}

template <class type> void List<type>::printFromFront() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  int counter = 1;
  for (Node<type> *ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << "NODE [" << counter++ << "] -> ";
    cout << ptr->value << endl;
  }
}

template <class type> void List<type>::printFromBack() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  int counter = length;
  for (Node<type> *ptr = tail; ptr != nullptr; ptr = ptr->back) {
    cout << "NODE [" << counter-- << "] -> ";
    cout << ptr->value << endl;
  }
}

template <class type> bool List<type>::delete_item(type item) {
  Node<type> *dummy;
  bool deleted = false;
  int counter = 1;

  if (isEmpty()) {
    cout << "List is empty, nothing to delete" << endl;
    deleted = true;
  }
  else if (head->value == item) {
    delete head;

    cout << "Item deleted at Node[1]" << endl;
    cout << "Length updated: " << --length << endl;

    deleted = true;

  }
  else if (tail->value == item) {
    dummy = tail;
    tail = dummy->back;
    tail->next = nullptr;
    delete dummy;

    cout << "Item deleted at Node[" << length-- << "]" << endl;
    cout << "Length updated: " << get_length() << endl;

    deleted = true;

  } else {
    Node<type> *walker = head;
    while (walker != nullptr) {
      if (walker->value == item) {
        dummy = walker;
        walker->back->next = dummy->next;
        dummy->next->back = walker->back;
        delete dummy;

        length--;
        cout << "Item deleted at Node[" << counter << "]" << endl;
        cout << "Length updated: " << get_length() << endl;

        deleted = true;
        break;
      } else {
        walker = walker->next;
        counter++;
      }
    }
  }
  return deleted;
}

template <class type> bool List<type>::search(type item) {

  bool check = false;
  if (isEmpty()) {
    cout << "List is empty, nothing to delete" << endl;
    check = true;
  } else if (head->value == item) {
    cout << "Item found at Node[1]" << endl;
    check = true;
  } else if (tail->value == item) {
    cout << "Item found at Node[" << get_length() << "]" << endl;
    check = true;
  } else {

    Node<type> *walker = head;
    int counter = 1;
    while (walker != nullptr) {
      if (walker->value == item) {
        cout << "Item found at Node[" << counter << "]" << endl;
        check = true;
        break;
      }
      walker = walker->next;
      counter++;
    }
  }
  return check;
}
