#include "list.h"

template <class x>
ulist<x> :: ulist(int max)
{
   length = 0;
   this->max = max;
   info = new x [max]; //dynamic array
}

template <class x>
ulist<x> :: ~ulist()
{
   delete [] info;
}

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
      info[length] = item;
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
