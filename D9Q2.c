#include <stdio.h>
#include <string.h>

void reverse(char s[], int n) {
    int left = 0, right = n - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char s[100];
    scanf("%s", s);

    int n = strlen(s);
    reverse(s, n);

    printf("%s", s);
    return 0;
}
