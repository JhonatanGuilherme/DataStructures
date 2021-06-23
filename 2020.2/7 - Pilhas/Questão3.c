#include <stdio.h>
#include <stdlib.h>

struct sPILHA {
  int *arr, MAX, pos;
};

void criar(struct sPILHA *pi, int tam_MAX);
void apagar(struct sPILHA *pi);
void push(struct sPILHA *pi, int dado);
int pop(struct sPILHA *pi);
int tamanho(struct sPILHA *pi);
void imprimir(struct sPILHA *pi);
int validar(char *str);

int main(void) {
  char str[101];
  printf("Entre com a string: ");
  scanf(" %[^\n]s", str);
  
  if (validar(str))
    printf("Balanceada\n");
  else
    printf("Nao Balanceada\n");
  
  return 0;
}

void criar(struct sPILHA *pi, int tam_MAX) {
  pi->arr = malloc(sizeof(int) * tam_MAX);
  pi->MAX = tam_MAX;
  pi->pos = 0;
}

void apagar(struct sPILHA *pi) {
  free(pi->arr);
  pi->MAX = 0;
  pi->pos = 0;
}

void push(struct sPILHA *pi, int dado) {
  if (pi->pos < pi->MAX)
    pi->arr[pi->pos++] = dado;
  else
    printf("Nao foi possivel inserir %d. Pilha cheia.\n", dado);
}

int pop(struct sPILHA *pi) {
  if (pi->pos)
    return pi->arr[--pi->pos];
  printf("Não há elementos. Pilha vazia.\n");
  exit(1);
}

int tamanho(struct sPILHA *pi) {
  return pi->pos;
}

void imprimir(struct sPILHA *pi) {
  printf("P[ ");
  for (int i = pi->pos - 1; i >= 0; i--)
    printf("%d ", pi->arr[i]);
  printf("]\n");
}

int validar(char *str) {
  char *s = str;
  int x = 0, y = 0, z = 0;
  while (*s) {
    if (*s == '[')
      x++;
    else if (*s == ']')
      x--;
    else if (*s == '{')
      y++;
    else if (*s == '}')
      y--;
    else if (*s == '(')
      z++;
    else if (*s == ')')
      z--;
    s++;
  }
  return (!x && !y && !z);
}
