#include <stdio.h>
#include <stdlib.h>

typedef struct {
 unsigned MAX;
 int *arr, pos;
} Lista;

void criar(Lista *list, int tam_MAX);
void apagar(Lista *list);

void inserir_ord(Lista *list, int elemento);
void remover(Lista *list, int elemento);
int buscar(Lista *list, int elemento);

int obter(Lista *list, int indice);
int tamanho(Lista *list);
void imprimir(Lista *list);

int main(void) {
  Lista l1, l2;
  criar(&l1, 5);
  criar(&l2, 8);

  inserir_ord(&l1, 2);
  inserir_ord(&l1, 4);
  inserir_ord(&l1, 1);

  imprimir(&l1);

  apagar(&l1);
  apagar(&l2);

  return 0;
}

void criar(Lista *list, int tam_MAX) {
  list->arr = (int*) malloc(sizeof(int) * tam_MAX);
  list->MAX = tam_MAX;
  list->pos = 0;
}

void apagar(Lista *list) {
  free(list->arr);
  free(list);
}

void inserir_ord(Lista *list, int elemento) {
  int i, p;
  if (list->pos < list->MAX) {
    for (i = 0; i < list->pos; i++)
      if (list->arr[i] >= elemento)
        break;
      
    for (p = list->pos; p > i; p--)
      list->arr[p] = list->arr[p - 1];
    list->arr[i] = elemento;
    list->pos++;
  } else
	  printf("Não foi possível inserir %d. Lista cheia.\n", elemento);
}

void remover(Lista *list, int elemento) {
  int p = buscar(list, elemento);

  if (p == -1)
	  return;
 
  for (int i = p; i < list->pos - 1; i++)
	  list->arr[i] = list->arr[i + 1];
  list->pos--;
}

int buscar(Lista *list, int elemento) {
  for (int i = 0; i < list->pos; i++) {
    if (list->arr[0] == elemento)
      return i;
  }

  return -1;
}

int obter(Lista *list, int indice) {
  if (indice < 0 || indice >= list->pos) {
    printf("Indice %d fora dos limites da Lista.\n", indice);
    exit(1);
  }
  return list->arr[indice];
}

int tamanho(Lista *list) {
  return list->pos;
}

void imprimir(Lista *list) {
  for (int i = 0; i < list->pos; i++)
    printf("%d ", list->arr[i]);
  printf("\n");
}
