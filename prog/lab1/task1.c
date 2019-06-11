#include <stdio.h>
#include <stdlib.h>

void init(int **arr, int n) {
  *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    (*arr)[i] = i;
  }
}
int main() {
  int *arr, n = 10;
  init(&arr, n);
  for (int i = 0; i < n; i++) {
	printf("%d\n", arr[i]);
  }
  free(arr);
  return 0;
}