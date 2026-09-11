#include <stdio.h>

void main()
{
    int a[] = {1,2,3,4,5,6,7};
    int b[] = {10,20,30,40,50,60,70};

    int *c[] = {a, b};
    size_t rows = sizeof(c) / sizeof(c[0]);
    size_t cols = sizeof(a) / sizeof(a[0]);

    for (size_t r = 0; r < rows; ++r) {
        for (size_t col = 0; col < cols; ++col) {
            printf("%d, ", c[r][col]);
        }
    }
}