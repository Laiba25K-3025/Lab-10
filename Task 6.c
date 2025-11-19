#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};


void manage_student_marks(struct Student students[], int num_students) {
    int highest_score = -1;
    char highest_scorer_name[50] = "";
    int total_marks = 0;
    int i;
    
   
    printf("\n----Student Marks Table ----\n");
    printf("--------------------------------\n");
    printf("Name\t\tMarks\n");
    printf("--------------------------------\n");


    for (i = 0; i < num_students; i++) {
     
        printf("%s\t\t%d\n", students[i].name, students[i].marks);
        
      
        if (students[i].marks > highest_score) {
            highest_score = students[i].marks;
       
            strcpy(highest_scorer_name, students[i].name);
        }
        
       
        total_marks += students[i].marks;
    }
    printf("--------------------------------\n");


    float average_marks = (float)total_marks / num_students; 
    

    printf("\n----Analysis Results----\n");
    printf("Top Student: \t\t%s with %d marks\n", highest_scorer_name, highest_score);
    printf("Class Average: \t\t%.2f marks\n", average_marks); 
    printf("Total Students: \t%d\n", num_students);
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

  
    manage_student_marks(class_data, num_students);
    
    return 0;
}
