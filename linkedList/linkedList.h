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
  void search();
  void printFromFront();
  void printFromBack();
  void printEdges();
  bool delete_item(type);
  // iterator function from first to last
  // iterator function from last to first
};
