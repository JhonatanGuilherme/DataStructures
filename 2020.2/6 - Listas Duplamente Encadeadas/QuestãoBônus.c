#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sFuncionario {
  char *nome, *ocupacao;
  float salario;
  struct sFuncionario *ant;
  struct sFuncionario *prox;
};

struct sFuncionario *ini = NULL, *fim = NULL;

int cargoToInt(char *nome);
void inserir_ord(char *nome, char *ocupacao, float salario) ;
void apagar(void);
struct sFuncionario *buscar(char *nome);
void remover(char *nome);
char *obter(struct sFuncionario *node);
int tamanho(void);
void imprimir(void);

int main(void) {
  inserir_ord("Joao", "Peao", 5000);
  inserir_ord("Mario", "Supervisor", 8000);
  inserir_ord("Alberto", "Gerente", 6000);
  inserir_ord("Mateus", "Gerente", 4500);

  imprimir();

  return 0;
}

int cargoToInt(char* nome) {
  if (!strcmp(nome, "Gerente"))
    return 2;
  else if (!strcmp(nome, "Supervisor"))
    return 1;
  return 0;
}

void inserir_ord(char *nome, char *ocupacao, float salario) {
  struct sFuncionario *aux = ini, *novo = (struct sFuncionario*) malloc(sizeof(struct sFuncionario));
  if (!novo)
    exit(1);
  novo->nome = (char*) malloc(sizeof(char) * strlen(nome));
  novo->ocupacao = (char*) malloc(sizeof(char) * strlen(ocupacao));
  strcpy(novo->nome, nome);
  strcpy(novo->ocupacao, ocupacao);
  novo->salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;

  while (aux && (cargoToInt(ocupacao) < cargoToInt(aux->ocupacao) || (cargoToInt(ocupacao) == cargoToInt(aux->ocupacao) && salario < aux->salario))) {
    aux = aux->prox;
  }

  if (!ini)
	  ini = fim = novo;
  else if (aux == ini) {
    novo->prox = ini;
    ini->ant = novo;
    ini = novo;
  } else if (!aux) {
    fim->prox = novo;
    novo->ant = fim;
    fim = novo;
  } else {
    aux->ant->prox = novo;
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant = novo;
  }
}

void apagar(void) {
  struct sFuncionario *aux = ini, *ant;

  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}

struct sFuncionario *buscar(char *nome) {
  struct sFuncionario *aux = ini;

  while (aux) {
	  if (strcmp(aux->nome, nome) == 0)
      return aux;
	  aux = aux->prox;
  }

  return NULL;
}

void remover(char *nome) {
  struct sFuncionario *aux = buscar(nome);

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

char *obter(struct sFuncionario *node) {
  if (!node) {
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
  
  return node->nome;
}

int tamanho(void) {
  struct sFuncionario *aux = ini;
  int tam = 0;
  
  while (aux) {
    tam++;
    aux = aux->prox;
  }
  
  return tam;
}

void imprimir(void) {
  struct sFuncionario *aux = ini;

  printf("FUNCIONARIOS\n");
  while (aux) {
    printf("%s %s %.2f\n", aux->nome, aux->ocupacao, aux->salario);
    aux = aux->prox;
  }
  printf("\n");
}
