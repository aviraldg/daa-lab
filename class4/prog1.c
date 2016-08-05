#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  
  int A[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  for(int i=1; i<N; i++) {
    int e = A[i];
    int j;
    for(j=i-1; j >= 0 && A[j] > e; j--) {
      A[j+1] = A[j];
    }
    A[j+1] = e;
  }
  
  for(int i=0; i<N; i++) {
    printf("%d ", A[i]);
  }
  putchar('\n');
    
  return EXIT_SUCCESS;
}

