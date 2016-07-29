#include <stdio.h>
#include <stdlib.h>

int *A;

int main(int argc, char *argv[]) {
  int N, E;
  scanf("%d %d", &N, &E);
  A = malloc(sizeof(int) * N * N);

  int i, j;
  for(i=0; i<E; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    A[N*a + b] = 1;
    A[N*b + a] = 1;
  }
  
  for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
      printf("%d ", A[N*i + j]);
    }
    putchar('\n');
  }
  putchar('\n');
  
  return EXIT_SUCCESS;
}

