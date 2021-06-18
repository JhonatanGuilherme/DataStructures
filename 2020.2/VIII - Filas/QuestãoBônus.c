#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ini(int dado);
void inserir_fim(int dado);
int remover_ini(void);
int remover_fim(void);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserir_fim(100);
  inserir_fim(50);
  inserir_fim(75);

  inserir_ini(80);
  inserir_ini(70);
  inserir_ini(40);

  imprimir();

  printf("Remover_ini -> %d\n", remover_ini());
  printf("Remover_fim -> %d\n", remover_fim());

  imprimir();

  printf("Remover_ini -> %d\n", remover_ini());
  printf("Remover_fim -> %d\n", remover_fim());

  imprimir();

  printf("Remover_ini -> %d\n", remover_ini());
  printf("Remover_fim -> %d\n", remover_fim());

  imprimir();

  return 0;
}

void inserir_ini(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else{
    novo->prox = ini;
    ini = novo;
  }
}

void inserir_fim(int dado) {
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else{
    fim->prox = novo;
    fim = novo;
  }
}

int remover_ini(void) {
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

int remover_fim(void) {
  if (fim) {
    int dado = fim->dado;
    struct sNODE *aux = ini;
      
    if (ini == fim)
      ini = fim = NULL;
    else {
      while (aux) {
        if (aux->prox == fim) {
          free(aux->prox);
          aux->prox = NULL;
          fim = aux;
          break;
        }
        aux = aux->prox;
      }
    }

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
