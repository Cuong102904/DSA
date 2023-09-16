#include <stack>
#include <stdio.h>
#include <string.h>

char X[100];
stack<char> S;

int isPair(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    return 0;
}

int Solve(char *X)
{
    for (int i = 0; i < strlen(X); i++)
    {
        if (X[i] == '(' || X[i] == '{' || X[i] == '[')
            S.push(X[i]);
        else if (X[i] == ')' || X[i] == '}' || X[i] == ']')
            if (S.empty())
                return 0;
            else
            {
                char temp = S.top();
                S.top();
                if (isPair(temp, X[i]) == 0)
                    return 0;
            }
    }
    if (S.empty() == 1)
        return 1;
    else
        return 0;
}

int main()
{
    scanf("%d", &X);
    int result = Solve(X);
    printf("%d", result);
}