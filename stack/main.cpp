/*

*/

#include "stack.cpp"
int main()
{

   string eqt = "3+2*1";

   char eqt_1 [eqt.length()];

   for(int i = 0 ; i <= eqt.length() ; i++)
   {
      eqt_1[i] = eqt[i];
   }

   int arg1 = 0;
   arg1 = eqt_1[0] - '0';
   int arg2 = 0;
   arg2 = eqt_1[2] - '0';
   int arg3 = 0;
   arg3 = eqt_1[4] - '0';

   cout << arg1 + arg2 * arg3 << endl;

}
