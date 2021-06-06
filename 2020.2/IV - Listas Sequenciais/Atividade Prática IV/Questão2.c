#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int l[MAX], pos = 0;

void inserir(int elemento);
void remover(int elemento);
int buscar(int elemento);

int obter(int indice);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserir(10);
  inserir(20);
  inserir(30);
  inserir(30);

  imprimir();

  remover(20);
  imprimir();

  return 0;
}

// Somente inserir elemento caso ele não exista na lista.
void inserir(int elemento) {
  bool existe = false;
  for (int i = 0; i < pos; i++) {
    if (l[i] == elemento) {
      existe = true;
      break;
    }
  }
  if (!existe) {
    if (pos < MAX)
      l[pos++] = elemento;
    else
      printf("Nao foi possivel inserir %d. Lista cheia.\n", elemento);
  } else
    printf("Nao foi possivel inserir %d. Elemento ja existente.\n", elemento);
}

int buscar(int elemento) {
  for (int i = 0 ; i < pos ; i++){
    if (l[i] == elemento)
      return i;
  }

  return -1;
}

// Remover todas as ocorrências do elemento.
void remover(int elemento) {
  int p = buscar(elemento);

  if (p == -1)
	  return;
 
  for (int i = 0; i < pos; i++)
    if (l[i] == elemento) {
      for (int j = i; j < pos - 1; j++)
	      l[j] = l[j + 1];
      pos--;
    }
}

int obter(int indice) {
  if (indice < 0 || indice >= pos) {
    printf("Indice %d fora dos limites da lista.\n", indice);
    exit(1);
  }
  return l[indice];
}

int tamanho(void) {
  return pos;
}

void imprimir(void) {
  for (int i = 0; i < pos; i++)
    printf("%d ", l[i]);
  printf("\n");
}

void apagar(void) {
  pos = 0;
}
