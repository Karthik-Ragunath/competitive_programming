/*
 * Complete the function below.
 */

    static int countHoles(int num) {
        Map<Integer,Integer> countholes=new HashMap<Integer,Integer>();
        countholes.put(1,0);
        countholes.put(2,0);
        countholes.put(3,0);
        countholes.put(5,0);
        countholes.put(7,0);
        countholes.put(0,1);
        countholes.put(4,1);
        countholes.put(6,1);
        countholes.put(9,1);
        countholes.put(8,2);
        String input=String.valueOf(num);
        int length=input.length();
        char[] char_array=input.toCharArray();
        int holes=0;
        for(int i=0;i<length;i++)
        {
            int temp=(int)(char_array[i]-'0');
            holes=holes+countholes.get(temp);
        }
        return holes;
    }

