#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int l, int r, int p) {
  int i = l, j = r;
  while(i < j) {
    for(; A[i] < p && i < j; i++);
    for(; A[j] > p && j > i; j--);
    if(i >= j) break;
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
  }
  return i;
}

void quicksort(int *A, int l, int r) {
  if(l >= r) return;
  else {
    int p = A[l];
    int m = partition(A, l, r, p);
    quicksort(A, l, m - 1);
    quicksort(A, m + 1, r);
  } 
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  
  int A[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  quicksort(A, 0, N-1);
  
  for(int i=0; i<N; i++) {
    printf("%d ", A[i]);
  }
  putchar('\n');
    
  return EXIT_SUCCESS;
}

