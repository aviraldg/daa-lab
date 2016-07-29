#include <stdio.h>
#include <stdlib.h>

int *A;

int main(int argc, char *argv[]) {
  int N, E;
  scanf("%d %d", &N, &E);
  A = malloc(sizeof(int) * N * N);

  int i, j;
  for(i=0; i<E; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    A[N*a + b] = w;
    A[N*b + a] = w;
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

