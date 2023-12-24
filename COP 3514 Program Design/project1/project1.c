// Zahran Yahia Khan. This program calculates the charges for a floor cleaning equipment rental.

#include <stdio.h>

int main()
{
    int equipment;
    int days;
    int hours;
    int four_hrs_rate;
    int per_day, per_week; // per day rate, per week rate
    int total = 0;

    int day_cost, hrs_cost, week_cost; // daily cost, hourly cost, weekly cost
    int no_of_weeks, leftover_days; 
    int checking_capped_cost ;
    int leftover_days_cost;


    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection:");
    scanf(" %d", &equipment);
    while (equipment==1 || equipment==2 || equipment==3 || equipment==4)
    {

        printf("Enter days:");
        scanf(" %d", &days);

        printf("Enter hours:");
        scanf(" %d", &hours);

        if (hours<0 || hours>=24)
        {
            printf("Invalid hours.");

        }
        else
        {

            if (equipment==1)
            {
                four_hrs_rate = 7;
                per_day = 10;
                per_week = 40;
                
                if ( (days/7)==0 )
                {
                    day_cost = days*per_day;

                    if (hours<=4) // mistake in logic when hours is equal to 0
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }

                    total = day_cost+hrs_cost;
                    printf("Charge($): %d",total);

                    
                } else{

                    no_of_weeks = days/7;
                    leftover_days = days%7;

                    leftover_days_cost = leftover_days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }
                    
                    checking_capped_cost = leftover_days_cost + hrs_cost;


                    if (checking_capped_cost < per_week)
                    {
                        week_cost = no_of_weeks*per_week;
                        total = week_cost + leftover_days_cost + hrs_cost;
                    } else{
                        week_cost = (no_of_weeks+1) * per_week;
                        total = week_cost;
                    }
                    printf("Charge($): %d",total);
                }


            } else if (equipment==2)
            {
                four_hrs_rate = 27;
                per_day = 39;
                per_week = 156;
                
                if ( (days/7)==0 )
                {
                    day_cost = days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }

                    total = day_cost+hrs_cost;
                    printf("Charge($): %d",total);

                    
                } else{

                    no_of_weeks = days/7;
                    leftover_days = days%7;

                    leftover_days_cost = leftover_days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }
                    
                    checking_capped_cost = leftover_days_cost + hrs_cost;


                    if (checking_capped_cost < per_week)
                    {
                        week_cost = no_of_weeks*per_week;
                        total = week_cost + leftover_days_cost + hrs_cost;
                    } else{
                        week_cost = (no_of_weeks+1) * per_week;
                        total = week_cost;
                    }
                    printf("Charge($): %d",total);
                }
                
            } else if (equipment==3)
            {
                four_hrs_rate = 61;
                per_day = 87;
                per_week = 348;
                
                if ( (days/7)==0 )
                {
                    day_cost = days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }

                    total = day_cost+hrs_cost;
                    printf("Charge($): %d",total);

                    
                } else{

                    no_of_weeks = days/7;
                    leftover_days = days%7;

                    leftover_days_cost = leftover_days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }
                    
                    checking_capped_cost = leftover_days_cost + hrs_cost;


                    if (checking_capped_cost < per_week)
                    {
                        week_cost = no_of_weeks*per_week;
                        total = week_cost + leftover_days_cost + hrs_cost;
                    } else{
                        week_cost = (no_of_weeks+1) * per_week;
                        total = week_cost;
                    }
                    printf("Charge($): %d",total);
                }
                
            } else if (equipment==4)
            {
                four_hrs_rate = 59;
                per_day = 84;
                per_week = 336;
                
                if ( (days/7)==0 )
                {
                    day_cost = days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }

                    total = day_cost+hrs_cost;
                    printf("Charge($): %d",total);

                    
                } else{

                    no_of_weeks = days/7;
                    leftover_days = days%7;

                    leftover_days_cost = leftover_days*per_day;

                    if (hours<=4)
                    {
                        hrs_cost = four_hrs_rate;
                    } else{
                        hrs_cost = per_day;
                    }
                    
                    checking_capped_cost = leftover_days_cost + hrs_cost;


                    if (checking_capped_cost < per_week)
                    {
                        week_cost = no_of_weeks*per_week;
                        total = week_cost + leftover_days_cost + hrs_cost;
                    } else{
                        week_cost = (no_of_weeks+1) * per_week;
                        total = week_cost;
                    }
                    printf("Charge($): %d",total);
                }
    
            }
            
        }

        return 1; 

    }
    printf("Invalid selection. Select from 1 to 4.");

    return 0;
}