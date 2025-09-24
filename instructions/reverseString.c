#include <stdio.h>
#include <string.h>


/**
 Leet Code:

Write a function that reverses a string.
The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
 
 */
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char s[] = "Racecar"; 
    printf("Original: %s\n", s);

    reverseString(s, strlen(s));
    printf("Reversed: %s\n", s);

    return 0;
}

/*
In this module, we learned about pointers, 
which are variables that store the address of other variables. 
Using a pointer for the string (char* s) let me change the 
string directly in memory without making a new one. 
This made it easier to reverse the string because 
I could just swap the characters in the same array.
*/
