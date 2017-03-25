#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>

char empty[] = "";
char normal[] = "hello World!";



int main(void)
{
  //check if empty strings are beeing copied
  char targetBuffer1[1] = {1};
  char *returnedPointer = strcpy(targetBuffer1,empty);
  assert(targetBuffer1[0]=='\0');

  //check if the returned pointer is the same as the destination pointer
  assert(returnedPointer == targetBuffer1);

  //check nornal copy process
  char targetBuffer2[13];
  strcpy(targetBuffer2,normal);
  for(int i = 0; i < 13; i++)
  {
    assert(targetBuffer2[i]==normal[i]);
  }


  return 0;
}
