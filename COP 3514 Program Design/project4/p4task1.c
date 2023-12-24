// Zahran Yahia Khan. This program calculates the number of seconds that an escalator was active.

#include <stdio.h>
int active_seconds(int arrival[], int n); // function declaration

int main()
{
    int i;
    int no_of_people;
    // Prompt user to enter the number of people
    printf("Enter number of people: ");
    scanf(" %d", &no_of_people);
    
    int result; // will use it to get the final output
    
    // using an array
    int a[no_of_people];
    
    // Prompt user to enter arrival times for each person
    printf("Enter arrival times: ");
    for (i=0; i<no_of_people; i++)
    {
        scanf("%d", &a[i]);
    }
    
    // calculating active seconds using the active_seconds function
    result = active_seconds(a,no_of_people);
    printf("Active seconds: %d",result);
    

    return 0;
}


// active_seconds function calcuates the total number of active seconds
// the array arrival[] represents the arrival time of each person and n is the length of the array arrival, representing the number of people
int active_seconds(int arrival[], int n)
{
    int *p; //declaring a pointer

    int time_count = 0; // will use it to calcuate the total number of active seconds
    int interval; // will use it to check the interval between the arrival times of two people
    
    // Iterating through the array of arrival times using a pointer
    for (p = arrival; p < arrival+n; p++)
    {

        // first person activates the escalator, so add 10 seconds
        if (p == arrival)
        {
            time_count += 10;
        }
        // calculating the interval between the current and previous person
        else
        {
            interval = *p - *(p-1);

            // if the gap is more than 10 seconds, the escalator stops
            if(interval>10)
            {
                time_count += 10;
                // since the amount of time that a person takes to go from the beginning to the end of the escalator is 10 seconds
            }
            else
            {
                // if the gap is 10 seconds or less, escalator remains active for that interval
                time_count += interval;
            }
        }

    }
    
    return time_count; // Returning the total active seconds
    
}