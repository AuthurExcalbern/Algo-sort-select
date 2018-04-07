#include <stdio.h> 
#include <stdlib.h>   
  
#include <time.h>  
   
/* prints a random number in the range 0 to 99 */   
int main(void)   
{   
   randomize();   
   printf("Random number in the 0-99 range: %d\n", random (100));   
   return 0;   
}   
