import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
    int numberofdigits,digitseliminated;
    Scanner in=new Scanner(System.in);
    numberofdigits=in.nextInt();
    digitseliminated=in.nextInt();
    int realsolutionnum=0;
    int realsolutionden=0;
    if(numberofdigits==3)
    {
        for(int den=100;den<1000;den++)
        {
            for(int num=100;num<den;num++)
            {
                float originalvalue=((float)num/(float)den);
                int temp,temp1,temp2,temp3,flagship1=0;
                Integer tempo;
                int count=0;
                /*String s1="";
                String s2="";*/
                String s3="";
                String s4="";
                int[][] comele=new int[3][3];
                int[] common=new int[3];
                int[] flag=new int[3];
                List<Integer> eliminationnum=new ArrayList<Integer>();
                List<Integer> indexnum=new ArrayList<Integer>();
                List<Integer> eliminationden=new ArrayList<Integer>();
                List<Integer> indexden=new ArrayList<Integer>();
                String numerator=String.valueOf(num);
                char[] numarray=numerator.toCharArray();
                String denominator=String.valueOf(den);
                char[] denarray=denominator.toCharArray(); 
                char[] numstrcon=new char[3];
                char[] denstrcon=new char[3];
                for(int i=0;i<3;i++)
                {
                    temp=numarray[i]-'0';
                    eliminationnum.add(temp);
                    indexnum.add(temp);
                }
                            
                for(int i=0;i<3;i++)
                {
                    temp=denarray[i]-'0';
                    eliminationden.add(temp);
                    indexden.add(temp);
                }
                            /*String test="";
                            Iterator numerator2=eliminationnum.iterator();
                            Iterator denominator2=eliminationden.iterator();
                            if((num==194)&&(den==291))
                            {
                                 while(numerator2.hasNext())
                                 {
                                    test=test+numerator2.next();
                                    System.out.println(test);
                                 }
                                 test="";
                                 while(denominator2.hasNext())
                                 {
                                     test=test+denominator2.next();
                                     System.out.println(test);
                                 }
                                
                            }*/
                for(int i=0;i<3;i++)
                {
                    tempo=denarray[i]-'0';
                    if((eliminationnum.contains(tempo))&&(tempo!=0))
                    {
                        count=count+1;
                        //common[count-1]=temp;
                        eliminationnum.remove(tempo);
                    }
                }
                for(int i=0;i<3;i++)
                {
                    tempo=numarray[i]-'0';
                    if((eliminationden.contains(tempo))&&(tempo!=0))
                    {
                        eliminationden.remove(tempo);
                    }
                }
                            /*if((num==194)&&(den==291))
                            {
                                System.out.println(count);
                            }                
                            if((num==194)&&(den==291))
                            {
                                System.out.println("hi");
                            }
                            test="";
                            Iterator numerator3=eliminationnum.iterator();
                            Iterator denominator3=eliminationden.iterator();
                            if((num==194)&&(den==291))
                            {
                                 while(numerator3.hasNext())
                                 {
                                    test=test+numerator3.next();
                                    System.out.println(test);
                                 }
                                 test="";
                                 while(denominator3.hasNext())
                                 {
                                     test=test+denominator3.next();
                                     System.out.println(test);
                                 }
                                
                            }*/
                for(int i=0;i<3;i++)
                {
                    temp=numarray[i]-'0';
                    for(int j=0;j<3;j++)
                    {
                        temp1=denarray[j]-'0';
                        if((temp==temp1)&&(flag[j]!=1)&&(temp!=0))
                        {
                            comele[i][j]=1; 
                            flag[j]=1;
                        }
                    }
                }
                        /*if((num==194)&&(den==291))
                        {
                            for(int i=0;i<3;i++)
                            {
                                for(int j=0;j<3;j++)
                                {
                                    if(comele[i][j]==1)
                                    {
                                        System.out.println(i+" "+j);
                                    }
                                }
                            }
                        }*/
                        
                        String test1="";
                        String test2="";
                if(count==digitseliminated)
                {
                    Iterator numerator1=eliminationnum.iterator();
                    Iterator denominator1=eliminationden.iterator();
                            /*if((num==132)&&(den==231))
                            {
                                 while(numerator1.hasNext())
                                 {
                                    test1=test1+numerator1.next();
                                    System.out.println(test1);
                                 }
                                 while(denominator1.hasNext())
                                 {
                                     test2=test2+denominator1.next();
                                     System.out.println(test2);
                                 }
                                
                            }*/
                    int enterflag1=0;
                    int enterflag2=0;
                    int number=10;
                    int m=3-digitseliminated;
                    int numeratorvalue=0,denominatorvalue=0;
                    while(numerator1.hasNext())
                    {
                        /*if(enterflag1==0)
                        {
                            tempo=(Integer)numerator1.next();
                            s1=String.valueOf(tempo);
                            enterflag1=1;
                        }
                        else
                        {
                            tempo=(Integer)numerator1.next();
                            s1=s1+String.valueOf(tempo);
                        }*/
                        tempo=(Integer)numerator1.next();
                        /*numstrcon[m]=(char)(tempo+'0');
                        System.out.println("the num is "+numstrcon[m]);
                        m++;*/
                                        numeratorvalue=numeratorvalue+(int)(tempo*(Math.pow(number,(m-1))));;
                                        m--;
                        
                        
                    }
                    m=3-digitseliminated;
                    while(denominator1.hasNext())
                    {
                        /*if(enterflag2==0)
                        {
                            tempo=(Integer)denominator1.next();
                            s2=String.valueOf(tempo);
                            enterflag2=1;
                        }
                        else
                        {
                            tempo=(Integer)denominator1.next();
                            s2=s2+String.valueOf(tempo);
                        }*/
                        tempo=(Integer)denominator1.next();
                        /*denstrcon[m]=(char)(tempo+'0');
                        System.out.println("the den is "+denstrcon[m]);
                        m++;*/
                                    denominatorvalue=denominatorvalue+(int)(tempo*(Math.pow(number,(m-1))));
                                    m--;
                    }
                    /*s1=s1.replace("\"","");
                    s2=s2.replace("\"","");*/
                    /*String s1=String.valueOf(numstrcon);
                    String s2=String.valueOf(denstrcon);
                    int numeratorvalue=Integer.parseInt(s1);
                    int denominatorvalue=Integer.parseInt(s2);*/
                            /*if((num==132)&&(den==231))
                            {
                                System.out.println(numeratorvalue+" "+denominatorvalue);
                            }*/
                    float computedvalue=((float)numeratorvalue/(float)denominatorvalue);
                    if(originalvalue==computedvalue)
                    {
                        System.out.println(num+" "+den);
                        realsolutionnum=realsolutionnum+num;
                        realsolutionden=realsolutionden+den;
                    }
                }
                if(count>digitseliminated)
                {
                    if(digitseliminated==(numberofdigits-1))
                    {
                        continue;
                    }
                    int diff=count-digitseliminated;
                    
                                        /*if((num==194)&&(den==291))
                                        {
                                            System.out.println("hi man");
                                        }*/
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(comele[i][j]==1)
                            {
                                temp2=i;
                                temp3=j;
                                                /*if((num==194)&&(den==291))
                                                {
                                                    System.out.println("hi yo "+temp2+" "+temp3);
                                                }*/
                            
                                for(int k=0;k<3;k++)
                                {
                                    if(k!=temp2)
                                    {
                                                /*if((num==194)&&(den==291))
                                                {
                                                    System.out.println("hi uuu");
                                                }*/
                                        temp=numarray[k]-'0';
                                        s3=s3+String.valueOf(temp);
                                    }
                                }
                                /*if((num==194)&&(den==291))
                                {
                                    System.out.println("hi girl");
                                    System.out.println(s3);
                                    //System.out.println(s4);
                                }
                                */
                                for(int k=0;k<3;k++)
                                {
                                    if(k!=temp3)
                                    {
                                        temp=denarray[k]-'0';
                                        s4=s4+String.valueOf(temp);
                                    }
                                }
                                //s3=s3.replace("\"","");
                                //s4=s4.replace("\"","");
                                int duplicatenum=Integer.parseInt(s3);
                                int duplicateden=Integer.parseInt(s4);
                                                /*if((num==194)&&(den==291))
                                                {
                                                    System.out.println("hi u");
                                                    System.out.println(s3);
                                                    System.out.println(s4);
                                                    System.out.println(duplicatenum+" "+duplicateden);
                                                }*/
                                s3="";
                                s4="";
                                float computedvalue1=(float)duplicatenum/(float)duplicateden;
                                if(computedvalue1==originalvalue)
                                {
                                    System.out.println(num+" "+den);
                                    realsolutionnum=realsolutionnum+num;
                                    realsolutionden=realsolutionden+den;
                                    flagship1=1;
                                    
                                }
                                if(flagship1==1)
                                {
                                    break;
                                }
                            }
                        }
                        if(flagship1==1)
                        {
                            break;
                        }
                    }
                }
                    
            }
        }
    }
    System.out.println(realsolutionnum+" "+realsolutionden);   
    
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}