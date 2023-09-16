#include <stdio.h>
#include <string.h>

void Palindrome(char str[], int fir)
{
    int last = strlen(str) - (fir + 1);
    if (str[last] == str[fir])
    {
        if (last == fir || last == fir - 1)
        {
            printf("This is palindrome.\n");
        }
        else
            printf("This is not palindrom");

        return Palindrome(str, fir + 1);
    }
    else
        printf("This is not palindrome.");
}

int main()
{
    char str[100];
    scanf("%s", str);
    Palindrome(str, 0);

    return 0;
}