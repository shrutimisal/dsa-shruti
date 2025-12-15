#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

/* Evaluate postfix expression */
int evaluatePostfix(char exp[])
{
    int i, op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++)
    {
        // If operand
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');   // convert char to int
        }
        // If operator
        else
        {
            op2 = pop();
            op1 = pop();

            switch (exp[i])
            {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            push(result);
        }
    }
    return pop();
}

int main()
{
    char exp[] = "231+*9-";
    printf("Result = %d", evaluatePostfix(exp));
    return 0;
}
