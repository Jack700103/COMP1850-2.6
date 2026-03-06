#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acutest.h"

int add_values(int a, int b) {
    return a + b;
}

void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void reverse_array(int *arr, int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

double average(int *arr, int n) {
    int sum = sum_array(arr, n);
    return (double)sum / n;
}

int find_max(int *arr, int n, int *index) {
    *index = 0;
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            *index = i;
        }
    }
    return max;
}

void invert_colors(unsigned char *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        pixels[i] = 255 - pixels[i];
    }
}

void rotate_90(unsigned char *pixels, int width, int height) {
    unsigned char *temp = malloc(width * height);
    memcpy(temp, pixels, width * height);
    
    int new_width = height;
    int new_height = width;
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixels[(y * new_width) + (new_width - 1 - x)] = temp[(x * height) + y];
        }
    }
    free(temp);
}

void scale_image(unsigned char *pixels, int width, int height, float scale) {
    int new_width = (int)(width * scale);
    int new_height = (int)(height * scale);
    unsigned char *scaled = malloc(new_width * new_height);
    
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int src_x = (int)(x / scale);
            int src_y = (int)(y / scale);
            scaled[y * new_width + x] = pixels[src_y * width + src_x];
        }
    }
    
    memcpy(pixels, scaled, new_width * new_height);
    free(scaled);
}

void test_all_functions(void) {
    int arr[] = {1,2,3,4,5};
    int idx;
    
    TEST_CHECK(add_values(3,4) == 7);
    swap_values(&arr[0], &arr[1]);
    TEST_CHECK(arr[0] == 2 && arr[1] == 1);
    TEST_CHECK(sum_array(arr,5) == 15);
    reverse_array(arr,5);
    TEST_CHECK(arr[0] == 5 && arr[4] == 2);
    TEST_CHECK_DOUBLE_EQ(average(arr,5), 3.0);
    TEST_CHECK(find_max(arr,5,&idx) == 5);
    
    unsigned char pixels[25] = {0};
    for(int i=0; i<25; i++) pixels[i] = i%256;
    
    invert_colors(pixels,5,5);
    TEST_CHECK(pixels[0] == 255);
    
    rotate_90(pixels,5,5);
    TEST_CHECK(pixels[0] == 20);
}

TEST_LIST = {
    {"all_functions_test", test_all_functions},
    {NULL, NULL}
};
