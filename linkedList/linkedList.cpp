#include "linkedList.h"

template <class type> List<type>::List() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <class type> void List<type>::copyAll(const List &other) {
  if (other.length == 0) {
    head = tail = nullptr;
    length = 0;
  } else {
    // work this
  }
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

template <class type> bool List<type>::isEmpty() {
   return (length == 0);
}

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
  Node<type> *walker = head;
  Node<type> *dummy;
  bool deleted = false;

  if(isEmpty())
  {
     cerr << "Nothing to delete, list is empty" << endl;
  }
 else if(head->value == item)
  {
     dummy = head;
     head = dummy->next;
     head->back = nullptr;
     length--;
     cout << "length updated: " << length << endl;
     delete dummy;

     deleted = true;
 }
 else if (tail->value == item){
    dummy = tail;
    tail = dummy->back;
    tail->next = nullptr;
    length--;
    cout << "length updated: " << length << endl;
    delete dummy;

    deleted = true;

} else {
    while (walker != nullptr || walker->value != item) {
     if (walker->value == item) {
        dummy = walker;
        walker->back->next = dummy->next;
        dummy->next->back = walker->back;
        length--;
        cout << "length updated: " << length << endl;
        delete dummy;

        deleted = true;
        break;
     } else {
        walker = walker->next;
     }
    }
}
  return deleted;
}

template <class type>
bool List<type>::search(type item) {
//    int counter = 1;
    Node<type> *walker = head;
    bool found = false;
    
    if(isEmpty())
    {
        cerr << "Nothing to look for, list is empty" << endl;
    }
    else if(head->value == item)
    {
        cout << "Value found in Node[1]" << endl;
        found = true;
    }
    else if (tail->value == item)
    {
        cout << "Value found in Node [" << length << "]" << endl;
        found = true;
    } else {
        while(walker != nullptr || walker->value != item)
        {
            if(walker->value == item)
            {
                found = true;
                break;
            } else {
                walker = walker->next;
            }
        }
    }
    return found;
}
