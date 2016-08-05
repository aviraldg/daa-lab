#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))


void find_max_min(int *A, int l, int r, int *min, int *max) {
  if(l == r) {
    *min = *max = A[l];
  } else {
    int lmin, lmax, rmin, rmax, mid;
    mid = (l + r)/2;
    find_max_min(A, l, mid, &lmin, &lmax);
    find_max_min(A, mid + 1, r, &rmin, &rmax);
    *min = MIN(lmin, rmin);
    *max = MAX(lmax, rmax);
  }
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  
  int A[N];
  for(int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  
  int min, max;
  find_max_min(A, 0, N-1, &min, &max);
  
  printf("max = %d, min = %d\n", max, min);
    
  return EXIT_SUCCESS;
}

