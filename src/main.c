#include "stdio.h"

#include "test.h"

int main()
{
   printf("In main.\n");

   printf("From function: %d.\n", test_fn(1));

   return 0;
}
