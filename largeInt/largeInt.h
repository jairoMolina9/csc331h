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
  bool neg;
  List<type> list;
  typename List<type>::Iterator iter;
public:
  largeInt(){
      numbers = "";
      neg = false;
      iter = nullptr;
  }
  
  friend istream &operator>>( istream  &input, largeInt<type> &A ) {
        input >> A.numbers;
        if(A.numbers[0] == '-'){
            A.numbers.erase(0,1);
            A.neg = true;
        }
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
 
 void is_negative(){
     if(neg){
         cout << "negative" << endl;
     } else {
         cout << "positive" << endl;
     }
 }
 
 largeInt operator+( largeInt<type> &other) {
     is_negative();
     largeInt<int> result;
     
     int dummy = 0;
     int carry = 0;
     bool extra_1 = true;
     bool extra_2 = true;
     
    while(iter != nullptr || other.iter != nullptr){
        if(*iter != 9)
            extra_1 = false;
        
        if(*(other.iter) != 9)
            extra_2 = false;
        
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
        if(dummy > 9){
            carry = 1;
            result.list.insert_front(dummy-10);
            
        } else {
            carry = 0;
            result.list.insert_front(dummy);
        }
    }
     
     if(extra_1 || extra_2){
         result.list.insert_front(1);
     }
  return result;
 }
    
};


#endif /* LARGEINT_H */
