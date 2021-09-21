#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

struct Node * traversaling(struct Node * ptr)
{
    int i=1;
    while(ptr != NULL)
    {
        printf("Element %d is %d \n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
    
}
struct Node * insertinbegining(struct Node * head, int data)
{
    struct Node * ptr=head;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct Node * insertinbetween(struct Node * head, int data, int index)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    
    int i=0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}

struct Node * insertinend(struct Node * head, int data)
{
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=87;
    head->next=second;

    second->data=78;
    second->next=third;

    third->data=34;
    third->next=fourth;

    fourth->data=35;
    fourth->next=NULL;
     
    int num;
    printf("The previous linked list \n");
    traversaling(head);
    printf("\n");
    printf("\n ");
    printf("choice the insert operation \n");
    printf("1. Insert the element in begining of the list \n");
    printf("2. Insert the element in between of the list \n");
    printf("3. Insert the element in end of the list \n");
    printf("Enter the selection(1-3) : \n");
    scanf("%d",&num);
    printf("After the operation \n");


    switch (num)
    {
    case 1:
        head = insertinbegining(head,89);
        traversaling(head);
        break;
    
    case 2:
        head = insertinbetween(head,89,2);
        traversaling(head);
        break;

    case 3:
        head =insertinend(head,89);
        traversaling(head);
        break;

    default:
        printf("Invalid selection !! ");    
        break;
    }

    return 0;
}