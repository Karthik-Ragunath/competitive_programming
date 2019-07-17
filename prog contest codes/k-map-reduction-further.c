#include <stdio.h>


int main(void) {
	int noofvariables,number,input[100]={0},j=0,i,noofminterms,binaryofinput[100][100]={0},k,m,count;
	int group[100]={0},type[100]={0};//zerocounter=0,onecounter=0,twocounter=0,threecounter=0,fourcounter=0;
	int groupings[100][100][100]={0},duplicate[100][100][100]={0},num[100]={0},flagship,n;
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
	/*for(i=0;i<=noofminterms;i++)
	{
		switch(type[i])
		{
			case 0:
				for(m=0;m<noofvariables;m++)
				{
					groupings[type[i]][zerocounter][m]=binaryofinput[i][m];
				}
				zerocounter++;
				break
			case 1:
				for(m=0;m<noofvariables;m++)
				{
					groupings[type[i]][onecounter][m]=binaryofinput[i][m];
				}
				onecounter++;
				break;
			case 2:
				for(m=0;m<noofvariables;m++)
				{
					groupings[type[i]][twocounter][m]=binaryofinput[i][m];
				}
				twocounter++;
				break;
			case 3:
				for(m=0;m<noofvariables;m++)
				{
					groupings[type[i]][threecounter][m]=binaryofinput[i][m];
				}
				threecounter++;
				break;
			case 4:
				for(m=0;m<noofvariables;m++)
				{
					groupings[type[i]][fourcounter][m]=binaryofinput[i][m];
				}
				fourcounter++;
				break;
		}
	}*/
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
		while(num[i]--)
		{
			for(m=0;m<noofvariables;m++)
			{
				printf("%d",groupings[i][num[i]][m]);
			}
			printf("\n");
		}
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		while(num[i]--)
		{
			for(m=0;m<noofvariables;m++)
			{
				duplicate[i][num[i]][m]=groupings[i][num[i]][m];
			}
			
		}
		
	}
	for(i=0;i<noofvariables;i++)
	{
		//printf("hi\n");
		while(num[i]--)
		{
			n=i+1;
			{
				while(num[n]--)
				{
					for(m=0;m<noofvariables;m++)
					{
						flagship=0;
						if(groupings[i][num[i]][m]!=groupings[n][num[n]][m])
						{
							flagship=flagship+1;
							
						}
					}
					if(flagship==1)
					{
						//printf("i am here \n");
						for(m=0;m<noofvariables;m++)
						{
							if(groupings[i][num[i]][m]!=groupings[n][num[n]][m])
							{
								
							}
						}
					}
				
				}
			}
		}
	}
	
}
