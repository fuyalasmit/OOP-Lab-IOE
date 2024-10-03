// Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.
#include <stdio.h>
int main() {
    struct student {
        char name[20];
        float marks;
    };

    int n, i;
    printf("How many students: ");
    scanf("%d", &n);
    struct student std[n];

    for (i = 0; i < n; i++) {
        printf("Enter name of student no. %d: ", i + 1);
        scanf("%s", std[i].name); 
        printf("Enter marks of student no. %d: ", i + 1);
        scanf("%f", &std[i].marks);
    }

    printf("\n\n");
    for (i = 0; i < n; i++) {
        printf("The name of student no. %d is: %s\n", i + 1, std[i].name);
        printf("The marks of student no. %d are: %.2f\n", i + 1, std[i].marks); 
    }

    return 0;
}
