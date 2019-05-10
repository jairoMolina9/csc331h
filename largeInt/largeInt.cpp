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
 *
   --------------------------------------------
*/

#include "largeInt.h"

/* Default Constructor */
template <class type> LargeInt<type>::LargeInt() {
  numbers = "";
  iter = nullptr;
  negative = false;
}

/* Set string to individual nodes */
template <class type> void LargeInt<type>::setNodes() {
  for (int i = 0; i < numbers.length(); i++) {
    list.insert_back(numbers[i] - '0');
  }
  iter = list.end(); // automatically sets iterator ready to calculate
}

/* Check negative case */
template <class type> int LargeInt<type>::checkCase(bool negA, bool negB){
    int case_numb = 0;

    if(!negA && negB)
        case_numb = 1;

   if(negA && !negB)
        case_numb = 2;

    if(negA && negB)
        case_numb = 3;

    return case_numb;
}

/* Addition */
template <class type> LargeInt<type> LargeInt<type>::operator+( LargeInt<type> &addend_2) {
  LargeInt<type> sum;
  LargeInt<type> addend_1 = *this;

  int case_numb = checkCase(this->negative, addend_2.negative);

    if(case_numb == 1){
        addend_2.negative = false;
        sum = addend_1 - addend_2;
    } else if ( case_numb == 2) {
        addend_1.negative = false;
        sum = addend_1 - addend_2;
        sum.negative = true;
    } else if ( case_numb == 3){
        addend_2.negative = false;
        sum = addend_1 - addend_2;
    } else {

  int result = 0;
  int carry = 0;


  while(iter != nullptr || addend_2.iter != nullptr){

     /*adding nodes
      case 1: list2 is traversed fully
      case 2: list1 is traversed fully
      case 3: traverse both lists
    */
     if(addend_2.iter == nullptr){
        result = (*iter + carry);
        --iter; //move list A iter
     }
     else if(iter == nullptr) {
        result = *(addend_2.iter) + carry;
        --(addend_2.iter); //move list B iter
     }
     else{
        result = (*(addend_2.iter) + *iter) + carry;
        --iter;
        --(addend_2.iter);
     }

     /*addition results
      case 1: result is double digit
      case 2: result is single digit
     */
     if(result > 9){
        carry = 1;//always 1, max is 9+9 = '1''8'
        sum.list.insert_front(result-10);//insert single digit
     } else {
         carry = 0;
        sum.list.insert_front(result);
     }

  }

  /* Check if 9 is the first value in the lists*/
  iter = list.begin();
  addend_2.iter = addend_2.list.begin();

  if( (*iter == 9 || *(addend_2.iter) == 9) && (*iter != 0 && *(addend_2.iter) != 0)){
     sum.list.insert_front(1); //inserts 1 in front
  }
    }
 return sum;
}

