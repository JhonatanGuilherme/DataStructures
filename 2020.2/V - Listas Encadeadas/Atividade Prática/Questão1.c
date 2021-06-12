#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);
int obter(struct sNODE *node);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserir(10);
  inserir(20);
  inserir(30);
  inserir_ini(40);

  imprimir();
  remover(20);
  imprimir();

  apagar();

  return 0;
}

void inserir(int dado) {
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

void inserir_ini(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  
  if (!ini)
    ini = fim = novo;
  else {
    novo->prox = ini;
    ini = novo;
  }
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
}

struct sNODE *buscar(int dado){
  struct sNODE *aux = ini;

  while (aux) {
    if (dado == aux->dado)
      return aux;
    aux = aux->prox;
  }

  return NULL;
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

void apagar(void) {
  struct sNODE *aux = ini, *ant;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}
