#include <stdio.h>

int main(void) {
	int a[100][100]={0},dimension,i,j,k,pivotelement;
	//a[100][100]={0};
	//int b[100][100];
	//b[100][100]={0};
	printf("Enter the dimension of the square matrix : \n");
	scanf("%d",&dimension);
	printf("enter the elements of the matrix: \n");
	for(i=1;i<=dimension;i++)
	{
		for(j=1;j<=dimension;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	/*for(i=1;i<=dimension;i++)//creating a duplicate array
	{
		for(j=1;j<=dimension;j++)
		{
			b[i][j]=a[i][j];
		}
	}*/
	for(j=1;j<=dimension;j++)
	{
		pivotelement=a[j][j];
		for(i=1;i<=dimension;i++)
		{
			if(i==j)
			{
				continue;
			}
			else
			{
				for(k=1;k<=dimension;k++)
				{
					if(k==j)
					{
						continue;
					}
					else
					{
						a[i][k]=(pivotelement*a[i][k])-(a[j][k]*a[i][j]);
					}
				}
			}
		}
		for(i=1;i<=dimension;i++)
		{
			if(i==j)
			{
				continue;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
	printf("the soltion is : \n");
	for(i=1;i<=dimension;i++)
	{
		for(j=1;j<=dimension;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	
	
	// your code goes here
	return 0;
}
