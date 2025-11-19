#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
    
};

void find_results(struct Student students[], int num_students) {
    int highest_score = -1;
    char highest_scorer_name[50] = "";
    int total_marks = 0;
    int i;
    
    printf("Student Marks:\n");
    printf("Name\t\tMarks\n");
    printf("---------------------\n");

    for (i = 0; i < num_students; i++) {
        printf("%s\t\t%d\n", students[i].name, students[i].marks);

        if (students[i].marks > highest_score) {
            highest_score = students[i].marks;
       
            strcpy(highest_scorer_name, students[i].name);
        }
        
        total_marks += students[i].marks;
    }


    float average_marks = (float)total_marks / num_students; 
    

    printf("\n---------------------\n");
    printf("Highest Scorer: %s with %d marks\n", highest_scorer_name, highest_score);
    printf("Average Marks: %.2f\n", average_marks); 
}

int main() {

    struct Student class_data[] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"Diana", 96},
        {"Eve", 88}
    };

  
    int num_students = sizeof(class_data) / sizeof(class_data[0]);

    find_results(class_data, num_students);
    
    return 0;
}
