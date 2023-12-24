// Zahran Yahia Khan
// This program is designed to compute the exclusive OR of two input arrays, resulting in an array containing elements that are present in either of the input arrays, but not in both. 

#include <stdio.h>

// function declaration
void exclusive_or(int *a, int n1,  int *b, int n2, int *c, int *size); 

int main()
{
	int i; // Variable declarations
	int n1;
    int n2;

    // User input for the length and elements of array #1
	printf("Enter length of array #1:");
	scanf("%d", &n1);
	int a[n1];
	printf("Enter array elements: "); 
	for(i=0;i<n1;i++)
		scanf("%d", &a[i]);


    // User input for the length and elements of array #2
    printf("Enter length of array #2:");
	scanf("%d", &n2);
    int b[n2];
    printf("Enter array elements: "); 
	for(i=0;i<n2;i++)
		scanf("%d", &b[i]);

    // Output array declaration
    int c[n1+n2];
    // The actual length of the output array will be determined by the exclusive_or function.

    int size; 
    exclusive_or(a, n1, b, n2, c, &size);
    // The function needs to modify the value of the size variable, and passing its address allows the function to do that.

    // Printing the result
    printf("Output: ");
    for (i = 0; i < size; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

	
	return 0;
}

// Function to find the exclusive OR of two arrays
void exclusive_or(int *a, int n1,  int *b, int n2, int *c, int *size)
{
    // declaring the pointers
    int *p;
    int *q;
    int *r = c;
    *size = 0; // initializing the variable pointed to by the 'size' pointer with the value 0

    // Processing Array 'a'
    for (p = a; p < a+n1; p++)
    {
        int repeat = 0; // will use it to check whether an element is repeated in the other array

        // Nested loop to check for repeated elements in Array 'b'
        for (q = b; q < b+n2; q++)
        {
            if (*p == *q)
            {
                repeat = 1; // Flag indicating that the element is repeated
                break;
            }
        }
        
        // If the element is not repeated, add it to the result array 'c'
        if (repeat == 0)
        {
            *r++ = *p;
            // Incrementing the value pointed to by the 'size' pointer
            (*size)++;
        }
        
    }
    
    // Processing Array 'b'
    for (q = b; q < b+n2; q++)
    {
        int repeat = 0; // will use it to check whether an element is repeated in the other array

        // Nested loop to check for repeated elements in Array 'a'
        for (p = a; p < a+n1; p++)
        {
            if (*q == *p)
            {
                repeat = 1; // Flag indicating that the element is repeated
                break;
            }
        }
        
        // If the element is not repeated, add it to the result array 'c'
        if (repeat == 0)
        {
            *r++ = *q;
            // Incrementing the value pointed to by the 'size' pointer
            (*size)++;
        }
        
    }
}

