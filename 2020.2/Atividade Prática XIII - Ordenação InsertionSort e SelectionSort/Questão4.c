#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado) {
  struct sNODE *novo = (struct sNODE *)malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
    ini = fim = novo;
  else {
    fim->prox = novo;
    fim = novo;
  }

  return;
}

void remover(int dado) {
  struct sNODE *aux = ini, *ant = NULL;

  while (aux) {
    if (dado == aux->dado) {
      if (aux == ini)
        ini = ini->prox;
      else if (aux == fim) {
        ant->prox = NULL;
        fim = ant;
      } else
        ant->prox = aux->prox;

      free(aux);
      return;
    }

    ant = aux;
    aux = aux->prox;
  }

  return;
}

void imprimir() {
  struct sNODE *aux = ini;

  printf("[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");

  return;
}

void troca(struct sNODE *a, struct sNODE *b) {
  int t = a->dado;
  a->dado = b->dado;
  b->dado = t;

  return;
}

struct sNODE *indexMin(struct sNODE *ini) {
  struct sNODE *aux = ini, *im;
  int menor = aux->dado;

  while (aux) {
    if (aux->dado < menor) {
      im = aux;
      menor = aux->dado;
    }
    aux = aux->prox;
  }

  return im;
}

void selectionSort(int tam) {
  struct sNODE *aux = ini, *im;
  for (int i = 0; i < tam - 1; i++) {
    im = indexMin(aux->prox);
    if (im->dado < aux->dado) {
      troca(im, aux);
    }
    aux = aux->prox;
  }

  return;
}

int main(void) {
  int tam = 5;
  inserir(2);
  inserir(5);
  inserir(3);
  inserir(1);
  inserir(4);

  selectionSort(tam);
  imprimir();

  return 0;
}
