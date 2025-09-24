/**
 * Student Name: Koshin Mohamed
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}



int test_swap_two() {
    printf("2. test_swap_one()\n");
    int a = 15;
    int b = 30;
    swap(&a, &b);
    if (a == 30 && b == 15) {
        return 1;
    }
    return 0;
}


/**
 * Tests the create_array_of_ints_fib function
*/

int test_create_array_of_ints_fib() {
    printf("3. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); 
    return 1;
}

int test_create_array_of_ints_fibTwo() {
    printf("4. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(10);
    int expected[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    for (int i = 0; i < 10; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); 
    return 1;
}



int test_reverse_array(){
printf("5. test_reverse_array()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};

    reverse_array(arr, 5);

    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) return 0;
    }
    return 1;
}

int test_reverse_arrayTwo() {
    printf("6. test_reverse_arrayTwo()\n");
    int arr[] = {10, 20, 30, 40};
    int expected[] = {40, 30, 20, 10};

    reverse_array(arr, 4);

    for (int i = 0; i < 4; i++) {
        if (arr[i] != expected[i]) return 0;
    }
    return 1;
}

// Double Array Tests

int test_double_array_size() {
    printf("7. test_double_array_size()\n");
    int arr[] = {1, 2, 3, 4};
    int *new_arr = double_array_size(arr, 4);
    if (!new_arr) return 0;

    int expected[] = {1, 2, 3, 4, 0, 0, 0, 0};
    for (int i = 0; i < 8; i++) {
        if (new_arr[i] != expected[i]) {
            free(new_arr);
            return 0;
        }
    }

    free(new_arr);
    return 1;
}

int test_double_array_sizeTwo() {
    printf("8. test_double_array_sizeTwo()\n");
    int arr[] = {100, 200, 300, 400};
    int *new_arr = double_array_size(arr, 4);
    if (!new_arr) return 0;

    int expected[] = {100, 200, 300, 400, 0, 0, 0, 0};
    for (int i = 0; i < 8; i++) {
        if (new_arr[i] != expected[i]) {
            free(new_arr);
            return 0;
        }
    }

    free(new_arr);
    return 1;
}

// Tests for Copying elements of an array from start to end into a new array and vice versa


int test_copy_array_start_end_loop() {
    printf("9. test_copy_array_start_end_loop()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int *new_arr = copy_array_start_end_loop(arr, 5, 1, 3, &new_size); 
    if (!new_arr) return 0;

    int expected[] = {2, 3, 4};
    for (int i = 0; i < new_size; i++) {
        if (new_arr[i] != expected[i]) {
            free(new_arr);
            return 0;
        }
    }
    free(new_arr);
    return 1;
}


int test_copy_array_start_end_loopTwo() {
    printf("10. test_copy_array_start_end_loopTwo()\n");
    int arr[] = {1, 2, 3, 4, 5};
    int new_size;
    int *new_arr = copy_array_start_end_loop(arr, 5, 3, 1, &new_size); 
    if (!new_arr) return 0;

    int expected[] = {4, 5, 1, 2};
    for (int i = 0; i < new_size; i++) {
        if (new_arr[i] != expected[i]) {
            free(new_arr);
            return 0;
        }
    }
    free(new_arr);
    return 1;
}

// Tests to creating point 

int test_create_point_one() {
    printf("11. test_create_pointOne()\n");
    Point* p = create_point(10, 20);
    if (!p) return 0;
    if (p->x != 10 || p->y != 20) {
        free(p);
        return 0;
    }
    free(p);
    return 1;
}


int test_create_point_two() {
    printf("12. test_create_pointTwo()\n");
    Point* p = create_point(8, 16);
    if (!p) return 0;
    if (p->x != 8 || p->y != 16) {
        free(p);
        return 0;
    }
    free(p);
    return 1;
}

// Testing creating a polygons  

int test_create_polygon_sizeOne() {
    printf("13. test_create_polygon_sizeOne()\n");
    Polygon *poly = create_polygon(3);
    if (!poly) return 0;

    if (poly->size != 3) {
        free(poly->points);
        free(poly);
        return 0;
    }

    free(poly->points);
    free(poly);
    return 1;
}


int test_create_polygon_sizeTwo() {
    printf("14. test_create_polygon_sizeTwo()\n");
    Polygon *poly = create_polygon(5);
    if (!poly) return 0;

    if (poly->size != 5) {
        free(poly->points);
        free(poly);
        return 0;
    }

    free(poly->points);
    free(poly);
    return 1;
}


int test_free_polygon() {
    printf("15. test_free_polygon()\n");
    Polygon *poly = create_polygon(8);
    free_polygon(poly);
    return 1; 
}


int test_free_polygonTwo() {
    printf("16. test_free_polygonTwo()\n");
    Polygon *poly = create_polygon(4);
    free_polygon(poly);
    return 1; 
}

// Rectangle Tests

int test_create_rectangleOne() {
    printf("17. test_create_rectangleOne\n");
    Polygon *rect = create_rectangle(2, 3);
    if (!rect || rect->size != 4) return 0;

    if (rect->points[0]->x != 0 || rect->points[0]->y != 0) return 0;
    if (rect->points[2]->x != 2 || rect->points[2]->y != 3) return 0;

    free_polygon(rect);
    return 1;
}

int test_create_rectangleTwo() {
    printf("18. test_create_rectangleTwo\n");
    Polygon *rect = create_rectangle(4, 4);
    if (!rect || rect->size != 4) return 0;

    if (rect->points[1]->x != 4 || rect->points[1]->y != 0) return 0;
    if (rect->points[3]->x != 0 || rect->points[3]->y != 4) return 0;

    free_polygon(rect);
    return 1;
}

// Triangle Tests


int test_create_triangleOne() {
    printf("19. test_create_triangleOne()\n");
    Polygon* tri = create_triangle(6, 8);
    if (!tri) return 0;
    if (tri->size != 3) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0 ||
        tri->points[1]->x != 6 || tri->points[1]->y != 0 ||
        tri->points[2]->x != 6 || tri->points[2]->y != 8) {
        free_polygon(tri);
        return 0;
    }
    free_polygon(tri);
    return 1;
}

// Test for a right triangle with width 10, height 3

int test_create_triangleTwo() {
    printf("20. test_create_triangleTwo()\n");
    Polygon* tri = create_triangle(10, 3);
    if (!tri) return 0;
    if (tri->size != 3) {
        free_polygon(tri);
        return 0;
    }
    if (tri->points[0]->x != 0 || tri->points[0]->y != 0 ||
        tri->points[1]->x != 10 || tri->points[1]->y != 0 ||
        tri->points[2]->x != 10 || tri->points[2]->y != 3) {
        free_polygon(tri);
        return 0;
    }
    free_polygon(tri);
    return 1;
}

// Printing Tests

int test_print_pointOne() {
    printf("21. Print Point One ");
    Point p = {100, 1000};
    print_point(&p);
    printf("\n");
    return 1; 
}


int test_print_pointTwo() {
    printf("22. Print Point Two ");
    Point p = {200, 2000};
    print_point(&p); 
    printf("\n");
    return 1;
}

int test_print_polygonOne() {
    printf("23. Print Polygon One ");
    Polygon *tri = create_triangle(5, 4);
    print_polygon(tri);
    free_polygon(tri);
    return 1;
}

int test_print_polygonTwo() {
    printf("24. Print Polygon Two ");
    Polygon *rect = create_rectangle(3, 2);
    print_polygon(rect);
    free_polygon(rect);
    return 1;
}

// Area Calculation tests

int test_calculate_polygon_areaOne() {
    printf("25. Calculate Polygon Area One Rect: \n");
    Polygon *rect = create_rectangle(2, 2); 
    double area = calculate_polygon_area(rect); 
    printf("Area: %.2f\n", area); 
    free_polygon(rect);
    return 1;
}


int test_calculate_polygon_areaTwo() {
    printf("26. Calculate Polygon Area Two Tri: \n");
    Polygon *tri = create_triangle(9, 6); 
    double area = calculate_polygon_area(tri); 
    printf("Area: %.2f\n", area); 
    free_polygon(tri);
    return 1;
}





// this is a list of all the unit tests

int (*unitTests[])() = {
        test_swap_one,
        test_swap_two, 
        test_create_array_of_ints_fib,
        test_create_array_of_ints_fibTwo,
        test_reverse_array,
        test_reverse_arrayTwo, 
        test_double_array_size, 
        test_double_array_sizeTwo,
        test_copy_array_start_end_loop,
        test_copy_array_start_end_loopTwo,
        test_create_point_one,
        test_create_point_two,
        test_create_polygon_sizeOne,
        test_create_polygon_sizeTwo, 
        test_free_polygon,
        test_free_polygonTwo,
        test_create_rectangleOne,
        test_create_rectangleTwo, 
        test_create_triangleOne,
        test_create_triangleTwo,
        test_print_pointOne,
        test_print_pointTwo,
        test_print_polygonOne,
        test_print_polygonTwo, 
        test_calculate_polygon_areaOne,
        test_calculate_polygon_areaTwo,
    
};


int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
