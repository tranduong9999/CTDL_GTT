#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int *data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.data = (int *)malloc(size * sizeof(int));
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(Stack *s, int value) {
    if (s->top < s->maxSize - 1) {
        s->data[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) return 0;
    return s->data[s->top--];
}

int evaluatePostfix(char expr[]) {
    int len = strlen(expr);
    Stack s = createStack(len);
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (ch) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
    }
    int result = pop(&s);
    free(s.data);
    return result;
}

int main() {
    char expr[1001];
    fgets(expr, sizeof(expr), stdin);
    size_t len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}
