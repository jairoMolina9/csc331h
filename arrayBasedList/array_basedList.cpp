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

  ulist <int> list_1(max);

  startMenu(list_1);
  
  ulist<int> list_2(max);
  
  list_2 = list_1;
  list_2.printList();
  

}

void startMenu(ulist <int> &list_1)
{
   int option = 0;

   while(option != -1)
   {
         cout << "\nEnter option \n1. Insert \n2. Delete \n3. Search \n4. Print\n\nTO END TYPE -1\n";
         cin >> option;

      switch(option)
      {

         case 1:
                insertItem(list_1);
                break;
         case 2:
                deleteItem(list_1);
                break;

         case 3:
                searchItem(list_1);
                break;

         case 4:
                printList(list_1);
                break;
         default:
                break;

      }
   }
}

void insertItem(ulist <int> &list_1)
{

   int item;
   cout << "\nInsert number : " << endl;
   cin >> item;

   list_1.insertItem(item);

}

void deleteItem(ulist <int> &list_1)
{
   int item;
   cout << "\nInsert number : " << endl;
   cin >> item;

   list_1.deleteItem(item);
}

void searchItem(ulist <int> &list_1)
{
   int item;

   cout << "\nInsert number: " << endl;
   cin >> item;

   bool found = list_1.searchItem(item);

   (found) ? cout << "\n" << item << " exists on the list\n" : cout << "\n" << item << " does not exist\n";
}

void printList(ulist <int> &list_1)
{
   cout << endl;
   list_1.printList();
}
