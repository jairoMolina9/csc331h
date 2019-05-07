/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti
   LargeInt Project
   "largeInt.h"
   --------------------------------------------
               <In this File>
   You will find the overloaded functions to
   compute arithmetic expressions using LargeInt
   objects
   --------------------------------------------
*/

#ifndef LARGEINT_H
#define LARGEINT_H

#include "linkedList.cpp"
#include <string>
template <class type> class LargeInt {
private:
  string numbers;
  List<type> list;
  typename List<type>::Iterator iter;
public:
 LargeInt();

  friend istream &operator>>( istream  &input, LargeInt<type> &A ) {
        input >> A.numbers;
        A.setNodes();
        return input;
  }

  friend ostream &operator<<( ostream  &output, const LargeInt &A ) { //output the function
        output << "Numbers: " << A.numbers;
        return output;
     }

 void setNodes();

 void printValues();

 LargeInt<type> operator+( LargeInt<type> &other);

};


#endif /* LARGEINT_H */
