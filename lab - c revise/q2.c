// Write a program to find the position of the character 'c' in the sentence "idea without execution is worthless" using pointer and string.
#include <stdio.h>
int main()
{
    char str[] = "idea without execution is worthless";
    char *ptr = str;
    int position = 1;

    while (*ptr != '\0')
    {
        if (*ptr == 'c')
        {
            printf("Position of 'c': %d\n", position);
            break;
        }
        ptr++;
        position++;
    }

    if (*ptr == '\0')
    {
        printf("Character 'c' not found in the string.\n");
    }

    return 0;
}
