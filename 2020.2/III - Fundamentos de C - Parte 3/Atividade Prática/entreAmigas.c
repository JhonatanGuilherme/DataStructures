#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

char comparison[4], numbers[MAX], phrase[MAX], *token = NULL;
char letters[27] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int counter;

int traduzir(char *string) {
  counter = 0;
  token = strtok(string, " ");
  while (token != NULL) {
    phrase[counter] = letters[atoi(token)];
    token = strtok(NULL, " ");
    counter++;
  }
  strncpy(comparison, phrase, 3);
  if (strcmp(comparison, "fim") == 0)
    return 1;
  printf("%s\n", phrase);

  return 0;
}

int main(void) {
  comparison[3] = '\0';

  while (1) {
    scanf(" %[^\n]s", numbers);
    if (traduzir(numbers) == 1)
      break;
  }

  return 0;
}
