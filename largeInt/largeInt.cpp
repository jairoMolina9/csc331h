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
    
    /*
      Check sign
      Case 1: ( + ) ( - )
      Case 2: ( - ) ( + )
      Case 3: ( - ) ( - )
    */
    
    if(!negA && negB) 
        case_numb = 1;

   if(negA && !negB)
        case_numb = 2;

    if(negA && negB)
        case_numb = 3;

    return case_numb;
}

/* Gets Rids of zeros*/
template <class type> void LargeInt<type>::cleanResult( LargeInt<type> &result){
    result.iter = result.list.begin();

    if(result.list.get_length() > 1) {
    while(*(result.iter) == 0 ){
        result.list.deleteFromFront();
        ++(result.iter);
    }
    if(*(result.iter) == 0)
        result.list.deleteFromFront(); //deletes last zero
    }
}

/* Addition */
template <class type> LargeInt<type> LargeInt<type>::operator+( LargeInt<type> &addend_2) {
    iter = list.end();
    addend_2.iter = addend_2.list.end();
    
    LargeInt<type> sum;
    LargeInt<type> addend_1 = *this;
    
    int case_numb = checkCase(this->negative, addend_2.negative);
    
    /*
      Check sign
      Case 1: ( + ) ( - )
      Case 2: ( - ) ( + )
      Case 3: ( - ) ( - )
    */
    
    if(case_numb == 1){
        addend_2.negative = false;
        sum = addend_1 - addend_2;
    
    } else if ( case_numb == 2) {
        addend_1.negative = false;
        sum = addend_2 - addend_1;
        
        if(addend_1 <= addend_2){
            sum.negative = false;
        } else {
            sum.negative = true;
        }
    
    } else if ( case_numb == 3){
        addend_2.negative = false;
        sum = addend_1 - addend_2;
    
    } else {
        
        int result = 0;
        int carry = 0;
        
        while(iter != nullptr || addend_2.iter != nullptr){
            
            /*
              adding nodes
              case 1: ONLY check RIGHT list
              case 2: ONLY check LET list
              case 3: CHECK both lists
            */
            
            if(addend_2.iter == nullptr){
                result = (*iter + carry);
                --iter; //move right list iterator
            
            } else if(iter == nullptr) {
                result = *(addend_2.iter) + carry;
                --(addend_2.iter); //move left list iterator
            
            } else{
                result = (*(addend_2.iter) + *iter) + carry;
                --iter;
                --(addend_2.iter);
            }
            
            /*
              addition results
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
        
        if(carry == 1){
            //if both are not negative
            if(!this->negative && !addend_2.negative){
                sum.list.insert_front(1); //inserts 1 in front
            }
        }
    }
    return sum;
}

/* Subtract */
template <class type> LargeInt<type> LargeInt<type>::operator-( LargeInt<type> &subtrahend) {
    LargeInt<type> difference;
    LargeInt<type> minuend = *this;
    
    int case_numb = checkCase(this->negative, subtrahend.negative);
    
    /*
      Check sign
      Case 1: ( + ) ( - )
      Case 2: ( - ) ( + )
      Case 3: ( - ) ( - )
    */
    
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
        
        int diff = 0; //difference between two single digits
        int carry = 0;
        int exp = 0; //adds 10 to minuend if needed
        bool neg = false;
        
        //Checks if output will be negative
        if( subtrahend > *this)
            neg = true;
        
        /*
          Compute subtraction
          Case 1: Negative Subtraction
          Case 2: Normal Subtraction
        */
        if(neg){
            difference = subtrahend - *this;
            difference.negative = true;
        
        } else {
            
            while(iter != nullptr || subtrahend.iter != nullptr){
                
                /*
                  Compute subtraction
                  Case 1: Carry is set and both digit are equal
                  Case 2: RIGHT digit >= LEFT digit
                  Case 3: RIGHT digit < LEFT digit
                 */
                if (carry == 1 && (*iter == *(subtrahend.iter)) ){
                    diff = 9;
                    carry = 1;
                
                }else if(*iter >= *(subtrahend.iter)) {
                    exp = 0;
                    diff = ((*iter - carry) + exp) - *(subtrahend.iter);
                    carry = 0;
                
                } else if (*iter < *(subtrahend.iter)){
                    exp = 10;
                    diff = ((*iter - carry) + exp) - *(subtrahend.iter);
                    carry = 1;
                }
                
                difference.list.insert_front(diff);
                
                /*
                  Move iterators
                  Case 1: ONLY move RIGHT iterator
                  Case 2: ONLY move LEFT iterator
                  Case 3: BOTH iterators move
               */
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
    
    cleanResult(difference);
    return difference;
}

/* Multiply */
template <class type> LargeInt<type> LargeInt<type>::operator*( LargeInt<type> &multiplier) {
    
    LargeInt<type> product = *this;
    
    LargeInt<type> counter;
    counter.list.insert_front(2);//default start at 2

    LargeInt<type> dummy; //used to add 1 to counter
    dummy.list.insert_front(1);

    int case_numb = checkCase(this->negative, multiplier.negative);

    /* set negative signs to false, easier computation*/
    negative = false;
    multiplier.negative = false;

    while(counter < multiplier){

        counter = counter + dummy;

        product = product + *this;
        //cout << product;
    }

    /*
      Check sign
      Case 1: ( - ) * ( - ) = + 
    */
    if(case_numb == 1 || case_numb == 2)
        product.negative = false;

    return product;
}

/* Divide */
template <class type> LargeInt<type> LargeInt<type>::operator/( LargeInt<type> &divisor) {
    
    LargeInt<type> remainder = *this;
    LargeInt<type> quotient;

    LargeInt<type> dummy;//used to add 1 to quotient
    dummy.list.insert_front(1);

    int case_numb = checkCase(this->negative, divisor.negative);

    /* set negative signs to false, easier computation*/
    remainder.negative = false;
    divisor.negative = false;

    if(remainder == divisor){
       quotient.list.insert_front(1);
    } else {
        
        while(remainder > divisor){
            remainder = remainder - divisor;
            quotient = quotient + dummy;
        }
    }
    
    /*
      Check sign
      Case 1: ( - ) % ( + ) = -
      Case 2: ( + ) % ( - ) = - 
    */
    if(case_numb == 1 || case_numb == 2)
        quotient.negative = true;
    
    return quotient;
}

/* Modolus */
template <class type> LargeInt<type> LargeInt<type>::operator%( LargeInt<type> &divisor) {

   LargeInt<type> remainder = *this;

   LargeInt<type> dummy;
   dummy.list.insert_front(1);

   int case_numb = checkCase(this->negative, divisor.negative);

   /* set negative signs to false, easier computation*/
   remainder.negative = false;
   divisor.negative = false;

   while(remainder > divisor){

      remainder = remainder - divisor;

   }
   
    /*
      Check sign
      Case 1: ( - ) % ( + ) = -
      Case 2: ( + ) % ( - ) = - 
    */
   if(case_numb == 1 || case_numb == 2)
      remainder.negative = true;

   return remainder;

}

/* Equal */
template <class type> bool LargeInt<type>::operator==( LargeInt<type> &other){
    bool equal = true;
    
    if(list.get_length() == other.list.get_length()) {
        
        while(iter != nullptr ) {
            
            if( *iter != *(other.iter) ) {
                equal = false;
                return equal;
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
        
        if(this->list.get_length() < other.list.get_length() ){
           less = true;
        } else if (this->list.get_length() > other.list.get_length()) {
           less = false;
        } else {
            
            iter = list.begin();
            other.iter = other.list.begin();
            
            for(int i = 0; i < list.get_length(); i++){
                
                if( *iter < *(other.iter)){
                    less = true;
                    break;
                } else if ( *iter == *(other.iter)){
                    less = true;
                } else if( *iter > *(other.iter )) {
                    less = false;
                    break;
                }
                
                ++iter;
                ++(other.iter);
            }
        }
    }
    
    iter = list.end();
    other.iter = other.list.end();
   
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
        
        if(this->list.get_length() < other.list.get_length() ){
            bigger = false;
        
        } else if (this->list.get_length() > other.list.get_length()) {
            bigger = true;
        
        } else if ( *this == other ){
            bigger = false;
        
        }else {
            
            iter = list.begin();
            other.iter = other.list.begin();
            
            while(iter != nullptr ){
                
                if(*iter == *(other.iter) ){
                    
                    bigger = true;
                
                } else if(*iter < *(other.iter)){
                    bigger = false;
                    break;
                
                } else if ( *iter > *(other.iter)) {
                    bigger= true;
                    break;
                }
                
                ++iter;
                ++(other.iter);
            }
        }
    }
    
    iter = list.end();
    other.iter = other.list.end();

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