/* Subtract */
template <class type> LargeInt<type> LargeInt<type>::operator-( LargeInt<type> &subtrahend) {
    LargeInt<type> difference;
    LargeInt<type> minuend = *this;
    int case_numb = checkCase(this->negative, subtrahend.negative);

    if(case_numb == 1){
        subtrahend.negative = false;
        difference = minuend + subtrahend;
    } else if ( case_numb == 2) {
        minuend.negative = false;
        difference = minuend + subtrahend;
        difference.negative = true;
    } else if ( case_numb == 3){
        subtrahend.negative = false;
        difference = minuend + subtrahend;
    } else {

    /* Variables needed */
    int diff = 0; //difference between two single digits
    int carry = 0;
    int exp = 0; //adds 10 to minuend if needed
    bool neg = false;

    /* Finds if output will be negative
     Case 1: Same length, but listA head->info < listB head->info
     Case 2: Length from listA < listB
     */
    iter = list.begin(); //need to look first digit
    subtrahend.iter = subtrahend.list.begin(); //need to look first digit

    if( ( list.get_length() == subtrahend.list.get_length() ) && (*iter < *(subtrahend.iter)) )
        neg = true;
    if( ( list.get_length() < subtrahend.list.get_length() ))
        neg = true;

    iter = list.end();
    subtrahend.iter = subtrahend.list.end();

    /* Compute subtraction
     Case 1: Swich List A and List B, negative output
     Case 2: Normal Subtraction
     */
    if(neg){
    while(iter != nullptr || subtrahend.iter != nullptr){
        if(*(subtrahend.iter) >= *iter) {
            diff = ((*(subtrahend.iter) - carry) + exp) -*iter ;
            carry = 0;
        } else if (*(subtrahend.iter) < *iter){
            exp = 10;
            diff = ((*(subtrahend.iter) - carry) + exp) -*iter ;
            carry = 1;
        }

        difference.list.insert_front(diff);

        if(iter == nullptr){
            --(subtrahend.iter);
        } else if ((subtrahend.iter) == nullptr) {
            --iter;
        } else {
            --iter;
            --(subtrahend.iter);
        }
     }

    difference.negative = true;

    } else {
    while(iter != nullptr || subtrahend.iter != nullptr){
        if(*iter >= *(subtrahend.iter)) {
            exp = 0;
            diff = ((*iter - carry) + exp) - *(subtrahend.iter);
            carry = 0;
        } else if (*iter < *(subtrahend.iter)){
            exp = 10;
            diff = ((*iter - carry) + exp) - *(subtrahend.iter);
            carry = 1;
        }

        difference.list.insert_front(diff);

        if(iter == nullptr){
            --(subtrahend.iter);
        } else if ((subtrahend.iter) == nullptr) {
            --iter;
        } else {
            --iter;
            --(subtrahend.iter);
        }
     }
    }
   }

    return difference;
}

/* Equal */
template <class type> bool LargeInt<type>::operator==( LargeInt<type> &other){
    bool equal = true;

    if(list.get_length() == other.list.get_length()) {
        for(int i = 0 ; i < list.get_length(); i++) {
            if( *iter != *(other.iter) ) {
                equal = false;
                break;
            }
            --iter;
            --(other.iter);
        }
    } else {
        equal = false;
    }
    return equal;
}

/* Less */
template <class type> bool LargeInt<type>::operator<( LargeInt<type> &other) {

    bool less = true;

    int case_numb = checkCase(this->negative, other.negative);

    if(case_numb == 1){
      less = false;
   } else if(case_numb == 2){
      //do nothing
   } else {

    if (list.get_length() > other.list.get_length()){
        less = false;
    } else if (list.get_length() < other.list.get_length()){
        less = true;
    } else {
        iter = list.begin();
        other.iter = other.list.begin();

        if( *iter >= *(other.iter))
            less = false;
    }
}

    return less;
}

/* Bigger */
template <class type> bool LargeInt<type>::operator>( LargeInt<type> &other) {

    bool bigger = true;

    int case_numb = checkCase(this->negative, other.negative);

    if(case_numb == 1){
      //do nothing
   } else if(case_numb == 2){
      bigger = false;
   } else {

    if (list.get_length() < other.list.get_length()){
        bigger = false;
    } else if (list.get_length() > other.list.get_length()){
        bigger = true;
    } else {
        iter = list.begin();
        other.iter = other.list.begin();

        if( *iter <= *(other.iter))
            bigger = false;

         if(case_numb == 3)
            bigger = !bigger;
    }
}

    return bigger;
}

/* Less or Equal */
template <class type> bool LargeInt<type>::operator>=( LargeInt<type> &other) {
    bool bigger_equal = false;

    if( *this > other || *this == other)
        bigger_equal = true;

    return bigger_equal;
}

/* Bigger or Equal */
template <class type> bool LargeInt<type>::operator<=( LargeInt<type> &other) {
    bool less_equal = false;

    if( *this < other || *this == other)
        less_equal = true;

    return less_equal;
}
