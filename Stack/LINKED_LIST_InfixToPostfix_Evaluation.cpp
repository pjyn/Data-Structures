# include<bits/stdc++.h>
using namespace std;

class Node{
  public:int data;
  Node *next;
}*top=NULL;
void push(int x)
{
    Node *t = new Node();
    if(t == NULL)
      cout<<"Stack is Overflow";
    else
    {
        top = t;
        t->data = x;
        top = top->next;
    }
}
int pop()
{
    int x = -1;
    if(top == NULL)
      cout<<"Stack is Underflow";
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    else
    {
      return 1;
    }
}
int pre(char x)
{
    if(x == '+' || x == '-')
      return 1;
    if(x == '*' || x == '-')
      return 2;
    else
      return 0;
}
char *InfixToPostfix(char *infix)             //CONVERSION..
{
    int i = j =0;
    int l = strlen(infix);
    char *postfix;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix) > infix(top->data))
            { push(infix[i++]);  }
            else
            { postfix(infix[j++] = pop() ; }
        }
    }
    while(infix[i] != '\0')
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}
char *eval(char *postfix)                   //EVALUATION..
{
    int i = 0;
    int x1,x2,r;
    for(i=0;postfix[i] != '\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i] - '\0');      //ASCII value 
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch(postfix[i])
            {
                case 1: r = x1 + x2;
                        break;
                case 2: r = x1 - x2;
                        break;
                case 3: r = x1 * x2;
                        break;
                case 4: r = x1 / x2;
                        break;
            }
            push(r);
            
        }
    }
    return top->data;
}
int main()
{
  char *infix = "a+b*cd/-";
  char *postfix = InfixToPostfix(infix);
  cout<<"After conversion:  "<<postfix;
  char *postfix = "246*+82/-7*";
  cout<<"Result is:  "<<eval(postfix);
  return 0;
}
