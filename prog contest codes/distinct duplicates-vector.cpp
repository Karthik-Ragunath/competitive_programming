/*
 * Complete the function below.
 */
int countDuplicates(vector < int > numbers) {
    long long int vectorsize,i,j,count=0,array[10000],k=1,l,duplicate,flag;
    array[0]=0;
    array[1]=0;
    vectorsize=numbers.size();
    for(i=1;i<vectorsize;i++)
        {
        j=i;
        while(j--)
            {
            if(numbers[i]==numbers[j])
                {
                duplicate=numbers[i];
                l=k;
                while(l)
                    {
                    if(duplicate==array[l])
                        {
                        flag=0;
                        break;
                        }
                    else
                        {
                        flag=1;
                        }
                    l=l-1;
                    }
                if(flag==1)
                    {
                    k=k+1;
                    array[k]=duplicate;
                    count=count+1;
                    }
            
                }
            }
        }
    return count;
}

