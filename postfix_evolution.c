/*
    postfix evaluation:-
    ------- ----------

2 3 + 4 5 * - 
            i

if i is an operend:
  push into stack 

if i is an operator:
  pop 2 values from the stack
  
  op1=2
  po2=3
then apply operator as op2 operator op1 and store in res
2+3=5
then push into the stack

finally stack[0] is the answer


*/
#include<stdio.h>
int perform_oper(int op1,char op,int op2)
{
	switch(op)
	{
		case '+':return op2+op1;
		case '-':return op2-op1;
		case '*':return op2*op1;
		case '/':return op2/op1;
		case '^':return op2^op1;
	}
}
int isoper(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return 1;
		default: return 0;
	}
}
int post_eval(char * post)
{
	int i,val=0,st[100],top=-1,op1,op2,res;
	for(i=0;post[i]!='\0';i++)
	{
		if(isoper(post[i]))
		{
			op1=st[top--];
			op2=st[top--];
			res=perform_oper(op1,post[i],op2);
			st[++top]=res;
		}
		else
		{
			if(post[i]>=48 && post[i]<=57)//53>=48 and 53<=57
			{
				val=val*10+post[i]-'0';
			}
			else if(post[i]==' ' && val!=0)
			{
				st[++top]=val;
				val=0;
			}	
		}
	}
	return st[0];
}
int main()
{
	char post[100];
	int res;
	scanf("%[^\n]s",post);//4 5 2 3 * - * 2 3 * +
	res=post_eval(post);
	printf("%d ",res);
}

