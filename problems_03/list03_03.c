/*
FEDERAL UNIVERSITY OF AMAZONAS - UFAM
IE08 - BACHELOR'S IN COMPUTER SCIENCE 
ICC014 - LAB. OF ADVANCED PROGRAMMING - 2019/01
LIST 03 - CHALLENGE 03
STUDENT - MARCOS AVNER PIMENTA DE LIMA

Screws & Nuts

Pedro is working on a new job at a screw and nut store. Every week he will receive new orders for mixed screws in large boxes and need to know where he should store those products.

Mango, who is Pedro's supervisor, asked him to arrange all the bolts and nuts in a huge rack so that it is easy to respond where it is possible to find each predetermined batch of screws and how much each of these lots the store has.

Pedro receives all the bolts and nuts in boxes labeled with the product size range. For example, two boxes with the respective ranges (1, 2) and (4, 8) represent batches of products of size (1, 2, 4, 5, 6, 7, 8). A number of bolt and nut may be present in more than one box, and it appears in the list once for each interval. For example, three boxes with their respective ranges (1, 3), (2, 4) and (3,5) represent lots of bolts and nuts of size (1, 2, 2, 3, 3, 3, 4, 4 , 5).

Use QuickSort for Sorting and Binary Search

Input

The input starts with the number M (M <100) of test cases. Each test case consists of several lines. The first line contains a positive integer N (N <100) which indicates the number of screw boxes. Following are N rows, each with two X and Y values ​​(1 ≤ X <Y ≤ 100) representing the sizes of the batches of bolts and nuts present in that box. The next entry line will contain a single positive integer Num (1 ≤ Num ≤ 100), which indicates the number that Mango wants to search after all the products are organized on the rack or rack.

Note The shelf or rack has shelves listed from 0 to P, this P must not exceed 1000.

Output

Each input case should produce a single output line, indicating the positions of the shelf on which the Num screw is located or indicating that the screw could not be found, as shown in the example below.

EXAMPLE
INPUT
3
3
1 3
2 4
3 5
4
4
1 3
2 4
1 5
3 6
3
2
1 3
3 5
7

OUTPUT
4 found from 6 to 7
3 found from 5 to 8
7 not found
*/

#include <stdio.h>
#include <stdlib.h>

short binarySearch(unsigned char v[], short inicio, short fim, unsigned char valor)  { 
  if (fim >= inicio) {
    short mid = inicio + (fim - inicio) / 2; 
  
    // If the element is present at the middle itself 
    if (v[mid] == valor) {
      while ((mid > 0) && (v[mid-1] == valor))
        mid--;
      return mid;
    } 
  
    // If element is smaller than mid, then 
    // it can only be present in left subarray 
    if (v[mid] > valor) 
      return binarySearch(v, inicio, mid - 1, valor); 
  
    // Else the element can only be present in right subarray 
    return binarySearch(v, mid + 1, fim, valor); 
  } 
  
  // We reach here when element is not present in array 
  return -1;
} 

void qSortInterno(unsigned char v[], short inicio, short fim) {
  unsigned char pivot, temp;
  short i,j;

  if(fim - inicio > 0) { /* tem mais de 1 elemento */
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2];
    
      do {
        while(v[i] < pivot) i++; /* procura por algum item do lado errado  >= pivot */
        while(v[j] > pivot) j--; /* procura por algum item do lado errado <= pivot */
        
        if(i<= j) { /* deixa o igual para garantir que ao final i<j */
          temp = v[i];
          v[i] = v[j];
          v[j] = temp;
          i++; j--;
        }
      } while (i<=j);
    
      qSortInterno(v, inicio, j);
      qSortInterno(v, i,fim);
    }
}

void quickSort(unsigned char v[], short n) {
  qSortInterno(v, 0, n-1);
}

int main() {
  short m, cx, pos;
  unsigned char *ranges, *parafusos, valor;
  short n = 0, i, j;
  
  scanf("%hd", &m);
  while (m > 0) {
    scanf(" %hd", &cx);
    cx *= 2;

    ranges = (unsigned char *)malloc(sizeof(unsigned char) * cx);
    for(i = 0; i < cx; i += 2) {
      scanf(" %hhu %hhu", &ranges[i], &ranges[i+1]);
      n += (ranges[i+1] - ranges[i]) + 1;
    }
    
    parafusos = (unsigned char *)malloc(sizeof(unsigned char) * n);
    j = 0;
    for (i = 0; i < cx; i += 2) {
      while (ranges[i] <= ranges[i+1]) {
        parafusos[j] = ranges[i];
        ranges[i]++;
        j++;
      }
    }
    free(ranges);
    
    scanf(" %hhu", &valor);
    quickSort(parafusos, n);
    
    pos = binarySearch(parafusos, 0, n, valor);
    
    if (pos >= 0) {
      printf("%hhu found from %hd to ", valor, pos);
      while ((pos < n) && (parafusos[pos] == valor))
        pos++;
      printf("%hd\n", (short)(pos-1));
    } else {
      printf("%hd not found\n", valor);  
    }    

    free(parafusos);
    n = 0;
    m -= 1;
  }
  
  return 0;
}