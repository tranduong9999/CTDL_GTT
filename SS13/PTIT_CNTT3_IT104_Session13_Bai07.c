#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.data = (char *)malloc(size * sizeof(char));
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(Stack *s, char value) {
    if (s->top < s->maxSize - 1) {
        s->data[++s->top] = value;
    }
}

char pop(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->data[s->top--];
}

char peek(Stack *s) {
    if (s->top == -1) return '\0';
    return s->data[s->top];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValidBrackets(char expr[]) {
    int len = strlen(expr);
    Stack s = createStack(len);
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.top == -1 || !isMatching(peek(&s), ch)) {
                free(s.data);
                return 0;
            }
            pop(&s);
        }
    }
    int valid = s.top == -1;
    free(s.data);
    return valid;
}

int main() {
    char expr[1001];
    fgets(expr, sizeof(expr), stdin);
    size_t len = strlen(expr);
    if (expr[len - 1] == '\n') expr[len - 1] = '\0';

    if (isValidBrackets(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
