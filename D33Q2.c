#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int size) {
    int stack[1000], top = -1;

    for (int i = 0; i < size; i++) {
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];

            if (tokens[i][0] == '+') stack[++top] = a + b;
            else if (tokens[i][0] == '-') stack[++top] = a - b;
            else if (tokens[i][0] == '*') stack[++top] = a * b;
            else stack[++top] = a / b;

        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }

    return stack[top];
}
