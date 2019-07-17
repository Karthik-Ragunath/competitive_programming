#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct binarytreenode
{
    int data;
    struct binarytreenode *leftnext;
    struct binarytreenode *rightnext;
};
int main()
{
    int fixer,leftsum=0,rightsum=0,checker1,checker2;
    struct binarytreenode *rootnode=NULL;
    struct binarytreenode *lefthead=NULL;
    struct binarytreenode *righthead=NULL;
    struct binarytreenode *temp=NULL;
    temp=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
    printf("is the tree empty:press 1 for no and 0  for yes \n");
    scanf("%d",&fixer);
    if(fixer==0)
    {
        printf("The tree is empty and hence it is a sumtree\n");
        return 0;
    }
    printf("Enter the rootnode element :\n");
    int element;
    scanf("%d",&element);
    rootnode=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
    rootnode->data=element;
    checker1=rootnode->data;
    printf("Enter the number of elements in left subtree of rootnode:\n");
    int leftcount,rightcount,i;
    scanf("%d",&leftcount);
    if(leftcount!=0)
    {
        printf("Enter the elements of left subtree:\n");
    }
    for(i=0;i<leftcount;i++)
    {
        if(i==0)
        {
            printf("Enter the first element:\n");
            lefthead=(struct binarytreenoode*)malloc(sizeof(struct binarytreenode));
            scanf("%d",&element);
            lefthead->data=element;
            leftsum=lefthead->data;
            lefthead->leftnext=NULL;
            lefthead->rightnext=NULL;
            rootnode->leftnext=lefthead;
            continue;
        }
        else
        {
            temp=lefthead;
            while(temp!=NULL)
            {
                printf("Which side u want to traverse: 0 for left and 1 for right :\n");
                scanf("%d",&fixer);
                if(fixer==0)
                {
                    temp=temp->leftnext;
                }
                else
                {
                    temp=temp->rightnext;
                }
            }
            temp=(struct bianrytreenode*)malloc(sizeof(struct binarytreenode));
            printf("Enter the element:\n");
            scanf("%d",&element);
            temp->data=element;
            leftsum=leftsum+temp->data;
            temp->leftnext=NULL;
            temp->rightnext=NULL;
        }
    }
    printf("Enter the number of elements in right subtree: \n");
    scanf("%d",&rightcount);
    if(rightcount!=0)
    {
        printf("Enter the elements of right subtree: \n");
    }
    for(i=0;i<rightcount;i++)
    {
        if(i==0)
        {
            printf("Enter the first element: \n");
            scanf("%d",&element);
            righthead=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
            righthead->data=element;
            rightsum=righthead->data;
            righthead->leftnext=NULL;
            righthead->rightnext=NULL;
            rootnode->rightnext=righthead;
            continue;
        }
        else
        {
            temp=righthead;
            while(temp!=NULL)
            {
                printf("Which side u want to traverse:0 for left and 1 for right\n");
                scanf("%d",&fixer);
                if(fixer==0)
                {
                    temp=temp->leftnext;
                }
                else
                {
                    temp=temp->rightnext;
                }
            }
            temp=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
            printf("Enter the element:\n");
            scanf("%d",&element);
            temp->data=element;
            rightsum=rightsum+temp->data;
            temp->rightnext=NULL;
            temp->leftnext=NULL;
        }
    }
    checker2=leftsum+rightsum;
    if(checker1==checker2)
    {
        printf("The given binary tree is a sum tree\n");
    }
    else
    {
        printf("The given binary tree is not a sum tree\n");
    }
    return 0;
}