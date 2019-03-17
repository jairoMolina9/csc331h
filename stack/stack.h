#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
   T info;
   Node<T> *down; //same as next
};

template <class T>
class Stack{
private:
   Node<T> *top;
   int capacity;

public:
   Stack(); //default cnstr
   ~Stack();
   Stack(const Stack<T>&); //copy csntr
   void operator=(const Stack<T>&); // assignment overload

   bool isFullStack(); //returns false always
   bool isEmptyStack(); // top == null?
   void initializeStack(); //initialize

   void push(T item); //add element to top
   void pop(); //remove element
   T _top();//retrieve top

   void copyStack(const Stack<T>&); //copy entire stack
};


#endif /* STACK_H */
