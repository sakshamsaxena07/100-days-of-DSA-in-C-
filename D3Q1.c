#include <stdio.h>

int main() {
    int n, k, found = -1, count = 0;

    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        count++;
        if(arr[i] == k) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", count);

    return 0;
}
