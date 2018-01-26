/*Author: Aaron Marlatt
*1/24/2018
*CSCE 155e
*
*
*This program gives the bearing in degrees on the scale of [0,360) when user
*inputs latitude/longitude of two locations.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main(int argc, char **argv)
{
  double latitudeOrigin;
  double longitudeOrigin;
  double latitudeDestination;
  double longitudeDestination;
  double latOriginRadians;
  double latDestinationRadians;
  double longOriginRadians;
  double longDestinationRadians;
  double longDifferenceRadians;
  double theta;
  //theta is bearing in degrees
  double x;
  double y;
  double answer;
  double pi = M_PI;

  printf("Please enter Latitude of starting point (South needs to be entered as a negative value):");
  scanf("%lf", &latitudeOrigin);
  printf("Please enter Longitude of starting point (West needs to be entered as a negative value):");
  scanf("%lf", &longitudeOrigin);
  printf("Please enter Latitude of destination (South needs to be entered as a negative value):");
  scanf("%lf", &latitudeDestination);
  printf("Please enter Longitude of destination (West needs to be entered as a negative value):");
  scanf("%lf", &longitudeDestination);

  latOriginRadians = (latitudeOrigin*pi)/180;
  latDestinationRadians = (latitudeDestination*pi)/180;
  longOriginRadians = (longitudeOrigin*pi)/180;
  longDestinationRadians = (longitudeDestination*pi)/180;
  longDifferenceRadians = ((longitudeDestination-longitudeOrigin)*pi)/180;

  y = (sin(longDifferenceRadians))*(cos(latDestinationRadians));
  x = (cos(latOriginRadians))*(sin(latDestinationRadians))-(sin(latOriginRadians))*(cos(latDestinationRadians))*(cos(longDifferenceRadians));
  theta = atan2(y,x);
  answer = (theta*180)/pi;
  printf("Your bearing in degrees is %lf", answer);

  return 0;

}
