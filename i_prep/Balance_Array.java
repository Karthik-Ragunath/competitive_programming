/*
 * Complete the function below.
 */

    static int balanceSum(int[] A) {
        int length=A.length;
        int left_sum=A[0];
        int right_sum=0;
        for(int i=1;i<length;i++)
        {
            right_sum=right_sum+A[i];
        }
        for(int i=1;i<length;i++)
        {
            right_sum=right_sum-A[i];
            if(left_sum==right_sum)
            {
                return i+1;
            }
            left_sum=left_sum+A[i];
        }
        return 0;
    }

