import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
import java.lang.*;

class Node
{
    int item;
    Node left;
    Node right;
}

public class Solution {
    public static void main(String[] args) {
        int number_of_queries;
        Scanner in=new Scanner(System.in);
        number_of_queries=in.nextInt();
        Node root=new Node();
        Queue<Node> queue=new LinkedList<Node>();
        for(int i=0;i<number_of_queries;i++)
        {
            if(i==0)
            {
                int query_type,data;
                //query_type=in.nextInt();
                data=in.nextInt();
                Node newnode=new Node();
                newnode.item=data;
                newnode.left=null;
                newnode.right=null;
                root=newnode;
                queue.add(root);
                System.out.println(root.item);
            }
            else
            {
                Node tempNode=queue.poll();
                for(int j=1;j<=2;j++)
                {
                    int query_type,data;
                    //query_type=in.nextInt();
                    data=in.nextInt();
                    if(tempNode.left==null)
                    {
                        tempNode.left=new Node();
                        tempNode.left.item=data;
                        tempNode.left.left=null;
                        tempNode.left.right=null;
                        queue.add(tempNode.left);
                        System.out.println(tempNode.left.item+" 1");
                    }
                    if(j==1)
                    {
                        i=i+1;
                        if(i>=number_of_queries)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if(tempNode.right==null)
                    {
                        tempNode.right=new Node();
                        tempNode.right.item=data;
                        tempNode.right.left=null;
                        tempNode.right.right=null;
                        queue.add(tempNode.right);
                        System.out.println(tempNode.right.item+" 2");
                    }
                }
            }
        }
        System.out.println("Output checker");
        Queue<Node> output_checker=new LinkedList<Node>();
        output_checker.add(root);
        while(!(output_checker.isEmpty()))
        {
            Node temporary=output_checker.poll();
            System.out.println(temporary.item);
            if(temporary.left!=null)
            {
                output_checker.add(temporary.left);
            }
            if(temporary.right!=null)
            {
                output_checker.add(temporary.right);
            }
        }
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}