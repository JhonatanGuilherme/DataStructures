#include <stdio.h>
#include <stdlib.h>

struct sNODE {
  int dado;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void apagar(void);
struct sNODE *buscar(int dado);
void remover(int dado);
int obter(struct sNODE *node);
int tamanho(void);
void imprimir(void);
void imprimir_reverso(void);

int main(void) {
  inserir(10);
  inserir(20);
  inserir_ini(30);
  
  imprimir();
  imprimir_reverso();

  return 0;
}

void inserir(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->ant = NULL;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else {
    fim->prox = novo;
    novo->ant = fim;
    fim = novo;
  }
}

void inserir_ini(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->ant = NULL;
  novo->prox = NULL;

  if (!ini)
    ini = fim = novo;
  else {
    novo->prox = ini;
    ini->ant = novo;
    ini = novo;
  }
}

void apagar(void) {
  struct sNODE *aux = ini, *ant;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}

struct sNODE *buscar(int dado) {
  struct sNODE *aux = ini;

  while (aux) {
	  if (dado == aux->dado)
      return aux;
	  aux = aux->prox;
  }

  return NULL;
}

void remover(int dado) {
  struct sNODE *aux = buscar(dado);

  if (!aux)
	  return;

  if (!aux->ant && !aux->prox)
	  ini = fim = NULL;
  else if (aux == ini) {
    ini = ini->prox;
    ini->ant = NULL;
  } else if (aux == fim) {
    fim = fim->ant;
    fim->prox = NULL;
  } else {
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
  }
  free(aux);
}

int obter(struct sNODE *node) {
  if (!node) {
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
 
  return node->dado;
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
 
  printf("[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

void imprimir_reverso(void) {
  struct sNODE *aux = fim;
 
  printf("[ ");
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->ant;
  }
  printf("]\n");
}
