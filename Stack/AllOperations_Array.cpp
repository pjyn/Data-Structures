# include<iostream>
using namespace std;
class stack{
  public:int size;
  int top;
  int *s;
}st;
void create(stack *st)
{
    cout<<"Enter the size:";
    cin>>st->size;
    st->top = -1;
    st->s = new int [st->size];
}

void display(stack *st)
{
    int i;
    for(i=st->top;i>=0;i--)
        cout<<st->s[i]<<"\t";
    cout<<endl
}
void push(stack *st,int x)
{
    if(st->top == st->size-1)
        cout<<"Overflow";
    else
    { 
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(stack *st)
{
    int x = -1;
    if(st->top == -1)
        cout<<"Underflow";
    else
    {
        x = st->s[st->top--];
    }
    return x; 
}
int peek(stack *st , int index)
{
    int x = -1;
    if(st->top-index+1<0)
        cout<<"Invalid Index";
    x = st->s[top-index+1];
    return x;
}
int isEmpty(stack *st)
{
    if(st->top == -1)
        return 1;
    return 0;
}
int isFull(stack *st)
{
    if(st->top == st->size-1)
        return 1;
    return 0;
}
int stackTop(stack *st)
{
    if(!isEmpty(st))
        return st->s[st->top];
    return -1;
}
int main()
{
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    display(&st);
    pop(&st);
    display(&st);
    return 0;
}
