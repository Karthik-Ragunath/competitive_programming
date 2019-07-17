#include <iostream>
using namespace std;

int main() {
	long long int matrix[100][100],realproduct,product1,product2,product3,product4;
	int i,j;
	realproduct=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			cin>>matrix[i][j];
		}
	}
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			product1=matrix[i][j]*matrix[i+1][j]*matrix[i+2][j]*matrix[i+3][j];
			product2=matrix[i][j]*matrix[i+1][j+1]*matrix[i+2][j+2]*matrix[i+3][j+3];
			product3=matrix[i][j]*matrix[i][j+1]*matrix[i][j+2]*matrix[i][j+3];
			product4=matrix[i][j+3]*matrix[i+1][j+2]*matrix[i+1][j+1]*matrix[i+3][j];
			if(product1>=product2)
			{
				if(product1>=product3)
				{
					if(product1>=product4)
					{
						if(product1>=realproduct)
						{
							realproduct=product1;
						}
					}
					else
					{
						if(product4>=realproduct)
						{
							realproduct=product4;
						}
					}
				}
				else
				{
					if(product3>=product4)
					{
						if(product3>=realproduct)
						{
							realproduct=product3;
						}
					}
					else
					{
						if(product4>=realproduct)
						{
							realproduct=product4;
						}
					}
					
				}
			}
			else
			{
				if(product2>=product3)
				{
					if(product2>=product4)
					{
						if(product2>=realproduct)
						{
							realproduct=product2;
						}
					}
					else
					{
						if(product4>=realproduct)
						{
							realproduct=product4;
						}
					}
				}
				else
				{
					if(product3>=product4)
					{
						if(product3>=realproduct)
						{
							realproduct=product3;
						}
					}
					else
					{
						if(product4>=realproduct)
						{
							realproduct=product4;
						}
					}
					
				}
			}
            
			
			
		}
	}
    cout<<realproduct;
	
	// your code goes here
	return 0;
}