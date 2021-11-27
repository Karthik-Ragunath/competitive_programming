/*
 * Complete the function below.
 */

    static void counterGame(String[] tests) {
        int testcases=tests.length;
        BigInteger[] input_array=new BigInteger[65];
        input_array[0]=BigInteger.valueOf(1);
        for(int i=1;i<65;i++)
        {
            input_array[i]=input_array[i-1].multiply(BigInteger.valueOf(2));
        }
        for(int k=0;k<testcases;k++)
        {
            BigInteger input=new BigInteger(tests[k]);
            int user;
            //System.out.println(input);
            for(user=1;;user++)
            {
                int low=0;
                int high=64;
                boolean flagship=false;
                for(int j=0;low<=high;j++)
                {
                    int mid=(low+high)/2;
                    if(input_array[mid].compareTo(input)==0)
                    {
                        flagship=true;
                        break;
                    }
                    if(input_array[mid].compareTo(input)<0)
                    {
                        low=mid+1;
                        continue;
                    }
                    if(input_array[mid].compareTo(input)>0)
                    {
                        high=mid-1;
                    }
                }
                if(flagship==false)
                {
                    input=input.subtract(input_array[high]);
                }
                else
                {
                    input=input.divide(BigInteger.valueOf(2));
                }
                if(input.compareTo(BigInteger.valueOf(1))==0)
                {
                    break;
                }
            }
            if(user%2==1)
            {
                System.out.println("Louise");
            }
            else
            {
                System.out.println("Richard");
            }
        }


    }