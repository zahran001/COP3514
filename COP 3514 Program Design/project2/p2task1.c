// Zahran Yahia Khan. This program determines whether a user entered a number which contains at least one digit 3 and is a multiple of 3.

#include <stdio.h>

int main()
{
    int number;
    printf("Enter input:");
    scanf(" %d", &number);
    
    int calculate_length = number; // Variable to calculate the length of the variable 'number'
    int convert_number = number; // Variable to convert 'number' into a string (1-D array)
    
    int length_number=0; // Length of the variable number
    do
    {
        ++length_number;
        calculate_length /= 10; // Divide by 10 to count digits
        
    } while (calculate_length); 
    
    
    char str[length_number]; // Declare a character array to hold the string representation of 'number'
    
    int i = 0; // Initialize index for 'str'
    int j = 0; // Initialize index for iterating through 'str'

    // Convert 'number' to a string and store it in 'str'
    while (convert_number != 0)
    {
        int digit = convert_number % 10;
        str[i++] = digit + '0'; // Convert digit to character and store it in 'str'
        convert_number /= 10; // Move to the next digit
    }
    
    str[i] = '\0'; // Null-terminate the string since each String is terminated with a null character (\0).
    
    // The string str will be in reversed order but it will not affect out calculation as we are just looking for the character 3 throughout the string.
 
    // for numbers which are divisible by 3
    if ((number%3) == 0) 
    {
        while (j < length_number)
        {
            if (str[j] == '3')
            {
                printf("yes\n"); // number is divisible by 3 and contains the digit 3
                return 1; // exit the program with a success code
            }
            j++;
        }
        printf("no\n"); // number is divisible by 3 but doesn't contain the digit 3
    }
    else
    {
        printf("no\n"); // number is not divisible by 3
    }
    return 0;
    
}