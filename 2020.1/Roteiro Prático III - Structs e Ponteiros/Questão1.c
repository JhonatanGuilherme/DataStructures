#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
  int indice;
  char nome[50];
  int idade;
};

int main(void) {
  struct Aluno a[5];
  for (int i = 0; i < 5; i++) {
    a[i].indice = i + 1;
    scanf("%s", a[i].nome);
    scanf("%d", &a[i].idade);
  }
  for (int i = 0; i < 5; i++) {
    if (a[i].indice == 2) {
      printf("Posicao: %d.\n", i + 1);
      printf("Nome: %s.\n", a[i].nome);
      printf("Idade: %d.\n", a[i].idade);
    }
  }

  return 0;
}
