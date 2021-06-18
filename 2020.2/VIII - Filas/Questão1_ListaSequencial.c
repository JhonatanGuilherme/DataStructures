#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

void enqueue(int elemento);
int dequeue(void);
int tamanho(void);
void imprimir(void);
void apagar(void);
int getFront(void);

int main(void) {
  enqueue(100);
  enqueue(50);
  enqueue(75);

  imprimir();

  printf("Dequeue -> %d\n", dequeue());
  printf("Dequeue -> %d\n", dequeue());

  imprimir();

  printf("Dequeue -> %d\n", dequeue());

  imprimir();

  printf("Dequeue -> %d\n", dequeue());

  apagar();

  return 0;
}

void enqueue(int elemento) {
  if (pos < MAX)
	  l[pos++] = elemento;
  else
	  printf("Nao foi possivel inserir %d. Fila cheia.\n", elemento);
}

int dequeue(void) {
  if (pos) {
    int dado = l[0];
    for (int i = 0; i < pos - 1; i++)
      l[i] = l[i + 1];
    pos--;
    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(void) {
  if (pos)
    return pos;
  else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

void imprimir(void) {
  printf("F[ ");
  for (int i = 0; i < pos; i++)
	  printf("%d ", l[i]);
  printf("]\n");
}

void apagar(void) {
  pos = 0;
}

int getFront(void) {
  return l[0];
}
