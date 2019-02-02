/*
  Jairo Molina
  ArrayBased list
  2019
*/

#include <time.h>
#include "list.cpp"

void startMenu(ulist <int> &);
void printList(ulist <int> &);
void insertItem(ulist <int> &);
void deleteItem(ulist <int> &);
void searchItem(ulist <int> &);

int main()
{

  int max;

  cout << "Enter max amount" << endl;
  cin >> max;

  ulist <int> l1(max);

  startMenu(l1);

}

void startMenu(ulist <int> &l2)
{
   int option = 0;

   while(option != -1)
   {
         cout << "\nEnter option \n1. Insert \n2. Delete \n3. Search \n4. Print\n\nTO END TYPE -1\n";
         cin >> option;

      switch(option)
      {

         case 1:
                insertItem(l2);
                break;
         case 2:
                deleteItem(l2);
                break;

         case 3:
                searchItem(l2);
                break;

         case 4:
                printList(l2);
                break;
         default:
                break;

      }
   }
}

void insertItem(ulist <int> &l2)
{

   int item;
   cout << "\nInsert number : " << endl;
   cin >> item;

   l2.insertItem(item);

}

void deleteItem(ulist <int> &l2)
{
   int item;
   cout << "\nInsert number : " << endl;
   cin >> item;

   l2.deleteItem(item);
}

void searchItem(ulist <int> &l2)
{
   int item;

   cout << "\nInsert number: " << endl;
   cin >> item;

   bool found = l2.searchItem(item);

   (found) ? cout << "\n" << item << " exists on the list\n" : cout << "\n" << item << " does not exist\n";
}

void printList(ulist <int> &l2)
{
   cout << endl;
   l2.printList();
}
