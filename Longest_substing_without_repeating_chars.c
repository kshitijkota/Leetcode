//Question url: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*

In this approach, I find the longest substring without repeating characters by using two pointers:
1. start: Points to the beginning of the current window.
2. end: Points to the end of the current window.

I also use a hashmap to keep track of whether each character is visited or unvisited.

- If the character at the "end" pointer is unvisited, I increase the size of the window, mark the character as visited, and increment the "end" pointer.
- If the character at the "end" pointer is already visited, I increment the "start" pointer by one, decrease the size of the window, and unmark the character at "start".

This logic ensures that the algorithm runs in O(n) time complexity.

*/

#include <stdio.h>
#include <string.h>

int hash_function(char a){
    int val;
    val=a;
    return val;
}

int lengthOfLongestSubstring(char* s) {
    int longest=1;
    int temp_longest=1;
    char array[256]={0};

    if(*s=='\0'){
        return 0;
    }
    char *start=s;
    char *end=s;
    array[hash_function(*s)]=1;
    end++;
    if(*end=='\0'){
        return 1;
    }
    while(*end!='\0'){
        if(array[hash_function(*end)]==0){
            array[hash_function(*end)]=1;
            end++;
            temp_longest++;
        }
        else if(array[hash_function(*end)]==1){
            array[hash_function(*start)]=0;
            start++;
            temp_longest--;
        }
        else if(start==end){
            end++;
            temp_longest++;
        }
        if(temp_longest>longest){
            longest=temp_longest;
        }

    }
    return longest;
}