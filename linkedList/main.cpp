// Example of linked list
//
// Jairo Molina

#include "linkedList.cpp"

template <class type> void insert(List<type> &);

template <class type> void print(List<type> &);

int main() {
  List<int> l2;
  l2.insert_front(3);
  l2.insert_front(2);
  l2.insert_front(1);
  List<int> l3;
  l3 = l2;


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

    switch (option) {
    case 1:
      insert(l1);
      break;
    case 2:
      break;
    case 3:
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
  int option = 0;
  int input;

  cout << "From where do you wish to enter a value \n1. Front \n2. Back"
       << endl;
  cin >> option;

  cout << "Enter the value you wish to enter: ";
  cin >> input;

  if (option == 1) {
    list.insert_front(input);
  } else if (option == 2) {
    // list.insert_back(input);
  }
}

template <class type> void print(List<type> &list) {
  int option;

  cout << "Choose what you desire to print \n1. Front -> Back \n2. Front <- "
          "Back \n3. Edges"
       << endl;

  cin >> option;

  if (option == 1) {
    list.printFromFront();
  } else if (option == 2) {
    // list.printFromBack(input);
  } else if (option == 3) {
    list.printEdges();
  }
}
