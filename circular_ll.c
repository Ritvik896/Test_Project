#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *start = NULL;
node *create(node *start, int n) // insertion at end -append
{
    node *newnode, *ptr;
    int num, i;
    for (i = 0; i < n; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter num: ");
        scanf("%d", &num);
        newnode->data = num;
        if (start == NULL)
        {
            newnode->next = newnode;
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = start;
        }
    }
    return start;
}
node *ins_at_begin(node *start) // insertion at beginning
{
    node *newnode, *ptr;
    newnode = (node *)malloc(sizeof(node));
    int num;
    printf("Enter insertion value :");
    scanf("%d", &num);
    newnode->data = num;
    while (ptr->next != start)
        ptr = ptr->next;
    newnode->next = start;
    start = newnode;
    ptr->next = start;
    return start;
}
node *ins_at_end(node *start) // insertion at end
{
    node *newnode, *ptr;
    newnode = (node *)malloc(sizeof(node));
    int num;
    printf("Enter insertion value :");
    scanf("%d", &num);
    newnode->data = num;
    while (ptr->next != start)
        ptr = ptr->next;
    newnode->next = start;
    ptr->next = newnode;
    return start;
}

node *ins_before(node *start)
{
    node *ptr, *preptr, *newnode;
    newnode = (node *)malloc(sizeof(node));
    int num, val;
    ptr = start;
    preptr = ptr;
    printf("Enter val and num :");
    scanf("%d %d", &val, &num);
    newnode->data = num;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    newnode->next = ptr;
    preptr->next = newnode;
    return start;
}
node *ins_after(node *start)
{
    node *ptr, *newnode;
    newnode = (node *)malloc(sizeof(node));
    int num, val;
    ptr = start;
    printf("Enter val and num :");
    scanf("%d %d", &val, &num);
    newnode->data = num;
    while (ptr->data != val)
        ptr = ptr->next;
    newnode->next = ptr->next;
    ptr->next = newnode;
    return start;
}

node *del_beg(node *start) // del at beginninng
{
    start = start->next;
}
node *del_end(node *start) // del at the ends
{
    node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}
node *del_after_val(node *start) // deletion after val
{
    node *ptr, *preptr;
    int val;
    printf("Enter val :");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}
void display(node *start) // node display
{
    node *ptr = start;
    printf("Linked List: ");
    while (ptr->next != start)
    {
        printf("->%d", ptr->data);
        ptr = ptr->next;
    }
    printf("->%d", ptr->data);
    printf("\n");
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    start = create(start, n);
    display(start);
    // start = ins_at_begin(start);
    // display(start);
    // start = ins_at_end(start);
    // display(start);
    // start = ins_before(start);
    // display(start);
    // start = ins_after(start);
    // display(start);
    // start = del_beg(start);
    // display(start);
    // start = del_end(start);
    // display(start);
    // start = del_after_val(start);
    // display(start);
    return 0;
}