#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>


const char *alpha= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


int main(void)
{
  //testing if all alphanumerical characters are recognized
  for(int i = 0; i < strlen(alpha); i++)
  {
    assert(isalpha(alpha[i]));
  }

  for(unsigned char x = 0; x < 255; x++)
  {
    if(isalpha(x))
    {
      int flg = 0;
      for(int i = 0; i < strlen(alpha); i++)
      {
        if(alpha[i]==x){
          flg = 1;
          break;
        }
      }
      if(flg == 0)
      {
        printf("%c was recognized as alphabetical character\n",x);
        return -1;
      }
    }
  }


  return 0;
}
