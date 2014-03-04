// 568 - Just the Facts
#include <iostream>
#include <stdio.h>

using namespace std;

//trim 0
unsigned long trim_zero(unsigned long value)
{
   while (value % 10 == 0)
      value = value / 10;

   return value;
}

int main()
{
   int n;
   int ans[10010];
   unsigned long now;
   unsigned long i;

   //initial
   ans[0] = 1;
   ans[1] = 1;
   now = 1;

   //calculate the answer
   for (i = 2; i <= 10000; i++)
   {
      now = now * trim_zero(i);
      now = trim_zero(now);
      ans[i] = now % 10;
      now = now % 100000;		//avoid to overflow of now, use mod to smaller the value of now
   }

   //read input and output retult
   while (cin >> n)
      printf("%5d -> %d\n", n, ans[n]);

   return 0;
}
