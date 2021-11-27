/*
 * Complete the function below.
 */

    static int[] CountBits(int n) {
        int count=0;
        String answer=Integer.toBinaryString(n);
        char[] char_array=answer.toCharArray();
        int length=answer.length();
        ArrayList<Integer> answer_list=new ArrayList<Integer>();
        for(int i=0;i<length;i++)
        {
            if(char_array[i]=='1')
            {
                answer_list.add(i+1);
            }
        }
        Integer[] answer_array=answer_list.toArray(new Integer[answer_list.size()]);
        int temp=answer_list.size();
        int[] returner=new int[temp+1];
        returner[0]=temp;
        for(int i=0,j=1;i<temp;i++,j++)
        {
            returner[j]=(int)(answer_array[i]);
        }
        return returner;
    }

