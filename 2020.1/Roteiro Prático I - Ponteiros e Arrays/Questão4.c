#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  scanf("%d", &n);
  int a[n]; 
  int b[n];
  /*scanf("%d[^\n]", &a[n]);
  printf("%d",a[0]);*/
  for (int i = 0; i < n; i++) {
    scanf("%d[^\n]", &a[i]);
  }
  int i = 0;
  for (i = 0; i < n; i++) {
    if (i == 0){
      b[i] = ((a[i] + a[i + 1]) / 2);
      continue;
    } else if (i == n - 1) {
      b[i] = ((a[i] + a[i - 1]) / 2);
      continue;
    } else {
      b[i] = ((a[i - 1] + a[i] + a[i + 1]) / 3);
      continue;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}
