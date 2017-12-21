#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>


int main()
{
  //testing overlaping memory
  char str[] = "asd asd psd csd";
  char str2[] = "asd asd asd asd";
  memmove(str,str+8,7);
  assert(strcmp(str,str2));
  return 0;
}
