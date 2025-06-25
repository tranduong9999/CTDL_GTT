#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};

int main() {
    struct Student students[5];
    int searchId;
    int found = 0;

    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);
    }

    printf("Nhap ID can tim: ");
    scanf("%d", &searchId);

    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            printf("{ id: %d, name: \"%s\", age: %d }\n",
                   students[i].id, students[i].name, students[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Sinh vien khong ton tai\n");
    }

    return 0;
}
