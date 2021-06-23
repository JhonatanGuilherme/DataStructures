#include <stdio.h>
#include <stdlib.h>

void intercala(char l[], int ini, int fim, int meio) {
  int aux[fim - ini + 1], p_aux = 0;
  int ini1 = ini, ini2 = meio + 1;

  while ((ini1 <= meio) && (ini2 <= fim)) {
    if (l[ini1] <= l[ini2])
      aux[p_aux] = l[ini1++];
    else
      aux[p_aux] = l[ini2++];
    p_aux++;
  }

  for (int i = ini1; i <= meio; i++)
    aux[p_aux++] = l[i];

  for (int i = ini2; i <= fim; i++)
    aux[p_aux++] = l[i];

  for (int i = ini, j = 0; i <= fim; i++, j++)
    l[i] = aux[j];
  
  return;
}

void mergeSort(char l[], int ini, int fim) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(l, ini, meio);
    mergeSort(l, meio + 1, fim);
    intercala(l, ini, fim, meio);
  }

  return;
}

int main(void) {
  char l[10] = {'a', 'c', 'j', 'b', 'g', 'e', 'f', 'd', 'h', 'i'};
  mergeSort(l, 0, 9);

  for (int i = 0; i <= 9; i++)
    printf("%c ", l[i]);

  return 0;
}
