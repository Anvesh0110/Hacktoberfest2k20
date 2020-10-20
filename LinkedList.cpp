#include<iostream>
using namespace std;
struct linklist
{
	int item;//4 bytes
	struct linklist *next;//self referential pointer	
};
typedef struct linklist node;//from next time we can use 'node' instead of 'struct linklist'
node *head=NULL;//null pointer
int ele;
int main()
{
	void create();
	void delnode();
	void display();
	int ch;
	do
	{
		cout<<("Enter the choice:\n1.Create\n2.Display\n3.Delete first node\n");
		cin>>ch;
		switch(ch)
		{
			case 1:create();break;
			case 2:display();break;
			case 3:delnode();break;
			default:cout<<"Enter correct choice <1-3>\n";
		}
	}while(ch!=3);
}
void create()
{
	cout<<"Enter the element : ";
	cin>>ele;
	if(head==NULL)
	{
		head = new node;
		head->item = ele;
		head->next=NULL;
	}
	else
	{
		node *p=head,*q;
		while(p->next!=NULL)
		p = p->next;
		q = new node;
		q->item = ele;
		p->next=q;
		q->next=NULL;
	}
}
void display()
{ 
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->item<<" ";
		p = p->next;
	}
	cout<<"\n";
}
void delnode()
{
	if(head==NULL)
	cout<<"Empty List\n";
	else
	{
		node *ptr=head;
		head=head->next;
		delete(ptr);
		ptr->next=NULL;
		ptr=NULL;
	}
	display();
}
