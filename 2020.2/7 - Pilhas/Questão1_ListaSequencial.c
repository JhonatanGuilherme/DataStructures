#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

void push(int elemento);
int pop(void);
int tamanho(void);
void imprimir(void);
void apagar(void);
int getTopo(void);

int main(void) {
  push(100);
  push(50);
  push(200);

  printf("Pop em Pilha -> %d\n", pop());

  imprimir();

  apagar();

  return 0;
}

void push(int elemento) {
  if (pos < MAX)
	  l[pos++] = elemento;
  else
  	printf("Não foi possível inserir %d. Pilha cheia.\n", elemento);
}

int pop(void) {
  if (pos)
	  return l[--pos];
  else {
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
  }
}

int tamanho(void) {
  return pos;
}

void imprimir(void) {
  printf("P[ ");
  for (int i = pos - 1; i >= 0; i--)
	  printf("%d ", l[i]);
  printf("]\n");
}

void apagar(void) {
  pos = 0;
}

int getTopo(void) {
  if (pos)
    return l[pos - 1];
  printf("Nao ha elementos. Pilha vazia.\n");
  exit(1);
}
