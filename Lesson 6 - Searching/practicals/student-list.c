#include "search_stu.h"

int main(void){
    Student temp_stu;

    printf("Enter Name: \n");
    scanf("%[^\n]",temp_stu.name);
    printf("Enter ID: ");
    scanf("%d ",temp_stu.stuId);
    
    printf("Enter Age: ");
    scanf("%d",temp_stu.age);

    printf("***************\n");
    printf("Name: %s | ID: %d",temp_stu.name, temp_stu.stuId);

    
}