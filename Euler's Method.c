#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Suggested Tests
// Test 1: y_prime = 2x + 0y + 0  with 0,0 starting point and 0.5 time step. Solving for x = 10.

struct Point {
    float x;
    float y;
};

typedef struct Point Point;

float start_x, start_y, time_step, final_val, coeff_x, coeff_y, pow_x, pow_y, constant;

Point * create_point(float x, float y){
    Point * p = (Point*)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

float slope(Point * p){
    float slope = ((coeff_x * pow(p->x, pow_x)) + ( coeff_y * pow(p->y, pow_y)) + constant);
    return slope;
}

int print_point_at_index(int i, Point* a[]){
    printf("The point at that index is (%.2f, %.2f)", a[i]->x, a[i]->y);
    return 0;
}


int main(void) {
    printf("Welcome to Euler's Method Helper.\n\nI can help you solve simple differential equations with independent variable x and dependent variable y of the form:\n\ndy/dx = ax^b + cy^d + e.\n\n");
    
    
    printf("First, enter the right hand side of the equation as follows coefficient of x, power of x, coefficient of y, power of y, added constant.\nExample: '2,3,-7,5,-4' for a right hand side of 2x^3 - 7x^5 - 4.\n\n");
    scanf("%f,%f,%f,%f,%f", &coeff_x, &pow_x, &coeff_y, &pow_y, &constant);
    
    printf("\n\nEnter the starting point.\nExample: 4,3 for a point with an x value of 4 and a y value of 3.\n\n");
    scanf("%f,%f", &start_x, &start_y);
    
    printf("\n\nNow, enter the final value of x and the time step used to calculate it.\nExample: '5:0.1' if you want to calculate y value when x = 5 with a time step of 0.1 \n\n**Remember that a small time step means a large number of points, which will yield greater accuracy, but take longer to calculate.\n\n");
    scanf("%f:%f", &final_val, &time_step);
    
    int num_of_points = abs((final_val - start_x) / time_step);
    
    Point* points_array[num_of_points];
    
    FILE *points;
    points = fopen("points.txt", "w");
    
    fprintf(points, "These are the points that were used at each timestep on the way to the final point. The format is as follows: (x value, y value, slope at this point)\n");
    
    int i = 0;
    
    if(final_val <= start_x){
        while (final_val <= start_x){
            points_array[i] = create_point(start_x, start_y);
            float this_slope = slope(points_array[i]);
            fprintf(points, "(%.2f, %.2f, %.2f), \n", points_array[i]->x, points_array[i]->y, this_slope);
            start_x = start_x - time_step;
            start_y = start_y + (time_step * this_slope);
            i++;
            printf("1");
        }
    } else {
        while (final_val >= start_x){
            points_array[i] = create_point(start_x, start_y);
            float this_slope = slope(points_array[i]);
            fprintf(points, "(%.2f, %.2f, %.2f), \n", points_array[i]->x, points_array[i]->y, this_slope);
            start_x = start_x + time_step;
            start_y = start_y + (time_step * this_slope);
            i++;
            printf("1");
        }
    }
    printf("\n\nAll done! The point after each timestep has been added to the points.txt file! There are a total of %d points. If you would like a particular index, then enter it below and you will get the point that belongs on that index.\n\n", num_of_points + 1);
    
    int index;
    scanf("%d", &index);
    
    print_point_at_index(index, points_array);
    
    /*while (1){
     printf("\n\n");
     print_point_at_index(index);
     printf("Feel free to enter another index\n\n");
     scanf("%d", &index);
     }*/
    
    return 0;
}
