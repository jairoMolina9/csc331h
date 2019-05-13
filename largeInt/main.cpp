/*
   Jairo Molina
   molinaandres9991@gmail.com
   CSC 331H. Prof Salvatti
   LargeInt Project
   "main.cpp"
   --------------------------------------------
               <In this File>
   Two menus to test large int arithmetic and 
   conditional expressions:
   - R = A + B
   - R = A - B
   - R = A * B
   - R = A / B
   - R = A % B
   - > , < , <= , >= , ==
 *
   --------------------------------------------
*/

#include "largeInt.h"

void calc(int);
void menu_2();
void menu(char);
void setNumbers(LargeInt&, LargeInt&);


int main() {
char option;

do{

  
   string text = "1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n6.Conditions\n0.Exit\n";
   cout << text << "Enter: ";
   
   cin >> option;
   
   menu(option);
   
}while (option != '0');

cout << "GOODBYE" << endl;

}


/* INSERT VALUES */
void setNumbers(LargeInt& A, LargeInt& B){
   cout << "\nFirst enter values List 1: " << endl;
   cin >> A;

   cout << "\nFirst enter values List 2: " << endl;
   cin >> B;
}

/* PERFORMS SPECIFIC EXPRESSION */
void calc(int opt){
   
   LargeInt A;
   LargeInt B;
   
   LargeInt R;

   setNumbers(A, B);
   
   switch(opt){
       case '1':
           cout << "\n\tADDITION\t" << endl;
            R = A+B;
            cout << R;
            break;
       case '2':
           cout << "\n\tSUBTRACTION\t" << endl;
           R = A-B;
           cout << R;
           break;
       case '3':
           cout << "\n\tMULTIPLY\t" << endl;
           R = A*B;
           cout << R;
           break;
       case '4':
           cout << "\n\tDIVIDE\t" << endl;
           R = A/B;
           cout << R;
           break;
       case '5':
           cout << "\n\tMODULUS\t" << endl;
           R = A%B;
           cout << R;
           break;
       case '6':
           menu_2();
       default:
           break;
   }
}

/* DISPLAYS ARITHMETIC MENU */
void menu(char opt){

   switch(opt){
      case '1':
          calc(opt);
          break;
      case '2':
          calc(opt);
          break;
      case '3':
          calc(opt);
          break;
      case '4':
          calc(opt);
          break;
      case '5':
          calc(opt);
          break;
      case '6':
          menu_2();
      default:
          break;

   }

}

/* DISPLAYS CONDITIONS MENU */
void menu_2(){
    
   LargeInt A;
   LargeInt B;

   setNumbers(A, B);
   
   char opt;
   string out;
    
 
   
   do{  
       string text = "1. >\n2. <\n3. >=\n4. <=\n5. ==\n0.Back\n";
   cout << text << "Enter: ";
   
   cin >> opt;
       
   switch(opt){
      case '1':
          (A>B) ? out = "A bigger than B" : out = "A not bigger than B";
      break;
      case '2':
          (A<B) ? out = "A less than B" : out = "A not less than B";
      break;
      case '3':
          (A>=B) ? out = "A bigger/equal than B" : out = "A not bigger/equal than B";
      break;
      case '4':
          (A<=B) ? out = "A less/equal than B" : out = "A not less/equal than B";
      break;
      case '5':
          (A==B) ? out = "A equal than B" : out = "A not equal than B";
      default:
      break;
   }
   
   cout << "\t" << out << endl;
   }while( opt != '0');
   
   

}
