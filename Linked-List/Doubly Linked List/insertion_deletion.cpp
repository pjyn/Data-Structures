# include<iostream>
using namespace std;

class Node{
  public:int data;
  Node *next;
  Node *prev;
}*first = NULL;

void create(int a[] , int n)
{
  if(n <= 0)
      cout<<"Not possible";
   else
      Node first = new Node();
   first->data = a[0];
   first->next = first->prev = NULL;
   Node *t,*last;
   last = first;
   for(int i=1;i<n;i++)
   {
      Node *t = new Node();
      t->data = a[i];
      t->next = NULL;
      t->prev = last;
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

void insert(Node *p, int pos)
{
  int x;
  cout<<"Enter the data to insert: ";
  cin>>x;
  if( pos == 0)
  {
      Node *t = new Node();
      t->data = x;
      t->next = first;
      first->prev = t;
      t->prev = NULL;
      first = t;
  }
  else
  {
    Node *t = new Node();
    Node *q = new Node();
    for(int i=1;i<=pos;i++)
    {
      q = p;
      p = p->next;
      if(p == NULL && q->next == NULL)
      {
        t->data = x;
        t->next = NULL;
        t->prev = q;
        q->next = t;
      }
    }
    t->data = x;
    t->next = q->next;
    p->prev = t;
    q->next = t;
    t->prev = q;
  }
}
int Deletion(Node *p)
{
  int m,x;
  cout<<"Enter the position at which deletion should be performed: ";
  cin>>m;
  if( m == 0)
  {
    first = first->next;
    x = first->data;
    delete p;
    return x;
  }
  else
  {
    for(int i=0;i<m;i++)
    {
      p = p->next;
    }
    p->prev->next = p->next;
    if(p->next)
    {
      p->next->prev = p->prev;  
    }
    x = p->data;
    delete p;
    return x;
  }
}
int main()
{
  int pos;
  int a[] = {10,20,30,40,50,60};
  create(a,6);
  display(first);
  cout<<"Enter the position at which insertion should be done: ";
  cin>>pos;
  insert(first,pos);
  display(first);
  cout<<"Deletion element is :"<<Deletion(first);
  return 0;
}





