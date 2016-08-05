#include <stdio.h>
#include <stdlib.h>

int _bsearch(int *A, int l, int r, int v) {
  if(l > r) {
    return -1;
  } else {
    int m = (l + r)/2;
    if(A[m] == v) {
      return m;
    } else if (v < A[m]) {
      return _bsearch(A, l, m, v);
    } else {
      return _bsearch(A, m+1, r, v);
    }
  }
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  
  int A[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  int v;
  scanf("%d", &v);
  
  int i = _bsearch(A, 0, N-1, v);
  printf("i = %d\n", i);
    
  return EXIT_SUCCESS;
}

