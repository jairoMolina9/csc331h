/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti
   LargeInt Project
   "linkedList.cpp"
   --------------------------------------------
               <In this File>
   I implement the following functions:
   - Insert Front & Back
   - Print Front, Back, Edges
   - Search and Delete
   - Remove all, Copy all
   - Constructors, Operator= Overloaded
   - is_Empty, get_Length
   and the Iterator class implemantion:
   - Operator++, --, *, !=, ==
   --------------------------------------------
*/

#include "linkedList.h"

/* Default List Constructor */
template <class type> List<type>::List() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

/* Destructor */
template <class type> List<type>::~List() {
  /*To successfuly erase a list, all the nodes must be deallocated*/
  removeAll();
 // cout << "Destructor called, List deleted" << endl; // useful for debugging
}

/* This is a copy constructor that receives an object as parameter */
template <class type> List<type>::List(const List<type> &other) {
  copyAll(other);
}

/* Overloaded assignment operator, similar to copy constructor */
template <class type>
List<type> &List<type>::operator=(const List<type> &other) {
  if (head == other.head) { // some clients may try to assign two equal objects
    cerr << "They are the same" << endl;
  } else {
    /*Main difference between the copy constructor and the
      operator= function is that in this case we must deallocate
      any existing Nodes before copying all
    */
    removeAll();
    copyAll(other);
  }
  return *this; // returns the left hand object
}

/* Performs deep copy between two objects */
template <class type> void List<type>::copyAll(const List &other) {
  if (other.get_length() == 0) {
    head = tail = nullptr;
    length = 0;
  } else {
    length = other.length; // no need to increment length
    head = new Node<type>;
    head->value = other.head->value;
    head->back = nullptr;
    head->next = nullptr;
    /*The use of two pointers is for efficiency*/
    Node<type> *other_walker = other.head->next;
    Node<type> *this_walker = head;
    while (other_walker != nullptr) {
      this_walker->next = new Node<type>;
      this_walker->next->value = other_walker->value;
      this_walker->next->next = nullptr;
      this_walker->next->back = this_walker;

      this_walker = this_walker->next;
      other_walker = other_walker->next;
    }
    tail = this_walker; // let tail pointer be the last node
  }
}

/* Inserts value into the front of list */
template <class type> void List<type>::insert_front(type info) {
  if (isEmpty()) { // if is empty create head node
    head = new Node<type>;
    head->back = nullptr;
    head->next = nullptr;
    head->value = info;
    tail = head; // only one node thus tail and head point at same place
    length++;    // increase length by one
  } else {
    Node<type> *new_Node = new Node<type>;
    new_Node->value = info;
    new_Node->back = nullptr;
    new_Node->next = head;
    head->back = new_Node;

    head = new_Node; // sets current head to new node
    length++;        // increase length by one
  }

  //cout << "Value inserted into Node[1]" << endl;
}

/* Inserts value into the back of list */
template <class type> void List<type>::insert_back(type info) {
  if (isEmpty()) {
    head = new Node<type>;
    head->back = nullptr;
    head->next = nullptr;
    head->value = info;
    tail = head; // only one node thus tail and head point at same place
    length++;    // increase length by one
  } else {
    Node<type> *new_Node = new Node<type>;
    new_Node->value = info;
    new_Node->back = tail;
    new_Node->next = nullptr;
    tail->next = new_Node;

    tail = new_Node; // sets current tail to new node
    length++;        // increase length by one
  }

 // cout << "Value inserted into Node[" << length << "]\n" << endl;
}

/* Removes every node front->back in a list */
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

/* Prints from front->back */
template <class type> void List<type>::printFromFront() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  for (Node<type> *ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << ptr->value;
  }
  cout << endl;
}

/* Prints from back->front */
template <class type> void List<type>::printFromBack() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  int counter = length; // used as a dummy var
  for (Node<type> *ptr = tail; ptr != nullptr; ptr = ptr->back) {
    cout << "NODE [" << counter-- << "] -> ";
    cout << ptr->value << endl;
  }
}

