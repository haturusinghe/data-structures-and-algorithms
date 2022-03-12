#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct student {
  char id[12];
  char name[20];
  char gender[2];
  char grade[2];
}Student;


int main(void){
    Student stu;
    while(true){
        printf("Enter the data of student\n ");
        printf("Enter student ID: ");
        scanf("%s", stu.id);
        printf("Enter student name: ");
        scanf("%s", stu.name);
        printf("Enter student Gender: ");
        scanf("%s", stu.gender);
        printf("Enter student Grade: ");
        scanf("%s", stu.grade);
        printf("#########\n");
        printf("%s %s %s Grade:%s \n",stu.id, stu.name, stu.gender, stu.grade);
    }
    
}