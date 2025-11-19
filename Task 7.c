#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 4
#define MAX_COURSES 10
#define MAX_COURSE_NAME 20

int main() {
    char students[NUM_STUDENTS][20] = {"Alice", "Bob", "Charlie", "Diana"};
    char courses[NUM_STUDENTS][MAX_COURSES][MAX_COURSE_NAME] = {
        {"Math", "Physics", "Chemistry"},
        {"Biology", "Physics"},
        {"History", "Math", "Physics", "English"},
        {"Math"}
    };
    int course_count[NUM_STUDENTS] = {3, 2, 4, 1};
    char search_course[MAX_COURSE_NAME];
    int i, j, found;

    printf("Students and their registered courses:\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("%s: ", students[i]);
        for (j = 0; j < course_count[i]; j++) {
            printf("%s", courses[i][j]);
            if (j < course_count[i] - 1) printf(", ");
        }
        printf("\n");
    }

    printf("\nEnter the course to search: ");
    scanf("%s", search_course);

    printf("Students taking %s:\n", search_course);
    for (i = 0; i < NUM_STUDENTS; i++) {
        found = 0;
        for (j = 0; j < course_count[i]; j++) {
            if (strcmp(courses[i][j], search_course) == 0) {
                found = 1;
                break;
            }
        }
        if (found) printf("%s\n", students[i]);
    }

    printf("\nOverloaded students (more than 3 courses):\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        if (course_count[i] > 3) {
            printf("%s\n", students[i]);
        }
    }

    return 0;
}
