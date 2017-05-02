#include <stdio.h>
#include <stdlib.h>

int main(){
  int *x = (int*)malloc(4);
  x[1] = 0;
  printf("%d\n",x[2]);
  return x[1];
}
