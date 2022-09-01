/**
 * Andrew Duweling and Nicholas Wayman
 * 2022/08/31
 *
 * This program prompts the user to enter
 * the latitude and longitude of two locations
 * and then computes the distance betwen them
 * using the formula:
 *
 * d = arccos (sin(φ1) sin(φ2) + cos(φ1) cos(φ2) cos(∆)) · R
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double latitudeA, longitudeA, latitudeB, longitudeB;

  printf("Please enter the latitude of location A:\n");
  scanf("%lf", &latitudeA);
  if(latitudeA < -90 || latitudeA > 90) {
      printf("ERROR: please enter a valid coordinate between -90 and 90\n");
      exit(1);
  }

  printf("Please enter the longitude of location A:\n");
  scanf("%lf", &longitudeA);
  if(longitudeA < -180 || longitudeA > 180) {
      printf("ERROR: please enter a valid coordinate between -180 and 180\n");
      exit(1);
  }

  printf("Please enter the latitude of location B:\n");
  scanf("%lf", &latitudeB);
  if(latitudeB < -90 || latitudeB > 90) {
      printf("ERROR: please enter a valid coordinate between -90 and 90\n");
      exit(1);
  }

  printf("Please enter the longitude of location A:\n");
  scanf("%lf", &longitudeB);
  if(longitudeB < -180 || longitudeB > 180) {
      printf("ERROR: please enter a valid coordinate between -180 and 180\n");
      exit(1);
  }

  double latitudeRadA = ((latitudeA) / 180) * M_PI;
  double longitudeRadA = ((longitudeA) / 180) * M_PI;
  double latitudeRadB = ((latitudeB) / 180) * M_PI;
  double longitudeRadB = ((longitudeB) / 180) * M_PI;
  double radius = 6371;
  double distance = acos(sin(latitudeRadA) * sin(latitudeRadB) + cos(latitudeRadA) * cos(latitudeRadB) * cos(longitudeRadB - longitudeRadA)) * radius;

  printf("Location Distance\n");
  printf("========================\n");
  printf("Origin:      (%lf, %lf)\n", latitudeA, longitudeA);
  printf("Destination: (%lf, %lf)\n", latitudeB, longitudeB);
  printf("Air distance is %lf kms\n", distance);

}
