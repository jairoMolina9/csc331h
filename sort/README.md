<h1> Project Specs </h1>
<p> <b> External Files </b><br>
    <ul>
    <li><i>originalData.txt</i> :<br>This file has the data
                              generated depending on the
                              user's option, it does not change
                              throughout the program, it is repeatedly
                              retrieved everytime a sorting algorithm is 
                              successfully finished. This allows the program to
                              test each algorithm with the same set of random data.
                              </li>
   <li><i>data_A.txt</i> :<br> This file stores the sorted data
                               that is processed using array_A after
                               the sorting algorithms are called, the file
                               only stores the sorted data for array_A which is
                               the array with a size of <b>100</b>. Keep in mind that the
                               array_A is reset to the data from the <i>originalData.txt
                               </i>after it is inserted into this file. This file also contains
                               the exact amount of swaps and comparisons that the algorithm performed.
                               </li>
   <li><i>data_B.txt</i> :<br> This file stores the sorted data
                               that is processed using array_B after
                               the sorting algorithms are called, the file
                               stores the sorted data for array_B which has a 
                               maximun size of <b>1000</b>. Keep in mind that the array_B
                               is reset to the data from the <i>originalData.txt</i> after it
                               is inserted into this file. This file also contains the exact amount 
                               of swaps and comparisons that the algorithm performed.
                               </li>
   </ul>
  <p> <b> Sorting Algorithms </b><br>
<ul> 
      <li> Selection Sort </li>
      <li> Insertion Sort </li>
      <li> Heap Sort </li>
      <li> Merge Sort </li>
      <li> Quick Sort </li> 
     
</ul>
<p> <b> Software Notes </b><br>
<ul> 
     <li> Menu that contains 3 different random number distributions 
       <ul>
         <li> a) Completely Random </li>
         <li> b) Sorted in ascending order, 90% only</li>
         <li> c) Reversed and same as b </li>
         <li> d) Sorted except for last 10% </li>
      </ul>
    </li>
</ul>

   
