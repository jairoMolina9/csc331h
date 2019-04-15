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
  count_compare = 0;

  int i, j, min_i;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < size - 1; i++) {
    // Find the minimum element in unsorted array
    min_i = i;
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_i]) {
        min_i = j;
        count_compare++;
      }
    }
    // Swap the found minimum element with the first element
    swap(&arr[min_i], &arr[i]);
  }
  writeSorted(arr, size, dataFile);
}

/* Insertion Sort Algorithm */
void insertionSort(int arr[], int size, ofstream &dataFile) {
   dataFile << "**** Insertion Sort ****" << endl;
   count_swaps = 0;
   count_compare = 0;
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
           swap(&arr[j+1], &arr[j]);
            j = j - 1;
            count_compare++;
        }
        swap(&arr[j+1], &key);
    }
     writeSorted(arr, size, dataFile);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int size, int i)  {
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < size && arr[l] > arr[largest]) {
        largest = l;
        count_compare++;
     }

    // If right child is larger than largest so far
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
        count_compare++;
     }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        count_compare++;
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int size, ofstream &dataFile) {
   dataFile << "**** Heap Sort ****" << endl;
   count_swaps = 0;
   count_compare = 0;
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // One by one extract an element from heap
    for (int i=size-1; i>=0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    writeSorted(arr, size, dataFile);
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            count_compare++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            count_compare++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {

    if (l < r)
    {
      count_compare++;
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
           count_compare++;
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high)
    {
      count_compare++;
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
    if (i < 100){
      originalData << tmp_A[i] << endl; //1 to 90 sorted 90 100 random
}else
    originalData << tmp_B[i-100] << endl;//100 900 sorted 900 1000 random
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
  insertionSort(arr_a, size_a, data_A);
  insertionSort(arr_b, size_b, data_B);

  // Heap Sort
  readOriginal(arr_a, arr_b, originalData);
  heapSort(arr_a, size_a, data_A);
  heapSort(arr_b, size_b, data_B);

  // Merge Sort
  //easier to reset global variables and
  //set the title of sorting here because
  //algorithm is in recursion and otherwise would
  //constantly reset and print to file
  readOriginal(arr_a, arr_b, originalData);
  count_swaps = 0;
  count_compare = 0;
  data_A << "**** Merge Sort ****" << endl;
  mergeSort(arr_a, 0, size_a - 1);
  writeSorted(arr_a, size_a, data_A);
  data_B << "**** Merge Sort ****" << endl;
  mergeSort(arr_b, 0, size_b - 1);
  writeSorted(arr_a, size_a, data_B);

  // Quick Sort
  //easier to reset global variables and
  //set the title of sorting here because
  //algorithm is in recursion and otherwise would
  //constantly reset and print to file
  readOriginal(arr_a, arr_b, originalData);
  count_swaps = 0;
  count_compare = 0;
  data_A << "**** Quick Sort ****" << endl;
  quickSort(arr_a, 0, size_a - 1);
  writeSorted(arr_a, size_a, data_A);
  data_B << "**** Quick Sort ****" << endl;
  quickSort(arr_b, 0, size_b - 1);
  writeSorted(arr_a, size_a, data_B);

  data_A.close();
  data_B.close();
}

int main() {
  srand(time(NULL));

  fstream originalData;

  originalData.open("originalData.txt");

  char option;
  do{
  cout << "Enter an option:\n";
  cout << "a) completely random\n";
  cout << "b) 90% increasing order, 10% random\n";
  cout << "c) reversed and same as b\n";
  cout << "d) sorted array except for 10%\n";
  cout << "x) to exit\n";

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
  if(option == 'a' || option == 'b' || option == 'c' || option == 'd')
  cout << "\n VALUES INSERTED IN FILE \n" <<endl;

}while(option != 'x' && option != 'X');

  originalData.close();
  return 0;
}
