#include <stdio.h>
#include <string.h>
int palindrome(char str[], int start, int end)
{
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    else if (str[start] == str[end])
    {
        return palindrome(str, start + 1, end - 1);
    }
}
int main()
{
    char str[100];
    int check;
    printf("Moi nhap 1 chuoi: ");
    gets(str);
    check = palindrome(str, 0, strlen(str) - 1);
    if (check == 1)
        printf("%s is palindrone", str);
    else
        printf("%s is not palindrone", str);
    return 0;
}