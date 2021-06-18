#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sAVIAO{
  char modelo[101], nomePiloto[101], numeroVoo[11];
  int numeroPassageiros;
  struct sAVIAO *prox;
};

struct sAVIAO *ini = NULL, *fim = NULL;

void adicionarAviao(char numeroVoo[11], char modelo[101], char nomePiloto[101], int numeroPassageiros);
void autorizarDecolagem(void);
int quantidadeEmEspera(void);
void imprimirDadosPrimeiroAviao(void);
void imprimirDadosTodos(void);
void apagar(void);

int main(void) {
  adicionarAviao("001", "Boeing", "Piloto 1", 80);
  adicionarAviao("002", "Airbus", "Piloto 2", 70);
  adicionarAviao("003", "Embraer", "Piloto 3", 90);

  imprimirDadosPrimeiroAviao();
  imprimirDadosTodos();

  apagar();

  return 0;
}

void adicionarAviao(char numeroVoo[11], char modelo[101], char nomePiloto[101], int numeroPassageiros) {
  struct sAVIAO *novo = (struct sAVIAO*) malloc(sizeof(struct sAVIAO));
  strcpy(novo->numeroVoo, numeroVoo);
  strcpy(novo->modelo, modelo);
  strcpy(novo->nomePiloto, nomePiloto);
  novo->numeroPassageiros = numeroPassageiros;
  novo->prox = NULL;

  if (!ini)
	  ini = fim = novo;
  else {
    fim->prox = novo;
    fim = novo;
  }
}

void autorizarDecolagem(void) {
  if (ini) {
    struct sAVIAO *tmp = ini;
      
    if (ini == fim)
      ini = fim = NULL;
    else
      ini = ini->prox;

    free(tmp);
  } else {
    printf("Nao ha elementos. Fila vazia.\n");
    exit(1);
  }
}

int quantidadeEmEspera(void) {
  struct sAVIAO *aux = ini;
  int tam = 0;
  
  while (aux) {
    tam++;
    aux = aux->prox;
  }
  
  return tam;
}

void imprimirDadosPrimeiroAviao(void) {
  struct sAVIAO *aux = ini;
 
  printf("INFORMACOES DO PRIMEIRO AVIAO\n");
  printf("Numero de voo: %s\n", aux->numeroVoo);
  printf("Modelo da aeronave: %s\n", aux->modelo);
  printf("Nome do piloto: %s\n", aux->nomePiloto);
  printf("Numero de passageiros: %d\n\n", aux->numeroPassageiros);
}

void imprimirDadosTodos(void) {
  struct sAVIAO *aux = ini;
  int cont = 1;
 
  printf("INFORMACOES GERAIS\n");
  while (aux) {
    printf("AVIAO %d\n", cont++);
    printf("Numero de voo: %s\n", aux->numeroVoo);
    printf("Nome do piloto: %s\n", aux->nomePiloto);
    aux = aux->prox;
  }
}

void apagar(void) {
  struct sAVIAO *aux = ini, *ant = NULL;
 
  while (aux) {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }

  ini = fim = NULL;
}
