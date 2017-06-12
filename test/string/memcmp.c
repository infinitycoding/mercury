#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>

const char testStr1[12] = "doasfjaesolf";
const char testStr2[12] = "dobsfjaesolf";
const char testStr3[12] = "doxsfjaesolf";


int main(void)
{
  //check equal strings
  int result = memcmp(testStr1,testStr1,12);
  assert(result == 0);

  //check not equal strings with
  result = memcmp(testStr1,testStr2,12);
  assert(result < 0);

  //check not equal strings
  result = memcmp(testStr2,testStr1,12);
  assert(result > 0);
  return 0;
}
