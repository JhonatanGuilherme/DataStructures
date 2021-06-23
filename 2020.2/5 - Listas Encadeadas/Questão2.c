#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alunoNode{
  char *nome;
  float nota1, nota2, media;
  struct alunoNode *prox;
};

struct alunoNode *ini = NULL, *fim = NULL;

void inserirAluno(char *nome, float nota1, float nota2);
void removerAluno(char *nome);
struct alunoNode *buscar(char *nome);
char *obter(struct alunoNode *node);
int tamanho(void);
void imprimir(void);
void apagar(void);

int main(void) {
  inserirAluno("Dudu", 8.5, 8.9);
  inserirAluno("John", 8.0, 9.2);
  inserirAluno("Biel", 7.3, 10.0);
  imprimir();

  removerAluno("John");
  imprimir();

  apagar();

  return 0;
}

void inserirAluno(char *nome, float nota1, float nota2) {
  struct alunoNode *novo = malloc(sizeof(struct alunoNode));
  novo->nome = malloc(sizeof(char) * strlen(nome));
  if (!novo || !novo->nome)
    exit(1);
  strcpy(novo->nome, nome);
  novo->nota1 = nota1;
  novo->nota2 = nota2;
  novo->media = (nota1 + nota2) / 2;
  novo->prox = NULL;
  
  if (!ini) {
	  ini = fim = novo;
    novo->prox = NULL;
  } else if (ini->media <= novo->media) {
    novo->prox = ini;
    ini = novo;
  } else {
    struct alunoNode *aux = malloc(sizeof(struct alunoNode));
    if (!aux)
      exit(1);
    aux = ini;
    while (aux) {
      if (!aux->prox) {
        fim->prox = novo;
        fim = novo;
        return;
      } else if (aux->prox->media <= novo->media) {
        novo->prox = aux->prox;
        aux->prox = novo;
        return;
      }
      aux = aux->prox;
    }
  }
}

void removerAluno(char *nome) {
  struct alunoNode *aux = ini, *ant = NULL;

  while (aux) {
	  if (strcmp(aux->nome, nome) == 0) {
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

struct alunoNode *buscar(char *nome) {
  struct alunoNode *aux = ini;

  while (aux) {
    if (strcmp(aux->nome, nome))
      return aux;
    aux = aux->prox;
  }

  return NULL;
}

char *obter(struct alunoNode *node) {
  if (!node) {
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
 
  return node->nome;
}

int tamanho(void) {
  struct alunoNode *aux = ini;
  int tam = 0;
 
  while (aux) {
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(void) {
  struct alunoNode *aux = ini;
 
  while (aux) {
    printf("Nome: %s ", aux->nome);
    printf("Media: %.2f\n", aux->media);
    aux = aux->prox;
  }
  printf("\n");
}

void apagar(void) {
  struct alunoNode *aux = ini, *ant;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  ini = fim = NULL;
}
