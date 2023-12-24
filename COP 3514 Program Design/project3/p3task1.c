// Zahran Yahia Khan. This program calculates the charges for a floor cleaning equipment rental.

#include <stdio.h>
int charge(int a, int b, int c, int days, int hours); // function declaration

int main()
{
    int equipment;
    int days;
    int hours;
    int result; // will use it to calculate the final output
    
    int specific_four_hrs_rate; // 4-hour rate for the selected equipment
    int specific_per_day, specific_per_week; // per day rate and per week rate for the selected equipment

    // Using a multidimensional array
    int equipment_rates[4][3] = {
        // Equipment 1: 4-hour rate, per day rate, per week rate
        {7,10,40},
        // Equipment 2: 4-hour rate, per day rate, per week rate
        {27,39,156},
        // Equipment 3: 4-hour rate, per day rate, per week rate
        {61,87,348},
        // Equipment 4: 4-hour rate, per day rate, per week rate
        {59,84,336}
        
    };
    

    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection:");
    scanf(" %d", &equipment);

    if ((equipment==1 || equipment==2 || equipment==3 || equipment==4))
    {
        printf("Enter days:");
        scanf(" %d", &days);

        printf("Enter hours:");
        scanf(" %d", &hours);

        if (hours<0 || hours>=24)
        {
            printf("Invalid hours.");
            return 1; // exit program with status 1 to indicate a nonnormal exit
        }
        
        // get the selected equipment
        specific_four_hrs_rate = equipment_rates[equipment-1][0];
        specific_per_day = equipment_rates[equipment-1][1];
        specific_per_week = equipment_rates[equipment-1][2];
        
        result = charge(specific_four_hrs_rate,specific_per_day,specific_per_week,days,hours);
        printf ("Charge($):%d", result);
        
        
    }
    else
    {
        printf("Invalid selection. Select from 1 to 4.");
        return 1; 
    }

    return 0;
}

// using a function 
// passing values of days and hours from the main function to the charge function by passing them as arguments
int charge(int a, int b, int c, int days, int hours)
{
    
    int four_hrs_rate; // 4-hour rate
    int per_day, per_week; // per day rate, per week rate
    int total = 0;

    int day_cost, hrs_cost, week_cost; // cost of days, cost of hours, cost of weeks
    int no_of_weeks, leftover_days; // leftover_days variable will be used in calculation of capped cost
    int checking_capped_cost;
    int leftover_days_cost;
        
    four_hrs_rate = a;
    per_day = b;
    per_week = c;
        
    // If the calculation of weeks is not needed
    if ((days / 7) == 0)
    {
        day_cost = days * per_day;

    if ((hours>0) && (hours <= 4))
	{
	    hrs_cost = four_hrs_rate;
        // any number of hours greater than 0 and less than or equal to 4-hours will be charged with the 4-hour rate
	} else if (hours==0)
    {
        hrs_cost = 0;
    }
    else
    {
	    hrs_cost = per_day;
        // rental of any period of less than a day will be capped with the per day rate
    }

    total = day_cost + hrs_cost;

    }
    else
    {
        // calculation of weeks is needed
        no_of_weeks = days / 7;
        leftover_days = days % 7; // excess days remaining after the integer value of the number of weeks

        leftover_days_cost = leftover_days * per_day;

        if ((hours>0) && (hours <= 4))
	    {
	        hrs_cost = four_hrs_rate;
	    }
	    
        else if (hours==0)
        {
            hrs_cost=0;
        }
        else
        {
            hrs_cost = per_day;
        }
            
        checking_capped_cost = leftover_days_cost + hrs_cost;
            
        // A rental of any period of less than a week will be capped with the per week rate

        if (checking_capped_cost < per_week)
        {
            week_cost = no_of_weeks * per_week;
            total = week_cost + leftover_days_cost + hrs_cost;
            
        }
        else
        {
            week_cost = (no_of_weeks + 1) * per_week;
            total = week_cost;
        }

    }
     
    return total;
}