#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int idade;
  char nome[50];
  int *notas;
} aluno;

int main() {
  aluno a1, a2;
  a1.idade = 10;
  strcpy(a1.nome, "Pedro");
  a1.idade = 12;
  strcpy(a2.nome, "Maria"); // 'a1.nome' foi passado duas vezes, alterando "Pedro".

  a1.notas = (int *)malloc(5 * sizeof(int));
  a2.notas = (int *)malloc(5 * sizeof(int));

  int i;
  for (i = 0; i < 5; i++) {
    a1.notas[i] = 100;
  }
  // 'a2.notas = a1.notas;' faria com que 'a2.notas' apontasse para 'a1.notas'.
  for (i = 0; i < 4; i++) {
    a2.notas[i] = 90;
  }
  double media = 0;
  for (i = 0; i < 5; i++) {
    media += a1.notas[i];
  }
  media = media / 5;
  printf("Media de %s: %.2lf\n", a1.nome, media);

  media = 0;
  for (i = 0; i < 4; i++) {
    media += a2.notas[i];
  }
  media = media / 4;
  printf("Media de %s: %.2lf\n", a2.nome, media);

  free(a1.notas);
  free(a2.notas);

  system("pause");
  return 0;
}
