# include<iostream>
using namespace std;

class Node{
	public:int data;
	Node *next;
}*first=NULL;

Node *p=NULL;
Node *head = NULL;
Node *tail;

void display(Node *p)
{
	while(p)
	{
		cout<<p->data<<"\t";
		p = p->next;
	}
	cout<<endl;
}

void create(int data,int n)
{
	if(n % 2 == 1)			//for odd index
	{
		p = new Node();
		p->data = data;	
		p->next = head;			
		head = p;		//jo new node bnaayenge usko head pointer point krega  traingle bn gya
	}
	else
	{
		p = new Node();
		p->data = data;
		p->next = NULL;
		if(head->next == NULL)	//end m insert krega ek baar hi chlega starting m 
			head->next = p;
		else
			tail->next = p;	//baad m y chlega..
		tail = p;
	}
	display(head);
}

int count (Node *p)
{
	int flag=0;
	while(p)
	{
		flag++;
		p = p->next;
	}
	return flag;
}

void onefourth(Node*p,int z)
{
	int x = z/4;
	for(int i=1;i<x;i++)
	{
		p=p->next;
	}
	cout<<"1/4 is:"<<p->data<<endl;
}

void lastfourth(Node *p)
{
	if(p == NULL || p->next == NULL || p->next->next == NULL || p->next->next->next == NULL)
		return ;
	while(p->next!=NULL && p->next->next!=NULL && p->next->next->next!=NULL && p->next->next->next->next!=NULL)
	{
		p = p->next;
	}
	cout<<"Last fourth element is: "<<p->data<<endl;
}
int main()
{
	int x,n;
	cout<<"Enter size of Linked List:\n";
	cin>>n;
	int a[n+1];
	cout<<"Enter the elements of L.L:\n";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		create(a[i],i);
	}
	lastfourth(head);
	x = count(head);
	onefourth(head,x);
	return 0;
}
