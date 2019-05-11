#include "largeInt.cpp"

void menu_2();
void menu(char);
void setNumbers(LargeInt<int>&, LargeInt<int>&);

int main() {
char option = '0';  //default

do{

   menu(option);

   cin >> option;

}while (option != 0);


  // LargeInt<int> A;
  // cout << "Enter values List A: " << endl;
  // cin >> A;
  //
  //
  // LargeInt<int> B;
  // cout << "Enter values List B: " << endl;
  // cin >> B;
  //
  //  LargeInt<int> R;
  //  R = A%B;
  //  cout << R;

// if(A==B)
//     cout << "\nEqual" << endl;
//
// if(A<B)
//     cout << "\nLess" << endl;

// if(A>B)
//     cout << "\nBigger" << endl;

// if(A>=B)
//     cout << "\nBigger or Equal" << endl;
//
// if(A<=B)
//     cout << "\nLess or Equal" << endl;
}

void add(){
   cout << "\n\tADDITION\t" << endl;
   LargeInt<int> A;
   LargeInt<int> B;
   LargeInt<int> R;

   setNumbers(A, B);

   R = A+B;
   cout << R;
}

void setNumbers(LargeInt<int>& A, LargeInt<int>& B){
   cout << "\nEnter values List A: " << endl;
   cin >> A;

   cout << "\nEnter values List B: " << endl;
   cin >> B;
}

void menu(char opt){
   string text = "1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n6.Conditions\n0.Exit\n";
   cout << text << "Enter: ";

   switch(opt){
      case '1':
      add();
      break;
      case '2':
      break;
      case '3':
      break;
      case '4':
      break;
      case '5':
      break;
      case '6':
      menu_2();
      default:
      break;

   }

}

void menu_2(){
   char opt = 'D';//default
   string text = "1. >\n2. <\n3. >=\n 4. <=\n 5. ==\n0.Back\n";
   cout << text << "Enter: ";

   switch(opt){
      case '1':
      break;
      case '2':
      break;
      case '3':
      break;
      case '4':
      break;
      case '5':
      default:
      break;
   }

}
