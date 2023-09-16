#include <stdio.h>
#include <string.h>

int countWords(char *text)
{
    int count = 0;
    int isWord = 0;

    while (*text != '\0')
    {
        if (*text == ' ' || *text == '\n' || *text == '\t')
        {
            isWord = 0;
        }
        else if (isWord == 0)
        {
            isWord = 1;
            count++;
        }
        text++;
    }

    return count;
}

int main()
{
    char text[1000];

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0'; // Remove the newline character at the end

    int wordCount = countWords(text);

    printf("Number of words: %d\n", wordCount);

    return 0;
}
