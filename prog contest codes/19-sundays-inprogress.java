/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	int compute(BigInteger year,int month,int date)
	{
		BigInteger monthly,dating,offset;
		monthly=BigInteger.valueOf(month);
		dating=BigInteger.valueOf(date);
		BigInteger q,m,calculatedyear,k,j;
		int computedvalue;
		q=dating;
		if(monthly.compareTo(BigInteger.valueOf(3))<0)
		{
			m=monthly.add(BigInteger.valueOf(12));
			calculatedyear=year.subtract(BigInteger.valueOf(1));
		}
		else
		{
			m=monthly;
			calculatedyear=year;
		}
		k=calculatedyear.mod(BigInteger.valueOf(100));
		j=calculatedyear.divide(BigInteger.valueOf(100));
		offset=(j.multiply(BigInteger.valueOf(5))).add(j.divide(BigInteger.valueOf(4)));
		offset=(offset.add(k)).add(k.divide(BigInteger.valueOf(4)));
		offset=offset.add(((BigInteger.valueOf(13)).multiply(m.add(BigInteger.valueOf(1)))).divide(BigInteger.valueOf(5)));
		offset=offset.add(q);
		offset=offset.mod(BigInteger.valueOf(7));
		computedvalue=offset.intValue();
		return computedvalue;
	}
	int isleapyear(BigInteger year1)
	{
		if(((year1.mod(BigInteger.valueOf(400))).compareTo(BigInteger.valueOf(0)))==0)
		{
			return 1;
		}
		else if(((year1.mod(BigInteger.valueOf(100))).compareTo(BigInteger.valueOf(0)))==0)
		{
			return 0;
		}
		else if(((year1.mod(BigInteger.valueOf(4))).compareTo(BigInteger.valueOf(0)))==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int monthlydays(BigInteger year2,int month2)
	{
		switch(month2)
		{
			case 1:
				return 31;
				
			case 2:
				int z;
				z=isleapyear(year2);
				if(z==1)
				{
					return 29;
				}
				else
				{
					return 28;
				}
			case 3:
				return 31;
			case 4:
				return 30;
			case 5:
				return 31;
			case 6:
				return 30;
			case 7:
				return 31;
			case 8:
				return 31;
			case 9:
				return 30;
			case 10:
				return 31;
			case 11:
				return 30;
			case 12:
				return 31;
			default:
				System.out.println("wrong entry");
		
		}
		return 0;
		
	}

	public static void main (String[] args) throws java.lang.Exception
	{
		int testcases,checkvalue,loopiteration,sunday;
        Scanner in=new Scanner(System.in);
        BigInteger sourceyear,destinationyear,i;
        int sourcemonth,destinationmonth,p;
        int sourcedate,destinationdate;
        testcases=in.nextInt();
        for(int a=0;a<testcases;a++)
        {
        	sunday=0;
        	BigInteger[] year=new BigInteger[2];
        	int[] month=new int[2];
        	int[] day=new int[2];
        	for(p=0;p<=1;p++)
        	{
        		year[p]=in.nextBigInteger();
        		month[p]=in.nextInt();
        		day[p]=in.nextInt();
        	}
        	sourceyear=year[0];
        		//System.out.println(sourceyear);
        	destinationyear=year[1];
        		//System.out.println(destinationyear);
        	sourcemonth=month[0];
        	destinationmonth=month[1];
        	sourcedate=day[0];
        	destinationdate=day[1];
        	for(i=sourceyear;i.compareTo(destinationyear)<=0;i=i.add(BigInteger.valueOf(1)))
        	{
        				System.out.println("I am here");
        		if((i.compareTo(sourceyear)==0)&&(i.compareTo(destinationyear)==0))	
        		{
        			for(int j=sourcemonth;j<=destinationmonth;j++)
        			{
        				if((j==sourcemonth)&&(j==destinationmonth))
        				{
        						System.out.println("I am also here");
        					for(int k=sourcedate;k<=destinationdate;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        							
        						}
        					}
        				}
        				else if(j==sourcemonth)
        				{
        					loopiteration=new Ideone().monthlydays(i,j);
        					for(int k=sourcedate;k<=loopiteration;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        					
        				}
        				else if(j==destinationmonth)
        				{
        					for(int k=1;k<=destinationdate;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        				else
        				{
        					loopiteration=new Ideone().monthlydays(i,j);
        					for(int k=1;k<=loopiteration;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        				
        			}
        		}
        		else if(i.compareTo(sourceyear)==0)
        		{
        			for(int j=sourcemonth;j<=12;j++)
        			{
        				if(j==sourcemonth)
        				{
        					loopiteration=new Ideone().monthlydays(i,j);
        					for(int k=sourcedate;k<=loopiteration;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        				else
        				{
        					loopiteration=new Ideone().monthlydays(i,j);
        					for(int k=1;k<=loopiteration;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        			}
        		}
        		else if(i.compareTo(destinationyear)==0)
        		{
        			for(int j=1;j<=destinationmonth;j++)
        			{
        				if(j==destinationmonth)
        				{
        					for(int k=1;k<=destinationdate;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        				else
        				{
        					loopiteration=new Ideone().monthlydays(i,j);
        					for(int k=1;k<=loopiteration;k++)
        					{
        						checkvalue=new Ideone().compute(i,j,k);
        						if(checkvalue==1)
        						{
        							sunday=sunday+1;
        						}
        					}
        				}
        			}
        		}
        		else
        		{
        			for(int j=1;j<=12;j++)
        			{
        				loopiteration=new Ideone().monthlydays(i,j);
        				for(int k=1;k<=loopiteration;k++)
        				{
        					checkvalue=new Ideone().compute(i,j,k);
        					if(checkvalue==1)
        					{
        						sunday=sunday+1;
        					}
        				}
        			}
        		}
        	}
        	
        System.out.println(sunday);	
        }
		// your code goes here
	}
}