/*
 * Complete the function below.
 */

    static int minUnfairness(int k, int[] arr) {
        Arrays.sort(arr);
        int length=arr.length;
        /*for(int i=0;i<length;i++)
        {
            System.out.println(arr[i]);
        }*/
        int answer=2000000000;
        for(int i=0;i<=(length-k);i++)
        {
            int max=0;
            int min=2000000000;
            for(int j=i;j<(i+k);j++)
            {
                if(arr[j]>max)
                {
                    max=arr[j];
                }
                if(arr[j]<min)
                {
                    min=arr[j];
                }
            }
            int temp=max-min;
            if(temp<answer)
            {
                answer=temp;
            }
            //System.out.println(i+" "+answer);
        }
        return answer;
    }

