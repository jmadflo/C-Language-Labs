#include <stdio.h>
#include <math.h>

/*this program provides the area, perimeter, and lengths of sides
of a 2D triangle with x-y coordinates provided by the user*/

int main(void) {
  
  float x1;
  float x2;
  float x3;
  float y1;
  float y2;
  float y3;
  
  float area;
  float perimeter;
  float side1;
  float side2;
  float side3;
  
  printf("Enter the x-y coordinates of the three points of the desired triangle");
  printf(" in the form of a comma separated list of numbers.\n\n");
  printf("Example: 1,2,3,4,5,6  for a triangle PQR of points P(1,2), Q(3,4), and R(5,6)\n\n");
  scanf("%f, %f, %f, %f, %f, %f", &x1, &y1, &x2, &y2, &x3, &y3);
  
  float euclidean_distance_2D (float first_x, float first_y, float second_x, float second_y) {
    return sqrt(((first_x-second_x)*(first_x-second_x))+((first_y-second_y)*(first_y-second_y)));
  }
  
  side1 = euclidean_distance_2D(x1, y1, x2, y2); //without function: use sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
  side2 = euclidean_distance_2D(x2, y2, x3, y3); //without function: use sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
  side3 = euclidean_distance_2D(x3, y3, x1, y1); //without function: use sqrt(((x3-x1)*(x3-x1))+((y3-y1)*(y3-y1)));
  perimeter = side1 + side2 + side3;
  area = .5*fabs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
  
  printf("\nThis triangle has an area of %f, a perimeter of %f, and sides of lengths %f, %f, and %f\n", area, perimeter, side1, side2, side3);
  
  return 0;
}