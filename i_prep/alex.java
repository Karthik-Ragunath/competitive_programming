/*
 * Complete the function below.
 */

    static int verifyItems(String[] origItems, float[] origPrices, String[] items, float[] prices) {
        int length1=origItems.length;
        int length2=items.length;
        Map<String,Float> original=new TreeMap<String,Float>();
        for(int i=0;i<length1;i++)
        {
            original.put(origItems[i],origPrices[i]);
        }
        int count=0;
        for(int i=0;i<length2;i++)
        {
            String temp=items[i];
            if(original.containsKey(temp))
            {
                float tempo=original.get(temp);
                if(tempo!=prices[i])
                {
                    count=count+1;
                }
            }
        }
        return count;
    }

