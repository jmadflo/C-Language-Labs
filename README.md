# C-Language-Labs
Lab assignments from my class Programming for Scientists and Engineers

- Lab 1 Instructions:
Three points on the coordinate xy-plane determine a triangle, this could be a degenerate triangle.
You need to write a C program that prompts the user to enter six real numbers that represent the coordinates of three points on the Cartesian plane, and your program should report
the area
the perimeter
the length of each side
of the generated triangle.

- Lab 2 Instructions:
Let R and S be two rectangles in the xy-plane whose sides are parallel to the coordinate axes. Each rectangle is described by its center and its height and width. Determine if R and S overlap.

- Lab 3 Instructions:
Write a program that prompts the user to enter a positive integer n and displays a pyramid, as shown in the following sample run:  
Enter the number of lines: 7

                  1
                  
                2 1 2
                
              3 2 1 2 3
              
            4 3 2 1 2 3 4
            
          5 4 3 2 1 2 3 4 5
          
        6 5 4 3 2 1 2 3 4 5 6
        
      7 6 5 4 3 2 1 2 3 4 5 6 7 
      

- Lab 4 Instructions:
  Write a C program that generates two files: one named random_ints.txt containing 1≤n≤1000 random integers, separated by commas, in the     range [2,1000000]; and a second file named primes.txt that contains a list of those prime numbers contained in random.txt.

- Lab 5 Instructions:
  Write a C program that prompts the user a nonnegative integer n and produces an array of arrays of integers that contain the binomial     coefficients (rs) where 0≤s≤r≤n and prints them row by row. 
  Example:
  Suppose that n=5, then your array of arrays should be:

  1

  1 1

  1 2 1

  1 3 3 1

  1 4 6 4 1

  1 5 10 10 5 1


- Lab 6 Instructions:
  Define the Circle structure that contains:

  Two double data fields named x and y that specify the center of the circle.

  A data field radius.

  Define the following functions

  A function that creates a circle with the specified x, y, and radius. and returns a pointer to it.

  A function get_area(Circle * c) that returns the area of a circle.

  A function get_perimeter(Circle * c) that returns the perimeter of a circle.

  A function contains(Circle * c, double x, double y) that returns true if the specified point (x, y) is inside the circle c.

  A function contains(Circle * c1, Circle * c2) that returns true if c1 is inside c2.

  A function overlaps(Circle * c1, Circle * c2) that returns true if c1 overlaps with c2.

  Construct examples to test each of your functions.

- Lab 7 Instructions:

  Using the Node structure

  An integer data field named elem.

  A pointer field named next.

  Define the following functions

  A function that given an array of integers, creates a list with the elements of the array and returns a pointer to the head of the list.

  A function get_length(Node * h) that returns the length of a given list.

  A function append(Node *  h, int n) that appends a node containing n at the end of the list h.

  A function pre_append(Node *  h, int n) that pre_appends a node containing n at the beginning of the list h.

  A function join(Node * h1, Node * h2) that joins the list defined by h1 followed by the list h2.

  Construct examples to test each of your functions.


- Euler's Method: A program which uses Euler's Method for solving differential equations in a numerical way to solve equations of the type:

  dy/dx = ax^b + cy^d + e
