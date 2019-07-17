/*
 * Complete the function below.
 */
int countDuplicates(vector < int > numbers) {
    int vectorsize,i,j,count=0;
    vectorsize=numbers.size();
    for(i=1;i<vectorsize;i++)
        {
        j=i;
        while(j--)
            {
            if(numbers[i]==numbers[j])
                {
                count=count+1;
                break;
                }
            }
        }
    return count;


}

