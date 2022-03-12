#include "stu_ls.h"

int main() {
    int n;
    int choice;
    char grade[5];
    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of students: ");
    scanf("%d", & n);
    createList(n);
    printf("1 to display original student details list\n2 to display sorted student details list\n3 binary searc for student details list ");
      do {
        printf("\nEnter Choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
          printf("\nData in the original student list \n");
          display();
          break;
        case 2:
          printf("\nData in the sorted student list \n");
          selectionSort();
          display();
          break;
        case 3:
          printf("Enter student Grade to search: ");
          scanf("%s", grade);
          if (binary_search(grade) == NULL)
            printf("GRADE IS NOT PRESENT IN THE LIST");
          else
            printf("GRADE %s IS PRESENT IN THE LIST:", grade);
          break;
        }
      } while (choice != 0);
      return 0;
    }