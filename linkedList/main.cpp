/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti

   LargeInt Project
   "main.cpp"

   --------------------------------------------
               <In this File>

   I created a Menu to test each function from
   the List class, as well as commented how to
   test the copy constructor and operator =

   --------------------------------------------
*/

#include "linkedList.cpp"

/*Prototype of the functions for the Menu*/
template <class type> void insert(List<type> &);

template <class type> void print(List<type> &);

template <class type> void search(List<type> &);

template <class type> void delete_item(List<type> &);

void checkInput(int &, int);

int main() {
  /* Uncomment lines 25 - 40 to test copy constructor and = operator */
  //  cout << "\nTESTING COPY CONSTRUCTOR & OPERATOR= " << endl;
  //  cout << "\n";
  //
  //  List<int> l2;
  //  cout << "Random values\n" << endl;
  //  l2.insert_front(3);
  //  l2.insert_front(2);
  //  l2.insert_front(1);
  //  cout << "List 1: " << endl;
  //  l2.printFromFront();
  //  List<int> l3;
  //  l3 = l2;
  //  cout << "\nList 2: " << endl;
  //  l3.printFromFront();
  // cout << "END OF TESTING" << endl;
  // cout << "\n\n";

  List<int> l1;

  int option = 0;

  /*MENU*/
  do {
    cout << "Enter an option: " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Print" << endl;
    cout << "-1 to Exit" << endl;

    cin >> option;
    // validates option and second arguments sets type of error
    checkInput(option, 1);

    /*After option is validated*/
    switch (option) {
    case 1:
      insert(l1);
      break;
    case 2:
      delete_item(l1);
      break;
    case 3:
      search(l1);
      break;
    case 4:
      print(l1);
      break;
    default:
      break;
    }
  } while (option != -1); // will exit only if option = -1
}

/*------------------------------------
NOTE: Each function receives a refere
      nce to an object as a parameter,
      because this allows the menu fun
      ctions to be seperated from the
      main
-------------------------------------*/

/*Insert function*/
template <class type> void insert(List<type> &list) {
  int option;
  int input;

  cout << "From where do you wish to enter a value \n1. Front \n2. Back"
       << endl;

  cin >> option;
  // validates option and second arguments sets type of error
  checkInput(option, 2);

  cout << "Enter the value you wish to enter: ";
  cin >> input;
  // validates option and second arguments sets type of error
  checkInput(input, 3);

  if (option == 1) { // From front
    list.insert_front(input);
  } else if (option == 2) { // From back
    list.insert_back(input);
  }
}

/*Print function*/
template <class type> void print(List<type> &list) {
  int option;

  cout << "Choose a printing option \n1. Front -> Back \n2. Front <- "
          "Back \n3. Edges"
       << endl;

  cin >> option;
  // validates option and second arguments sets specific case
  checkInput(option, 4);

  /*After option is validated*/
  switch (option) {
  case 1:
    list.printFromFront();
    break;
  case 2:
    list.printFromBack();
    break;
  case 3:
    list.printEdges();
  default:
    break;
  }
}

/*Search function*/
template <class type> void search(List<type> &list) {
  int input;

  cout << "Enter the value you are looking for: " << endl;
  cin >> input;
  // validates option and second arguments sets specific case
  checkInput(input, 3);

  // receives flag return from class function search()
  bool exists = list.search(input);
  if (!exists) { // if false
    cout << "Item does not exist" << endl;
  }
}

/*Delete function*/
template <class type> void delete_item(List<type> &list) {
  int input;

  cout << "Enter the value to be deleted: " << endl;
  cin >> input;
  // validates option and second arguments sets specific case
  checkInput(input, 3);

  // receives flag return from class function delete()
  bool deleted = list.delete_item(input);
  if (!deleted) { // if flase
    cout << "Item does not exist" << endl;
  }
}

/*----------------------------------------------------------
                  <In This Function>

First argument is the value to be validated
Second arguments sets the specific type of error
Note: This does not restrict data type, it remains generic
-----------------------------------------------------------*/
void checkInput(int &value, int error) {
  switch (error) {
  case 1: // error 1
    while (cin.fail() || (value < -1 || value > 4)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1, 2, 3, 4 or -1)" << endl;
      cin >> value;
    }
    break;
  case 2: // error 2
    while (cin.fail() || (value < 1 || value > 2)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1 or 2)" << endl;
      cin >> value;
    }
    break;
  case 3: // error 3
    while (cin.fail()) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a correct value" << endl;
      cin >> value;
    }
    break;
  case 4: // error 4
    while (cin.fail() || (value < 1 || value > 3)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1, 2 or 3)" << endl;
      cin >> value;
    }
    break;
  default:
    break;
  }
}
