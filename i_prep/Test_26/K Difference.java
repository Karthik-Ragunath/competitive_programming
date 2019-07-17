/*
 * Complete the function below.
 */

    static int kDifference(int[] a, int k) {
        int length=a.length;
        int count=0;
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {
                int absolute=(int)(Math.abs(a[i]-a[j]));
                if(absolute==k)
                {
                    count=count+1;
                }
            }
        }
        return count;
    }

