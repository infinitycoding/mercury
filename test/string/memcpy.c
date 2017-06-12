#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <assert.h>

const char testSrc[20] = "hjnO384ryuaed/olhi12";
char testDest[20];

int main()
{
  memcpy(testDest,testSrc,20);
  for(size_t i = 0; i < 20; i++){
    assert(testSrc[i] == testDest[i]);
  }
  return 0;
}
