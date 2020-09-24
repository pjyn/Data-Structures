# include<bits/stdc++.h>
using namespace std;

class Node{
  public:int data;
  Node *next;
}*front=NULL,*rear=NULL;

bool isEmpty()
{
    if(front == NULL)
        return true;
    else
        return false;
}
void enqueue(int x)
{
    Node *t = new Node();
    if(t == NULL)
      cout<<"Queue is Full";
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front = rear = t;
            rear->next = front;   //last node ko front node se connect krne k liye..
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *t;
    if(isEmpty())
        cout<<"Queue is Empty";
    else if(front == rear)    //in case, only one element is left
    {
        front = rear = t;
        x = t->data;
        delete t;
    }
    else
    {
        t = front ;
        front = front->next;
        x = t->data;
        delete t;
        return x;
    }
}

void display(Node *p)
{
    while(p->next != front)     
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display(front);
    cout<<"\nDeleted Element is: "<<dequeue();
    display(front);
    return 0;
}
