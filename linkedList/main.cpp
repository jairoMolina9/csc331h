/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti

   LargeInt Project
   "main.cpp"
*/

#include "linkedList.cpp"

template <class type> void insert(List<type> &);

template <class type> void print(List<type> &);

template <class type> void search(List<type> &);

template <class type> void delete_item(List<type> &);

void checkInput(int &, int);

int main() {
   // Erase the comments between 24 - 39 to test copy constructor and = operator
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

  do {
    cout << "Enter an option: " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Search" << endl;
    cout << "4. Print" << endl;
    cout << "-1 to Exit" << endl;

    cin >> option;
    checkInput(option, 1);

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
  } while (option != -1);
}

template <class type> void insert(List<type> &list) {
  int option;
  int input;

  cout << "From where do you wish to enter a value \n1. Front \n2. Back"
       << endl;

  cin >> option;
  checkInput(option, 2);

  cout << "Enter the value you wish to enter: ";
  cin >> input;
  checkInput(option, 3);

  if (option == 1) {
    list.insert_front(input);
  } else if (option == 2) {
    list.insert_back(input);
  }
}

template <class type> void print(List<type> &list) {
  int option;

  cout << "Choose a printing option \n1. Front -> Back \n2. Front <- "
          "Back \n3. Edges"
       << endl;

  cin >> option;
  checkInput(option, 4);

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

void checkInput(int &option, int error) {
  switch (error) {
  case 1:
    while (cin.fail() || (option < -1 || option > 4)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1, 2, 3, 4 or -1)" << endl;
      cin >> option;
    }
    break;
  case 2:
    while (cin.fail() || (option < 1 || option > 2)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1 or 2)" << endl;
      cin >> option;
    }
    break;
  case 3:
    while (cin.fail()) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a correct value" << endl;
      cin >> option;
    }
    break;
  case 4:
    while (cin.fail() || (option < 1 || option > 3)) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Enter a valid option: ( 1, 2 or 3)" << endl;
      cin >> option;
    }
    break;
  default:
    break;
  }
}

template <class type> void search(List<type> &list) {
  int input;

  cout << "Enter the value you are looking for: " << endl;
  cin >> input;
  checkInput(input, 3);

  //    list.search(input);

  bool check = list.search(input);
  if (!check) {
    cout << "Item does not exist" << endl;
  }
}

template <class type> void delete_item(List<type> &list) {
  int input;

  cout << "Enter the value to be deleted: " << endl;
  cin >> input;
  checkInput(input, 3);
  bool check = list.delete_item(input);
  if (!check) {
    cout << "Item does not exist" << endl;
  }
}
