#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], ini = 0, fim = 0;

void enqueue(int elemento);
int dequeue(void);
int tamanho(void);
void imprimir(void);
void apagar(void);
int getFront(void);
int elementoNaFila(int elemento);
int indiceNaFila(int indice);

int main(void) {
  enqueue(100);
  enqueue(50);
  enqueue(75);
  enqueue(55);
  enqueue(65);
  enqueue(95);
  enqueue(15);
  enqueue(35);
  enqueue(80);

  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());

  imprimir();

  printf("getFront -> %d\n", getFront());
  printf("%d na Fila? -> %d\n", 15, elementoNaFila(15));
  printf("%d na Fila? -> %d\n", 100, elementoNaFila(100));

  printf("indice %d na Fila? -> %d\n", 0, indiceNaFila(0));
  printf("indice %d na Fila? -> %d\n", 5, indiceNaFila(5));

  apagar();

  return 0;
}

void enqueue(int elemento) {
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini)) {
    l[fim++] = elemento;
	  if (fim == MAX) fim = 0;
  } else
	  printf("Nao foi possivel inserir %d. Fila cheia.\n", elemento);
}

int dequeue(void) {
  if (ini != fim) {
    int dado = l[ini++];
    if (ini == MAX) ini = 0;
    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(void) {
  if (ini <= fim)
	  return fim - ini;
  else
	  return MAX - (ini - fim);
}

void imprimir(void) {
  printf("F[ ");
  for (int i = ini; i != fim; i++) {
    if (i == MAX) i = 0;
    printf("%d ", l[i]);
  }
  printf("]\n");
}

void apagar(void) {
  ini = fim = 0;
}

int getFront(void) {
  if (ini != fim)
    return l[ini];
  else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int elementoNaFila(int elemento) {
  for (int i = ini; i != fim; i++) {
    if (i == MAX) i = 0;
    else if (l[i] == elemento)
      return 1;
  }

  return 0;
}

int indiceNaFila(int indice) {
  if (ini == fim)
    return 0;
  else if (ini < fim)
    return (indice >= ini && indice < fim);
  else
    return (indice <= ini || indice > fim);
}
