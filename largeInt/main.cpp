#include "largeInt.h"

int main() {
  largeInt<int> A;
  cout << "Enter values: " << endl;
  cin >> A;
  
  largeInt<int> B;
  cout << "Enter values (2): " << endl;
  cin >> B;
  
  largeInt<int> R;
  cout << "Value -> ";
  R = A+B;
  cout << "Result: " << endl;  
  R.printValues();
 
  
}
