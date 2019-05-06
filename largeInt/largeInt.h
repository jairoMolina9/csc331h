/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   largeInt.h
 * Author: molin
 *
 * Created on April 27, 2019, 11:44 AM
 */

#ifndef LARGEINT_H
#define LARGEINT_H

#include "linkedList.cpp"
#include <string>
template <class type> class largeInt {
private:
  string numbers;
  List<type> list;
  typename List<type>::Iterator iter;
public:
  largeInt(){
      numbers = "";
      iter = nullptr;
  }

  friend istream &operator>>( istream  &input, largeInt<type> &A ) {
        input >> A.numbers;
        A.setNodes();
        return input;
  }

  friend ostream &operator<<( ostream  &output, const largeInt &A ) {
        output << "Numbers: " << A.numbers;
        return output;
     }

 void setNodes() {
     for(int i = 0; i < numbers.length(); i++){
         list.insert_back(numbers[i] - '0');
     }
     iter = list.end(); //automatically sets iterator ready to calculate
  }

 void printValues() {
     list.printFromFront();
 }


 largeInt operator+( largeInt<type> &other) {
   largeInt<int> result;

   int dummy = 0;
   int carry = 0;


   while(iter != nullptr || other.iter != nullptr){

      /*adding two digits
        case 1: list1 is at the end
        case 2: list2 is at the end
        case 3: add value list1 & list2
      */
      if(other.iter == nullptr){
         dummy = (*iter + carry);
         --iter;
      }
      else if(iter == nullptr) {
         dummy = *(other.iter) + carry;
         --(other.iter);
      }
      else{
         dummy = (*(other.iter) + *iter) + carry;
         --iter;
         --(other.iter);
      }

      /*addition results
        case 1: result is double digit
        case 2: result is single digit
      */
      if(dummy > 9){
         carry = 1;//always 1, max is 9+9 = '1''8'
         result.list.insert_front(dummy-10);//insert single digit
      } else {
         carry = 0;
         result.list.insert_front(dummy);
      }
   }

   /* Check if 9 is the first value in the lists*/
   iter = list.begin();
   other.iter = other.list.begin();

   if( *iter == 9 || *(other.iter) == 9){
      result.list.insert_front(1); //inserts 1 in front
   }

  return result;
 }

};


#endif /* LARGEINT_H */
