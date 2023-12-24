// Zahran Yahia Khan. This program determines if the input characters are in order or not.

#include <stdio.h>
#include <ctype.h> // Used to handle character case and classification

int main()
{
    char ch1;
    char ch2;
    int in_order = 1; // Flag to track if characters are in order
    
    printf("Enter input:");

    ch1 = getchar(); // Get the first character
    char ch1_lowercase = tolower(ch1); // Convert it to lowercase
    
    // Get the second character
    while((ch2 = getchar())!='\n')
    {
        
        char ch2_lowercase = tolower(ch2); // Convert it to lowercase
        //check for alphabetical letters
        if((ch1_lowercase>='a' && ch1_lowercase<='z') && (ch2_lowercase>='a' && ch2_lowercase<='z')) 
        {
            // the second character has to be greater than or equal to the first one 
            if (ch2_lowercase < ch1_lowercase) 
            {
                in_order = 0; // Set the flag to indicate characters are not in order
            } 
        }
        else
        {
            printf("invalid input\n");
            return 1; // Exit the program due to invalid input  
        }
             
        ch1_lowercase = ch2_lowercase; // Update ch1_lowercase for the next iteration
    }
    
    if (in_order)
    {
        printf("in order\n");
    } else {
        printf("not in order\n");
    }
 
    return 0;
}