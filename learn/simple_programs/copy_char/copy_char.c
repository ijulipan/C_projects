/*
Task: Write a function to copy the first n characters from an
array src to an array dst. Below is given a function to use
void copy_n(char dst[], char src[], int n);

1. write two arrays, dst and src
2. src will be filled with characters while dst is empty
3. find the total number of elements in src then loop through 
each element
4. put each character in a temp variable and copy over to dst*/

#include <stdio.h>

// Solution when using array indexing
void copy_n(char dst[], char src[], int n){

    for (int i = 0;i < n;i++){
        dst[i] = src[i];
    }
}


// Solution when using pointer arithmetics
void copy_n(char *dst, const char *src, int n){
    for(int i = 0;i < n;i++){
        *(dst + i) = *(src + i);
    }
}


int main(){
    char src[] = "Hello, World!";

    int n = sizeof(src) / sizeof(src[0]);
    int dst_size = n + 1;
    char dst[dst_size];

    copy_n(dst, src, n);

    printf("Source: %s\n", src);
    printf("Destination: %s\n", dst);

    return 0;


}