#include <iostream>
using namespace std;

template <class dataType>
struct node
{
   dataType data;
   node* next;
};

template <class dataType>
class List{
private:
   dataType length;
   node<dataType> *head;

public:
   List();
   List(const List<dataType>&);
   ~List();
   void insertNode(dataType);
   void deleteItem(dataType);
   //copy constructor
   void operator=(const List&);
   bool search(dataType data);
   void printList();
};
