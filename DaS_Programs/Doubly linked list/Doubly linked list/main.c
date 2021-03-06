#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * start=NULL;
struct node * create(struct node *);
struct node * display(struct node *);
struct node * insert_beg(struct node *);
struct node * insert_end(struct node *);
struct node * insert_after(struct node *);
struct node * insert_before(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * delete_after(struct node *);
struct node * delete_node(struct node *);
struct node * delete_list(struct node *);
struct node * sort_list(struct node *);

int main()
{
    int ch;
    
    do{
        
        printf("Enter your choice: \n1.Create list\n2.Display list\n3.Insert at the beginning\n4.Insert at the end\n5.Insert after\n6.Insert Before\n7.Delete beginning\n8.Delete end\n9.Delete after a given node\n10.Delete before a given node\n11.Delete node\n12.Delete list\n13.Exit\nYour Choice: ");
        scanf("%d",&ch);
        
        switch (ch)
        {
            case 1:
                start= create(start);
                break;
                
            case 2:
                start= display(start);
                break;
                
            case 3:
                start=insert_beg(start);
                break;
                
            case 4:
                start=insert_end(start);
                break;
                
            case 5:
                start=insert_after(start);
                break;
                
            case 6:
                start=insert_before(start);
                break;
                
            case 7:
                start=delete_beg(start);
                break;
                
            case 8:
                start=delete_end(start);
                break;
                
            case 9:
                start=delete_after(start);
                break;
                
            case 10:
                start=insert_before(start);
                break;
                
            case 11:
                start=delete_node(start);
                break;
                
            case 12:
                start=delete_list(start);
                break;
                
            default:
                printf("INVALID CHOICE!");
                break;
        }
    }while (ch<=12) ;
    
    return 0;
}

struct node *create(struct node *start)
{
    int num;
    struct node *new_node;
    
    if (start==NULL)
    {
        
        printf("Enter the data:\n");
        scanf("%d",&num);
        
        new_node=(struct node *)malloc(sizeof(struct node));        //creation of new_node
        new_node->data=num;                                         //data of newnode now has num
        new_node->prev=NULL;
        new_node->next=NULL;
        start=new_node;                                         //start points to whole pointer new_node

    }
    else
    {
        printf("List already exists!\n\n");
    }
    
    return start;
};

struct node * display(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr;
        ptr=start;
        
        while (ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    
    return start;
};

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    
    printf("Enter the data:\n");
    scanf("%d",&num);
    
    new_node=(struct node *)malloc(sizeof(struct node));        //creation of new_node
    new_node->data=num;                                         //data of newnode now has num
    
    if (start==NULL)
    {
        start=new_node;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    else
    {
        new_node->next=start->prev;                                 //OR: start->prev=new_node;
        new_node->prev=NULL;
        start=new_node;
    }
    
    return start;
};

struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    
    printf("Enter the data:\n");
    scanf("%d",&num);
    
    ptr=start;
    
    new_node=(struct node *)malloc(sizeof(struct node));        //creation of new_node
    new_node->data=num;                                         //data of newnode now has num
    
    if (start==NULL)
    {
        printf("List empty!\n\n");
        start=new_node;
        new_node->next=NULL;
    }
    else
    {
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node->next=NULL;
    }
    return start;
};

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num,val;
    
    printf("Enter the data:\n");
    scanf("%d",&num);
    
    preptr=start;
    ptr=start->next;
    
    new_node=(struct node *)malloc(sizeof(struct node));        //creation of new_node
    new_node->data=num;                                         //data of newnode now has num
    
    printf("Enter the node value after which you want to insert new node: ");
    scanf("%d",&val);
    
    if (start==NULL)
    {
        printf("List empty!\n\n");
        start=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
    }
    else
    {
        while (preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
            
        }
        new_node->next=ptr;
        ptr->prev=new_node;
        preptr->next=new_node;
        new_node->prev=preptr;
    }
    return start;
};

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num,val;
    
    printf("Enter the data:\n");
    scanf("%d",&num);
    
    preptr=start;
    ptr=start->next;
    
    new_node=(struct node *)malloc(sizeof(struct node));        //creation of new_node
    new_node->data=num;                                         //data of newnode now has num
    
    printf("Enter the node value after which you want to insert new node: ");
    scanf("%d",&val);
    
    if (start==NULL)
    {
        printf("List empty!\n\n");
        start=new_node;
        new_node->next=NULL;
    }
    else
    {
        while (ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
            
        }
        new_node->next=ptr;
        ptr->prev=new_node;
        preptr->next=new_node;
        new_node->prev=preptr->next;
    }
    return start;
};

struct node *delete_beg(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr;
        ptr=start;
        
        start=start->next;
        start->prev=NULL;
        free(ptr);
        
    }
    return start;
};

struct node *delete_end(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr,*preptr;
        preptr=start;
        ptr=start->next;
        
        while (ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
    }
    return start;
};


struct node *delete_after(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr,*preptr;
        int val;
        
        printf("Enter the node value after which you want to delete node: ");
        scanf("%d",&val);
        
        preptr=start;
        ptr=start->next;
        
        while (preptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        
        ptr->next->prev=preptr;
        preptr->next=ptr->next;
        
        free(ptr);
    }
    return start;
};

struct node *delete_before(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr,*preptr;
        int val;
        
        printf("Enter the node value before which you want to delete node: ");
        scanf("%d",&val);
        
        preptr=start;
        ptr=start->next;
        
        while (ptr->next->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        ptr->next->prev=preptr;
        preptr->next=ptr->next;
        
        free(ptr);

    }
    return start;
};

struct node *delete_node(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
        struct node *ptr,*preptr;
        int val;
        
        printf("Enter the node value which you want to delete: ");
        scanf("%d",&val);
        
        preptr=start;
        ptr=start->next;
        
        while (ptr->data!=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        ptr->next->prev=preptr;
        preptr->next=ptr->next;
        
        free(ptr);

    }
    return start;
};

struct node *delete_list(struct node *start)
{
    if (start==NULL)
    {
        printf("List empty!\n\n");
    }
    else
    {
    
        while (start!=NULL)
        {
            start=delete_beg(start);
        }
    }
    return start;
};

/*
struct node *sort_list(struct node *start)
{
    struct node *ptr,*preptr;
    int temp;
    
    preptr=start;
    
    while (preptr->next!=NULL)
    {
        ptr=preptr->next;
        while (ptr!=NULL)
        {
            if (ptr->data>preptr->data)
            {
                temp=ptr->data;
                ptr->data=preptr->data;
                preptr->data=temp;
            }
            preptr=preptr->next;
        }
        
    }
    
    return start;
};
*/

