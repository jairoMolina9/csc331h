#include "linkedList.h"

template <class dataType>
List<dataType> :: List()
{
   this->data = 0;
   this->head = nullptr;

}

template <class dataType>
void List<dataType> :: insertNode(dataType data)
{
   node<dataType> *new_head;
   new_head = new node<dataType>;

   new_head->data = data;
   new_head->next = head;
   head = new_head;

}

template <class dataType>
void List<dataType> :: deleteItem(dataType data)
{

   node<dataType> *local_head = this->head;

   if(head->data == data)
   {
      head = head->next;
      delete local_head;

      return;
   }

   while(local_head!=nullptr)
   {
      if(local_head->data == data)
      {
         node<dataType> *temp = local_head->next;
         local_head = temp->next;
         delete temp;

         return;
      }
      else
         local_head = local_head->next;
   }

   /*
   while(p->next != nullptr && p->next->data != data)
   {
   p = p->next;
   if(p->next == nullptr )
   {
   cout << "item not found";
}
else{
node<dataType> *t = p->next;
p->next = t->next;
delete t;
length--;
}
   }
   */


}

//overloading =
/*
if(this!=&other)
{
makeEmpty();
copy(other);
}

*/



//copy constructor
template <class dataType>
List<dataType> :: List(const List<dataType>& other)
{
   if(other.length == 0)
   {
      head = nullptr;
      length =0;
   }
   else{
      node<dataType> *s = other.first;
      length = other.length;

      head = new node<dataType>;
      head->info = s->info;

      node<dataType> *t = head;

      while(s->next != nullptr)
      {
         t->next = new node<dataType>;
         t = t->next;

         s = s->next;
         t->info = s->info;
      }

   }
}

template <class dataType>
List<dataType> :: ~List()
{
   node<dataType> *local_head;
   while(head!=nullptr)
   {
      local_head = head;
      head = head->next;
      delete local_head;

   }
}

template <class dataType>
void List<dataType> :: printList()
{
   //create a local head pointing at the head address
   node<dataType> *local_head = this->head;

   int i = 1;
   while(local_head){

      //print out data
      cout << i << ": " << local_head->data << endl;

      //local pointer address now points at next node
      local_head = local_head->next;
      i++;
   }
}

template <class dataType>
bool List<dataType> :: search(dataType data)
{
   //create a local head pointing at the head address
   node<dataType> *local_head = this->head;

   bool exists = false;

   //must follow this because if pointer is null then there
   //cant be data
   // while(local_head && p->data <= item)
   while(local_head && local_head->data != data){

      if(local_head->info == data)
      exists = true;

      local_head = local_head->next;

   }

   return exists;
}
