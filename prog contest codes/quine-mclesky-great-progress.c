#include <stdio.h>


int main(void) {
	int noofvariables,number,input[100]={0},j=0,i,noofminterms,binaryofinput[100][100]={0},k,m,count;
	int group[100]={0},type[100]={0},b,c,primeimplicant[100][100]={0},x=0;
    int d=0,e=0,f=1,pairings[100][100][100]={0},secondlevel[100][100]={0},y;
	int groupings[100][100][100]={0},copy[100][100][100]={0},pairs[100][100]={0},num[100]={0},flagship,n;
	printf("enter the number of variables : \n");
	scanf("%d",&noofvariables);
	printf("enter the minterms(after giving all the variables as inputs enter -1 to specify the end)) : \n");
	while(scanf("%d",&number)!=-1)
	{
		input[j]=number;
		j++;
	}
	noofminterms=j-2;
	for(i=0;i<=noofminterms;i++)
	{
		printf("%d\n",input[i]);
	}
	
	for(i=0;i<=noofminterms;i++)
	{
		if(input[i]<2)
		{
			k=noofvariables-1;
			binaryofinput[i][k]=input[i];
		}
		else
		{
			k=noofvariables-1;
			while(input[i]>1)
			{
				binaryofinput[i][k]=input[i]%2;
				k=k-1;
				input[i]=input[i]/2;
			}
			binaryofinput[i][k]=input[i];
		}
	}
	for(i=0;i<=noofminterms;i++)
	{
		for(m=0;m<noofvariables;m++)
		{
			printf("%d",binaryofinput[i][m]);
		}
		printf("\n");
	}
	for(i=0;i<=noofminterms;i++)
	{
		count=0;
		for(m=0;m<noofvariables;m++)
		{
			
			if(binaryofinput[i][m]==1)
			{
				count=count+1;
			}
			
		}
		group[count]=group[count]+1;
		type[i]=count;
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		printf("%d\n",group[i]);
	}
	for(i=0;i<=noofminterms;i++)
	{
		for(m=0;m<noofvariables;m++)
		{
			groupings[type[i]][num[type[i]]][m]=binaryofinput[i][m];
		}
		num[type[i]]=num[type[i]]+1;
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				printf("%d",groupings[i][b][m]);
			}
			printf("\n");
		}
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				copy[i][b][m]=groupings[i][b][m];
			}
			
		}
		
	}
	for(i=0;i<noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			n=i+1;
			for(c=0;c<num[n];c++)
			{
				flagship=0;
				for(m=0;m<noofvariables;m++)
				{
					if(groupings[i][b][m]!=groupings[n][c][m])
					{
						flagship=flagship+1;
					}
				}
				if(flagship==1)
				{
					for(m=0;m<noofvariables;m++)
					{
						if(groupings[i][b][m]!=groupings[n][c][m])
						{
							copy[n][c][m]=-1;
							pairs[i][b]=1;
							pairs[n][c]=1;
						}
					}
				}
				
			}
			
		}
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				printf("%d",copy[i][b][m]);
			}
			printf("\n");
		}
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			if(pairs[i][b]!=1)
			{
				for(m=0;m<noofvariables;m++)
				{
					primeimplicant[x][m]=groupings[i][b][m];
				}
				x++;
			}
		}
		
	}
	for(i=0;i<x;i++)
	{
		for(m=0;m<noofvariables;m++)
		{
			printf("%d",primeimplicant[i][m]);
		}
		printf("\n");
	}
	printf("hi guys\n");
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				printf("%d",groupings[i][b][m]);
			}
			printf("\n");
		}
		
	}
	for(i=0;i<noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			n=i+1;
			for(c=0;c<num[n];c++)
			{
				flagship=0;
				for(m=0;m<noofvariables;m++)
				{
					if(groupings[i][b][m]!=groupings[n][c][m])
					{
						flagship=flagship+1;
					}
				}
				if(flagship==1)
				{
					for(m=0;m<noofvariables;m++)
					{
						
						printf("%d",groupings[i][b][m]);
						pairings[d][e][m]=groupings[i][b][m];
					}
					printf("\n");
					
					for(m=0;m<noofvariables;m++)
					{
						printf("%d",groupings[n][c][m]);
						pairings[d][f][m]=groupings[n][c][m];
					}
					printf("\n");
					d++;
				
				}
				
			}
			
		}
	}
	//printf("%d",jones[9][9][9]);
    printf("hi guys , i am here \n");
	for(i=0;i<d;i++)
	{
		for(m=0;m<noofvariables;m++)
		{
			printf("%d",pairings[i][e][m]);
		}
		printf("\n");
		for(m=0;m<noofvariables;m++)
		{
			printf("%d",pairings[i][f][m]);
		}
		printf("\n");
	}
    for(i=0;i<d;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            if(pairings[i][e][m]==pairings[i][f][m])
            {
                secondlevel[i][m]=pairings[i][f][m];
            }
            else
            {
                secondlevel[i][m]=-1;
            }
        }
    }
    y=i;
    printf("hi everyone,i am here now\n");
    for(i=0;i<y;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%d",secondlevel[i][m]);
        }
        printf("\n");
    }
    
return 0;	
}
