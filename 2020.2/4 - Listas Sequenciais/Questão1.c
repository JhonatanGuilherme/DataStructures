#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//const unsigned int MAX = 10;
int l[MAX], pos = 0;

void inserir(int elemento);
void inserir_ini(int elemento);
void remover(int elemento);
int buscar(int elemento);
int obter(int indice);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  return 0;
}

void inserir(int elemento) {
  if (pos < MAX)
	  l[pos++] = elemento;
  else
	  printf("Não foi possível inserir %d. Lista cheia.\n", elemento);
}

void inserir_ini(int elemento) {
  if (MAX > pos) {
    for (int i = pos; i > 0; i--)
      l[i] = l[i - 1];
	  l[0] = elemento;
	  pos ++;
  } else
	  printf("Não foi possivel inserir %d no início. Lista cheia.\n", elemento);
}

int buscar(int elemento){
  for (int i = 0; i < pos; i++) {
    if (l[i] == elemento)
      return i;
  }
  return -1;
}

void remover(int elemento){
  int p = buscar(elemento);
  if (p == -1)
	  return;
 
  for (int i = p; i < pos - 1; i++)
	  l[i] = l[i + 1];
  pos--;
}

int obter(int indice){
  if (indice < 0 || indice >= pos) {
    printf("Indice %d fora dos limites da Lista.\n", indice);
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
