#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tester
{
    int value;
    struct tester* next;
};
struct tester *checking(struct tester *head,int checker_value)
{
    struct tester *temp;
    temp=(struct tester*)malloc(sizeof(struct tester));
    temp=head;
    int flagship=0;
    while(temp!=NULL)
    {
        if(flagship==0)
        {
            if(temp->value>=checker_value)
            {
                printf("Hi1 %d\n",temp->value);
                if(temp->next==NULL)
                {
                    temp=temp->next;
                    head=head->next;
                    printf("All elements in the list are greater than or equal to limiter value\n");
                    break;
                }
                else
                {
                    printf("Hi2 %d\n",temp->value);
                    temp=temp->next;
                    head=head->next;
                }
            }
            else
            {
                flagship=1;
                printf("Hi3 %d\n",temp->value);
                if(temp->next==NULL)
                {
                    break;
                }
            }
        }
        else
        {
            if(temp->next->next==NULL)
            {
                if(temp->next->value>=checker_value)
                {
                    printf("Hi4 %d\n",temp->next->value);
                    temp->next=temp->next->next;
                    break;
                }
                else
                {
                    printf("Hi5 %d\n",temp->next->value);
                    temp=temp->next;
                    break;
                }
            }
            else
            {
                if(temp->next->value>=checker_value)
                {
                    printf("Hi6 %d\n",temp->next->value);
                    temp->next=temp->next->next;
                }
                else
                {
                    printf("Hi7 %d\n",temp->next->value);
                    temp=temp->next;
                }
            }
        }
    }
    return head;
}
int main()
{
    int number_of_values,checker_value;
    struct tester *list;
    struct tester *head;
    printf("Enter the number of terms: \n");
    scanf("%d",&number_of_values);
    list=(struct tester*)malloc(sizeof(struct tester));
    head=(struct tester*)malloc(sizeof(struct tester));
    int temp;
    printf("Enter the values:\n");
    for(int i=0;i<number_of_values;i++)
    {
        scanf("%d",&temp);
        if(i==0)
        {
            list->value=temp;
            list->next=NULL;
            head=list;
        }
        else
        {
            list->next=(struct tester*)malloc(sizeof(struct tester));
            list=list->next;
            list->value=temp;
            list->next=NULL;
        }
    }
    printf("Enter the limiter value :\n");
    scanf("%d",&checker_value);
    struct tester *answer;
    answer=(struct tester*)malloc(sizeof(struct tester));
    answer=checking(head,checker_value);
    printf("The solution is :\n");
    if(answer==NULL)
    {
        printf("No solution\n");
        return 0;
    }
    while(answer!=NULL)
    {
        printf("%d ",answer->value);
        answer=answer->next;
    }
}