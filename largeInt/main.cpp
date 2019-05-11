#include "largeInt.cpp"

int main() {

  LargeInt<int> A;
  cout << "Enter values List A: " << endl;
  cin >> A;


  LargeInt<int> B;
  cout << "Enter values List B: " << endl;
  cin >> B;

   LargeInt<int> R;
   R = A/B;
   cout << R;

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
