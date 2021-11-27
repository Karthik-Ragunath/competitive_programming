    static int[] max_Chocolates(int[] arr) {
        int testcases=arr.length;
        int[] max=new int[testcases];
        for(int i=0;i<testcases;i++)
        {
            int temp=arr[i];
            for(int k=1;k<temp;k++)
            {
                int j=temp-k;
                int tempo=k*j;
                if(tempo>max[i])
                {
                    max[i]=tempo;
                }
            }
        }
        return max;

    }

