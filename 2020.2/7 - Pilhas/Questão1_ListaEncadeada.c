#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

void push(int dado);
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

void push(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!topo)
	  topo = novo;
  else {
    novo->prox = topo;
    topo = novo;
  }
}

int pop(void) {
  if (topo) {
	  int dado = topo->dado;
    struct sNODE *tmp = topo;
      
    topo = topo->prox;

    free(tmp);

    return dado;
  } else {
    printf("Nao ha elementos. Pilha vazia.\n");
    exit(1);
  }
}

int tamanho(void) {
  struct sNODE *aux = topo;
  int tam = 0;
 
  while (aux) {
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(void) {
  struct sNODE *aux = topo;
 
  printf("P[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void apagar(void) {
  struct sNODE *aux = topo, *ant;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  topo = NULL;
}

int getTopo(void) {
  if (topo)
    return topo->dado;
  printf("Nao ha elementos. Pilha vazia.\n");
  exit(1);
}
