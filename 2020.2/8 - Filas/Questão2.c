#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

void criar(struct sFILA *fi);
void apagar(struct sFILA *fi);
void enqueue(struct sFILA *fi, int dado);
int dequeue(struct sFILA *fi);
int tamanho(struct sFILA *fi);
void imprimir(struct sFILA *fi);

int main(void) {
  struct sFILA fila1;
  criar(&fila1);

  enqueue(&fila1, 100);
  enqueue(&fila1, 50);
  enqueue(&fila1, 200);

  printf("Dequeue em Fila1 -> %d\n", dequeue(&fila1));

  imprimir(&fila1);

  apagar(&fila1);

  return 0;
}

void criar(struct sFILA *fi) {
  fi->ini = fi->fim = NULL;
}

void apagar(struct sFILA *fi) {
  struct sNODE *aux = fi->ini, *ant = NULL;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  fi->ini = fi->fim = NULL;
}

void enqueue(struct sFILA *fi, int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!fi->ini)
	  fi->ini = fi->fim = novo;
  else {
    fi->fim->prox = novo;
    fi->fim = novo;
  }
}

int dequeue(struct sFILA *fi) {
  if (fi->ini) {
    int dado = fi->ini->dado;
    struct sNODE *tmp = fi->ini;
      
    if (fi->ini == fi->fim)
      fi->ini = fi->fim = NULL;
    else
      fi->ini = fi->ini->prox;

    free(tmp);

    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(struct sFILA *fi) {
  struct sNODE *aux = fi->ini;
  int tam = 0;
  
  while (aux) {
    tam++;
    aux = aux->prox;
  }
  
  return tam;
}

void imprimir(struct sFILA *fi) {
  struct sNODE *aux = fi->ini;
 
  printf("F[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}
