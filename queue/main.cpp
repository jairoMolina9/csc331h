#include <iostream>

using namespace std;

int main(){

}

/* LINKED LIST QUEUE*/
/*
template<class type>
class Queue {
private:
node<type>*front;
node<type>*rear;
}
*/
template <class type>
void queue<type>::enqueue(type item) {

   node<type> *ptr = new node<type>;
   ptr->data = item;
   ptr->next = nullptr;
   if(front == nullptr)
   front = ptr;
   else rear->next = temp;

   rear = temp;

}

template <class type>
void queue<type>::dequeue(type item) {
   node<type> *ptr = new node<type>;
   if(temp != rear)
      front = front->next;
      else rear = nullptr;

      delete temp;
}


/* ARRAY BASED QUEUE*/
/*
template<class type>
class Queue {
private:
type *data;
int max;
public:

}
*/
