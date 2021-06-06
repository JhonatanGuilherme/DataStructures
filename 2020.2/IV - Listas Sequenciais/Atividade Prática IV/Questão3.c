#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_SIZE 5
#define MAX 21

char *l[ARRAY_SIZE];
int pos = 0;

void inserir(char *elemento);
void inserir_ord(char *elemento);
void remover(char *elemento);
int buscar(char *elemento);

char *obter(int indice);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserir_ord("primeira posicao");
  inserir_ord("segunda posicao");
  inserir_ord("terceira posicao");
  inserir_ord("quarta posicao");
  inserir_ord("quinta posicao");
  imprimir();

  return 0;
}

void inserir(char *elemento) {
  if (pos < ARRAY_SIZE) {
    l[pos] = (char*) malloc(sizeof(char) * MAX);
    if (!l[pos])
      exit(1);
    strcpy(l[pos++], elemento);
  } else
    printf("Não foi possível inserir.\n");
}

void inserir_ord(char *elemento) {
  int a, i;
  if (pos < ARRAY_SIZE) {
    for (i = 0; i < pos; i++) {
      if (strcmp(l[i], elemento) >= 0)
        break;
    }

    for (a = pos; a > i; a--)
      l[a] = l[a - 1];

    l[i] = (char*) malloc(sizeof(char) * MAX);
    if (!l[pos])
      exit(1);
    strcpy(l[i], elemento);
    pos++;
  } else
    printf("Não foi possível inserir.\n");
}

int buscar(char *elemento) {
  for (int i = 0; i < pos; i++) {
    if (strcmp(l[i], elemento) == 0)
      return i;
  }
  return -1;
}

void remover(char *elemento) {
  int p = buscar(elemento);

  if (p == -1)
    return;
  
  for (int i = p; i < pos; i++)
    l[i] = l[i + 1];

  pos--;
}

char *obter(int indice) {
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
    printf("%s\n", l[i]);
}

void apagar(void) {
  pos = 0;
}
