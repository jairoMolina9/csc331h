/*
  Jairo Molina
  ArrayBased list
  2019
*/

#include <time.h>
#include "list.h"

int main()
{

  srand(time(NULL));

  arrayList arr1;

  for(int i = 0 ; i < 5 ; i++)
  {
    arr1.insertItem( rand() % 100 + 1 );
  }

  arr1.show();

  arr1.deleteItem(4);

  cout << "\nupdated \n\n";

  arr1.show();

}
