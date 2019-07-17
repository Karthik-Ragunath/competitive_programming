/*
 * Complete the function below.
 */

    static String[] cavityMap(String[] arr) {
        int length=arr.length;
        char[][] character_array=new char[length][length];
        for(int i=0;i<length;i++)
        {
            character_array[i]=arr[i].toCharArray();
        }
        int[][] integer_array=new int[length][length];
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length;j++)
            {
                integer_array[i][j]=(int)(character_array[i][j]-'0');
            }
        }
        String[] answers=new String[length];
        for(int i=0;i<length;i++)
        {
            if((i==0)||(i==(length-1)))
            {
                answers[i]=String.valueOf(character_array[i]);
                continue;
            }
            for(int j=0;j<length;j++)
            {
                if((j!=0)&&(j!=(length-1)))
                {
                    if((integer_array[i][j]>integer_array[i][j+1])&&(integer_array[i][j]>integer_array[i][j-1]))
                    {
                        character_array[i][j]='X';
                    }
                }
            }
            answers[i]=String.valueOf(character_array[i]);
        }
        for(int i=0;i<length;i++)
        {
            System.out.println(answers[i]);
        }
        return answers;
    }

