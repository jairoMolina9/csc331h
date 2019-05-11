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
  bool negative;
  typename List<type>::Iterator iter;
public:
 LargeInt();

friend istream &operator>>( istream  &input, LargeInt<type> &A ) {
    input >> A.numbers;
    if(A.numbers[0] == '-'){
        A.numbers.erase(0,1);
        A.negative = true;
    }
    A.setNodes();
    return input;
}

friend ostream &operator<<( ostream  &output, LargeInt &A ) { //output the function
    if(A.negative)
    {
        output << "Result: -";
    } else {
        output << "Result: ";
    }
    A.list.printFromFront();
    return output;
  }

void setNodes();

int checkCase(bool, bool);

LargeInt<type> operator+( LargeInt<type> &);

LargeInt<type> operator-( LargeInt<type> &);

LargeInt<type> operator*( LargeInt<type> &);

LargeInt<type> operator/( LargeInt<type> &);

LargeInt<type> operator%( LargeInt<type> &);

void cleanResult(LargeInt<type>&);

bool operator!=(LargeInt<type> &);

bool operator==( LargeInt<type> &);

bool operator<(LargeInt<type> &);

bool operator>(LargeInt<type> &);

bool operator>=(LargeInt<type> &);

bool operator<=(LargeInt<type> &);
};


#endif /* LARGEINT_H */
