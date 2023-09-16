Problem: Intersection Rectangle and Circle
Description

Given a rectangle (segments are parallel with the vertical and horizontal axis) specified by two opposite points (x1,y1), (x2,y2) and a circle specified by the center (x,y) and the radius r. Write a program to check if these two shapes intersect with each other (have common points).

Input
Line 1: contains a positive integer T (1 <= T <= 100000) which is the number of test-cases.
Subsequent lines are test-cases, each test-case consists of two lines:
Line 1: 4 integers x1, y1, x2, y2 (-100000 <= x1, y1, x2, y2 <= 100000)
Line 2: 3 integers x, y, r (-100000 <= x, y, r <= 1000000)

Output
Line i (i = 1,..., T) contains 1 if the answer of the ith test-case is YES, and contains 0, otherwise

Example
Input 
2
0 0 4 2
2 3 2
0 0 3 3
10 10 1

Output 
1
0