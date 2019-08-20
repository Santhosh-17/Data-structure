#include<stdio.h>
#include<string.h>
char stack[20];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
if(top == -1)
    return -1;
else
    return stack[top--];
}
int prior(char x)
{
if(x == '+' || x == '-')
    return 1;
else if(x == '*' || x == '/' || x=='%')
    return 2;
else if(x =='^')
    return 3;
else
    return 0;
}
int isAlpha(char x)
{
    if((x >='A' && x<='Z')||(x >='a' && x<='z') )
        return 1;
    else
        return 0;
}
int isOpera(char x)
{
   if(x == '^' || x=='*'|| x=='/' || x=='+' || x=='-')
        return 1;
   else
    return 0;
}
int main()
{
    int i=0,j=0,check = 1;
    char infix[20],postfix[20];
    printf("Enter the Infix Expression :");
    gets(infix);
    while(infix[i]!= '\0')
    {
        if(isAlpha(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else if(infix[i] =='(')
        {
            check = 0;
            push(infix[i]);
        }
        else if(isOpera(infix[i]))
        {
            if(top == -1 && check == 1)
            {
                push(infix[i]);
            }
            else if(check)
            {
                char temp;
                temp = pop();
                if(prior(temp)>=prior(infix[i]))
                {
                    postfix[j]=temp;
                    push(infix[i]);
                    j++;
                }
                else
                {
                    push(temp);
                    postfix[j]=infix[i];
                    j++;
                }
            }
            else
            {
               push(infix[i]);
            }
        }
        else if(infix[i] ==')')
        {
            check = 1;
            char y ;
            y = pop();
            while(y != '(')
            {
                postfix[j]=y;
                j++;
                y = pop();
            }
        }
        else;


        i++;
    }
    while( top != -1)
    {
        char z;
        z = pop();
        postfix[j]=z;
        j++;
    }
    postfix[j]='\0';
    printf("\nPostfix Expression is = ");
    printf("%s",postfix);
    printf("\n");
}
