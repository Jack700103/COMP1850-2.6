#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 精简版acutest实现 */
#define TEST_CHECK(exp) \
    if (!(exp)) { \
        fprintf(stderr, "%s:%d: Check failed: %s\n", __FILE__, __LINE__, #exp); \
        exit(1); \
    }

/* Task1函数实现 */
int add_values(int a, int b) { return a + b; }
void swap_values(int *a, int *b) { int t=*a; *a=*b; *b=t; }
int sum_array(int *arr, int n) { int s=0; for(int i=0; i<n; i++) s+=arr[i]; return s; }
void reverse_array(int *arr, int n) { for(int i=0; i<n/2; i++) { int t=arr[i]; arr[i]=arr[n-1-i]; arr[n-1-i]=t; } }
double average(int *arr, int n) { return (double)sum_array(arr,n)/n; }
int find_max(int *arr, int n, int *index) { *index=0; int m=arr[0]; for(int i=1; i<n; i++) { if(arr[i]>m) { m=arr[i]; *index=i; } } return m; }

/* Task2图像处理 */
void invert_colors(unsigned char *p, int w, int h) { for(int i=0; i<w*h; i++) p[i]=255-p[i]; }

/* 测试用例 */
int main() {
    /* 测试add_values */
    TEST_CHECK(add_values(3,4) == 7);
    
    /* 测试swap_values */
    int a=1,b=2;
    swap_values(&a,&b);
    TEST_CHECK(a == 2 && b == 1);
    
    /* 测试sum_array */
    int arr[] = {1,2,3,4,5};
    TEST_CHECK(sum_array(arr,5) == 15);
    
    /* 测试reverse_array */
    reverse_array(arr,5);
    TEST_CHECK(arr[0] == 5 && arr[4] == 2);
    
    /* 测试average */
    TEST_CHECK(fabs(average(arr,5)-3.0) < 0.01);
    
    /* 测试invert_colors */
    unsigned char pixels[25];
    for(int i=0; i<25; i++) pixels[i] = i%256;
    invert_colors(pixels,5,5);
    TEST_CHECK(pixels[0] == 255);
    
    printf("All tests passed\n");
    return 0;
}
