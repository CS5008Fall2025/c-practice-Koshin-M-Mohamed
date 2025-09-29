# Homework - C Practice Report

Completely answer the report questions below. Make sure to double check the final version to make sure it is easily readable on your github repository. 




1. What is the difference between a standard numeric type (int, float, double) and a pointer?


Numeric types int, float, double store numbers while a pointer stores the address of where a value is in the memory. The pointer allows you to change the value it points to. 
   

2. In your test file, we had the following code:
    
    ```c
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    ```
    Later in the code we only `free(arr)` but not expected. Why is this? What is the difference in where they are stored in memory?

    Heap memory is where you store stuff with malloc, so you have to free it yourself, while stack memory is automatic and gets cleaned up when the function ends.

3. What is the difference between the heap and stack when related to memory allocation and management?

The heap is for memory you allocate manually with malloc and have to free yourself, while the stack is automatic memory for local variables that gets cleaned up when the function ends.


4. Take the following code:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point pt = {x, y};
     return &pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      return 0;
   }
   ```
   Would the code run correctly? Even if it does compile, what would be some potential runtime issues? After answering your thoughts, put the output of a run below (you may need to run it a few times).
   

After trying to compile: 

reportTest.c:10:13: warning: function returns address of local variable [-Wreturn-local-addr]
   10 |      return &pt;

The function was returning the address of a local stack variable, and when the function ended that memory went away, so the pointer was pointing to an invalid memory.
   
   Fix the code in the following block:
   ```c
   
   //Fixed up

   #include <stdio.h>
   #include <stdlib.h>

   typedef struct {
     int x, y;
   } Point;

   Point * new_point(int x, int y) {
     Point* pt = malloc(sizeof(Point));
      if (!pt) return NULL;
    pt->x = x;
    pt->y = y;
    return pt;
   }

   int main() {
      Point* point = new_point(10, 10);
      printf("x: %d, y: %d", point->x, point->y);
      free(point);
      return 0;
   }
   ```

5. When you use `malloc`, where are you storing the information?

When you use `malloc`, the memory is stored on the heap, which stays allocated until you manually free it.

6. Speaking about `malloc` and `calloc`, what is the difference between the two (you may need to research it!)?

According to GeeksforGeeks, the difference between `malloc` and `calloc` is that `malloc` just grabs a block of memory without setting it to anything, while `calloc` grabs memory and sets everything to zero. `malloc` takes the total number of bytes, and `calloc` takes how many elements and how big each one is.

7. What are some common built in libraries used for C, list at least 3 and explain each one in your own words. Name a few (at least 3) functions in those libraries (hint: we used two of the most common ones in this assignment. There are many resources online that tell you functions in each library - you need to include at least 1 reference, but ideally for every library, you should have a reference to it)?
   - Example: stdlib.h - provides functions for general-purpose operations including
              memory management and random numbers [1].
     - void * malloc(size_t) - allocates memory specified in size on the heap and returns a pointer to that location
     - void * calloc(size_t num_elements, size_t element_size) - contiguous allocation for allocating arrays with the default value of 0. Slower than malloc. 
     - int rand(void) - returns a random integer between 0 and RAND_MAX. Seed should be set before hand. 
   
   1. string.h
      strcpy() : copies one string into another string
      strcat() : concatenates one string onto the end of another.
      strlen() : gives you the length of a string.
      refrence Geeksforgeeks.org
   
   2. stdio.h
      scanf() : lets you take input from the user
      printf() : prints text or numbers to the screen.
      fopen() : opens a file so you can read or write to it
      refrence Geeksforgeeks.org
  
   3. stdlib.h 
      malloc() : allocates memory on the heap.
      calloc() : allocates memory and also sets it to zero.
      free() : frees up memory you got from malloc or calloc.
 

8. Looking at the struct Point and Polygon, we have a mix of values on the heap, and we make ample use of pointers. Take a moment to draw out how you think that looks after `create_triangle(2,3)` is called (see an example below). The important part of the drawing it to see that not everything is stored together in memory, but in different locations! Store the image file in your github repo and link it here. You can use any program to draw it such as [drawIO](https://app.diagrams.net/), or even draw it by hand and take a picture of it. 

"imageHeap.png" file attached to the intructions folder


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

Question: What is a heap and its various types?

Answer: 

   A heap is a type of tree data structure that follows a special 
rule called the heap property. The heap property just means that the parent node is either always bigger or always smaller than its child nodes depending on the type of heap. From what I read on W3Schools, heaps are mostly used for priority queues because they let you quickly get the smallest or largest value.

   There are different kinds of heaps. The most common one is called a binary heap, which is just a complete binary tree that can be a max heap or a min heap. In a max heap, the parent is always greater than or equal to the children, so the largest number is always at the top. In a min heap, the parent is always smaller than or equal to the children, which means the smallest number is at the top. There are also other types like Fibonacci heap and binomial heap, but those are more advanced and usually used in harder algorithms.




2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others. 

## Deeper Thinking
In Java and Python, do you think new objects are stored on the stack or the heap? Feel free to work through your thoughts as to why it would be better to store them on the stack or heap. You should consider pass by reference, and how that is similar to pointer in your answer. Feel free to use resources, but make sure to cite them, and include the citation below using ACM format. You will note LLMs are not valid references, but they can give you directions to valid references. Make sure to use your own words. 

Answer here using a paragraph (not just bullet points). 

In Python, new objects are usually stored on the heap, which is a part of memory where data can stay even after a function ends. If objects were stored on the stack, they would disappear as soon as the function finished, making it hard to use the same object in different parts of the program. Variables in Python hold references to objects on the heap, which is kind of like pointers in C because the reference lets us access and change the object from different places. This also makes pass by reference possible, so if one variable changes an object, any other variable pointing to it sees the change too. Storing objects on the heap is better for bigger or longer-lasting data, while the stack is more suited for small, short-lived things.


## References
Add any references you use here. Use ACM style formatting, adding to the numbers as you add the reference. 

1. cppreference.com Contributors. 2025. Standard library header <stdlib.h>. cppreference.com. Retrieved May 1, 2025 from https://en.cppreference.com/w/c/header/stdlib

2. Python Software Foundation. (2023). Memory Management — Python 3.13.7 documentation. Retrieved from https://docs.python.org/3/c-api/memory.html

3. GeeksforGeeks. 2025. Difference between malloc() and calloc() in C. GeeksforGeeks. from https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-in-c/


## Resource/Help: Linking to images?
To link an image, you use the following code

```markdown
![alt text](path / link to image)
```
for example
```markdown
![my memory drawing](instructions/rectangle_points.png)
```


Here is a sample using: 
```c
void my_func() {
    Polygon* r = create_rectangle(5,5);
    printf("The area of the rectangle is %d\n", area(r));
}
```

![my memory drawing](instructions/rectangle_points.png)

Note: This is a simplified version. However, it helps illustrate why we need to use `free` on the pointers in the struct. If we do not, we will have memory leaks! (memory that is allocated, but not freed, and thus cannot be used by other programs). In the above example code, `r` is created, and then the variable is destroyed when the function ends. However, the memory allocated for the struct is not freed, and thus we have a memory leak.

When you work on your version for `create_triangle(2, 3)`, you do not have to be exact on the memory structure (the locations on the heap were randomly chosen). The idea is more to show how the memory is stored, and the pointers to different memory addresses. 

