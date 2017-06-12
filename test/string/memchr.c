#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>

const char testStr[12] = "do;sfjaesolf";


int main(void)
{
  //check naive functionality
  void *result = memchr(testStr,';',12);
  assert(result == &(testStr[2]));

  //check if character is not part of the array
  result = memchr(testStr,'x',12);
  assert(result == NULL);

  //check if only first occurance is returned
  result = memchr(testStr,'s',12);
  assert(result == &(testStr[3]));
   return 0;
}
