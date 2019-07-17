#include<stdio.h>
#include<stdlib.h>

struct listnode1
{
    int data;
    struct listnode1* next;
};
struct listnode2
{
    int data;
    struct listnode2* next;
};
int main()
{
    int flagship=1;
    int noofele1,noofele2,temp,flag=0,i;
    struct listnode1 *newnode1=NULL;
    struct listnode1 *head1=NULL;
    struct listnode1 *solution=NULL;
    struct listnode1 *protohead1=NULL;
    struct listnode1 *solutionhead=NULL;
    struct listnode2 *newnode2=NULL;
    struct listnode2 *head2=NULL;
    struct listnode2 *protohead2=NULL;
    newnode1=(struct listnode1*)malloc(sizeof(struct listnode1));
    head1=(struct listnode1*)malloc(sizeof(struct listnode1));
    protohead1=(struct listnode1*)malloc(sizeof(struct listnode1));
    solution=(struct listnode1*)malloc(sizeof(struct listnode1));
    solutionhead=(struct listnode1*)malloc(sizeof(struct listnode1));
    newnode2=(struct listnode2*)malloc(sizeof(struct listnode2));
    head2=(struct listnode2*)malloc(sizeof(struct listnode2));
    protohead2=(struct listnode2*)malloc(sizeof(struct listnode2));
    printf("Enter the number of elements in list1 and list2 :\n");
    scanf("%d%d",&noofele1,&noofele2);
    printf("Enter the elements of list1 :\n");
                //printf("%d %d\n",noofele1,noofele2);
    for(i=0;i<noofele1;i++)
    {
        if(i==0)
        {
            scanf("%d",&temp);
            newnode1->data=temp;
            newnode1->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head1=newnode1;
            protohead1=newnode1;
            newnode1=newnode1->next;
            continue;
        }
        else if(i==(noofele1-1))
        {
            scanf("%d",&temp);
            newnode1->data=temp;
            newnode1->next=NULL;
            continue;
        }
        else
        {
            scanf("%d",&temp);
            newnode1->data=temp;
            newnode1->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            newnode1=newnode1->next;
            continue;
        }
    }
    printf("Enter the elements of list2 :\n");
    for(i=0;i<noofele2;i++)
    {
        if(i==0)
        {
            scanf("%d",&temp);
            newnode2->data=temp;
            newnode2->next=(struct listnode2*)malloc(sizeof(struct listnode2));
            head2=newnode2;
            protohead2=newnode2;
            newnode2=newnode2->next;
            continue;
        }
        else if(i==(noofele2-1))
        {
            scanf("%d",&temp);
            newnode2->data=temp;
            newnode2->next=NULL;
        }
        else
        {
            scanf("%d",&temp);
            newnode2->data=temp;
            newnode2->next=(struct listnode2*)malloc(sizeof(struct listnode2));
            newnode2=newnode2->next;
            continue;
        }
    }
                 /*while(head1!=NULL)
                 {
                        temp=head1->data;
                        printf("%d\n",temp);
                        head1=head1->next;
                 }
                 while(head2!=NULL)
                 {
                        temp=head2->data;
                        printf("%d\n",temp);
                        head2=head2->next;
                 }*/
    while((head1!=NULL)&&(head2!=NULL))
    {
        temp=head1->data+head2->data;
        solution->data=temp;
        solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
        if(flagship==1)
        {
            solutionhead=solution;
            flagship=0;
        }
        solution=solution->next;
        head1=head1->next;
        head2=head2->next;
    }
    if((head1==NULL)&&(head2!=NULL))
    {
        flag=1;
    }
    if((head1!=NULL)&&(head2==NULL))
    {
        flag=2;
    }
    if(flag==1)
    {
        while((head2->next)!=NULL)
        {
            solution->data=head2->data;
            solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head2=head2->next;
            solution=solution->next;
        }
        solution->data=head2->data;
        solution->next=NULL;
    }
    if(flag==2)
    {
        while((head1->next)!=NULL)
        {
            solution->data=head1->data;
            solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head1=head1->next;
            solution=solution->next;
        }
        solution->data=head1->data;
        solution->next=NULL;
    }
    while(solutionhead!=NULL)
    {
        temp=solutionhead->data;
        printf("%d ",temp);
        solutionhead=solutionhead->next;
    }
    return 0;
}