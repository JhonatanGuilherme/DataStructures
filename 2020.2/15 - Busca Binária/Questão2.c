#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBin(char *l[], int tam, char *str) {
  int ini = 0, fim = tam - 1;
  int meio = (ini + fim) / 2;

  while (ini <= fim) {
    if (strcmp(str, l[meio]) == 0)
      return meio;
    else {
      if (strcmp(str, l[meio]) < 0)
        fim = meio - 1;
      else
        ini = meio + 1;
      meio = (ini + fim) / 2;
    }
  }

  return -1;
}

int main() {
  char *l[] = {"abc", "boa noite", "cachorro", "dado", "estrutura de dados"}, tam = 5;

  printf("Achei 'boa noite' em %d \n", buscaBin(l, tam, "boa noite"));
  printf("Achei 'estrutura de dados' em %d \n", buscaBin(l, tam, "estrutura de dados"));

  return 0;
}
