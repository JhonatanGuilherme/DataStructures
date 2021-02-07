// Aula 0
// - Estrutura básica de um programa em C
// - Entrada e Saída
// - Estruturas Condicionais
// - Estruturas de Repetição

#include <stdio.h> // Entrada e saída padrão.

// C é uma linguagem modular baseada em funções.
int main() {
  printf("Aula 0\n");

  char ch = 'A';
  int num = 100;
  printf("Ch: %c || Num: %d\n", ch, num);

  scanf(" %d", &num);
  printf("%d\n", num);

  scanf(" %c", &ch);
  printf("%c\n", ch);

  char str[50];

  scanf(" %[^\n]s", str); // Formato correto para receber uma string. (scanset)
  printf("%s\n", str);

  return 0;
}

// Os tipos de dados em C: void, char, int, float, double.

// %c == Caractere (char)
// %d == Inteiro (int)
// %f == Ponto flutuante (float)
// %g == Ponto flutuante (melhor apresentação)
// %s == String
