#include<iostream>
#include<string.h>
#include<ctype.h> // for isalpha & isdigit
using namespace std;
class mandu
{

public:
    char st[25];
    int top;
     void push(char); //pushes characters to the stack
    char pop(); //pops out a character and returns it to postfix string
    int priority(char); // to check the priority of operators
    void convert(char[],int); // to convert the infix expression to postfix
    mandu()  // constructor to initialize top to -1
        {
        top=-1;

        }
    };
                                            void mandu::push(char banana)
                                            {
                                            if(top==24)
                                            cout<<"\n stack is full ";
                                            else
                                             {
                                            top++;
                                            st[top]=banana;  //banana is pushed to the stack :D
                                             }
                                            }
                                                                char mandu::pop()
                                                                {
                                                                int gooseberry;
                                                               if(top==-1)
                                                                cout<<"\n stack is empty ";

                                                                    {
                                                                    gooseberry=st[top];
                                                                    top--;
                                                                    }
                                                                return gooseberry;  //gooseberry is returned to write to the postfix string
                                                                }
                                          int mandu::priority(char apple)
                                          {
                                            int newton;
                                           if(apple=='(' || apple==')' )  //lowest priority
                                               newton=0;
                                           else if(apple=='+' || apple=='-')
                                            newton=1;
                                           else if(apple=='*' || apple=='/')
                                            newton=2;
                                           else if(apple=='^')     //highest priority
                                            newton=3;
                                           return newton;
                                          }
                                                                 void mandu::convert(char grapes[],int size)  //grapes receives the infix string
                                                                 {
                                                                    char postfix[25];//postfix string defined
                                                                    int j=0; //index of the postfix string
                                                                    char poperjoy; //he is a temporary popper
                                                                        for(int i=0;i<size;i++)
                                                                        {
                                                                            char donut=grapes[i]; //donut is a temporary variable
                                                    // 1. if the scanned symbol is an operand,put it in the postfix string
                                                                            if(isalpha(donut)||isdigit(donut)) //to check whether donut is an alphabet or digit
                                                                                {
                                                                                    postfix[j]=donut;
                                                                                    j++;
                                                                                }
                                                    // 2. if the scanned symbol is an open paranthesis, then push it on to the stack
                                                                            else if(donut== '(' )
                                                                              push(donut);
                                                   //3. if the  symbol is  a closing paranthesis, pop until an '(' is obtained.
                                                                            else if(donut==')')
                                                                            {
                                                                                poperjoy=pop();
                                                                                 while(poperjoy!='(')
                                                                                 {
                                                                                     postfix[j]=poperjoy; //puts the popped elements to the postfix string
                                                                                     j++;
                                                                                     poperjoy=pop(); //poperjoy pops until ( obtained
                                                                                 }
                                                                            }
                                                  //4. if the symbol is an operator
                                                                            else
                                                                            {
                                                        //if operator has same or less precedence then that @ the top of stack, pop all such operators and put in postfix
                                                                                if(top!=-1)
                                                                                {
                                                                                    while(priority(donut)<=priority(st[top]))
                                                                                    {
                                                                                     poperjoy=pop();
                                                                                     postfix[j]=poperjoy;
                                                                                     j++;
                                                                                    }
                                                                                }
                                                        //else push the incoming operator to the stack
                                                                                else
                                                                                {
                                                                                    push(donut);
                                                                                }

                                                                 }

                                                                                             }
                                                //5.pop all the elements from stack to make it empty
                                                                      while(top!=-1)
                                                                      {
                                                                          poperjoy=pop();
                                                                          if((poperjoy!='(')&&(poperjoy!=')'))
                                                                             {
                                                                                 postfix[j]=poperjoy;
                                                                                  j++;
                                                                             }
                                                                     }
                                                                 for(int j=0;j<size;j++) //outputs postfix
                                                                 {
                                                                   cout<<postfix[j];
                                                                 }
                                                        }



	int main()
	{
	mandu adam; //object
	char infix[25];
	cout<<"Enter infix expression ";
	cin>>infix;
	int size=strlen(infix);
    cout<<"\n The postfix Expression is ";
    adam.convert(infix,size);
	}

