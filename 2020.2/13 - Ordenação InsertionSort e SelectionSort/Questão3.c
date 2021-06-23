#include <stdio.h>
#include <stdlib.h>

void insertionSort(char l[], int tam) {
  for (int i = 1; i < tam; i++) {
    int eleito = l[i];
    int j = i - 1;

    while (j >= 0 && l[j] > eleito) {
      l[j + 1] = l[j];
      j = j - 1;
    }
    l[j + 1] = eleito;
  }

  return;
}

int main(void) {
  char l[] = {'e', 'c', 'a', 'd', 'b'};
  int tam = 5;

  insertionSort(l, tam);

  for (int i = 0; i < tam; i++)
    printf("%c ",l[i]);
  
    return 0;
}
