// Zahran Yahia Khan
/*This program takes a user-entered string, compresses it using a simple algorithm that encodes 
consecutive repeating characters, and outputs the compressed string.*/

#include <stdio.h>
#define N 1000
// the input length for the string is no more than 1000 characters

void compress(char *input, char *output); // function declaration

void compress(char *input, char *output)
{
    char *p = input; // will use it to go through the input string
    char *q = output; // will use it to make the output string


    // continue processing until the end of the input string
    while (*p != '\0')
    {
        char *next = p + 1; // pointer to the next character
        int count = 1; // starting with the value 1 as we have at least one occurrence of *p

        // counting consecutive characters
        while (*next == *p)
        {
            count++;
            next++;
        }

        // if there is only one occurrence of the character, add it to the output string
        if(count == 1)
        {
            *q++ = *p;
        }

        // If there are two occurrences of the character, similarly, adding them to the input string
        else if(count == 2)
        {
            *q++ = *p;
            *q++ = *p;
        }

        // if the value of count is greater than 2
        else
        // convert the count to a character and store it in the compressed string
        {
            *q++ = (char)(count + '0'); 
            *q++ = *p; // copy the character to the compressed string
        }
        
        p = next; // Moving to the next character
    }

    *q = '\0'; // Null-terminate the output string
}

int main()
{
    char string1[N+1];
    char string2[N+1];

    printf("Enter message: ");
    scanf("%s",string1);

    compress(string1, string2);

    printf("Output: %s\n", string2);

    return 0;
}