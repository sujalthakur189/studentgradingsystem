#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    float grades[5];
    float average;
    char letter_grade;
} Student;

void calculateAverage(Student *student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 5;
    student->letter_grade = (student->average >= 90) ? 'A' :
                            (student->average >= 80) ? 'B' :
                            (student->average >= 70) ? 'C' :
                            (student->average >= 60) ? 'D' : 'F';
}

void addStudent(Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    for (int i = 0; i < 5; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &students[*count].grades[i]);
    }
    calculateAverage(&students[*count]);
    (*count)++;
}

void viewStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Average: %.2f, Letter Grade: %c\n", 
               students[i].name, students[i].average, students[i].letter_grade);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("1. Add Student\n2. View Students\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
