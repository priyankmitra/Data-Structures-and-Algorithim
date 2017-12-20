/* Menu driven programme for implication of singly linked list */
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next; // next is a pointer which points address of the node type
};
// step1 : create a head first.
struct node * create(int *move)  //this function will return a pointer of struct node type
{
	struct node *ptr; 
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data = 0;
	ptr->next  = NULL;
	*move = *move + 1 ;
	printf("\nHead Created!!!\n");
	return ptr;
}
//step 2 : Insert a node 
void insert(int index, int value, struct node *ptr)  // ptr is pointing the head
{
	struct node *newptr, *temp;
	int i = 0;
	newptr = (struct node*)malloc(sizeof(struct node*));
	newptr->data = value;
	ptr->data = ptr->data + 1;
	while(i<index)
	{
		ptr = ptr->next;
		i++;
	}
	temp = ptr->next;
	ptr->next = newptr;
	newptr->next = temp;
}
// Step 3 : Display the list
void display(struct node *ptr)
{
	printf("List Is :-                 ");
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		printf("%d->",ptr->data);
	}
	printf("NULL\n");
}
// to find a value
int find(int info, struct node *ptr)
{
	printf("Value found at the :-       ");
	int i=0,count = 0;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
		if(ptr->data==info)
		{ 
			printf("Index = %d    ",i);
			count++;
		}
		i++;
	}
	printf("\n");
	return count;  // return 0 if no value found
}
void delet(int index,struct node *ptr)
{
	int i=0,temp;
	temp = ptr->data-1;// max value of index which can be deleted
	while(i<index)
	{
		ptr=ptr->next;
		i++;
	}
	if(temp==index)
		ptr->next=NULL;
	else
		ptr->next = (ptr->next)->next;
}
void modify(int index, int newvalue ,struct node *ptr)
{
	int i=0;
	while(i<=index)
	{
		ptr = ptr->next;
		i++;
	}
	ptr->data = newvalue;
}
int main()
{
	struct node *head;
	int choice,var=0,index,value,info,check,newvalue;
	while(1)
	{
		printf(" ------Menu------\n");
		printf("|1)Create Head   |\n|2)Insert a Node |\n|3)Display List  |\n|4)Find a node   |\n|5)Delete a node |\n|6)Modify a node |\n|7)ReverseTheList|\n|8)Exit          |\n");
		printf(" ----------------\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : head = create(&var); // first create a head
					 break;

			case 2 : if(var==0)
			         {
					 	printf("Create Head first!!!\n");
					 	break;
					 }
					 printf("Enter the Index and Data\n");
					 printf("Index :- ");scanf("%d",&index);
					 if(index<0 || index>head->data)
					 {
					 	printf("Invalid Index!!!\n");
					 	break;
					 }
					 printf("Data :- ");scanf("%d",&value);
					 insert(index,value,head);
					 display(head);
					 break;

			case 3 : if(var==0)
			         {
					 	printf("Create Head first!!!\n");
					 	break;
					 }
					 display(head);
					 break;
			case 4 : if(var==0)
			         {
					 	printf("Create Head first!!!\n");
					 	break;
					 }
					 printf("Enter tne Data to be find :- ");scanf("%d",&info);
					 check = find(info,head);
					 if(check == 0)
					 	printf("No such value found!!!\n");
					 break;

			case 5 : if(var==0)
			         {
					 	printf("Create Head first!!!\n");
					 	break;
					 }
					 printf("Enter the value to be deleted :- ");
					 scanf("%d",&value);
					 check = find(value,head);
					 if(check == 0)
					 {
					 	printf("No such value found!!!\n");
					 	break;
					 }
					 printf("Enter the index to be deleted :- \n");
					 printf("Index -> ");scanf("%d",&index);
					 delet(index,head);
					 printf("New ");display(head);
					 break;

			case 6 : if(var==0)
			         {
					 	printf("Create Head first!!!\n");
					 	break;
					 }
					 printf("Enter the data to be modified :- ");
					 scanf("%d",&value);
					 check = find(value,head);
					 if(check == 0)
					 {
					 	printf("No such value found!!!\n");
					 	break;
					 }
					 printf("Enter the index to be modified :- ");scanf("%d",&index);
					 printf("Enter the new value :- ");scanf("%d",&newvalue);
					 modify(index,newvalue,head);
					 printf("Modified ");display(head);
					 break;

			case 8 : exit(0);

			default : printf("Enter Valid Index!!!\n");

		}
	}
	return 0;
}
