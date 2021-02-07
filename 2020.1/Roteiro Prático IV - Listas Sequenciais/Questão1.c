#include <stdio.h>
#include <string.h>
#define MAX 999

int aux = 0, c = 0, cont = 0, contR = 0, contP = 0, contN = 0;
char b[MAX];

struct Livro {
  int codigo;
  char titulo[MAX], tipo[MAX], autor[MAX];
};

struct Livro L[45];

struct Romance {
  int codigo, posicao;
} LRomance[15];

struct Policial {
  int codigo, posicao;
} LPolicial[15];

struct NaoFiccao {
  int codigo, posicao;
} LNaoFiccao[15];

int main(void) {
  int a = 0;
  while (1) {
    printf("\n1 - Insercao\n");
    printf("2 - Retirada\n");
    printf("3 - Ver livro\n");
    printf("4 - Sair\n\n");
    printf("Digite: ");
    scanf("%d", &a);

    if (a == 1) {
      int a = 0;
      printf("Codigo: ");
      scanf("%d", &L[cont].codigo);
      printf("Titulo: ");
      scanf("%s", L[cont].titulo);
      printf("Tipo (romance, policial ou naoficcao): ");
      scanf("%s", L[cont].tipo);
      printf("Autor: ");
      scanf("%s", L[cont].autor);
      if (strcmp(L[cont].tipo, "romance") == 0) {
        LRomance[contR].codigo = L[cont].codigo;
        LRomance[contR].posicao = cont;
        contR++;
      } else if (strcmp(L[cont].tipo, "policial") == 0) {
        LPolicial[contP].codigo = L[cont].codigo;
        LPolicial[contP].posicao = cont;
        contP++;
      } else if (strcmp(L[cont].tipo, "naoficcao") == 0) {
        LNaoFiccao[contN].codigo = L[cont].codigo;
        LNaoFiccao[contN].posicao = cont;
        contN++;
      }
      printf("\nLivro %s adicionado com sucesso. \n", L[cont].titulo);
      cont++;
    } else if (a == 2) {
      char aux2[MAX];
      printf("------------ Retirar Livro -------------\n");
      printf("Tipo (romance, policial ou naoficcao): ");
      scanf("%s", b);
      printf("Codigo: ");
      scanf("%d", &c);

      if (strcmp(b, "romance") == 0) {
        for (int i = 0; i < contR; i++) {
          if (LRomance[i].codigo == c) {
            aux = LRomance[i].posicao;
            LRomance[i].posicao--;
            for (int j = i; j < contR - 1; j++) {
              LRomance[j] = LRomance[j + 1];
            }
            contR--;
            strcpy(aux2, L[aux].titulo);
            for (int j = aux; j < cont; j++) {
              L[j] = L[j + 1];
              break;
            }
          }
        }
      }

      if (strcmp(b, "policial") == 0) {
        for (int i = 0; i < contP; i++) {
          if (LPolicial[i].codigo == c) {
            aux = LPolicial[i].posicao;
            LPolicial[i].posicao--;
            for (int j = i; j < contP - 1; j++) {
              LPolicial[j] = LPolicial[j + 1];
            }
            contP--;
            strcpy(aux2, L[aux].titulo);
            for (int j = aux; j < cont; j++) {
              L[j] = L[j + 1];
              break;
            }
          }
        }
      }

      if (strcmp(b, "naoficcao") == 0) {
        for (int i = 0; i < contN; i++) {
          if (LNaoFiccao[i].codigo == c) {
            aux = LNaoFiccao[i].posicao;
            LNaoFiccao[i].posicao--;
            for (int j = i; j < contN - 1; j++) {
              LNaoFiccao[j] = LNaoFiccao[j + 1];
            }
            contN--;
            strcpy(aux2, L[aux].titulo);
            for (int j = aux; j < cont; j++) {
              L[j] = L[j + 1];
              break;
            }
          }
        }
      }
      cont--;
      if (strlen(aux2) > 2) {
        printf("\nLivro %s removido com sucesso.\n", aux2);
      } else {
        printf("\nErro.\n");
      }
    }

    else if (a == 3) {
      printf("------------ Mostrar Livro -------------\n");
      printf("Tipo (romance, policial, naoficcao): ");
      scanf("%s", b);
      printf("Codigo: ");
      scanf("%d", &c);
      int aux = 0;
      if (strcmp(b, "romance") == 0) {
        for (int i = 0; i < 15; i++) {
          if (LRomance[i].codigo == c) {
            aux = LRomance[i].posicao;
            break;
          }
        }
      } else if (strcmp(b, "policial") == 0) {
        for (int i = 0; i < 15; i++) {
          if (LPolicial[i].codigo == c) {
            aux = LPolicial[i].posicao;
            break;
          }
        }
      } else if (strcmp(b, "naoficcao") == 0) {
        for (int i = 0; i < 15; i++) {
          if (LNaoFiccao[i].codigo == c) {
            aux = LNaoFiccao[i].posicao;
            break;
          }
        }
      }
      if (strlen(L[aux].titulo) > 1) {
        printf("\nTitulo: %s", L[aux].titulo);
        printf("\nTipo: %s", L[aux].tipo);
        printf("\nAutor: %s\n", L[aux].autor);
      } else {
        printf("\nErro.\n");
      }
    }

    else if (a == 4) {
      break;
    }
  }
  
  return 0;
}
