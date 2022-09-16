#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main();
struct node
{
	char data[20];		//only use single string data for to-do-list items. Don't use space
	struct node *next;
	struct node *list=NULL;
};
struct node *start= NULL;

bool search(char x[])
{
struct node *t=start;
while(t!=NULL)
{
	if(x==string(t->data))
	return true;
	t=t->next;
	}
	return false;
}

void insertlist()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(node));
	cout<<"Enter list name:";
	cin>>temp->data;
	if(search(temp->data))
	{
		free(temp);
		cout<<"To-do-list already exists.. Please enter a different name"<<endl;
		return;
	}
	if(start==NULL)
	{
		temp->next=NULL;
		temp->list=NULL;
		start=temp;
	}
	else
	{
		temp->next=start;
		temp->list=NULL;
		start=temp;
	}
	cout<<"To-do-list added successfully"<<endl;
}

void deletelist()
{
	struct node *temp;
	if(start==NULL)
	cout<<"No list found!!\n";
	else
	{
		temp=start;
		start=start->next;
		free(temp);
		cout<<"To-do-list removed successfully"<<endl;
	}	
}

void displaylist()
{
	struct node *t;
	t=start;
	int i=1;
	while(t!=NULL)
	{
		cout<<i<<". "<<t->data<<endl;
		t=t->next;
		i++;
	}
}


void traverse(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{
		t=t->next;
	}
	int i=1;
	while(t->list!=NULL){
		t=t->list;
		cout<<i<<") "<<t->data<<endl;
		i++;
	}
}

void insertatfirst(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	struct node *temp;
	temp=(struct node *)malloc(sizeof(node));
	cout<<"\nEnter the task:";
	cin>>temp->data;
	if(t->list==NULL)
	{
		temp->list=NULL;
		t->list=temp;
	}
	else
	{
		temp->list=t->list;
		t->list=temp;
	}
}

void insertatn(char name[])
{	
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	
	int pos,i;
	cout<<"Enter the position of node:";
	cin>>pos;
	if(t->list==NULL||pos==1)
	insertatfirst(name);
	else
	{
	struct node *temp,*r;	
	temp=(struct node *)malloc(sizeof(node));
	cout<<"Enter the task:";
	cin>>temp->data;
    r=t->list;
	for(i=1;i<pos-1;i++)
	r=r->list;
	temp->list=r->list;
	r->list=temp;
	}
}

void insertatlast(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	
	if(t->list==NULL)
	insertatfirst(name);
	else
	{
	struct node *temp,*r;
	temp=(struct node *)malloc(sizeof(node));
	cout<<"\nEnter the task:";
	cin>>temp->data;
	temp->list=NULL;
	r=t->list;
	while(r->list!=NULL)
	r=r->list;
	r->list=temp;
	}
}

void deleteatfirst(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	
	struct node *temp;
	if(t->list!=NULL)
	{
		temp=t->list;
		t->list=t->list->list;
		free(temp);
	}	
}

void deleteatn(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	
	if(t->list!=NULL)
	{
	int pos;
	cout<<"Enter the position:";
	cin>>pos;
	if(pos==1)
	deleteatfirst(name);
	else
	{
	struct node *temp,*r;
	r=t->list;
	for(int i=1;i<pos-1;i++)
	r=r->list;
	temp=r->list;
	r->list=temp->list;
	free(temp);
	}
	}
}

void deleteatlast(char name[])
{
	struct node *t=start;
	while(name!=string(t->data))
	{	
		t=t->next;
	}
	
	if(t->list!=NULL)
	{
	if(t->list->list==NULL)
	deleteatfirst(name);
	
		struct node *temp,*r;
		r=t->list;
		while(r->list!=NULL)
		{
			temp=r;
			r=r->list;
		}
		temp->list=NULL;
		free(r);
	}
}


void addtask(char name[])
{
	int choice;
	while(1){
	system("cls");
	cout<<"To-do-list: "<<name<<endl;
	traverse(name);
	cout<<"\n\n";
		cout<<"1.Add task at first"<<endl;
		cout<<"2.Add task at Nth node"<<endl;
		cout<<"3.Add task at last"<<endl;
		cout<<"4.Back to Menu"<<endl;
		X:
		cout<<"\nPlease enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: insertatfirst(name);
				break;
			case 2: insertatn(name);
				break;
			case 3: insertatlast(name);
				break;
				case 4: main();
				break;
			default: cout<<"\nPlease enter valid choice!!";
			goto X;
		}
	}
}

void removetask(char name[])
{
	int choice;
	while(1){
	system("cls");
	if(choice==1||choice==2||choice==3)
	cout<<"Task removed successfully!!\n\n";
	cout<<"To-do-list: "<<name<<endl;
	traverse(name);
	cout<<"\n\n";
		cout<<"1.Delete task at first"<<endl;
		cout<<"2.Delete task at Nth node"<<endl;
		cout<<"3.Delete task at last"<<endl;
		cout<<"4.Back to Menu"<<endl;
		X:
		cout<<"\nPlease enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: deleteatfirst(name);
				break;
			case 2: deleteatn(name);
				break;
			case 3: deleteatlast(name);
				break;
				case 4: main();
				break;
			default: cout<<"\nPlease enter valid choice!!";
			goto X;
		}
	}
}


int main(){
		system("cls");
		int choice;
		char name[20];
		cout<<"Menu\n\n";
		cout<<"1.Add a to-do-list"<<endl;
		cout<<"2.Remove a to-do-list"<<endl;
		cout<<"3.Display all to-do-lists"<<endl;
		cout<<"4.Add task in to-do-list"<<endl;
		cout<<"5.Remove task in to-do-list"<<endl;
		cout<<"6.Display tasks of to-do-list"<<endl;
		cout<<"7.Exit\n";
		while(1){
		cout<<"\nPlease enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: insertlist();
				break;
			case 2: deletelist();
				break;
			case 3: displaylist();
				break;
			case 4:
				cout<<"Enter the to-do-list name to add task:";
				cin>>name;
				if(search(name))
				addtask(name);
				else
				cout<<"Specified to-do-list doesn't exist!!"<<endl;
				break;
			case 5:
				cout<<"Enter the to-do-list name to remove task:";
				cin>>name;
				if(search(name))
				removetask(name);
				else
				cout<<"Specified to-do-list doesn't exist!!"<<endl;
				break;
			case 6:
				cout<<"Enter the to-do-list name to display its tasks:";
				cin>>name;
				if(search(name))
				{
					cout<<"\nTo-do-list: "<<name<<endl;
					traverse(name);
				}
				else
				cout<<"Specified to-do-list doesn't exist!!"<<endl;
				break;
			case 7:  exit(0);
				break;
			default: cout<<"Please enter valid choice!!"<<endl;
		}
	}
}
