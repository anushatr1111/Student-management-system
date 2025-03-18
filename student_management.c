#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.csv"

typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

// Function to add a student
void addStudent() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(file, "%d,%s,%d,%.2f\n", s.id, s.name, s.age, s.marks);
    fclose(file);
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No students found!\n");
        return;
    }

    Student s;
    printf("\nID\tName\t\tAge\tMarks\n");
    printf("--------------------------------------\n");

    while (fscanf(file, "%d,%49[^,],%d,%f\n", &s.id, s.name, &s.age, &s.marks) != EOF) {
        printf("%d\t%-10s\t%d\t%.2f\n", s.id, s.name, s.age, s.marks);
    }

    fclose(file);
}

// Function to search for a student
void searchStudent() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    Student s;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &s.id, s.name, &s.age, &s.marks) != EOF) {
        if (s.id == searchId) {
            printf("Student Found: ID: %d, Name: %s, Age: %d, Marks: %.2f\n", s.id, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found!\n", searchId);
    }

    fclose(file);
}

// Function to delete a student
void deleteStudent() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    int deleteId;
    printf("Enter Student ID to delete: ");
    scanf("%d", &deleteId);

    FILE *temp = fopen("temp.csv", "w");
    if (!temp) {
        printf("Error creating temp file!\n");
        fclose(file);
        return;
    }

    Student s;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &s.id, s.name, &s.age, &s.marks) != EOF) {
        if (s.id != deleteId) {
            fprintf(temp, "%d,%s,%d,%.2f\n", s.id, s.name, s.age, s.marks);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.csv", FILE_NAME);

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found!\n", deleteId);
    }
}

// Main function with menu
int main() {
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
