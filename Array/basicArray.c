/*Arrays a kind of data structure that can store a fixed-size sequential collection of elements of the same type.
An array is used to store a collection of data,
but it is often more useful to think of an array as a collection of variables of the same type.*/

/*Programme will take 10 integers from the user and will print them in sequential order*/

#include <stdio.h>
 
int main () 
{

   int new[10]; /* n is an array of 10 integers */
   int i,j;
 
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < 10; i++ ) 
   {
       printf("Enter the %d no. :",i+1);
       scanf("%d",&new[i]);
   }
   
   /* output each array element's value */
   for (j = 0; j < 10; j++ ) {
      printf("Element[%d] = %d\n", j, new[j] );
   }
 
   return 0;
}

