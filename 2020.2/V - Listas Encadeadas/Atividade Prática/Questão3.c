#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

void inicializar(struct sLISTA *lst);
void apagar(struct sLISTA *lst);
void inserir_ord(struct sLISTA *lst, int dado);
void remover(struct sLISTA *lst, int dado);
struct sNODE *buscar(struct sLISTA *lst, int dado);
int obter(struct sNODE *node);
int tamanho(struct sLISTA *lst);
void imprimir(struct sLISTA *lst);

int main(void) {
  struct sLISTA lst;
  inicializar(&lst);

  inserir_ord(&lst, 100);
  imprimir(&lst);

  apagar(&lst);

  return 0;
}

void inicializar(struct sLISTA *lst) {
  lst->ini = lst->fim = NULL;
}

void apagar(struct sLISTA *lst) {
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->ini = lst->fim = NULL;
}

void inserir_ord(struct sLISTA *lst, int dado) {
  struct sNODE *aux = lst->ini, *ant = NULL;
  struct sNODE *novo = malloc(sizeof(struct sNODE));
  if (!novo)
    exit(1);
  novo->dado = dado;
  novo->prox = NULL;
  
  while (aux && dado > aux->dado) {
    ant = aux;
    aux = aux->prox;
  }

  if (!lst->ini)
    lst->ini = lst->fim = novo;
  else if (aux == lst->ini) {
    novo->prox = lst->ini;
    lst->ini = novo;
  } else if (!aux) {
    lst->fim->prox = novo;
    lst->fim = novo;
  } else {
    ant->prox = novo;
    novo->prox = aux;
  }

  return;
}

void remover(struct sLISTA *lst, int dado) {
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux) {
	  if (aux->dado == dado) {
      if (aux == lst->ini)
        lst->ini = lst->ini->prox;
      else if (aux == lst->fim) {
        ant->prox = NULL;
        lst->fim = ant;
      } else
        ant->prox = aux->prox;
      
      free(aux);
      return;
	  }
    ant = aux;
    aux = aux->prox;
  }
}

struct sNODE *buscar(struct sLISTA *lst, int dado) {
  struct sNODE *aux = lst->ini;

  while (aux) {
    if (aux->dado == dado)
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

int tamanho(struct sLISTA *lst) {
  struct sNODE *aux = lst->ini;
  int tam = 0;
 
  while (aux) {
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(struct sLISTA *lst) {
  struct sNODE *aux = lst->ini;
 
  while (aux) {
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("\n");
}
