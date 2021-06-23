// - Matrizes Unidimensionais e Multidimensionais
// - Strings
// - Structs

#include <stdio.h> // Além de entrada e saída, gets e fgets.
// Nunca utilizar GETS.
#include <stdlib.h> // Conversão de strings e alocação de memória.
// STDLIB também inclui exit(), para encerrar o programa.
// - atof(str)
// - stoi(str)
#include <ctype.h> // Funções a nível de caractere.
// - isalnum(ch)
// - isalpha(ch)
// - isdigit(ch)
// - isspace(ch)
#include <string.h> // Comparação, cópia e concatenação de strings.
// - strcpy(str1, str2)
// - strcat(str1, str2)
// - strlen(str)
// - strcmp(str1, str2)
// - strch(str, ch)
// - strstr(str1, str2)

// String é um array de caracteres terminados por '\0'.

// Definição de STRUCT.
struct dados {
  char nome[50];
  char endereco[200];
  unsigned idade; // UNSIGNED, pois assume somente valores positivos.
  char sexo;
} pessoa1;

// Definição de outro STRUCT com alias (TYPEDEF).
typedef struct {
  char nome[50];
} regDados;

struct dados pessoa2;

int main(void) {
  char str[50];
  char str1[] = "Teste 1";
  char *str2 = "Teste 2";
  char str3[] = {'T', 'e', 's', 't', 'e', ' ', '3'};
  int array[50], p = 0;

  struct dados pessoa3 = {"John", "Monte Castelo", 20, 'M'};

  scanf(" %[^\n]s", pessoa1.nome);
  printf("%s\n", pessoa1.nome);

  scanf(" %[^\n]s", str);
  printf("String = %s\n", str);

  while (str[p]) {
    printf("%c", str[p++]);
  }
  printf("\n");

  for (int i = 0; i < 50; i++) {
    scanf(" %d", &array[i]);
    printf("Array[%d] = %d\n", i, array[i]);
  }

  int inteiros[3] = {1, 2, 3};

  float flutuantes[3][2] = {{1.2, 4.8}, {4.0, 2.3}, {7.1, 8.9}};

  return 0;
}
