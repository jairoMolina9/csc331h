#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

int count_swaps = 0;
int count_compare = 0;

/* Sets array A and B to original values */
void readOriginal(int arr_a[], int arr_b[], fstream &originalFile) {
  originalFile.seekp(ios::beg);
  for (int i = 0; i < 1000; i++) {
    if (i < 100)
      originalFile >> arr_a[i];
    originalFile >> arr_b[i];
  }
}

/* Function to swap two elements */
void swap(int *element_a, int *element_b) {
  int temp = *element_a;
  *element_a = *element_b;
  *element_b = temp;
  count_swaps++;
}

/* Write array sorted data to txt file */
void writeSorted(int arr[], int size, ostream &dataFile) {

  for (int i = 0; i < size; i++) {
    dataFile << arr[i] << endl;
  }
  dataFile << "Total Swaps: " << count_swaps << endl;
  dataFile << "Total Comparisons: " << count_compare << endl;
}

/* Selection Sort Algorithm */
void selectionSort(int arr[], int size, ofstream &dataFile) {
  dataFile << "**** Selection Sort ****" << endl;
  count_swaps = 0;

  int i, j, min_i;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < size - 1; i++) {
    // Find the minimum element in unsorted array
    min_i = i;
    for (j = i + 1; j < size; j++)
      if (arr[j] < arr[min_i])
        min_i = j;

    // Swap the found minimum element with the first element
    swap(&arr[min_i], &arr[i]);
  }
  writeSorted(arr, size, dataFile);
}

void regularSort(int arr[], int size, char option) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (option == 'a') {
        if (arr[i] > arr[j]) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      } else if (option == 'd') {
        if (arr[i] < arr[j]) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
}

/* Random values to Array */
void optionA(fstream &originalData) {
  for (int i = 0; i < 1100; i++)
    originalData << rand() % 100 + 1 << endl;
}

/* Sorts arrays for menu option */
void optionB(fstream &originalData) {
  int tmp_A[100];
  int tmp_B[1000];
  originalData.seekp(ios::beg);
  // set random array
  for (int i = 0; i < 1000; i++) {
    if (i < 100)
      tmp_A[i] = rand() % 100 + 1;

    tmp_B[i] = rand() % 100 + 1;
  }

  // sort 90% asceding
  regularSort(tmp_A, (100 * 90) / 100, 'a');
  regularSort(tmp_B, (1000 * 90) / 100, 'a');

  // write into file
  for (int i = 0; i < 1000; i++) {
    if (i < 100)
      originalData << tmp_A[i] << endl;

    originalData << tmp_B[i] << endl;
  }
}

/* Reverse order and same as option B */
void optionC(fstream &originalData) {
  int tmp_A[100];
  int tmp_B[1000];

  originalData.seekp(ios::beg);

  // set random array
  for (int i = 0; i < 1000; i++) {
    if (i < 100)
      tmp_A[i] = rand() % 100 + 1;

    tmp_B[i] = rand() % 100 + 1;
  }

  // sort 90% asceding
  regularSort(tmp_A, (100 * 90) / 100, 'd');
  regularSort(tmp_B, (1000 * 90) / 100, 'd');

  // write into file
  for (int i = 0; i < 1000; i++) {
    if (i < 100)
      originalData << tmp_A[i] << endl;

     originalData << tmp_B[i] << endl;
  }
}

/* Function that calls all sorting functions */
void algorithms(fstream &originalData) {
  // sizes of arrays
  int size_a = 100, size_b = 1000;

  // declare arrays
  int arr_a[size_a], arr_b[size_b];

  // declare files for sorted
  ofstream data_A, data_B;

  // open files
  data_A.open("data_A.txt", ostream::out | ostream::trunc);
  data_B.open("data_B.txt", ostream::out | ostream::trunc);

  // Selection sort
  readOriginal(arr_a, arr_b, originalData);
  selectionSort(arr_a, size_a, data_A);
  selectionSort(arr_b, size_b, data_B);

  // Insertion Sort
  readOriginal(arr_a, arr_b, originalData);

  data_A.close();
  data_B.close();
}

int main() {
  srand(time(NULL));

  fstream originalData;

  originalData.open("originalData.txt");

  char option;
  cout << "Enter an option:\n";
  cout << "a) completely random\n";
  cout << "b) 90% increasing order, 10% random\n";
  cout << "c) reversed and same as b\n";
  cout << "d) sorted array except for 10%\n";

  cin >> option;

  switch (tolower(option)) {
  case 'a':
    optionA(originalData);    // creates data for option A
    algorithms(originalData); // calls sorting functions
    break;
  case 'b':
    optionB(originalData);    // creates data for option B
    algorithms(originalData); // calls sorting functions
    break;
  case 'c':
    optionC(originalData);    // creates data for option C
    algorithms(originalData); // calls sorting functions
    break;
  case 'd':
    optionB(originalData);    // creates data for option D
    algorithms(originalData); // calls sorting functions
  default:
    break;
  }

  originalData.close();
  return 0;
}
