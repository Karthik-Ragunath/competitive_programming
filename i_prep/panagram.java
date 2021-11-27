/*
 * Complete the function below.
 */

    static String isPangram(String[] strings) {
        String ans="";
        System.out.println(strings[0]);
        int length=strings.length;
        //System.out.println(length);
        for(int i=0;i<length;i++)
        {
            int str_length=strings[i].length();
            //System.out.println(str_length);
            String temp=strings[i];
            boolean[] panagram=new boolean[26];
            char[] char_array=temp.toCharArray();
            for(int k=0;k<str_length;k++)
            {
                if(char_array[k]==' ')
                {
                    continue;
                }    
                int temp1=(int)(char_array[k]-'a');
                panagram[temp1]=true;
            }
            boolean flagship=true;
            for(int j=0;j<26;j++)
            {
                
                if(panagram[j]==false)
                {
                    flagship=false;
                    break;
                }
            }
            if(flagship==false)
            {
                System.out.println("hi");
                ans=ans+"0";
            }
            else
            {
                ans=ans+"1";
            }
            System.out.println(ans);
        }
        return ans;

    }

