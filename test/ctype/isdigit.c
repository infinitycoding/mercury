#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>


const char *digits= "0123456789";


int main(void)
{
  //testing if all alphanumerical characters are recognized
  for(int i = 0; i < strlen(digits); i++)
  {
    assert(isalnum(digits[i]));
  }

  for(unsigned char x = 0; x < 255; x++)
  {
    if(isalnum(x))
    {
      int flg = 0;
      for(int i = 0; i < strlen(digits); i++)
      {
        if(digits[i]==x){
          flg = 1;
          break;
        }
      }
      if(flg == 0)
      {
        printf("%c was recognized as digit\n",x);
        return -1;
      }
    }
  }


  return 0;
}
