# include<iostream>
using namespace std;

class Node{
	public: int data;
	struct Node *next;
}*first=NULL;

void create(int a[] ,int n)
{
	if(n <= 0)
		cout<<"No linked list";
	else
		first = new Node();
	first->data = a[0];
	first->next = NULL;
	Node *t, *last;									//initiated 't' & 'last' pointer
	last = first;
	for(int i = 1 ; i < n ; i++)
	{
		t = new Node();
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
		cout<<p->data<<" \t";
		p = p->next;
	}
	cout<<"\n";
}


void insertsorted(Node *p,int data)
{
	Node  *q = NULL;		//'q' is the previous pointer
	Node *t = new Node();		// 't' is the prevailing 
	t->data = data;
	t->next = NULL;
	if(first == NULL)	//if there is no node at all
		first = t;
	else
	{
		while(p && p->data < data)		//........move till the element has not reach the destination..........
		{
			q = p;
			p = p->next;
		}
		if(p == first)	//if the element to be insert is at 1st posiiton 
		{
			t->next = first;
			first = t;
		}
		else		// .........or at any other place....
		{
			t->next = q->next;
			q->next = t;
		}
	}
}

int main()
{
	int a[] = {10,20,30,40,50};
	create(a,5);
	insertsorted(first,35);
	insertsorted(first,5);
	insertsorted(first,60);
	display(first);
	cout<<"\n\n";
	return 0;
}