/*Prints the value of the current head and tail pointer*/
template <class type> void List<type>::printEdges() {
  if (isEmpty()) {
    cerr << "The list is empty" << endl;
    return;
  }
  cout << "The HEAD value ";
  cout << "[ " << head->value << " ]" << endl;
  cout << "The TAIL value ";
  cout << "[ " << tail->value << " ]" << endl;
}

/* Checks if list is empty */
template <class type> bool List<type>::isEmpty() { return (length == 0); }

/* Deletes item , returns flag */
template <class type> bool List<type>::delete_item(type item) {
  Node<type> *dummy;    // dummy pointer used to delete value
  bool deleted = false; // flag

  if (isEmpty()) { // if the list is empty
    cout << "List is empty, nothing to delete" << endl;
    deleted = true;
} else if (length == 1){
   head = tail = nullptr;
   cout << "List is empty" << endl;
   length--;
}else if (head->value == item) { // if the item is found in the first node
    dummy = head;
    head = head->next;
    head->back = nullptr;
    delete dummy;

    cout << "\nItem deleted at Node[1]" << endl;
    cout << "Length updated: " << --length << endl;

    deleted = true;

  } else if (tail->value == item) { // if the item is found in the last node
    dummy = tail;
    tail = dummy->back;
    tail->next = nullptr;
    delete dummy;

    cout << "Item deleted at Node[" << length-- << "]"
         << endl; // postfix decrement
    cout << "Length updated: " << get_length() << endl;

    deleted = true;
  } else { // traverse the list
    Node<type> *walker = head;
    int counter = 1; // used to know which # node was deleted
    while (walker != nullptr) {
      if (walker->value == item) { // walker pointer finds the item
        dummy = walker;
        walker->back->next = dummy->next;
        dummy->next->back = walker->back;
        delete dummy;

        length--; // decrement length
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
  return deleted; // returns flag
}

/* Searches for an item , returns item */
template <class type> bool List<type>::search(type item) {
  bool check = false; // flag

  if (isEmpty()) { // if the list is empty
    cout << "List is empty, nothing to delete" << endl;
    check = true;
  } else if (head->value == item) { // if item found in first node
    cout << "Item found at Node[1]" << endl;
    check = true;
  } else if (tail->value == item) { // if item found in last node
    cout << "Item found at Node[" << get_length() << "]" << endl;
    check = true;
  } else { // traverse the list

    Node<type> *walker = head;
    int counter = 1; // used to know which # node was found
    while (walker != nullptr) {
      if (walker->value == item) { // walker finds item
        cout << "Item found at Node[" << counter << "]" << endl;
        check = true;
        break;
      }
      walker = walker->next;
      counter++;
    }
  }
  return check; // returns flag
}

/* Returns the current length of a list */
template <class type> int List<type>::get_length() const { return length; }

/* ITERATOR CLASS IMPLEMENTATION */
template <class type>
 class List<type>::Iterator {
private:
  Node<type> *iter; //pointer to a node

public:
  Iterator() : iter(nullptr) {}
  Iterator(Node<type> *ptr) : iter(ptr) {};

//Moves iterator forward
  Iterator operator++() {
    if (iter != nullptr) {
      iter = iter->next;
    }
    return iter;
  }

  //Shows the value of iterator
  const type operator*() const {
    type value;
    if (iter != nullptr) {
      value = iter->value;
    } else {
        value = 0;
    }
    return value; //return current iterator value
  }

//Moves iterator backward
  Iterator operator--() {
    if (iter != nullptr) {
      iter = iter->back;
    }
    return iter;
  }

//Checks if two iterators are not equal
  bool operator!=(const Iterator & other){
     return iter!=other.iter;
 }

 //Checks if two iterators are equal
 bool operator==(const Iterator & other){
    return iter==other.iter;
}
};
