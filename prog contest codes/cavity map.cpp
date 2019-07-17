#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
	string str,str1,str2;
	stringstream ss;
	int integer,i=0,j,a[100][100],size,duplicate,l,k;
	cin>>size;
	
	while(cin>>str)
	{	
		
	
	//	cout<<"hi"<<endl;
		ss.clear();
		ss<<str;
		if(ss>>integer)
			{
			cout<<integer<<endl;
			duplicate=size;
			j=size-1;
			while(duplicate--)
				{
					a[i][j]=integer%10;
					integer=integer/10;
					j=j-1;;
				}
			}
		i++;
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	/*ss.clear();
	ss<<a[2][2];
	ss>>str1;
	cout<<str1;
	ss.clear();*/
	 for(i=0;i<size;i++)
        {
        for(j=0;j<size;j++)
            {
            if((j!=0)&&(j!=size-1))
               {
                    l=a[i][j-1];
                    k=a[i][j+1];
                    if((a[i][j]>l)&&(a[i][j]>k))
                       {
                           a[i][j]=-1000;
                       }
               }
            }
        }
        for(i=0;i<size;i++)
        {
        for(j=0;j<size;j++)
            {
            cout<<a[i][j]<<endl;
            }
        }
        for(i=0;i<size;i++)
        {
        	for(j=0;j<size;j++)
        	{
        		ss.clear();
        		ss<<a[i][j];
        		ss>>str2;
        		if(str2=="-1000")
        		{
        			cout<<"X";
        		}
        		else
        		{
        			cout<<str2;
        		}
        		
        	}
        	cout<<endl;
        }
	
	// your code goes here
	return 0;
}