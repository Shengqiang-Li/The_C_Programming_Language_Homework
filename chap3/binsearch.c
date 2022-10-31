#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        // int mid = low + (high - low) / 2;
        int mid  = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int x = 1, n = 10;
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", binsearch(x, v, n));
    return 0;
}
