/* ============================================================
 * STUDENT IMPLEMENTATIONS - Complete these functions
 * ============================================================ */

/**
 * Function 1: add_values
 */
int add_values(int a, int b) {
    return a + b;
}

/**
 * Function 2: swap_values
 */
void swap_values(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Function 3: sum_array
 */
int sum_array(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

/**
 * Function 4: reverse_array
 */
void reverse_array(int *arr, int n) {
    // Use two pointers from start and end, swapping until they meet in the middle.
    for (int i = 0; i < n / 2; i++) {
        swap_values(&arr[i], &arr[n - 1 - i]);
    }
}

/**
 * Function 5: average
 */
double average(int *arr, int n) {
    // Handle edge case to prevent division by zero, though tests likely won't trigger it.
    if (n == 0) {
        return 0.0;
    }
    // Cast the sum to double before division to avoid integer truncation.
    return (double)sum_array(arr, n) / n;
}

/**
 * Function 6: find_max
 */
int find_max(int *arr, int n, int *index) {
    // The test cases assume n >= 1, but it's good practice to handle edge cases.
    if (n <= 0) {
        *index = -1;
        return 0;
    }

    int max_value = arr[0];
    int max_index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_index = i;
        }
    }

    *index = max_index; // Store the found index via the output parameter.
    return max_value;   // Return the maximum value.
}