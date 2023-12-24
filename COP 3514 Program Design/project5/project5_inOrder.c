// Zahran Yahia Khan. This program determines if the input characters are in order or not.

#include <stdio.h>
#include <ctype.h> // Used to handle character case and classification

int inOrder(char *input); // function declaration

int inOrder(char *input)
{
    char *p = input;
    while ((*p != '\0') && (*(p+1) != '\0'))
    {
        // converting characters to lowercase
        char ch1 = tolower(*p);
        char ch2 = tolower(*(p + 1));

        // checking if both characters are alphabetical
        if ((ch1 >= 'a' && ch1 <= 'z') && (ch2 >= 'a' && ch2 <= 'z'))
        {
            // checking if characters are in ascending order
            if (ch2 < ch1)
            {
                return 0; // Not in order
            }
        }
        else
        {
            return -1; // Invalid input (non-alphabetical letter)
        }

        p++;
    }
    return 1; // In order
}

//main function
int main(int argc, char *argv[])
{
    // check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("invalid input\n");
        return 1; // Exiting with an error status
    }

    // get input from command-line arguments
    char *input = argv[1];

    // calling the function to check if characters are in order
    int result = inOrder(input);
    if (result == 1)
    {
        printf("in order\n");
    }
    else if (result == 0)
    {
        printf("not in order\n");
    }
    else if (result == -1)
    {
        printf("invalid input\n");
    }

    return 0;
}