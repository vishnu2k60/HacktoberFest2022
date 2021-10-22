#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *link;
};
struct Node *top=NULL;
void push(char ch)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        exit(1);
    }    
    else
    {
        int d;
        ptr->data=ch;
        ptr->link=top;
        top=ptr;        
    }    
}
void pop()
{
    if(top!=NULL)
    {
        struct Node *ptr=top;
        top=top->link;
        ptr->link=NULL;
        free(ptr);
    }    
}
void display()
{
    if(top!=NULL)
    {
        struct Node *ptr=top;
        while(ptr)  
        {
            if(ptr->link!=NULL)
            printf("||%c|| --> ",ptr->data);
            else
            printf("||%c||  ",ptr->data);
            ptr=ptr->link;
        } 
    } 
}
int main()
{
    char str[1000];
    scanf("%s",str);
    
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        push(str[i]);
        else
        {
            if(str[i]==')')
            {
                if(top->data=='(')
                pop();
                else
                {
                    printf("NO\n");
                    pop();
                    break;
                }
            }
            else if(str[i]==']')
            {
                if(top->data=='[')
                pop();
                else
                {
                    printf("NO\n");
                    pop();
                    break;
                }
            }
            else if(str[i]=='}')
            {
                if(top->data=='{')
                pop();
                else
                {
                    printf("NO\n");
                    pop();
                    break;
                }
            }           
        }               
        i++;
    }
    if(top==NULL)
    printf("YES\n");
    if(top!=NULL)
    top=NULL;
    return 0;  
}