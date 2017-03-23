#include <libgen.h>

char *basename(char *path)
{
  char *end = path;
  while(*(end+1) != 0)
    end++;

  if(*end=='/')
    end--;

  char *start = end-1;
  while(*(start-1) != '/')
    start--;

  size_t baseSize  = 1+end-start;
  char *base = malloc(baseSize*sizeof(char));
  int i;
  for(i = 0; i < baseSize; i++)
  {
    base[i] = start[i];
  }
  return base;
}
