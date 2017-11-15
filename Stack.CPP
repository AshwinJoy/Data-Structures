#include<iostream.h>
#include<conio.h>
#define max 4
class stack
{

public:    int st[max],top;
	void push();
	void pop();
	void display();
	stack()
	{
	top=-1;
     
	}
};
void stack::push()
{
int item;
if(top==max-1)
cout<<"\n stack is full ";
else
{
cout<<"\n Enter item to be inserted ";
cin>>item;
top++;
st[top]=item;
cout<<"\n Insertion successful ";
}
}
	void stack::pop()
	{
	int item;
	if(top==-1)
	cout<<"\n stack is empty ";
	else
	{
	item=st[top];
	top--;
	cout<<"\n deleted item is "<<item;
	}}
void stack::display()
{
int i;
 if(top==-1)
 cout<<"\n stack is empty ";
 else
 {cout<<"\n The elements are ";
 for(i=top;i>-1;i--)
 cout<<st[i]<<" ";
 }
 }
	void main()
	{
	clrscr();
	int k,p;
	stack sasi;
	do{
	cout<<"\n 1;push  2;pop  3;display  ";
	cin>>k;
	switch(k)
	{
	case 1: sasi.push();
	break;
	case 2: sasi.pop(); break;
	case 3: sasi.display(); break;
	default: cout<<" invalid entry ";
	break;
	}
	cout<<"\n Do u wanna continue?,press 1, else0  ";
	cin>>p;
	}while(p==1);
	getch();
	}