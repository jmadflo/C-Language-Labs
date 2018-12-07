#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Circle{
    double x, y;
    double radius;
};

typedef struct Circle Circle;

Circle * return_pointer(double x, double y, double radius) {
    Circle * c = (Circle*)malloc(sizeof(Circle));
    c->x = x;
    c->y = y;
    c->radius = radius;
    return c;
}

double get_area(Circle * c) {
    return M_PI * c->radius * c->radius;
}

double get_perimeter(Circle * c) {
    return 2 * M_PI * c->radius;
}

int contains_point(Circle * c, double x, double y) {
    double distance_from_center = sqrt((x - c->x)*(x - c->x) + (y - c->y)*(y - c->y));
    if(distance_from_center <= c->radius) {
        return 1;
    } else {
        return 0;
    }
    
}

int contains_circle(Circle * c_1, Circle * c_2) {
    double distance = sqrt((c_1->x - c_2->x)*(c_1->x - c_2->x) + (c_1->y - c_2->y)*(c_1->y - c_2->y));
    if(c_2->radius > (distance + c_1->radius)) {
        return 1;
    } else {
        return 0;
    }
}

int overlaps(Circle * c_1, Circle * c_2) {
    double distance = sqrt((c_1->x - c_2->x)*(c_1->x - c_2->x) + (c_1->y - c_2->y)*(c_1->y - c_2->y));
    if(c_2->radius  + c_1->radius > distance) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    printf("Testing:\n");
    printf("c_1 is a circle of center point (7,8) and radius 9, while c_2 is a circle of center point (3,4) and radius 5\n");
    Circle * c_1 = return_pointer(7, 8, 9);
    Circle * c_2 = return_pointer(1, 2, 5);
    
    //test function 1
    if (c_1 && c_2){
        printf("The two circles have been successfully created!\n");
    }
    
    //test function 2
    printf("Area of first circle =  %f\n",  get_area(c_1));
    printf("Area of second circle =  %f\n",  get_area(c_2));
    
    //test function 3
    printf("Parameter of first circle = %f\n", get_perimeter(c_1));
    printf("Parameter of second circle = %f\n", get_perimeter(c_2));
    
    //test function 4
    if(contains_point(c_1, 6, 7)){
        printf("The point (6,7) is inside the first circle.\n");
    } else {
        printf("The point (6,7) is not inside the first circle.\n");
    }
    if(contains_point(c_2, 6, 7)){
        printf("The point (6,7) is inside the second circle.\n");
    } else {
        printf("The point (6,7) is not inside the second circle.\n");
    }
    
    //test function 5
    if(contains_circle(c_1, c_2)){
        printf("The first circle is contained inside the second circle.\n");
    } else {
        printf("The first circle is not contained inside the second circle.\n");
    }
    if(contains_circle(c_2, c_1)){
        printf("The second circle is contained inside the first circle.\n");
    } else {
        printf("The second circle is not contained inside the second circle.\n");
    }
    
    //test function 6
    if(overlaps(c_1, c_2)){
        printf("The two circles overlap.\n");
    } else {
        printf("The two circles do not overlap.\n");
    }
    return 0;
}