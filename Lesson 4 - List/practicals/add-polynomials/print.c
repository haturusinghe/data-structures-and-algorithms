//TODO print list reverse and vise versa

// reverse a list

/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* head_ref is a double pointer which points to head (or start) pointer 
  of linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    /*ADD A STATEMENT HERE*/
}

1->2->3->4->5->6
void fun(struct node* start)
{
    if(start == NULL)
    return;
    printf("%d  ", start->data); 
    if(start->next != NULL )
    fun(start->next->next);
    printf("%d  ", start->data);
}


typedef struct node 
{
    int value;
    struct node *next;
}Node;
 
Node *move_to_front(Node *head) 
{
    Node *p, *q;
    if ((head == NULL: || (head->next == NULL)) 
    return head;
    q = NULL; p = head;
    while (p-> next !=NULL) 
    {
        q = p;
        p = p->next;
    }
   _______________________________
  return head;
}