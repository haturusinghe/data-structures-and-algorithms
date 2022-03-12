#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <conio.h>

/* function prototypes */
void createList(int n);
struct Student * middle(struct Student * start, struct Student * last);
struct Student * binary_search(char grade[]);
void display();
void selectionSort();
void swap(struct Student * p1, struct Student * p2);
/////////

struct Student {
  char id[100];
  char name[50];
  char gender[5];
  char grade[5];
  struct Student * next;
}* head;


/*
 * Create a list of n nodes
 */
void createList(int n) {
  struct Student * newNode;
  struct Student * temp;
  int i;
  char id[100];
  char name[50];
  char gender[5];
  char grade[5];
  head = (struct Student * ) malloc(sizeof(struct Student));
  /*
   * If unable to allocate memory for head node
   */
  if (head == NULL) {
    printf("Unable to allocate memory.");
  } else {
    /*
     * Reads data of node from the user
     */
    printf("Enter the data of student 1: ");
    printf("Enter student ID: ");
    scanf("%s", id);
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter student Gender: ");
    scanf("%s", gender);
    printf("Enter student Grade: ");
    scanf("%s", grade);
    strcpy(head -> id, id);
    strcpy(head -> name, name); //this function return the copied string or copying name to head -> name
    strcpy(head -> gender, gender);
    strcpy(head -> grade, grade);
    head -> next = NULL; // Link the address field to NULL
    temp = head;
    /*
     * Create n nodes and adds to linked list
     */
    for (i = 2; i <= n; i++) {
      newNode = (struct Student * ) malloc(sizeof(struct Student));
      /* If memory is not allocated for newNode */
      if (newNode == NULL) {
        printf("Unable to allocate memory.");
        break;
      } else {
        printf("Enter the data of node %d: ", i);
        printf("Enter student ID: ");
        scanf("%s", id);
        printf("Enter student name: ");
        scanf("%s", name);
        printf("Enter student Gender: ");
        scanf("%s", gender);
        printf("Enter student Grade: ");
        scanf("%s", grade);
        strcpy(newNode -> id, id);
        strcpy(newNode -> name, name); //this function return the copied string
        strcpy(newNode -> gender, gender);
        strcpy(newNode -> grade, grade);
        newNode -> next = NULL; // Link the address field of newNode with NULL
        temp -> next = newNode; // Link previous node i.e. temp to the newNode
        temp = temp -> next;
      }
    }
    printf("STUDENT LIST IS CREATED SUCCESSFULLY\n");
  }
}
void display() {
  struct Student * current = head;
  while (current != NULL) {
    printf("Student ID: %s\n", current -> id);
    printf("Student Name: %s\n", current -> name);
    printf("Student Gender: %s\n", current -> gender);
    printf("Student Grade: %s\n", current -> grade);
    current = current -> next;
  }
}
//selectionSort() will sort nodes of the list in ascending order
void selectionSort() {
  struct Student * start = head; //start will point to head
  struct Student * traveerse;
  struct Student * min;
  while (start -> next != NULL) {
    min = start;
    traveerse = start -> next; //traverse will point to node next to start
    while (traveerse != NULL) {
      //find the minimum element from the list
      //Compare data of min and traverse node
      if (strcmp(min -> grade, traveerse -> grade) > 0) {
        min = traveerse; //min will points to traverse node
      }
      traveerse = traveerse -> next; //traverse will point to node next to traverse
    }
    swap(start, min);
    start = start -> next; //start will point to node next to start
  }
}
void swap(struct Student * p1, struct Student * p2) {
  struct Student * temp;
  strcpy(temp -> id, p1 -> id); //this function return the copied string
  strcpy(temp -> name, p1 -> name);
  strcpy(temp -> gender, p1 -> gender);
  strcpy(temp -> grade, p1 -> grade);
  strcpy(p1 -> id, p2 -> id);
  strcpy(p1 -> name, p2 -> name);
  strcpy(p1 -> gender, p2 -> gender);
  strcpy(p1 -> grade, p2 -> grade);
  strcpy(p2 -> id, temp -> id);
  strcpy(p2 -> name, temp -> name);
  strcpy(p2 -> gender, temp -> gender);
  strcpy(p2 -> grade, temp -> grade);
}
// function to find out middle element
struct Student * middle(struct Student * start, struct Student * last) {
  // if start points to NULL and is empty
  if (start == NULL) {
    return NULL;
  }
  struct Student * slow = start;
  struct Student * fast = start -> next;
  while (fast != last) {
    // fast is moved one step ahead
    fast = fast -> next;
    // if fast is not the last element
    if (fast != last) {
      // slow pointer is moved one step ahead
      slow = slow -> next;
      // fast pointer is moved one step ahead
      fast = fast -> next;
    }
  }
  return slow;
}
/* Binary Search to find Search Key */
struct Student * binary_search(char grade[]) {
  struct Student * start = head;
  struct Student * last = NULL;
  do {
    // calling middle function to find middle element
    struct Student * mid = middle(start, last);
    // If middle element is empty
    if (mid == NULL)
      return NULL;
    // If value is present at middle, we return it
    if (strcmp(mid -> grade, grade) == 0) {
      printf("id: %s\n", mid -> id);
      printf("Name: %s\n", mid -> name);
      printf("Gender: %s\n", mid -> gender);
      printf("Grade: %s\n", mid -> grade);
      //return ;
      return mid;
    }
    // If the middle element is less than the key
    else if (strcmp(mid -> grade, grade) < 0)
      start = mid -> next;
    // If the middle element is greater than the key
    else
      last = mid;
  } while (last == NULL || last != start);
  // value not present, so we return NULL
  return NULL;
}
