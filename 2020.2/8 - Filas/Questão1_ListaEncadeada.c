#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void enqueue(int dado);
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

void enqueue(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else {
    fim->prox = novo;
    fim = novo;
  }
}

int dequeue(void) {
  if (ini) {
    int dado = ini->dado;
    struct sNODE *tmp = ini;
      
    if (ini == fim)
      ini = fim = NULL;
    else
      ini = ini->prox;

    free(tmp);

    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

void apagar(void) {
  struct sNODE *aux = ini, *ant = NULL;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  ini = fim = NULL;
}

int tamanho(void) {
  struct sNODE *aux = ini;
  int tam = 0;
 
  while (aux) {
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(void) {
  struct sNODE *aux = ini;
 
  printf("F[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

int getFront(void) {
  if (ini)
    return ini->dado;
  else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}
