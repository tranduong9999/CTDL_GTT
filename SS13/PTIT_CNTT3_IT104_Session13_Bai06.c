#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.data = (char*)malloc(size * sizeof(char));
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(Stack* s, char value) {
    if (s->top < s->maxSize - 1) {
        s->data[++s->top] = value;
    }
}

char pop(Stack* s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->data[s->top--];
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    Stack s = createStack(len);
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            free(s.data);
            return 0;
        }
    }
    free(s.data);
    return 1;
}

int main() {
    char str[1001];
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
