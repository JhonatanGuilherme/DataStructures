#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
  int *arr, MAX, pos;
};

void criar(struct sPILHA *pi, int tam_MAX);
void apagar(struct sPILHA *pi);

void push(struct sPILHA *pi, int dado);
int pop(struct sPILHA *pi);

int tamanho(struct sPILHA *pi);
void imprimir(struct sPILHA *pi);

int main(void) {
  struct sPILHA pilha1;
  criar(&pilha1, 10);

  push(&pilha1, 100);
  push(&pilha1, 50);
  push(&pilha1, 200);

  printf("Pop em Pilha -> %d\n", pop(&pilha1));

  imprimir(&pilha1);

  apagar(&pilha1);

  return 0;
}

void criar(struct sPILHA *pi, int tam_MAX) {
  pi->arr = malloc(sizeof(int) * tam_MAX);
  pi->MAX = tam_MAX;
  pi->pos = 0;
}

void apagar(struct sPILHA *pi) {
  free(pi->arr);
  pi->MAX = 0;
  pi->pos = 0;
}

void push(struct sPILHA *pi, int dado) {
  if (pi->pos < pi->MAX)
    pi->arr[pi->pos++] = dado;
  else
    printf("Nao foi possivel inserir %d. Pilha cheia.\n", dado);
}

int pop(struct sPILHA *pi) {
  if (pi->pos)
    return pi->arr[--pi->pos];
  printf("Nao ha elementos. Pilha vazia.\n");
  exit(1);
}

int tamanho(struct sPILHA *pi) {
  return pi->pos;
}

void imprimir(struct sPILHA *pi) {
  printf("P[ ");
  for (int i = pi->pos - 1; i >= 0; i--)
    printf("%d ", pi->arr[i]);
  printf("]\n");
}
