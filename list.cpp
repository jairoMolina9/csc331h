#include "list.h"

//O(1)
arrayList::arrayList()
{
  //initializes default length
  length = 0;
}

//O(1)
void arrayList::makeEmpty()
{
  //makes it "empty", by starting from beginning
  length = 0;
}

//O(1)
bool arrayList::isFull() const
{
  //if length is 100 return true else return false
  return (length == 100 ? 1 : 0);
}

//O(1)
int arrayList::getLength()
{
  return length;
}

//O(1)
void arrayList::insertItem(int item)
{

  if(isFull())
  {
    return;
  }

  //item will be inserted in the array index based on variable length
  data[length] = item;
  length++;

}

//O(n)
void arrayList::deleteItem(int item)
{
  for(int i = 0 ; i < 100 ; i++)
  {
    //found item
    if(data[i] == item)
    {
      //because when insert item length prepares for next index thus last value inserted is in length-1
      data[i] = data[length-1];

      length--;
    }
  }
}

//O(n)
void arrayList::show()
{

  //only shows data inserted by user
  for(int i = 0 ; i < length ; i++)
  {
    cout << data[i] << endl;
  }
}
