import java.io.*;
import java.util.*;
import java.lang.*;
public class Solution {

    public static void main(String[] args) {
        int testcases;
        Scanner in=new Scanner(System.in);
        testcases=in.nextInt();
        in.nextLine();
        ArrayList<Integer> list=new ArrayList<Integer>();
        for(int k=0;k<testcases;k++)
        {
            String temp=in.nextLine();
            String[] input=temp.split(" ");
            int length=input.length;
            if(length!=1)
            {
                int operation=Integer.parseInt(input[0]);
                if(operation==1)
                {
                    int element=Integer.parseInt(input[1]);
                    list.add(element);
                    Integer[] array=list.toArray(new Integer[list.size()]);
                    for(int i=(list.size()-1);array[(i-1)/2]>array[i];i=((i-1)/2))
                    {
                        Integer temporary=array[i];
                        array[i]=array[(i-1)/2];
                        array[(i-1)/2]=temporary;
                        if((i-1)/2==0)
                        {
                            break;
                        }
                    }
                    list=new ArrayList<Integer>(Arrays.asList(array));
                }
                else
                {
                    Integer element=Integer.parseInt(input[1]);
                    int index=list.size()-1;
                    Integer deleted=list.remove(index);
                    //System.out.println("deleted :"+deleted);
                    if((int)element==(int)deleted)
                    {
                        continue;
                    }
                    Integer[] array=list.toArray(new Integer[list.size()]);
                    /*int[] input_array=new int[list.size()];
                    //System.out.println("List size :"+list.size());*/
                    int breaker=0;
                    //System.out.println("List Size: "+list.size());
                    for(int i=0;i<list.size();i++)
                    {
                        if((int)array[i]==(int)element)
                        {
                            //System.out.println("Inside");
                            breaker=i;
                            array[i]=deleted;
                            break;
                        }
                    }
                    /*for(int i=0;i<list.size();i++)
                    {
                        System.out.println(array[i]);
                    }
                    System.out.println("deleted :"+array[breaker]);
                    System.out.println("Breaker :"+breaker);*/
                    int max=list.size();
                    //int count=0;
                    for(int i=breaker;;)
                    {
                        //count=count+1;
                        //System.out.println(count);
                        if((i*2+1)<max)
                        {
                            //System.out.println("Hi 1");
                            if((i*2+2)<max)
                            {
                                //System.out.println("Hi 2");
                                if((int)array[i*2+1]>(int)array[i*2+2])
                                {
                                    //System.out.println("Hi 3");
                                    if((int)array[i]>(int)array[2*i+2])
                                    {
                                        //System.out.println("Hi 4");
                                        Integer temporary=array[i];
                                        array[i]=array[2*i+2];
                                        array[2*i+2]=temporary;
                                        i=2*i+2;
                                        continue;
                                    }
                                    else
                                    {
                                        //System.out.println("Hi 5");
                                        break;
                                    }
                                }
                                else
                                {
                                    if((int)array[i]>(int)array[2*i+1])
                                    {
                                        //System.out.println("Hi 6");
                                        Integer temporary=array[i];
                                        array[i]=array[2*i+1];
                                        array[2*i+1]=temporary;
                                        i=2*i+1;
                                        continue;
                                    }
                                    else
                                    {
                                        //System.out.println("Hi 7");
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                if((int)array[i]>(int)array[2*i+1])
                                {
                                    //System.out.println("Hi 8");
                                    Integer temporary=array[i];
                                    array[i]=array[2*i+1];
                                    array[2*i+1]=temporary;
                                    break;
                                }
                                else
                                {
                                    //System.out.println("Hi 9");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            //System.out.println("Hi 10");
                            break;
                        }
                    }
                    //System.out.println("2nd");
                    /*for(int i=0;i<list.size();i++)
                    {
                        array[i]=(Integer)input_array[i];
                        //System.out.println(i+" "+array[i]);
                    }*/   
                    list=new ArrayList<Integer>(Arrays.asList(array));
                }
            }
            else
            {
                //System.out.print("3 :");
                int element_to_be_displayed=list.get(0);
                System.out.println(element_to_be_displayed);
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}