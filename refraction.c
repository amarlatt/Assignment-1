/** Author: Aaron Marlatt
*Date 1/18/2018
*Assignment 1 Part 1 - refraction.c
*
*
* Program to find angle of refraction in water when both angle of light and refraction index
*are inputted by the user
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1)

int main (int argc, char **argv)
{
double incidence;
printf("Enter angle of incidence in degrees:\n");
scanf("%lf", &incidence);

if (incidence >= 0 && incidence <= 180) {
	double radians = incidence*PI/180;
	double index;
	printf("Thank you. Now please enter refraction index:\n");
	scanf("%lf", &index);
	if (index >= 0) {
		double SnellLeft = sin(radians)/index;
		double answer = asin(SnellLeft)*180/PI;
		printf("Your answer is %lf degrees\n", answer);
	}
	else {
		printf("Invalid refraction index. Please try again.\n");
	}
}
else {
	printf("Invalid angle measurement. Please try again.\n");
}
return 0;
}