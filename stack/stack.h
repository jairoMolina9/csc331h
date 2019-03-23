/*
 * main.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: Jairo Molina
 *
 *        Purpose: The purpose of this file is to set stack structure and its
 *                 functions.
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
   T info;
   Node<T> *down;                   //same as next
};

template <class T>
class Stack{
private:
   Node<T> *top;                    //Always points at top node
   int capacity;                    //Keeps track of size

public:
   Stack();                         //default constructor
   ~Stack();
   Stack(const Stack<T>&);          //copy constructor
   void operator=(const Stack<T>&); // assignment overload

   bool isFullStack();              //returns false always
   bool isEmptyStack();             // top == null?
   void initializeStack();          //initialize same as delete all

   void push(T item);               //add element to top
   void pop();                      //remove element from tops
   T _top();                        //retrieve info of top

   void copyStack(const Stack<T>&); //copy entire stack
};


#endif /* STACK_H */
