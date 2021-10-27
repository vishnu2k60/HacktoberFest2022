/* Program to for a general infix expression evaluation using stack 
About the program :
1.Take the input of the expression in an INFIX STACK
2. Convert it into postfix using stack .
3. Evaluate the postfix expression 
4. Get the result.

Algorithm :
1. Run a loop to check for the operators until a blank space is encountered in the expression.

2. if it is a first symbol push push it into the stack 
 else check for the priority of the symbol we have pushed into the stack before
  2.1 for Priority checking mention the priorities of the operators/ symbols in and another function 
  2.2 Check the present priority of the operator with the previously pushed stack.
  2.3 If the previously pushed operator has a greater priority pop it out into the POSTFIX STACK and push the present operator. 
  2.4 else only push the present one.
3. push the operands into the POSTFIX stack by popping from the infix stack .
Evaluation 
4. Define the operations 
5. After conclusion of an operation push the result  into the  stack
6. Use the result to perform the next operation .
7. Pop out the result .*/

//Code
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push(long int symbol);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char );
char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;
int main()
{
        long int value;
        top=-1;
        printf("Enter infix : ");
        gets(infix);
        infix_to_postfix();
        printf("Postfix : %s\n",postfix);
        value=eval_post();
        printf("Value of expression : %ld\n",value);
        return 0;
}
void infix_to_postfix()
{
        unsigned int i,p=0;
        char next;
        char symbol;
        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                if(!white_space(symbol))
                {
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        postfix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        default:
                             postfix[p++]=symbol;
                        }
                }
        }
        while(!isEmpty( ))
                postfix[p++]=pop();
        postfix[p]='\0';
}
int priority(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default :
                return 0;
        }
}
void push(long int symbol)
{
        if(top>MAX)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        stack[++top]=symbol;
}
long int pop()
{
        if( isEmpty() )
        {
                printf("Can't be evaluated\n");
                exit(1);
        }
        return (stack[top--]);
}
int isEmpty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}
int white_space(char symbol)
{
        if( symbol == BLANK || symbol == TAB )
                return 1;
        else
                return 0;
}
long int eval_post()
{
        long int a,b,temp,result;
        unsigned int i;
        for(i=0;i<strlen(postfix);i++)
        {
                if(postfix[i]<='9' && postfix[i]>='0')
                        push(postfix[i]-'0');
                else
                {
                        a=pop();
                        b=pop();
                        switch(postfix[i])
                        {
                        case '+':
                                temp=b+a; break;
                        case '-':
                                temp=b-a;break;
                        case '*':
                                temp=b*a;break;
                        case '/':
                                temp=b/a;break;
                        case '%':
                                temp=b%a;break;
                        case '^':
                                temp=pow(b,a);
                        }
                        push(temp);
                }
        }
        result=pop();
        return result;
}
