#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TEST_CHECK(exp) \
    do { if (!(exp)) { \
        fprintf(stderr, "%s:%d: Check failed: %s\n", __FILE__, __LINE__, #exp); \
        exit(1); \
    } } while(0)

int add_values(int a, int b) { return a + b; }
void swap_values(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int sum_array(int *arr, int n) { 
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    return total;
}

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

double average(int *arr, int n) { return (double)sum_array(arr, n) / n; }
int find_max(int *arr, int n, int *index) {
    *index = 0;
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            *index = i;
        }
    }
    return max_val;
}

void invert_colors(unsigned char *p, int w, int h) {
    for (int i = 0; i < w*h; i++) p[i] = 255 - p[i];
}

int main() {
    TEST_CHECK(add_values(3,4) == 7);
    
    int a=1,b=2;
    swap_values(&a,&b);
    TEST_CHECK(a == 2 && b == 1);
    
    int test_arr[] = {1,2,3,4,5};
    TEST_CHECK(sum_array(test_arr,5) == 15);
    
    reverse_array(test_arr,5);
    TEST_CHECK(test_arr[0] == 5 && test_arr[4] == 1);  
    
    TEST_CHECK(fabs(average(test_arr,5) - 3.0) < 0.01);
    
    unsigned char test_pixels[25];
    for (int i = 0; i < 25; i++) test_pixels[i] = i % 256;
    invert_colors(test_pixels,5,5);
    TEST_CHECK(test_pixels[0] == 255);
    
    printf("All tests passed\n");
    return 0;
}
