#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node*start =NULL;

node* create(node*start, int n){
    int i,num;
    node* newnode, *ptr;
    for(i=0;i<n;i++){
        newnode=(node*)malloc(sizeof(node));
        printf("Enter num: ");
        scanf("%d",&num);
        newnode->data=num;
        newnode->next=NULL;
        if(start==NULL){
            start=newnode;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
    }
     return start;
}

node* prepend(node* start, int n){
    int num, i;
    for(i=0;i<n;i++){
        printf("Enter num: ");
        scanf("%d",&num);
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=num;
        if(start==NULL){
            start=newnode;
        }
        else{
            newnode->next=start;
            start=newnode;
        }
    }
    return start;
}

void display(node* start){
    node* ptr=start;
    while(ptr!=NULL){
        printf("->%d",ptr->data);
        ptr=ptr->next;
    }
}


int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    //start =create(start, n);
    start=prepend(start, n);
    display(start);
}