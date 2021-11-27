/*
 * Complete the function below.
 */

    static String[] ReduceFraction(String[] fractions) {
        int length=fractions.length;
        String[] answer=new String[length];
        for(int i=0;i<length;i++) 
        {
            String[] fractos=fractions[i].split("/");
            int frac1=Integer.parseInt(fractos[0]);
            int frac2=Integer.parseInt(fractos[1]);
            int tempo1=frac1;
            int tempo2=frac2;
            while(frac2!=0)
            {
                int temp=frac2;
                frac2=frac1%frac2;
                frac1=temp;
            }
            //System.out.println(tempo1+" "+frac1);
            int answer1=tempo1/frac1;
            int answer2=tempo2/frac1;
            String stringer1=String.valueOf(answer1);
            String stringer2=String.valueOf(answer2);
            answer[i]=stringer1+"/"+stringer2;
        }
        return answer;
    }

