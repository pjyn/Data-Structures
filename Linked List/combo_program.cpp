# include<iostream>
using namespace std;

class Node{
	public:int data;
	struct Node *next;
}*first=NULL;

void create(int a[] , int n)
{
	
	if(n <= 0)
		cout<<"Cannot create linked list";
	else
		first = new Node();
	first->data = a[0];
	first->next = NULL;
	Node *last,*t ;
	last = first;
	for(int i = 1; i < n; i++)
	{
		Node *t = new Node();
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(Node *p)
{
	while(p)
	{
		cout<<p->data<<"\t";
		p = p->next;
	}
	cout<<endl;
}

void insert(int pos)
{
	Node *p = first;
	
	for(int i=0;i<pos;i++)
	{
		p = p->next;
	}
	int data;
	Node *t = new Node();
	cout<<"Enter any value:";
	cin>>data;
	t->data = data;
	t->next = p->next;
	p->next = t;
}

void insertsorted(Node *p,int data)
{
	Node *q = NULL;
	Node *t = new Node();
	t->data = data;
	t->next = NULL;
	if(first == NULL)
		first = t;
	else
	{
		while(p && p->data < data)
		{
			q = p;
			p = p->next;
		}
		if(p == first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next = q->next;
			q->next = t;
		}
		
	}
}

int main()
{
	int a[] = {10,20,30,40,50,60};
	create(a,6);
	insert(4);
	insertsorted(first,55);
	display(first);
	return 0;
}
