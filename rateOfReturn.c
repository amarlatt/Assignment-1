/*Author: Aaron Marlatt
*1/25/2018
*CSCE 155e
*
*
*This program gives rate of return when user inputs initial investment,
*days weeks and years invested, and amount of investment at the end.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char **argv){
  double initial;
  double final;
  double years;
  double weeks;
  double days;
  double finalYears;
  double base;
  double exponent;
  double percent;
  double answer;

  printf("Please enter initial amount invested:");
  scanf("%lf", &initial);

  printf("Please enter final amount:");
  scanf("%lf", &final);

  printf("Please enter total years invested:");
  scanf("%lf", &years);

  printf("Please enter remaining weeks invested:");
  scanf("%lf", &weeks);

  printf("Please enter remaining days invested:");
  scanf("%lf", &days);

  if(initial < 0 || years < 0 || weeks < 0 || days < 0 || years+days+weeks < 0){
    printf("Invalid. Please try again.\n");
    exit (1);
  }
  else{
    finalYears = years+((weeks*7)/365)+(days/365);
    base = final/initial;
    exponent = 1/finalYears;
    percent = pow(base,exponent);
    answer = 100*(percent-1);

    printf("Your rate of return is %lf percent.\n", answer);
  }

  return 0;
  }
