# include<iostream>
using namespace std;

struct Node{
  public:int data;
  struct node *next;
}*first=NULL;

void create(int a[], int n)
{
  if(n == 0)
    cout<<"Linked list cannot be created..!!!";
  else
    first = new Node();
  first->data = a[0];
  first->next = NULL;
  last = first;
  for(int i=0;i<n;i++)
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

void middle()
{
  Node *q = first;
  Node *p = first;
  while(p!=NULL && p->next != NULL )      //for finding 1/3 element => p!=NULL && p->next!=NULL && p->next->next!=NULL
  {
      q = q->next;
      p = p->next->next;                    //p = p->next->next->next
  }
  cout<<"Middle element is: "<<q->data;
}
int main()
{
   int a[] = {10,20,30,40,50};
   create (a,n);
   display(first);
   middle();
   return 0;
}
