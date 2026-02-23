#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);   // actual n

    int arr[n-1];
    int sum = 0;

    for(int i = 0; i < n-1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int total = n*(n+1)/2;

    printf("%d", total - sum);

    return 0;
}
