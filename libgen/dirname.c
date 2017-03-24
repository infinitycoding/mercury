#include <libgen.h>
#include <string.h>
#include <stdlib.h>

char  *dirname(char *path)
{
  char *slash = path;
  if(strrchr (path, '/') == NULL)
  {
    slash = NULL;
  }

  if (slash == path)
  {
    ++slash;
  }
  else if (slash != NULL && slash[1] == '\0')
  {
      slash = memchr (path, slash - path, '/');
  }

  if (slash != NULL)
  {
      char *buffer = malloc(1+slash-path);
      memcpy(buffer,path,slash-path);
      buffer[slash-path] = '\0';
      return buffer;
  }

  char *dot = malloc(sizeof(char)*2);
  dot[0] = '.';
  dot[1] = '\0';
  return dot;
}
