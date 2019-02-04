#include "list.h"

template <class x>
ulist<x> :: ulist(int max)
{
   length = 0;
   this->max = max;
   info = new x [max]; //dynamic array
}

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
} //end copy constructor

template <class x>
ulist<x> :: ~ulist()
{
   delete [] info;
   info = nullptr;
}

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
} //end of overloaded = function

template <class x>
void ulist<x> :: makeEmpty()
{
   length = 0;
}

template <class x>
bool ulist<x> :: isFull() const
{
   return length == max;
}

template <class x>
bool ulist<x> :: isEmpty() const
{
   return length == 0;
}

template <class x>
int ulist<x> :: getLength() const
{
   return length;
}

template <class x>
void ulist<x> :: insertItem (x item)
{
   if(!isFull())
   {
       if(isEmpty())
       {
           info[length] = item;
       }
       else{
           //sorting ascending order
           for(int i = 0; i < length; i++)
           {
               x dummy;
               if(item > info[i])
               {
                   dummy = info[i];
                   info[i] = item;
                   info[length] = dummy;
               }
           }
       }
       
       length++;
   }
   else
       cout << "\n\n LIST IS FULL \n\n";
}

template <class x>
void ulist<x> :: deleteItem(x item)
{
   for(int i = 0 ; i < length ; i++)
  {
    //found item
    if(info[i] == item)
    {
      //because when insert item length prepares for next index thus last value inserted is in length-1
      info[i] = info[--length];
    }
  }
}

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
}

template <class x>
void ulist<x> :: printList()
{
   cout << "\nThe LIST \n" ;
   for(int i = 0 ; i < length ; i++)
  {
     cout << info[i] << endl;
  }
}
