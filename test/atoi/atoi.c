#define _DEBUG

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <atoi.h>


int StaticValues[23] =
{
   1,2,3,4,5,6,7,
   8,9,10,21,25,100,
   107,189,255,387,521,
   1024,135,1112345,
   INT_MAX,INT_MIN
 };

 char *StaticResultsDec[22] =
 {
   "1","2","3","4","5","6","7",
   "8","9","10","21","25","100",
   "107","189","255","387","521",
   "1024","135","1112345",
   "2147483647"
 };

char *StaticResultsHex[22] =
{
  "1","2","3","4","5","6","7",
  "8","9","A","15","19","64",
  "6B","BD","FF","183","209",
  "400","87","10F919",
  "7FFFFFFF"
};



char output[255] = {0};



int main(void)
{
  //testing static dec table
  for(int i = 0; i < 22; i++)
  {
    itoa(StaticValues[i], output, 10);
    assert(!strcmp(output,StaticResultsDec[i]));
  }

  //testing static hex table
  for(int i = 0; i < 22; i++)
  {
    itoa(StaticValues[i], output, 16);
    assert(!strcmp(output,StaticResultsHex[i]));
  }

  return 0;
}
