/*Contact Management System*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
	char name[100];
	char mobileno[100];
	char email[200];
};
struct contact obj[100],temp;
void addition();
void validate();
void deletion();
void search();
void display();
void sort();
int choice,i,count=0,j=0,k=0,m,n,c=0;
char temp_name[100],temp_mobile[100],temp_email[100];
char empty[100]="";
int main()
{
	while(1)
	{
		printf("\nCONTACT MANAGEMENT SYSTEM\n1) CONTACT BOOK\n2) ADDITION\n3) DELETION\n4) SEARCH\n5) EXIT\nEnter your choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				display();
				break;	
			}	
			case 2: 
			{
				addition();
				break;	
			}
			case 3:
			{
				deletion();
				break;	
			}
			case 4:
			{
				search();
				break;			
			}
			case 5:
			{
				exit(1);
				break;	
			}
			default:
			{
				printf("\nPlease Enter the valid choice!!!\n");
				break;	
			}
		}	
	}
}
void validate()
{
	for(i=0;i<j;i++)
	{
		if(!strcmp(obj[i].name,temp_name))
		{
			printf("Name already exists!!!\n");	
		}
	}
	if(i==j)
	{
		count=0;
		for(i=0;temp_email[i]!='\0';i++)
		{
			if(temp_email[i]=='@' || temp_email[i]=='.')
			{
				count++;	
			}	
		}	
		if(count!=2)
		{
			printf("Please Enter correct Email\n");
			exit(1);
		}
		else
		{
			if(!(strlen(temp_email)>=5))
			{
				printf("\nPlease Enter correct Email\n");
				exit(1);	
			}
		}
	}
	for(i=0;i<10;i++)
	{
		if(strlen(temp_mobile)!=10 || temp_mobile[0]=='0')
		{
			printf("Enter valid Mobile Number");
			exit(1);	
		}
		else if(!(temp_mobile[i]>='0' && temp_mobile[i]<='9'))
		{
			printf("Enter valid Mobile Number");
			exit(1);	
		}	
	}
	for(i=0;i<j;i++)
	{
		if(!strcmp(temp_mobile,obj[i].mobileno))
		{
			printf("Phone Number already existed in contact book\n");
			exit(1);	
		}	
	}
}
void addition()
{
	printf("Enter the Name\t");
	scanf("%s",temp_name);
	printf("Enter the Mobile Number\t");
	scanf("%s",&temp_mobile);
	printf("Enter the email\t");
	scanf("%s",temp_email);
	validate();
	strcpy(obj[j].name,temp_name);
	strcpy(obj[j].mobileno,temp_mobile);
	strcpy(obj[j].email,temp_email);
	j++;
	c++;
	printf("\n\nContact saved successfully\n");
}
void deletion()
{
	printf("Enter the Name\t");
	scanf("%s",temp_name);
	for(i=0;i<j;i++)
	{
		if(!strcmp(obj[i].name,temp_name))
		{
			strcpy(obj[i].name,empty);
			strcpy(obj[i].mobileno,empty);
			strcpy(obj[i].email,empty);
			printf("\nContact Successfully Deleted!\n");
			c--;
			break;	
		}
	}
	if(i==j)
	{
		printf("\nContact Not found!\n");
	}
}
void search()
{
	printf("Enter the Name\t");
	scanf("%s",temp_name);
	for(i=0;i<j;i++)
	{
		if(!strcmp(obj[i].name,temp_name))
		{
			printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",obj[i].name,obj[i].mobileno,obj[i].email);
			break;	
		}	
	}
	if(i==j)
	{
		printf("\n Contact Not Found\n");	
	}
}
void sort()
{
	for(m=1;m<j;m++)
	{
		for(n=0;n<j-m;n++)
		{
			if(strcmp(obj[n].name,obj[n+1].name)>0)
			{
				temp=obj[n];
				obj[n]=obj[n+1];
				obj[n+1]=temp;
			}
		}	
	}
}
void display()
{
	if(c==0)
	{
		printf("\n\nNo Contact to displayed!!\n\n");
	}
	else
	{
		sort();
		printf("\n\nCONTACT BOOK\n\n");	
		for(i=0;i<j;i++)
		{
			if(strcmp(obj[i].name,empty))
			{
				printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n\n",obj[i].name,obj[i].mobileno,obj[i].email);
			}
		}
		printf("\n\n---THANK YOU----\n\n");
	}
}
