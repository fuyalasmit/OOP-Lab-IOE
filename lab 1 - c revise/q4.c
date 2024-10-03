// Write a program to read name, rollno, address, and phone number of each student in your class using structure. Store the information in file so that you can recover the information later. While recovering the information from the file sort the information alphabetically according to the name.
#include <stdio.h>
#include <string.h>

struct student
{
    char name[20];
    int roll;
    char address[50];
    char phone[15];
};

void sortStudents(struct student std[], int n)
{
    struct student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(std[i].name, std[j].name) > 0)
            {
                temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("How many students: ");
    scanf("%d", &n);
    struct student std[n];

    FILE *fptr = fopen("student.txt", "wb");
    if (fptr == NULL)
    {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter name of student no. %d: ", i + 1);
        scanf(" %[^\n]%*c", std[i].name); // This format allows to read multi-word strings
        printf("Enter roll number of student no. %d: ", i + 1);
        scanf("%d", &std[i].roll);
        printf("Enter address of student no. %d: ", i + 1);
        scanf(" %[^\n]%*c", std[i].address); // This format allows to read multi-word strings
        printf("Enter phone number of student no. %d: ", i + 1);
        scanf("%s", std[i].phone);
        fwrite(&std[i], sizeof(struct student), 1, fptr);
    }
    fclose(fptr);

    struct student stdFromFile[n];
    fptr = fopen("student.txt", "rb");
    if (fptr == NULL)
    {
        printf("Error opening file for reading.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fread(&stdFromFile[i], sizeof(struct student), 1, fptr);
    }
    fclose(fptr);

    sortStudents(stdFromFile, n);

    printf("\nSorted student information:\n");
    for (i = 0; i < n; i++)
    {
        printf("Name: %s\n", stdFromFile[i].name);
        printf("Roll No: %d\n", stdFromFile[i].roll);
        printf("Address: %s\n", stdFromFile[i].address);
        printf("Phone: %s\n\n", stdFromFile[i].phone);
    }

    return 0;
}
