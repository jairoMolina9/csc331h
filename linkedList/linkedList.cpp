#include "linkedList.h"

template <class type>
List<type>::List() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

template <class type>
void List<type>::copyAll(const List &other)
{
   if(other.length == 0)
   {
      head = tail = nullptr;
      length = 0;
   } else {
      head = new Node<type>;
      head = other.head;
      Node<type> *other_walker = other.head->next;
      while(other_walker != nullptr)
      {
         head = other_walker;
         other_walker = other_walker->next;
      }
      tail = other_walker;
   }
}

template <class type>
List<type>::List(const List<type> &other) {
   copyAll(other);
}

template <class type>
List<type>& List<type>::operator=(const List<type> &other)
{
   if(head == other.head)
   {
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

template <class type>
void List<type>::removeAll()
{
   Node<type>* walker;

   while(head != nullptr)
   {
      walker = head;
      head = head->next;
      delete walker;
   }
   tail = nullptr;
   length = 0;
}

template <class type>
void List<type>::insert_front(type info) {
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

template <class type>
bool List<type>::isEmpty(){
   return (length == 0);
}

template <class type>
void List<type>::printEdges() {
  cout << "The HEAD value" << endl;
  cout << "[ " << head->value << " ]" << endl;
  cout << "\n";
  cout << "The TAIL value" << endl;
  cout << "[ " << tail->value << " ]" << endl;
}

template <class type>
void List<type>::printFromFront() {
  int counter = 1;
  for (Node<type> *ptr = head; ptr != nullptr; ptr = ptr->next) {
    cout << "NODE [" << counter++ << "] -> ";
    cout << ptr->value << endl;
  }
}
