#include "largeInt.cpp"

int main() {
  LargeInt<int> A;
  cout << "Enter values: " << endl;
  cin >> A;

  LargeInt<int> B;
  cout << "Enter values (2): " << endl;
  cin >> B;

  LargeInt<int> R;
  cout << "Value -> ";
  R = A+B;
  cout << "Result: " << endl;
  R.printValues();


}
