/*Author: Aaron Marlatt
*CSE 155e
*1/24/2018
*
*
*This program tells the user whether or not they are exceeding their
*average daily usage, how much they will exceed their limit by, and
*how much data they can use on average for the rest of the cycle when
*the user inputs days used, days remaining and average data usage.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char **argv)
{
  double gigabytesStart;
  double currentDay;
  double totalGBUsed;
  double gigsRemaining;
  double daysRemaining;
  double idealAverage;
  double currentAverage;
  double neededAverage;
  double estimatedExcess;

  printf("Please enter the number of Gigabytes in your 30 day plan:");
  scanf("%lf", &gigabytesStart);
  printf("Please enter the current day in your cycle:");
  scanf("%lf", &currentDay);
  printf("Please enter the total number of Gigabytes used so far:");
  scanf("%lf", &totalGBUsed);
  if (currentDay > 30 || currentDay < 0 || gigabytesStart < 0 || totalGBUsed < 0){
    printf("Invalid. Please try again.");
  }
  else if(totalGBUsed >= gigabytesStart){
    printf("You're out of data. Sorry.");
  }
  else{
    daysRemaining = 30-currentDay;
    currentAverage = totalGBUsed/currentDay;
    gigsRemaining = gigabytesStart-totalGBUsed;
    estimatedExcess = (daysRemaining*currentAverage)-(gigsRemaining);
    neededAverage = gigsRemaining/daysRemaining;
    idealAverage = gigabytesStart/30;
    if(currentAverage > idealAverage){
      printf("You are exceeding your average daily use (%lf GB/day).\nContinuing this high usage, you'll exceed your data plan by %lfGB.\n\nTo stay below your data plan, use no more than %lf GB/day.", idealAverage,estimatedExcess,neededAverage);
    }
    else if (currentAverage == idealAverage){
      printf("Your current usage is ideal (%lf GB/day).", idealAverage);
    }
    else{
      printf("You are using under your average daily usage. (%lf GB/day). Your current usage is %lf GB/day.", idealAverage,currentAverage);
    }
  }


return 0;

}
