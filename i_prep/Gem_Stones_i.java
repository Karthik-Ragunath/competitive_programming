/*
 * Complete the function below.
 */

    static int gemstones(String[] rocks) {
        int length=rocks.length;
        int[] counter=new int[26];
        for(int i=0;i<length;i++)
        {
            int length1=rocks[i].length();
            //System.out.println(rocks[i]);
            char[] char_array=rocks[i].toCharArray();
            boolean[] flagship=new boolean[26];
            for(int j=0;j<length1;j++)
            {
                int temp=(int)(char_array[j]-'a');
                //System.out.println(temp);
                if(flagship[temp]==false)
                {
                    counter[temp]=counter[temp]+1;
                    flagship[temp]=true;
                }
            }
        }
        int answer=0;
        for(int i=0;i<26;i++)
        {
            if(counter[i]==length)
            {
                answer=answer+1;
            }
        }
        return answer;
    }

