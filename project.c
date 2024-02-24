#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int slot;
	int ID;
	int AGE;
	int next;
	char name[20];
	char gender[7];
	
}Information;

int main()
{
	
	Information *head = NULL;
	Information *temp = NULL; 
	Information *loop = NULL; 
	int x , y , z , pass , id , c1 , j;
	c1 = 0;
	j = 0;
	
	label3:	
	
	printf("For Admin Mode Enter 1.\nFor the User Mode Enter 2\n");

	scanf("%d",&x);
	
	switch(x)
	{
		case 1:
		printf("\n you are in the admin mode :");
		label1:
		printf("Please Enter Password: ");
		scanf("%d",&pass);
		c1++;
		if(pass == 1234)
		{
			printf("\n\nFor Adding New Patient Enter 1\nFor Editing Patient Enter 2\nFor Reserve a solt Enter 3\nFor Cancel resevation Enter 4\n");
			
			scanf("%d",&y);
			label2:
			while((y == 1) || (y == 2) || (y == 3) || (y == 4) || (y == 5))
			{
				
				if(y == 1)
				{
					while(y == 1)
					{
						Information *new_node = (Information*)malloc(sizeof(Information));					
						printf("\nPlease Enter the  Name : ");
						scanf("%s",&new_node->name);
						printf("Please Entre the age : ");
						scanf("%d",&new_node->AGE);
						printf("Please Enter the Gender: " );
						scanf("%s",&new_node->gender);
						printf("Please Enter ID : ");
						scanf("%d",&new_node->ID);
						new_node->next = NULL;
						if(head == NULL)
						{
							head = temp =new_node;
						}
						else
						{
							temp->next = new_node;
							temp = new_node;
						}
						j++;
						/*printf("you added a patient\n");
						printf("For Adding  1.\nFor Editing  Enter 2.\nFor Reserve a solt  Enter 3.\nFor Cancel resevation Enter ");
						printf("Your choice: ");
						scanf("%d",&y);	*/
						goto label3;
						
					}
					
				}
				
				if(y == 2)
				{
					printf("\nFor Editing, Please Enter ID : ");
					scanf("%d",&id);
					loop = head;
					do
					{
						if(loop->ID == id)
						{
							printf("Please Enter the  Name: ");
							scanf("%s",&loop->name);
							printf("Please Entre age : ");
							scanf("%d",&loop->AGE);
							printf("Please Enter  the Gender : " );
							scanf("%s",&loop->gender);
							printf("you edited  \n");
							break;
						}
						else
						{
							loop = loop->next;
						}
					}while(loop != NULL);
					loop = head;
					goto label3;
				}
				
				if(y == 3)
				{
					printf("\nslot available number1: 2pm to 2:30pm\n");
					printf("slot available number2: 2:30pm to 3pm\n");
					printf("slot available number3: 3pm to 3:30pm\n");
					printf("slot available number4: 4pm to 4:30pm\n");
					printf("slot available number5: 4:30pm to 5pm\n");
					printf("For Reservation, Please Enter ID of Patient: ");
					scanf("%d",&id);
					loop = head;
					do
					{
						if(loop->ID == id)
						{
							printf("Please enter number: ");
							scanf("%d",&loop->slot);
							break;
						}
						else
						{
							loop = loop->next;
						}
					}while(loop != NULL);
					loop = head;
					printf("you reserved\n");
					goto label3;
				}
				
				if(y == 4)
				{
					printf("\nslot available 1:from 2pm to 2:30pm\n");
					printf("slot available 2: 2:from 30pm to 3pm\n");
					printf("slot available 3:from 3pm to 3:30pm\n");
					printf("slot available 4:from 4pm to 4:30pm\n");
					printf("slot available 5:from 4:30pm to 5pm\n");
					printf("For cancel Reservation, Please Enter ID of Patient: ");
					scanf("%d",&id);
					loop = head;
					do
					{
						if(loop->ID == id)
						{
							loop->slot = NULL;
							break;
						}
						else
						{
							loop = loop->next;
						}
					}while(loop != NULL);
					loop = head;
					printf("Reservation is canceled\n");
					goto label3;
				}
				
				if(y == 5)
				{
					goto label3;
				}
				
			}
			
		}
		else
		{
			if(c1 == 3)
			{
				printf("Sorry, Password is incorrect for 3 times\n");
				c1 = 0;
			}
			else
			{
				printf("try again");
				goto label1;
			}
			
		}
		break;
		
		case 2:
		printf("you are in the user mode :");
		label6:
		printf("\nFor Viewing Patient record Enter 1.\nFor Viewing Today's resevations Enter 2");
		
		scanf("%d",&z);
		if(z == 1)
		{
			label4:
			printf("\nFor Viewing Patient record Enter Patient ID: ");
			scanf("%d",&id);
			loop = head;
			do
			{
				if(loop->ID == id)
				{
				
					printf("\nPatient name is: %s.\n",loop->name);
					printf("Patient AGE is: %d.\n",loop->AGE);	
					printf("Patient Gender is: %s.\n",loop->gender);
					
					break;
				}
				else
				{
					loop = loop->next;
				}
			}while(loop != NULL);
			loop = head;
			printf("\nFor Viewing Patient record Enter 1\nFor Viewing  resevations Enter 2\n");
			
			scanf("%d",&z);
			if(z == 1)
			{
				goto label4;
			}
			if(z == 2)
			{
				goto label5;
			}
			if(z == 3)
			{
				goto label3;
			}
		}
		if(z == 2)
		{
			label5:
			loop = head;
			while(loop != NULL)
			{
				if(loop->slot == 1)
				{
					printf("\nslot from 2pm to 2:30pm and ID is %d\n",loop->ID);
				}
				else if(loop->slot == 2)
				{
					printf("\nslot from 2:30pm to 3pm and ID is %d\n",loop->ID);
				}
				else if(loop->slot == 3)
				{
					printf("\nslot from 3pm to 3:30pm and ID is %d\n",loop->ID);
				}
				else if(loop->slot == 4)
				{
					printf("\nslot from 4pm to 4:30pm and ID is %d\n",loop->ID);
				}
				else if(loop->slot == 5)
				{
					printf("\nslot from 4:30pm to 5pm and ID is %d\n",loop->ID);
				}
				loop = loop->next;
			}
			loop = head;
			goto label6;
		}
		if(z == 3)
		{
			goto label3;
		}
		break;
		
		
	}	
	
	
}






































