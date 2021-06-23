#include <stdio.h>
#include <stdlib.h>

struct sFILA{
  int *arr, ini, MAX, fim;
};

void criar(struct sFILA *fi, int tam_MAX);
void apagar(struct sFILA *fi);
void enqueue(struct sFILA *fi, int dado);
int dequeue(struct sFILA *fi);
int tamanho(struct sFILA *fi);
void imprimir(struct sFILA *fi);

int main(void) {
  struct sFILA fila1;
  criar(&fila1, 5);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  printf("Dequeue em Fila1 -> %d\n", dequeue(&fila1));

  imprimir(&fila1);

  apagar(&fila1);

  return 0;
}

void criar(struct sFILA *fi, int tam_MAX) {
  fi->ini = fi->fim = 0;
  fi->MAX = tam_MAX;
}

void apagar(struct sFILA *fi) {
  fi->ini = fi->fim = 0;
  free(fi->arr);
}

void enqueue(struct sFILA *fi, int dado) {
  if ((fi->fim + 1) != fi->ini && !(fi->fim + 1 == fi->MAX && !fi->ini)) {
    fi->arr[fi->fim++] = dado;
	  if (fi->fim == fi->MAX) fi->fim = 0;
  } else
	  printf("Nao foi possivel inserir %d. Fila cheia.\n", dado);
}

int dequeue(struct sFILA *fi) {
  if (fi->ini != fi->fim) {
    int dado = fi->arr[fi->ini++];
    if (fi->ini == fi->MAX) fi->ini = 0;
    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(struct sFILA *fi) {
  if (fi->ini <= fi->fim)
	  return fi->fim - fi->ini;
  else
	  return fi->MAX - (fi->ini - fi->fim);
}

void imprimir(struct sFILA *fi) {
  printf("F[ ");
  for (int i = fi->ini; i != fi->fim; i++) {
    if (i == fi->MAX) i = 0;
    printf("%d ", fi->arr[i]);
  }
  printf("]\n");
}
