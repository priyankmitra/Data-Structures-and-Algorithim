// program to insert a single element in an array
#include <stdio.h>
void insert(int *p,int *q, int val, int index, int f)
{
  int i,j,k;
  for(i=0;i<index;i++)
  {
    q[i]=p[i];
  }
  q[i]=val;
  i=i+1;//for updated array
  k=i-1;//for old array
  //printf("%d\n",p[k]);
  for(j=i;j<f;j++)
  {
    q[j]=p[k];
    k++;
  }
}
int main()
{
  int arr[10], i,m,arr2[10+m],val,index, *pqr,f,j;

  printf("enter the elements in array : \n");
  for(i=0;i<10;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("elements are :\n");
  for(i=0;i<10;i++)
  {
    printf("%d ",arr[i]);
  }

  printf("\nEnter 1 to insert an element :");scanf("%d",&m);

  printf("Enter the value to be inserted and the index :- \n");
  scanf("%d %d",&val,&index);
  f=10+m;
  insert(arr,arr2,val,index,f);
  printf("Updated Array is : \n");
  for(j=0;j<f;j++)
  {
  printf("[%d] ",arr2[j] );
  }
}


