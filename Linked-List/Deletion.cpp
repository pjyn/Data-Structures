# include<iostream>
using namespace std;

class Node{
	public:int data;
	struct Node *next;
}*first = NULL;

void create(int a[] ,int n)
{
	if(n <= 0)
		cout<<"cannot make linked list";
	first = new Node();
	first->data = a[0];
	first->next = NULL;
	Node *t,*last;
	last = first;
	for(int i = 1;i < n ;i++)
	{
		Node *t = new Node();
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(Node* p)
{
	while(p)
	{
		cout<<p->data<<"\t";
		p = p->next; 
	}
}


int Delete(Node *p, int index)              // 2 pointers will be used 'q' is the previous pointer
{
	int x = -1 ,i;
	Node *q = NULL;
	if(index < 0 || index > 5)
		return -1;
		
	 
	if (index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		delete q;
		return x;
	}
	else
	{
		for(i=0;i<index;i++)
		{	
			q = p;
			p = p->next;	
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}

int main()
{
	int data;
	int a[] = {15,25,35,45,55,66};
	create (a,6);
	Delete(first,3);
	display(first);
	return 0;
}
