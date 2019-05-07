/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti
   LargeInt Project
   "largeInt.cpp"
   --------------------------------------------
               <In this File>
   I implement the following functions:
   - Read String to Nodes
   - Print From Front
   - Overload operator +
   - Overload operator -
   - Overload operator *
   - Overload operator /
   - Overload operator %
   --------------------------------------------
*/

#include "largeInt.h"

/* Default Constructor */
template <class type> LargeInt<type>::LargeInt() {
  numbers = "";
  iter = nullptr;
}

template <class type> void LargeInt<type>::setNodes() {
  for (int i = 0; i < numbers.length(); i++) {
    list.insert_back(numbers[i] - '0');
  }
  iter = list.end(); // automatically sets iterator ready to calculate
}

template <class type> void LargeInt<type>::printValues() {
    list.printFromFront();
}

/* Addition */
template <class type> LargeInt<type> LargeInt<type>::operator+( LargeInt<type> &other) {
  LargeInt<type> output;

  int result = 0;
  int carry = 0;


  while(iter != nullptr || other.iter != nullptr){

     /*adding first node
      case 1: list1 is at first node
      case 2: list2 is at first node
      case 3: add first node of list1 & list2
     */
     if(other.iter == other.list.begin()){
        result = (*iter + carry);
        --iter;
     }
     else if(iter == list.begin()) {
        result = *(other.iter) + carry;
        --(other.iter);
     }
     else{
        result = (*(other.iter) + *iter) + carry;
        --iter;
        --(other.iter);
     }

     /*addition results
      case 1: result is double digit
      case 2: result is single digit
     */
     if(result > 9){
        carry = 1;//always 1, max is 9+9 = '1''8'
        output.list.insert_front(result-10);//insert single digit
     } else {
        carry = 0;
        output.list.insert_front(result);
     }
  }

  /* Check if 9 is the first value in the lists*/
  iter = list.begin();
  other.iter = other.list.begin();

  if( *iter == 9 || *(other.iter) == 9){
     output.list.insert_front(1); //inserts 1 in front
  }

 return output;
}
