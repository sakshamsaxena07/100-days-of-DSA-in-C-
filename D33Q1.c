#include <ctype.h>

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* s) {
    char stack[100];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        if (isalnum(s[i]))
            printf("%c", s[i]);
        else if (s[i] == '(')
            stack[++top] = s[i];
        else if (s[i] == ')') {
            while (stack[top] != '(')
                printf("%c", stack[top--]);
            top--;
        } else {
            while (top != -1 && prec(stack[top]) >= prec(s[i]))
                printf("%c", stack[top--]);
            stack[++top] = s[i];
        }
    }

    while (top != -1)
        printf("%c", stack[top--]);
}
