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
                    int[] input_array=new int[list.size()];
                    for(int i=0;i<list.size();i++)
                    {
                        input_array[i]=(int)(array[i]);
                    }
                    int max_size=list.size();
                    if(max_size==1)
                    {
                        for(int i=0;i<list.size();i++)
                        {
                            array[i]=(Integer)input_array[i];
                            //System.out.println(array[i]);
                        }    
                        list=new ArrayList<Integer>(Arrays.asList(array));
                        continue;
                    }
                    for(int i=(list.size()-1);input_array[(i-1)/2]>input_array[i];i=((i-1)/2))
                    {
                        int temporary=input_array[i];
                        input_array[i]=input_array[(i-1)/2];
                        input_array[(i-1)/2]=temporary;
                        if((i-1)/2==0)
                        {
                            break;
                        }
                    }
                    //System.out.println("1st");
                    for(int i=0;i<list.size();i++)
                    {
                        array[i]=(Integer)input_array[i];
                        //System.out.println(i+" "+array[i]);
                    }    
                    list=new ArrayList<Integer>(Arrays.asList(array));
                }
                else
                {
                    int element=Integer.parseInt(input[1]);
                    int index=list.size()-1;
                    int deleted=list.remove(index);
                    //System.out.println("deleted :"+deleted);
                    if(element==deleted)
                    {
                        continue;
                    }
                    Integer[] array=list.toArray(new Integer[list.size()]);
                    int[] input_array=new int[list.size()];
                    //System.out.println("List size :"+list.size());
                    for(int i=0;i<list.size();i++)
                    {
                        input_array[i]=(int)(array[i]);
                    }
                    int breaker=0;
                    //System.out.println("List Size: "+list.size());
                    for(int i=0;i<list.size();i++)
                    {
                        if(input_array[i]==element)
                        {
                            breaker=i;
                            input_array[i]=deleted;
                            break;
                        }
                    }
                    //System.out.println("deleted :"+input_array[breaker]);
                    //System.out.println("Breaker :"+breaker);
                    int max=list.size();
                    int count=0;
                    for(int i=breaker;;)
                    {
                        count=count+1;
                        //System.out.println(count);
                        if((i*2+1)<max)
                        {
                            //System.out.println("Hi 1");
                            if((i*2+2)<max)
                            {
                                //System.out.println("Hi 2");
                                if(input_array[i*2+1]>input_array[i*2+2])
                                {
                                    //System.out.println("Hi 3");
                                    if(input_array[i]>input_array[2*i+2])
                                    {
                                        //System.out.println("Hi 4");
                                        int temporary=input_array[i];
                                        input_array[i]=input_array[2*i+2];
                                        input_array[2*i+2]=temporary;
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
                                    if(input_array[i]>input_array[2*i+1])
                                    {
                                        int temporary=input_array[i];
                                        input_array[i]=input_array[2*i+1];
                                        input_array[2*i+1]=temporary;
                                        i=2*i+1;
                                        continue;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                            else
                            {
                                if(input_array[i]>input_array[2*i+1])
                                {
                                    int temporary=input_array[i];
                                    input_array[i]=input_array[2*i+1];
                                    input_array[2*i+1]=temporary;
                                    break;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    //System.out.println("2nd");
                    for(int i=0;i<list.size();i++)
                    {
                        array[i]=(Integer)input_array[i];
                        //System.out.println(i+" "+array[i]);
                    }   
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