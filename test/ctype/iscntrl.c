#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>



int main(void)
{

  for(unsigned char x = 0; x < 255; x++)
  {
    if(iscntrl(x))
    {
      assert(x>=0x20 && x!=0x7F);
    }
  }
  return 0;
}
