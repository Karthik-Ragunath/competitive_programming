/*
 * Complete the function below.
 */

    static int maximum_XOR(int a, int b) {
        int maximum=0;
        for(int i=a;i<=b;i++)
        {
            for(int j=i;j<=b;j++)
            {
                int temp=i^j;
                if(temp>maximum)
                {
                    maximum=temp;
                }
            }
        }
        return maximum;
    }

