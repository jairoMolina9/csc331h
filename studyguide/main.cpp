#include <iostream>

using namespace std;

int main() {
  // test yourself
}

// FUNCTION #1
template <class T> int howMany(T item) {
  if (length == 0)
    return;

  int counter = 0;
  if (head->info == item)
    counter++;

  Node<T> *wlkr = head;
  while (wlkr->next != head) {
    cout << "while" << endl;
    if (wlkr->next->info == item) {
      counter++;
    } else if (wlkr->next->info < item)
      break;

    wlkr = wlkr->next;
  }
  return counter;
}

// FUNCTION #2
template <class T> int smaller(T item) {
  if (length == 0)
    cout << "List is empty";
  return 0;

  int bigger = 0;
  Node<T> *wlkr = head;
  while (wlkr != nullptr && wlkr->info >= item) {
    bigger++; //
    wlkr = wlkr->next;
  }
  return length - bigger;
}

// FUNCTION #3
template <class T> int deleteLast(T item) {
  if (length == 0) {
    cout << "empty list";
    return;

  } else if (length == 1) {
    delete tail;
    head = nullptr;
    tail = nullptr;

  } else {
    Node<T> *temp = tail;
    tail = tail->back;
    tail->next = nullptr;
    delete temp;
  }
}

// FUNCTION #4
template <class T> void printBoth() {
  if (length == 0)
    return;
  for (Node<T> *wlkr = head; wlkr != nullptr; wlkr = wlkr->next) {
    cout << wlkr->info << endl;
  }
  for (Node<T> *wlkr = tail; wlkr != nullptr; wlkr = wlkr->back) {
    cout << wlkr->info << endl;
  }
}

// FUNCTION #5
template <class T> void insert_end(T item) {

  Node<T> *newNode;

  if (head == nullptr) { // same as length == 0 or tail == nullptr
    newNode = new Node<T>;
    newNode->info = item;
    newNode->next = nullptr;
    newNOde->back = nullptr;
    tail = newNode;
    head = newNode;
  } else {
    newNode = new Node<T>;
    newNode->info = item;
    newNode->next = nullptr;
    newNOde->back = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

// FUNCTION #6
template <class T> void replace_item(T olditem, T newitem) {

  Node<T> *wlkr = head;
  while (wlkr != nullptr) {
    if (wlkr->info == olditem)
      wlkr->info = newitem;

    wlkr = wlkr->next;
  }
}

// FUNCTION #7
template <class T> void printPosition(T item) {
  int pos, counter = 1;
  Node<T> *wlkr = head; // sorted list descending order

  while (wlkr != nullptr) {
    if (wlkr->info == item || wlkr->info < item) {
      pos = counter;
      break;
    }

    counter++;
    wlkr = wlkr->next;
  }

  if (pos > 0) {
    cout << "The position of item is: " << pos;
  } else {
    cout << "Item does not exist" << endl;
  }
}

// FUNCTION 10
template <class T> int greater(Node<T> *&ptr, T item, int &total) {
  if (ptr != nullptr) {
    if (ptr->info > item) {
      greater(ptr->next, item, total++);
    } else
      greater(ptr->next, item, total);
  }
  return total;
}

// FUNCTION 11 descending order
template <class T> int how_many(Node<T> *&ptr, T item, int &total) {
  if (ptr != nullptr && ptr->info > item) {
    if (ptr->info == item) {
      greater(ptr->next, item, total++);
    } else
      greater(ptr->next, item, total);
  }
  return total;
}

// FUNCTION 12
template <class T> void insert_end(Node<T> *&ptr, T item) {
    if (ptr != nullptr) {
      insert_end(ptr->next, item);
    }
    ptr = new Node<T>;
    ptr->next = nullptr;
    ptr->info = item;
  }
}
