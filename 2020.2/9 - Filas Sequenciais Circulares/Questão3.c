#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], ini = 0, fim = 0;

void inserir_ini(int elemento);
void inserir_fim(int elemento);
int remover_ini(void);
int remover_fim(void);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserir_ini(3);
  inserir_fim(7);

  inserir_ini(4);
  inserir_fim(8);

  inserir_ini(5);
  inserir_fim(9);

  inserir_ini(0);
  inserir_fim(10);

  inserir_ini(-1);
  inserir_fim(11);

  imprimir();

  printf("Removendo do inicio: %d\n", remover_ini());
  imprimir();
  printf("Removendo do fim: %d\n", remover_fim());
  imprimir();

  printf("Removendo do inicio: %d\n", remover_ini());
  imprimir();
  printf("Removendo do fim: %d\n", remover_fim());
  imprimir();

  apagar();

  return 0;
}

void inserir_ini(int elemento) {
  if (ini - 1 != fim && !(ini - 1 == -1 && fim == MAX - 1)) {
    ini--;
    if (ini == -1) ini = MAX - 1;
    l[ini] = elemento;
  } else
	  printf("Nao foi possivel inserir %d. Fila cheia.\n", elemento);
}

void inserir_fim(int elemento) {
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini)) {
    l[fim++] = elemento;
	  if (fim == MAX) fim = 0;
  } else
	  printf("Nao foi possivel inserir %d. Fila cheia.\n", elemento);
}

int remover_ini(void) {
  if (ini != fim) {
    int dado = l[ini++];
    if (ini == MAX) ini = 0;
    return dado;
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int remover_fim(void) {
  if (ini != fim) {
    fim--;
    if (fim == -1) fim = MAX - 1;
    return l[fim];
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(void) {
  if (ini <= fim)
	  return fim - ini;
  else
	  return MAX - (ini - fim);
}

void imprimir(void) {
  printf("F[ ");
  for (int i = ini; i != fim; i++) {
    if (i == MAX) i = 0;
    printf("%d ", l[i]);
  }
  printf("]\n");
}

void apagar(void) {
  ini = fim = 0;
}
