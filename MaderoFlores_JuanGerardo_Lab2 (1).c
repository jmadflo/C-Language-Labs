#include <stdio.h>
#include <math.h>

int main(void) 
{
  float center_x1;
  float center_y1;
  float height1;
  float width1;
  float center_x2;
  float center_y2;
  float height2;
  float width2;

  printf("Please provide the center point, height, and width for two rectangles as a comma separated list of numbers.\n");
  printf("Example: 1,2,3,4,5,6,7,8 for a rectangle of center point (1,2), height of 3, and width of 4 and a second rectangle with a center point (5,6), height of 7, and width of 8.\n");
  scanf("%f,%f,%f,%f,%f,%f,%f,%f", &center_x1, &center_y1, &height1, &width1, &center_x2, &center_y2, &height2, &width2);
  
  int vertical_overlap = (fabs(center_y1-center_y2)<((height1/2)+(height2/2)));
  int horizontal_overlap = (fabs(center_x1-center_x2)<((width1/2)+(width2/2)));
  
  if ( vertical_overlap && horizontal_overlap){
    printf("\nThe rectangles overlap");
  } 
  else {
    printf("\nThe rectangles do not overlap");
  }
  return 0;
}