#include "list.h"

//This function is a default constructor that takes as
//parameter the max size of the array
template <class x>
ulist<x> :: ulist(int max)
{
   length = 0;
   this->max = max;
   info = new x [max]; //dynamic array
}//end default constructor

//This function is a DEEP COPY constructor that takes as
//parameter the address of an object of the same class
template <class x>
ulist<x> ::ulist(const ulist<x>& other)
{
    max = other.max;
    length = other.length;
    info = new x[max]; //dynamic array

    for(int i = 0; i < max; i++)
    {
        info[i] = other.info[i];
    }
} //end deep copy constructor

//This function is a destructor that deallocates the dynamic
//array when called
template <class x>
ulist<x> :: ~ulist()
{
   delete [] info;
   info = nullptr;
}//end of destructor

//This function overloads the = operator, the special part of this function
//is that it performs the same actions as a deep copy constructor with the
//addition that deallocates the local dynamic array variable because it
//needs to be free for the new dynamic array that will be assigned to via the =
//operator
template <class x>
ulist<x>& ulist<x>:: operator=( ulist<x> & list_2)
{
    if (this != &list_2)
    {
        delete []info;
        info = nullptr;

        this->length = list_2.length;
        this->max  = list_2.max;
        info = new x[max];

        for(int i = 0; i < max; i++)
        {
            this->info[i] = list_2.info[i];
        }
    }
    return *this;
} //returns ulist object with new values assigned

//This function "resets the array" from the point of view
//of the user
template <class x>
void ulist<x> :: makeEmpty()
{
   length = 0;
} //end of makeEmpty();

//This function checks if the array is at its maximun capacity
template <class x>
bool ulist<x> :: isFull() const
{
   return length == max;
} //returns boolean value

//This function checks if the array is "empty" from the point of view
//of the user
template <class x>
bool ulist<x> :: isEmpty() const
{
   return length == 0;
} //returns boolen value

//This function checks the current index of the dynamic array
template <class x>
int ulist<x> :: getLength() const
{
   return length;
} //returns int value

//This function inserts an inputted value in two different cases
//Case 1: If the user is inputting a value to the list for the first time
//        it will use an O(1) notation, simply assigning item to the first
//        index and exiting the funtion
//
//Case 2: For any value inputted after the first one, it will be automatically
//        sent to Case 2. It will use an O(n) notation, this algorithm
//        uses linear search to insert the inputted value in an ascending order
template <class x>
void ulist<x> :: insertItem (x item)
{
   if(!isFull())
   {
      //start of case 1
      if(isEmpty())
      {
         info[length] = item;
         length++; //moves to next available index in list
         return;
      } //end of case 1

      //start of case 2
      for(int i = 0; i < length; i++)
      {
         x dummy = info[i];
         if( item < dummy )
         {
            info[i] = item;
            info[length] = dummy;
            item = dummy;
         }
         else{
            info[length] = item;
         }
      }
      //end of case 2
      length++;//moves to next available index in list
   }
   else
       cout << "\n\n LIST IS FULL \n\n";
}

//This function deletes a value if it exists on the list
//also it keeps the list in ascending ordered, uses an O(n^2) notation
template <class x>
void ulist<x> :: deleteItem(x item)
{
   bool deleted = false;

   for(int i = 0 ; i < length ; i++)
  {
    //found item
    if(info[i] == item)
    {
      deleted = true;

      int i_index = i; //in way to use the value of "i" we copy it to another
                       //variable so the program does not affect the loop

      //re arranges list
      for(int j = 1 ; j < length; j++)
      {
         info[i_index++] = info[i+j];
      }

      //Above loop follows this order:
      // info[i] = info[i+1];
      // info[i+1] = info[i+2];
      // info[i+2] = info[i+3];

      length--;//decreaes "list length" by one
    }
  }

  if(!deleted)
  {
     cout << "\n Cannot delete " << item << " because it does not exist in this list\n" << endl;
 }
}//end of delete item function

//This function searches an item using a O(n) linear search
template <class x>
bool ulist<x> :: searchItem(x item)
{
   bool found = false;

   for(int i = 0 ; i < length ; i++)
  {
     //found item
     if(info[i] == item)
     found = true;
  }

  return found;
}//returns a boolean value

//This function prints the data in the list
template <class x>
void ulist<x> :: printList()
{
   cout << "\nThe LIST \n" ;
   for(int i = 0 ; i < length ; i++)
  {
     cout << info[i] << endl;
  }
}//end of print list function
