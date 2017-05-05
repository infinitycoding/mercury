#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>





const char *alnum= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
unsigned char table[255] = {0};



int main(void)
{
  //testing if all alphanumerical characters are recognized
  for(int i = 0; i < strlen(alnum); i++)
  {
    assert(isalnum(alnum[i]));
  }

  for(unsigned char x = 0; x < 255; x++)
  {
    if(isalnum(x))
    {
      int flg = 0;
      for(int i = 0; i < strlen(alnum); i++)
      {
        if(alnum[i]==x){
          flg = 1;
          break;
        }
      }
      if(flg == 0)
      {
        printf("%c was recognized as alphanumerical character\n",x);
        return -1;
      }
    }
  }


  return 0;
}
